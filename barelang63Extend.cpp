#include "barelang63Extend.h"

Extend::Extend()
{
}

void Extend::initExtend(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), uint8_t home_pin)
{
    init(pinA, pinB, encA, encB, userFunc);
    home.setPin(home_pin);

}

void Extend::homing(){
    if(home){
        setPos(0);
        Run(0);
        return;
    }
    goTo(0);
}

void Extend::homing(int speed){
    if(home){
        setPos(0);
        Run(0);
        return;
    }
    Run(speed);
}

bool Extend::getBt(){
    return home;
}