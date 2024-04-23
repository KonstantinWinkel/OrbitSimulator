// Author: Konstantin Winkel

// own includes
#include "controller.h"

Controller::Controller(Object * obj) {
    this->obj = obj;
}

LinearController::LinearController(Object * obj) : Controller(obj) {

}

void LinearController::initializeController() {

}

void LinearController::applyControlForce(long double timestamp) {
    obj->addForce(Eigen::Vector3<long double>(0,5,0));
}

void LinearController::finalizeController() {
    
}