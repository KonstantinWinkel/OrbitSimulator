// Author: Konstantin Winkel

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

// own includes
#include "object.h"

class Controller {

    protected:
        Object * obj;
    
    public:
        Controller(Object * obj);

        virtual void initializeController() = 0;
        virtual void applyControlForce(long double timestamp) = 0;
        virtual void finalizeController() = 0;
};

class LinearController: public Controller {
    public:
        LinearController(Object * obj);

        void initializeController() override;
        void applyControlForce(long double timestamp) override;
        void finalizeController() override;
};

#endif