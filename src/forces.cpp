// Author: Konstantin Winkel

// own includes
#include "constants.h"
#include "forces.h"

// cpp includes
#include <tgmath.h>


Vec3  Force::gravity(ld m1, ld m2, Vec3  distance) { 
    return distance * (-1) * (G_STAR * m1 * m2) / (powl(distance.norm(), 3)); 
}
