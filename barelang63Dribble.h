// #define ARDUINO_DRIBBLE_BARELANG63_HEADER
// #ifndef ARDUINO_DRIBBLE_BARELANG63_HEADER

#include "Arduino.h"
#include "barelangMotor.h"
#include "barelangSensor.h"

class DribblePot : public Potentiometer
{
    private:
        int initVal = 0;
        bool dir = true;
    public:
        DribblePot();

        DribblePot(uint8_t pot_pin, bool dir);

        operator int(){ return readDribPot();}

        void setDir(bool dir);

        void PotCallibration();

        int readDribPot();
};
// class Dribble{
//     private:
//     public:
// };

// #endif
