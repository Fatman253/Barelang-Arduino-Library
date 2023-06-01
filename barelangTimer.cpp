#include "barelangTimer.h"

barelangTimer::barelangTimer(){
    tick = millis();
}

bool barelangTimer::every(int ms){
    if(millis() - tick >= ms){
        tick = millis();
        return true;
    }
    return false;
}

void barelangTimer::settimePoint(){
    tick = millis();
}

unsigned long barelangTimer::sincetimePoint(){
    return millis() - tick;
}

bool barelangTimer::sincetimePoint(int ms){
    if(millis() - tick >= ms){
        return true;
    }
    return false;
}


barelangTimermicros::barelangTimermicros(){
    tick = millis();
}

bool barelangTimermicros::every(int us){
    if(millis() - tick >= us){
        tick = millis();
        return true;
    }
    return false;
}

void barelangTimermicros::settimePoint(){
    tick = millis();
}

bool barelangTimermicros::sincetimePoint(int us){
    if(millis() - tick >= us){
        return true;
    }
    return false;
}

unsigned long barelangTimermicros::sincetimePoint(){
    return millis() - tick;
}

