#ifndef ARDUINO_TIMER_BARELANG63
#define ARDUINO_TIMER_BARELANG63

#include "Arduino.h"

class barelangTimer{
    private:
        unsigned long tick;
    public:
    barelangTimer();

    operator unsigned long(){ return millis() - tick;}

    bool every(int ms);

    unsigned long sincetimePoint();

    bool sincetimePoint(int ms);

    void settimePoint();

    unsigned long getTick() { return tick;}
};

class barelangTimermicros{
    private:
        unsigned long tick;
    public:
    barelangTimermicros();

    operator unsigned long(){ return millis() - tick;}

    bool every(int us);

    unsigned long sincetimePoint();

    bool sincetimePoint(int us);

    void settimePoint();

    unsigned long getTick() { return tick;}
};

#endif /* BE5CE34B_97D2_4A72_B086_14859194AA5A */
