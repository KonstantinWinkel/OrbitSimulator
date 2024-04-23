// Author: Konstantin Winkel

// own includes
#include "constants.h"
#include "forces.h"

// cpp includes
#include <tgmath.h>


Eigen::Vector3<long double>  Force::gravity(long double m1, long double m2, Eigen::Vector3<long double>  distance) { 
    return distance * (-1) * (G_STAR * m1 * m2) / (powl(distance.norm(), 3)); 
}
