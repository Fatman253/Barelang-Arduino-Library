#include "barelang63Dribble.h"

DribblePot::DribblePot(){

}

DribblePot::DribblePot(uint8_t pot_pin, bool dir){
    setPin(pot_pin);
    this-> dir = dir;
    PotCallibration();
}

void DribblePot::setDir(bool dir){
    this->dir = dir;
}

void DribblePot::PotCallibration(){
    initVal = readPot();
}

int DribblePot::readDribPot(){
    if(dir)
        return readPot() - initVal;
    return initVal - readPot();
}
