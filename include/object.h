// Author: Konstantin Winkel

#ifndef _OBJECT_H_
#define _OBJECT_H_

// cpp includes
#include <string>
#include <vector>

// Eigen includes
#include <Eigen/Dense>

class Object {
    private:

        std::string name;

        Eigen::Vector3<long double> acceleration;
        Eigen::Vector3<long double> velocity;
        Eigen::Vector3<long double> position;

        Eigen::Quaternion<long double> orientation;
        Eigen::Vector3<long double> angular_velocity;

        long double mass;
        bool is_static = false;
        bool is_orientationless = false;

        // constructor for code grouping, should not be used on its own 
        Object(std::string name, long double mass);

    public:
        Object(std::string name, long double mass, Eigen::Vector3<long double> init_pos, Eigen::Vector3<long double> init_vel);
        Object(std::string name, long double mass, Eigen::Vector3<long double> init_pos, Eigen::Vector3<long double> init_vel, Eigen::Vector3<long double> init_theta, Eigen::Vector3<long double> init_omega);
        Object(std::string name, long double mass, Eigen::Vector3<long double> init_pos, Eigen::Vector3<long double> init_vel, Eigen::Quaternion<long double> init_Q, Eigen::Vector3<long double> init_dQ);
        Object(std::string name, long double mass, Object central_body, long double semimajor_axis, long double eccentricity, long double inclination, long double RAAN, long double peri_arg);
        ~Object();

        void startTimeStep();
        void addForce(Eigen::Vector3<long double>  force);
        void simulateTimeStep(long double step);

        void setStatic(bool b);
        void setOrientationless(bool b);

        long double getMass();
        bool getStatic(); 
        std::string getName();
        Eigen::Vector3<long double> getPosition();
        Eigen::Vector3<long double> getVelocity();
        Eigen::Quaternion<long double> getOrientationQuaternion();
        Eigen::Vector3<long double> getOrientation();
        Eigen::Vector3<long double> getAngularVelocity();
};

#endif