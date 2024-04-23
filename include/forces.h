// Author: Konstantin Winkel

#ifndef _FORCES_H_
#define _FORCES_H_

// Eigen includes
#include <Eigen/Dense>

class Force {
    public:
        static Eigen::Vector3<long double>  gravity(long double m1, long double m2, Eigen::Vector3<long double>  distance);
};

#endif