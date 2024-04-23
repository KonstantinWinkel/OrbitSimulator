// Author: Konstantin Winkel

// Example: 00
// Description: A body remains at rest, or in motion at a constant speed in a 
//              straight line, except insofar as it is acted upon by a force

// includes all headers
#include "api.h"

// cpp includes
#include <stdlib.h>

int main(int argc, char * agrv[]) {

    long double simulation_time = 1000.0;

    if(argc > 1) simulation_time = strtod(agrv[1], nullptr);
    
    Object sat1("Satellite1", 5, {0,0,0}, {1,0,0});

    PositionObserver obs1(sat1.getName(), 1, &sat1);


    World world(0.001, simulation_time, 1000);

    world.addObject(&sat1);
    world.addObserver(&obs1);

    world.simulate();

    return 0;
}