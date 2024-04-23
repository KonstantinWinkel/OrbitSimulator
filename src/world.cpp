// Author: Konstantin Winkel

// own includes
#include "eigen-utils.h"
#include "forces.h"
#include "world.h"

// cpp includes
#include <fstream>

World::World() { }

World::World(long double simulation_timestep, long double simulation_time, long double writing_ratio) {
    this->simulation_timestep = simulation_timestep;
    this->simulation_time = simulation_time;
    this->writing_ratio = writing_ratio;
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
    long long last_write = writing_ratio;

    for(Observer * o: observers) o->initializeObserver();
    for(Controller * c: controllers) c->initializeController();

    for(long double t = 0; t < simulation_time; t += simulation_timestep) {
        for(Object * obj1: objects) {
            obj1->startTimeStep();

            for(Object * obj2: objects) {
                if(obj1 == obj2) continue;
                if(obj1->getStatic() && obj2->getStatic()) continue;

                obj1->addForce(Force::gravity(obj1->getMass(), obj2->getMass(), obj1->getPosition() - obj2->getPosition()));
            }            
        }

        for(Controller * c: controllers) c->applyControlForce(t);

        for(Object * o: objects) o->simulateTimeStep(simulation_timestep);

        for(Observer * o: observers) o->logState(t);

    }

    for(Observer * o: observers) o->finalizeObserver();
    for(Controller * c: controllers) c->finalizeController();
}


void World::setSimulationTimestep(long double n) { simulation_timestep = n; }
void World::setSimulationTime(long double n) { simulation_time = n; }
void World::setWritingRatio(long long n) { writing_ratio = n; }

long double World::getSimulationTimestep() { return simulation_timestep; }
long double World::getSimulationTime() { return simulation_time; }
long long World::getWritingRation() {return writing_ratio; }