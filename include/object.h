// Author: Konstantin Winkel

#ifndef _OBJECT_H_
#define _OBJECT_H_

// own includes
#include "type-definitions.h"

// cpp includes
#include <string>
#include <vector>

class Object {
    private:

        std::string name;

        Vec3 acceleration;
        Vec3 velocity;
        Vec3 position;

        Quat orientation;
        Vec3 angular_velocity;

        ld mass;
        bool is_static = false;
        bool is_orientationless = false;

        // constructor for code grouping, should not be used on its own 
        Object(std::string name, ld mass);

    public:
        Object(std::string name, ld mass, Vec3 init_pos, Vec3 init_vel);
        Object(std::string name, ld mass, Vec3 init_pos, Vec3 init_vel, Vec3 init_theta, Vec3 init_omega);
        Object(std::string name, ld mass, Vec3 init_pos, Vec3 init_vel, Quat init_Q, Vec3 init_dQ);
        Object(std::string name, ld mass, Object central_body, ld semimajor_axis, ld eccentricity, ld inclination, ld RAAN, ld peri_arg);
        ~Object();

        void startTimeStep();
        void addForce(Vec3  force);
        void simulateTimeStep(ld step);

        void setStatic(bool b);
        void setOrientationless(bool b);

        ld getMass();
        bool getStatic(); 
        std::string getName();
        Vec3 getPosition();
        Vec3 getVelocity();
        Quat getOrientationQuaternion();
        Vec3 getOrientation();
        Vec3 getAngularVelocity();
};

#endif