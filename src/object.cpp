// Author: Konstantin Winkel

// own includes
#include "eigen-utils.h"
#include "constants.h"
#include "object.h"

// cpp includes
#include <iostream>
#include <tgmath.h>

Object::Object(std::string name, ld mass) {
    this->name = name;
    this->mass = mass;
}

Object::Object(std::string name, ld mass, Vec3  init_pos, Vec3  init_vel) : Object(name, mass) {
    this->position = init_pos;
    this->velocity = init_vel;
    this->acceleration = {0,0,0};
    this->orientation = Quat();
    this->angular_velocity = {0,0,0};
}

Object::Object(std::string name, ld mass, Vec3 init_pos, Vec3 init_vel, Vec3 init_theta, Vec3 init_omega) : Object(name, mass, init_pos, init_vel) {
    this->orientation = EigenUtils::QuaternionFromRPY(init_theta);
    this->angular_velocity = init_omega * DEG2RAD;
}

Object::Object(std::string name, ld mass, Vec3 init_pos, Vec3 init_vel, Quat init_Q, Vec3 init_omega) : Object(name, mass, init_pos, init_vel) {
    this->orientation = init_Q;
    this->angular_velocity = init_omega * DEG2RAD;
}

Object::Object(std::string name, ld mass, Object central_body, ld semimajor_axis, ld eccentricity, ld inclination,  ld RAAN, ld peri_arg) : Object(name, mass) {
    ld r_peri = semimajor_axis * (1 - eccentricity);
    ld vel = sqrtl(G_STAR * central_body.getMass() * (2 / r_peri - 1 / semimajor_axis ));

    this->position = {0, r_peri, 0};
    this->position = EigenUtils::rotationMatrix(peri_arg, 0, RAAN) * Vec3 {0, r_peri, 0};
    this->velocity = EigenUtils::rotationMatrix(peri_arg, 0, RAAN) * Vec3 {cosl(inclination * DEG2RAD), 0, sinl(inclination * DEG2RAD)} * vel;
    this->acceleration = {0,0,0};

}

Object::~Object() { }

void Object::startTimeStep() { 
    if(is_static) return;

    acceleration = {0,0,0};
}

void Object::addForce(Vec3  force) {
    if(is_static) return;

    acceleration += force / mass;
}

void Object::simulateTimeStep(ld step) {
    if(is_static) return;

    velocity += acceleration * step;
    position += velocity * step + acceleration * step * step * 0.5;

    if(is_orientationless) return;

   Quat d_q = orientation * Quat(0, 0.5 * step * angular_velocity);
   orientation = Quat(orientation.w() + d_q.w(), orientation.x() + d_q.x(), orientation.y() + d_q.y(), orientation.z() + d_q.z());
}

void Object::setStatic(bool b) { is_static = b; }
void Object::setOrientationless(bool b) { is_orientationless = b; }

ld Object::getMass() { return mass; }
bool Object::getStatic() { return is_static; }
std::string Object::getName() { return name; }
Vec3  Object::getPosition() { return position; }
Vec3  Object::getVelocity() { return velocity; }
Quat Object::getOrientationQuaternion() { return orientation; }
Vec3 Object::getOrientation() { return EigenUtils::ToEulerAngles(orientation); }
Vec3 Object::getAngularVelocity() { return angular_velocity; }