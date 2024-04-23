// Author: Konstantin Winkel

// own includes
#include "eigen-utils.h"
#include "constants.h"
#include "object.h"

// cpp includes
#include <iostream>
#include <tgmath.h>


Object::Object(std::string name, long double mass, Eigen::Vector3<long double>  init_pos, Eigen::Vector3<long double>  init_vel) {
    this->name = name;
    this->mass = mass;
    this->position = init_pos;
    this->velocity = init_vel;
    this->acceleration = {0,0,0};
}

Object::Object(std::string name, long double mass, Object central_body, long double semimajor_axis, long double eccentricity, long double inclination,  long double RAAN, long double peri_arg) {
    long double r_peri = semimajor_axis * (1 - eccentricity);
    long double vel = sqrtl(G_STAR * central_body.getMass() * (2 / r_peri - 1 / semimajor_axis ));

    this->name = name;
    this->mass = mass;
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
}

void Object::setStatic(bool b) { is_static = b; }


long double Object::getMass() { return mass; }
bool Object::getStatic() { return is_static; }
std::string Object::getName() { return name; }
Eigen::Vector3<long double>  Object::getPosition() { return position; }
Eigen::Vector3<long double>  Object::getVelocity() { return velocity; }