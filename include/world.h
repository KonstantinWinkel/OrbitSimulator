// Author: Konstantin Winkel

#ifndef _WORLD_H_
#define _WORLD_H_

// own includes
#include "controller.h"
#include "object.h"
#include "observer.h"
#include "type-definitions.h"

// cpp includes
#include <iostream>
#include <sstream>
#include <vector>


class World {

    private:
        std::vector<Object * > objects;
        std::vector<Observer * > observers;
        std::vector<Controller * > controllers;

        ld simulation_timestep = 0.1;
        ld simulation_time = 100.0;

    public:
        World();
        World(ld simulation_timestep, ld simulation_time);
        
        ~World();

        void addObject(Object * n);
        void addObjects(std::vector<Object * > objects);
        void addObserver(Observer * n);
        void addObservers(std::vector<Observer * > observers);
        void addController(Controller * c);
        void addControllers(std::vector<Controller * > controllers);
       
        void simulate();

        void setSimulationTimestep(ld n);
        void setSimulationTime(ld n);
        void setWritingRatio(long long n);

        ld getSimulationTimestep();
        ld getSimulationTime();
        long long getWritingRation();

};

#endif