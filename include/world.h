// Author: Konstantin Winkel

#ifndef _WORLD_H_
#define _WORLD_H_

// own includes
#include "controller.h"
#include "object.h"
#include "observer.h"

// cpp includes
#include <iostream>
#include <sstream>
#include <vector>


class World {

    private:
        std::vector<Object * > objects;
        std::vector<Observer * > observers;
        std::vector<Controller * > controllers;

        long double simulation_timestep = 0.1;
        long double simulation_time = 100.0;
        long long writing_ratio = 10;

    public:
        World();
        World(long double simulation_timestep, long double simulation_time, long double writing_ratio);
        
        ~World();

        void addObject(Object * n);
        void addObjects(std::vector<Object * > objects);
        void addObserver(Observer * n);
        void addObservers(std::vector<Observer * > observers);
        void addController(Controller * c);
        void addControllers(std::vector<Controller * > controllers);
       
        void simulate();

        void setSimulationTimestep(long double n);
        void setSimulationTime(long double n);
        void setWritingRatio(long long n);

        long double getSimulationTimestep();
        long double getSimulationTime();
        long long getWritingRation();

};

#endif