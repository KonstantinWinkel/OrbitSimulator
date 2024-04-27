// Author: Konstantin Winkel

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

// own includes
#include "object.h"
#include "type-definitions.h"

class Controller {

    protected:
        Object * obj;
    
    public:
        Controller(Object * obj);

        virtual void initializeController() = 0;
        virtual void applyControlForce(ld timestamp, ld delta_t) = 0;
        virtual void finalizeController() = 0;
};

class TimeIntervalController : public Controller {
    public:
        enum Direction {
            Prograde,
            Retrograde
        };
    
    private:
        struct Interval {
            Direction dir;
            ld start_time;
            ld end_time;
        };

        std::vector<Interval> intervals;

        ld force;

    public:

        TimeIntervalController(Object * obj, ld force);

        void initializeController() override;
        void applyControlForce(ld timestamp, ld delta_t) override;
        void finalizeController() override;

        void addInterval(Direction dir, ld start_time, ld end_time);
};

#endif