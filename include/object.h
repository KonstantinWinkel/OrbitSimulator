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

        long double mass;
        bool is_static = false;

    public:
        Object(std::string name, long double mass, Eigen::Vector3<long double> init_pos, Eigen::Vector3<long double> init_vel);
        Object(std::string name, long double mass, Object central_body, long double semimajor_axis, long double eccentricity, long double inclination, long double RAAN, long double peri_arg);
        ~Object();

        void startTimeStep();
        void addForce(Eigen::Vector3<long double>  force);
        void simulateTimeStep(long double step);

        void setStatic(bool b);

        long double getMass();
        bool getStatic(); 
        std::string getName();
        Eigen::Vector3<long double> getPosition();
        Eigen::Vector3<long double> getVelocity();
};

#endif