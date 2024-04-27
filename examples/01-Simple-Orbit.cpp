// Author: Konstantin Winkel

// Example: 01
// Description: Two satellites going around the earth, nothing
//              special, not even inclination

// includes all headers
#include "api.h"

// cpp includes
#include <stdlib.h>

int main(int argc, char * agrv[]) {

    // defines how long the simulation should run
    long double simulation_time = 6200.0_s;

    // if a command line argument is present, convert it to number and 
    // set it as the length of the simulation
    if(argc > 1) simulation_time = strtod(agrv[1], nullptr);
    
    // create three objects for the simulation
    // 1. Earth in the origin with no initial speed
    // 2. A satellite with a mass of 5kg at an altitude of 300km with a speed
    //    of 7725.84 m s^-1 (the velocity a satellite needs at that height to
    //    have a circular orbit)
    // 3. Another satellite with a mass of 5kg. This time we use the a different
    //    constructor to directly define an orbit around a central body, here Earth.
    //    The semi-major axis gets set to an altitude of 900km and all other keplerian
    //    elements (eccentricity, inclination, right ascencion of accending node and
    //    argument of perigee) are set to 0
    Object Earth("Earth", M_EARTH, {0,0,0}, {0,0,0});
    Object sat1("Satellite1", 5, {0, R_EARTH + 300.0_km, 0}, {7725.84 ,0 ,0});
    Object sat2("Satellite2", 5, Earth, R_EARTH + 900_km, 0, 0, 0, 0);

    // we set some properties of objects.
    // 1. Earth is so heavy compared to the satellites that we can safely assume it
    //    to be static, i.e. not moving due to gravity
    // 2. Again, we are only interested in position of the satellites and not their
    //    attitude so we set them to be orientationless
    Earth.setStatic(true);
    sat1.setOrientationless(true);
    sat2.setOrientationless(true);

    // We create 3 Position Observers, one for each Object
    // The satellites get observed every second, while for earth 
    PositionObserver obs0(Earth.getName(), 1000_s, &Earth);
    PositionObserver obs1(sat1.getName(), 1_s, &sat1);
    PositionObserver obs2(sat2.getName(), 1_s, &sat2);


    World world(1_ms, simulation_time);

    world.addObjects({&Earth, &sat1, &sat2});
    world.addObservers({&obs0, &obs1, &obs2});

    world.simulate();

    return 0;
}