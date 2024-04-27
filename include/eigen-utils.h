// Author: Konstantin Winkel

#ifndef _EIGEN_UTILS_H_
#define _EIGEN_UTILS_H_

// own includes
#include "constants.h"
#include "type-definitions.h"

// cpp includes
#include <string>

// Eigen includes
#include <Eigen/Dense>

static const Vec3 UnitX(1, 0, 0);
static const Vec3 UnitY(0, 1, 0);
static const Vec3 UnitZ(0, 0, 1);

class EigenUtils
{ 
    public:
        static std::string Vector3ToCSV(Vec3 v) {
            return std::to_string(v.x()) + ", " + std::to_string(v.y()) + ", " + std::to_string(v.z());
        }

        static Eigen::Matrix3<ld> rotationMatrix(ld x, ld y, ld z) {
            Eigen::AngleAxis<ld> r_z(z * DEG2RAD, UnitZ);
            Eigen::AngleAxis<ld> r_y(y * DEG2RAD, UnitY);
            Eigen::AngleAxis<ld> r_x(x * DEG2RAD, UnitX);
            Quat q = r_z * r_y * r_x;

            return q.matrix();
        }

        static Quat QuaternionFromRPY(Vec3 RPY) {
            Eigen::AngleAxis<ld> r_x(RPY.x() * DEG2RAD, UnitX);
            Eigen::AngleAxis<ld> r_y(RPY.y() * DEG2RAD, UnitY);
            Eigen::AngleAxis<ld> r_z(RPY.z() * DEG2RAD, UnitZ);
            Quat q = r_x * r_y * r_z;

            return q;
        }

        // source: https://stackoverflow.com/questions/31589901/euler-to-quaternion-quaternion-to-euler-using-eigen
        static Vec3 ToEulerAngles(const Quat& q) {
            Vec3 angles;    //RPY
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