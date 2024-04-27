// Author: Konstantin Winkel

#ifndef _EIGEN_UTILS_H_
#define _EIGEN_UTILS_H_

// own includes
#include "constants.h"

// cpp includes
#include <string>

// Eigen includes
#include <Eigen/Dense>

static const Eigen::Vector3<long double> UnitX(1, 0, 0);
static const Eigen::Vector3<long double> UnitY(0, 1, 0);
static const Eigen::Vector3<long double> UnitZ(0, 0, 1);

class EigenUtils
{ 
    public:
        static std::string Vector3ToCSV(Eigen::Vector3<long double> v) {
            return std::to_string(v.x()) + ", " + std::to_string(v.y()) + ", " + std::to_string(v.z());
        }

        static Eigen::Matrix3<long double> rotationMatrix(long double x, long double y, long double z) {
            Eigen::AngleAxis<long double> r_z(z * DEG2RAD, UnitZ);
            Eigen::AngleAxis<long double> r_y(y * DEG2RAD, UnitY);
            Eigen::AngleAxis<long double> r_x(x * DEG2RAD, UnitX);
            Eigen::Quaternion<long double> q = r_z * r_y * r_x;

            return q.matrix();
        }

        static Eigen::Quaternion<long double> QuaternionFromRPY(Eigen::Vector3<long double> RPY) {
            Eigen::AngleAxis<long double> r_x(RPY.x() * DEG2RAD, UnitX);
            Eigen::AngleAxis<long double> r_y(RPY.y() * DEG2RAD, UnitY);
            Eigen::AngleAxis<long double> r_z(RPY.z() * DEG2RAD, UnitZ);
            Eigen::Quaternion<long double> q = r_x * r_y * r_z;

            return q;
        }

        // source: https://stackoverflow.com/questions/31589901/euler-to-quaternion-quaternion-to-euler-using-eigen
        static Eigen::Vector3<long double> ToEulerAngles(const Eigen::Quaternion<long double>& q) {
            Eigen::Vector3<long double> angles;    //RPY
            const auto x = q.x();
            const auto y = q.y();
            const auto z = q.z();
            const auto w = q.w();

            // roll (x-axis rotation)
            double sinr_cosp = 2 * (w * x + y * z);
            double cosr_cosp = 1 - 2 * (x * x + y * y);
            angles[0] = std::atan2(sinr_cosp, cosr_cosp);

            // pitch (y-axis rotation)
            double sinp = 2 * (w * y - z * x);
            if (std::abs(sinp) >= 1)
                angles[1] = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
            else
                angles[1] = std::asin(sinp);

            // yaw (z-axis rotation)
            double siny_cosp = 2 * (w * z + x * y);
            double cosy_cosp = 1 - 2 * (y * y + z * z);
            angles[1] = std::atan2(siny_cosp, cosy_cosp);
            return angles;
        }
};

#endif