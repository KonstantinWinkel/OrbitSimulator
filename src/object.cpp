// Author: Konstantin Winkel

// own includes
#include "eigen-utils.h"
#include "constants.h"
#include "object.h"

// cpp includes
#include <iostream>
#include <tgmath.h>

Object::Object(std::string name, long double mass) {
    this->name = name;
    this->mass = mass;
}

Object::Object(std::string name, long double mass, Eigen::Vector3<long double>  init_pos, Eigen::Vector3<long double>  init_vel) : Object(name, mass) {
    this->position = init_pos;
    this->velocity = init_vel;
    this->acceleration = {0,0,0};
    this->orientation = Eigen::Quaternion<long double>();
    this->angular_velocity = {0,0,0};
}

Object::Object(std::string name, long double mass, Eigen::Vector3<long double> init_pos, Eigen::Vector3<long double> init_vel, Eigen::Vector3<long double> init_theta, Eigen::Vector3<long double> init_omega) : Object(name, mass, init_pos, init_vel) {
    this->orientation = EigenUtils::QuaternionFromRPY(init_theta);
    this->angular_velocity = init_omega * DEG2RAD;
}

Object::Object(std::string name, long double mass, Eigen::Vector3<long double> init_pos, Eigen::Vector3<long double> init_vel, Eigen::Quaternion<long double> init_Q, Eigen::Vector3<long double> init_omega) : Object(name, mass, init_pos, init_vel) {
    this->orientation = init_Q;
    this->angular_velocity = init_omega * DEG2RAD;
}

Object::Object(std::string name, long double mass, Object central_body, long double semimajor_axis, long double eccentricity, long double inclination,  long double RAAN, long double peri_arg) : Object(name, mass) {
    long double r_peri = semimajor_axis * (1 - eccentricity);
    long double vel = sqrtl(G_STAR * central_body.getMass() * (2 / r_peri - 1 / semimajor_axis ));

    this->position = {0, r_peri, 0};
    this->position = EigenUtils::rotationMatrix(peri_arg, 0, RAAN) * Eigen::Vector3<long double> {0, r_peri, 0};
    this->velocity = EigenUtils::rotationMatrix(peri_arg, 0, RAAN) * Eigen::Vector3<long double> {cosl(inclination * DEG2RAD), 0, sinl(inclination * DEG2RAD)} * vel;
    this->acceleration = {0,0,0};

}

Object::~Object() { }

void Object::startTimeStep() { 
    if(is_static) return;

    acceleration = {0,0,0};
}

void Object::addForce(Eigen::Vector3<long double>  force) {
    if(is_static) return;

    acceleration += force / mass;
}

void Object::simulateTimeStep(long double step) {
    if(is_static) return;

    velocity += acceleration * step;
    position += velocity * step + acceleration * step * step * 0.5;

    if(is_orientationless) return;
    
    /*
    // source: https://mariogc.com/post/angular-velocity-quaternions/
    Eigen::Matrix4<long double> OMEGA;

    OMEGA << 1, -angular_velocity.x() , -angular_velocity.y(), -angular_velocity.z(),
             angular_velocity.x(), 1, angular_velocity.z(), -angular_velocity.y(),
             angular_velocity.y(), -angular_velocity.z(), 1, angular_velocity.x(),
             angular_velocity.z(), angular_velocity.y(), -angular_velocity.x(), 1; 

    // approximation for matrix exponential with k = 1
    //orientation = Eigen::Quaternion<long double>((step / 2) * OMEGA * orientation.coeffs());

    */

   Eigen::Quaternion<long double> d_q = orientation * Eigen::Quaternion<long double>(0, 0.5 * step * angular_velocity);

   orientation = Eigen::Quaternion<long double>(orientation.w() + d_q.w(), orientation.x() + d_q.x(), orientation.y() + d_q.y(), orientation.z() + d_q.z());
}

void Object::setStatic(bool b) { is_static = b; }
void Object::setOrientationless(bool b) { is_orientationless = b; }

long double Object::getMass() { return mass; }
bool Object::getStatic() { return is_static; }
std::string Object::getName() { return name; }
Eigen::Vector3<long double>  Object::getPosition() { return position; }
Eigen::Vector3<long double>  Object::getVelocity() { return velocity; }
Eigen::Quaternion<long double> Object::getOrientationQuaternion() { return orientation; }
Eigen::Vector3<long double> Object::getOrientation() { return EigenUtils::ToEulerAngles(orientation); }
Eigen::Vector3<long double> Object::getAngularVelocity() { return angular_velocity; }