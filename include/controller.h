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
        virtual void applyControlForce(long double timestamp, long double delta_t) = 0;
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
            long double start_time;
            long double end_time;
        };

        std::vector<Interval> intervals;

        long double force;

    public:

        TimeIntervalController(Object * obj, long double force);

        void initializeController() override;
        void applyControlForce(long double timestamp, long double delta_t) override;
        void finalizeController() override;

        void addInterval(Direction dir, long double start_time, long double end_time);
};

#endif