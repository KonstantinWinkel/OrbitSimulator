// Author: Konstantin Winkel

// own includes
#include "eigen-utils.h"
#include "forces.h"
#include "world.h"

// cpp includes
#include <fstream>

World::World() { }

World::World(ld simulation_timestep, ld simulation_time) {
    this->simulation_timestep = simulation_timestep;
    this->simulation_time = simulation_time;
}

World::~World() { }

void World::addObject(Object * n) { 
    objects.push_back(n);
}

void World::addObjects(std::vector<Object * > objects) {
    for(Object * o: objects) addObject(o);
}

void World::addObserver(Observer * n) {
    observers.push_back(n);
}
void World::addController(Controller * c) {
    controllers.push_back(c);
}

void World::addControllers(std::vector<Controller * > controllers) {
    for(Controller * c: controllers) addController(c);
}

void World::addObservers(std::vector<Observer * > observers) {
    for(Observer * o: observers) addObserver(o);
}

void World::simulate() {

    for(Observer * o: observers) o->initializeObserver();
    for(Controller * c: controllers) c->initializeController();

    for(ld t = 0; t < simulation_time; t += simulation_timestep) {
        for(Object * obj1: objects) {
            obj1->startTimeStep();

            for(Object * obj2: objects) {
                if(obj1 == obj2) continue;
                if(obj1->getStatic() && obj2->getStatic()) continue;

                obj1->addForce(Force::gravity(obj1->getMass(), obj2->getMass(), obj1->getPosition() - obj2->getPosition()));
            }            
        }

        for(Controller * c: controllers) c->applyControlForce(t, simulation_timestep);

        for(Object * o: objects) o->simulateTimeStep(simulation_timestep);

        for(Observer * o: observers) o->logState(t);

    }

    for(Observer * o: observers) o->finalizeObserver();
    for(Controller * c: controllers) c->finalizeController();
}


void World::setSimulationTimestep(ld n) { simulation_timestep = n; }
void World::setSimulationTime(ld n) { simulation_time = n; }

ld World::getSimulationTimestep() { return simulation_timestep; }
ld World::getSimulationTime() { return simulation_time; }