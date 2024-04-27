// Author: Konstantin Winkel

// Example: 00
// Description: A body remains at rest, or in motion at a constant speed in a 
//              straight line, except insofar as it is acted upon by a force

// includes all headers
#include "api.h"

// cpp includes
#include <stdlib.h>

int main(int argc, char * agrv[]) {

    // defines how long the simulation should run
    long double simulation_time = 1000.0_s;

    // if a command line argument is present, convert it to number and 
    // set it as the length of the simulation
    if(argc > 1) simulation_time = strtod(agrv[1], nullptr);
    
    // create a single Object called "Satellite1" with a mass of 5kg,
    // its initial position in the origin and moving with 1 m s^-1 in
    // x direction
    Object sat1("Satellite1", 5, {0,0,0}, {1,0,0});

    // we are only interested in its position so we can disregard its orientation
    sat1.setOrientationless(true);

    // create a Position Observer with the name of sat1 that logs the
    // observes sat1 and logs its position every second
    PositionObserver obs1(sat1.getName(), 1_s, &sat1);

    // Create the world for our simulation that simulates one timestep every millisecond
    // for as long as the simulation time is set
    World world(1_ms, simulation_time);

    // add the object and the observer to the world
    world.addObject(&sat1);
    world.addObserver(&obs1);

    // run the simulation
    world.simulate();

    return 0;
}