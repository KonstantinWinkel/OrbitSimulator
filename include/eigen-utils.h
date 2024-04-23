// Author: Konstantin Winkel

#ifndef _EIGEN_UTILS_H_
#define _EIGEN_UTILS_H_

// own includes
#include "constants.h"

// cpp includes
#include <string>

// Eigen includes
#include <Eigen/Dense>

class EigenUtils
{
    public:
        static std::string Vector3ToCSV(Eigen::Vector3<long double> v) {
            return std::to_string(v.x()) + ", " + std::to_string(v.y()) + ", " + std::to_string(v.z());
        }

        static Eigen::Matrix3<long double> rotationMatrix(long double x, long double y, long double z) {
            Eigen::AngleAxis<long double> r_z(z * DEG2RAD, Eigen::Vector3<long double>(0,0,1));
            Eigen::AngleAxis<long double> r_y(y * DEG2RAD, Eigen::Vector3<long double>(0,1,0));
            Eigen::AngleAxis<long double> r_x(x * DEG2RAD, Eigen::Vector3<long double>(1,0,0));
            Eigen::Quaternion<long double> q = r_z * r_y * r_x;

            return q.matrix();
        }
};

#endif