// Author: Konstantin Winkel

// Example: 01
// Description: Two satellites going around the earth, nothing
//              special, not even inclination

// includes all headers
#include "api.h"

// cpp includes
#include <stdlib.h>

int main(int argc, char * agrv[]) {

    long double simulation_time = 6200.0;

    if(argc > 1) simulation_time = strtod(agrv[1], nullptr);
    
    Object Earth("Earth", M_EARTH, {0,0,0}, {0,0,0});
    Object sat1("Satellite1", 5, {0,R_EARTH + 300000, 0}, {7725.84 ,0 ,0});
    Object sat2("Satellite2", 5, Earth, R_EARTH + 900000, 0, 0, 0, 0);

    Earth.setStatic(true);

    PositionObserver obs0(Earth.getName(), 1000, &Earth);
    PositionObserver obs1(sat1.getName(), 1, &sat1);
    PositionObserver obs2(sat2.getName(), 1, &sat2);


    World world(0.001, simulation_time, 1000);

    world.addObjects({&Earth, &sat1, &sat2});
    world.addObservers({&obs0, &obs1, &obs2});

    world.simulate();

    return 0;
}