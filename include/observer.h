// Author: Konstantin Winkel

#ifndef _OBSERVER_H_
#define _OBSERVER_H_

// own includes
#include "object.h"

// cpp includes
#include <fstream>
#include <string>


class Observer {
    protected:
        std::string name;
        std::ofstream output;

        long double last_log = 0;
        long double log_interval = 1;
    
    public:
        Observer(std::string name, long double log_interval);

        virtual void initializeObserver() = 0;
        virtual void logState(long double timestamp);
        virtual void customLogState(long double timestamp) = 0;
        virtual void finalizeObserver() = 0;
};

class PositionObserver: public Observer {

    private:
        Object * obj;

    public:
        PositionObserver(std::string name, long double log_interval, Object * obj);
        
        void initializeObserver() override;
        void customLogState(long double timestamp) override;
        void finalizeObserver() override;
};


class VelocityObserver: public Observer {

    private:
        Object * obj;

    public:
        VelocityObserver(std::string name, long double log_interval, Object * obj);
        
        void initializeObserver() override;
        void customLogState(long double timestamp) override;
        void finalizeObserver() override;
};

class DistanceObserver: public Observer {
    
    private:
        Object * obj1;
        Object * obj2;
    
    public:
        DistanceObserver(std::string name, long double log_interval, Object * obj1, Object * obj2);
        
        void initializeObserver() override;
        void customLogState(long double timestamp) override;
        void finalizeObserver() override;
};

class SpeedObserver: public Observer {

    private:
        Object * obj;

    public:
        SpeedObserver(std::string name, long double log_interval, Object * obj);
        
        void initializeObserver() override;
        void customLogState(long double timestamp) override;
        void finalizeObserver() override;
};

class OrientationObserver: public Observer{

    private:
        Object * obj;

    public:
        OrientationObserver(std::string name, long double log_interval, Object * obj);

        void initializeObserver() override;
        void customLogState(long double timestamp) override;
        void finalizeObserver() override;
};

#endif