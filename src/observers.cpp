// Author: Konstantin Winkel

// own includes
#include "eigen-utils.h"
#include "observer.h"

#include <iostream>

/* #region Parent of all Observers */

Observer::Observer(std::string name, long double log_interval){
    this->name = name;
    this->output = std::ofstream(name + ".csv");
    this->log_interval = log_interval;
    this->last_log = -log_interval;
}

void Observer::logState(long double timestamp){
    if(last_log + log_interval > timestamp) return;

    last_log = timestamp;
    customLogState(timestamp);
}

/* #endregion */

/* #region Position Observer */

PositionObserver::PositionObserver(std::string name, long double log_interval, Object * obj) : Observer("Position" + name, log_interval) {
    this->obj = obj;
}

void PositionObserver::initializeObserver() {
    output << "t,x,y,z" << std::endl;
}

void PositionObserver::customLogState(long double timestamp) {
    output << timestamp << ", " << EigenUtils::Vector3ToCSV(obj->getPosition()) << std::endl;
}

void PositionObserver::finalizeObserver() {

}

/* #endregion */

/* #region Velocity Observer */

VelocityObserver::VelocityObserver(std::string name, long double log_interval, Object * obj) : Observer("Velocity" + name, log_interval) {
    this->obj = obj;
}

void VelocityObserver::initializeObserver() {
    output << "t,x,y,z" << std::endl;
}

void VelocityObserver::customLogState(long double timestamp) {
    output << timestamp << ", " << EigenUtils::Vector3ToCSV(obj->getVelocity()) << std::endl;
}

void VelocityObserver::finalizeObserver() {
    
}

/* #endregion */

/* #region Distance Observer */

DistanceObserver::DistanceObserver(std::string name, long double log_interval, Object * obj1, Object * obj2) : Observer("Distance" + name, log_interval) {
    this->obj1 = obj1;
    this->obj2 = obj2;
}

void DistanceObserver::initializeObserver() {
    output << "t,s" << std::endl;
}

void DistanceObserver::customLogState(long double timestamp) {
    output << timestamp << ", " << (obj1->getPosition() - obj2->getPosition()).norm() << std::endl;
}

void DistanceObserver::finalizeObserver() {
    
}

/* #endregion */

/* #region Speed Observer */

SpeedObserver::SpeedObserver(std::string name, long double log_interval, Object * obj) : Observer("Speed" + name, log_interval) {
    this->obj = obj;
}

void SpeedObserver::initializeObserver() {
    output << "t,v" << std::endl;
}

void SpeedObserver::customLogState(long double timestamp) {
    output <<  timestamp << ", " << obj->getPosition().norm() << std::endl;
}

void SpeedObserver::finalizeObserver() {
    
}

/* #endregion */