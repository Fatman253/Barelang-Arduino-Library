#ifndef BARELANG63_EXTEND_ARDUINO_HEADER
#define BARELANG63_EXTEND_ARDUINO_HEADER

#include "barelangMotor.h"
#include "barelangSensor.h"

class Extend : public MotorPos
{
    private:
    ButtonPU home;
    public:
    
    Extend();

    void initExtend(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), uint8_t home_pin);

    void homing();

    void homing(int speed);

    bool getBt();
};

#endif 
