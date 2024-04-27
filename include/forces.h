// Author: Konstantin Winkel

#ifndef _FORCES_H_
#define _FORCES_H_

// own includes

// Eigen includes
#include <Eigen/Dense>

class Force {
    public:
        static Vec3  gravity(ld m1, ld m2, Vec3  distance);
};

#endif