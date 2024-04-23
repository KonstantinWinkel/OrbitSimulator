// Author: Konstantin Winkel

// own includes
#include "controller.h"

Controller::Controller(Object * obj) {
    this->obj = obj;
}

/* #region Time Interval Controller */

TimeIntervalController::TimeIntervalController(Object * obj, long double force) : Controller(obj) {
    this->force = force;
}

void TimeIntervalController::initializeController() {

}

void TimeIntervalController::applyControlForce(long double timestamp, long double delta_t) {
    Eigen::Vector3<long double> movement_dir = obj->getVelocity();
    movement_dir.normalize();

    for(Interval i: intervals) {
        if(timestamp < i.start_time || timestamp > i.end_time) continue;

        if(i.dir == Prograde) obj->addForce(movement_dir * force);
        if(i.dir == Retrograde) obj-> addForce(-1 * movement_dir * force);
    }
}

void TimeIntervalController::finalizeController() {

}

void TimeIntervalController::addInterval(Direction dir, long double start_time, long double end_time) {
    Interval i = {dir, start_time, end_time};

    intervals.push_back(i);
}

/* #endregion */