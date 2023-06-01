#ifndef ARDUINO_SENSOR_BARELANG63_HEADER
#define ARDUINO_SENSOR_BARELANG63_HEADER

#include "Arduino.h"
class Button
{
private:
    uint8_t buttonPin;

    bool PrevVal;

public:
    Button();

    Button(uint8_t buttonPin);

    void setPin(uint8_t buttonPin);

    operator bool() {return digitalRead(buttonPin);}

    void setPin(uint8_t buttonPin, uint8_t mode);

    bool Rising();

    bool readButton();
};

class ButtonPU
{
private:
    uint8_t buttonPin;
    bool PrevVal;

public:
    ButtonPU();

    ButtonPU(uint8_t buttonPin);

    operator bool() {return !digitalRead(buttonPin);}

    void setPin(uint8_t buttonPin);

    bool Rising();

    bool readButton();
};

class Potentiometer
{
private:
    uint8_t pot_pin;

public:
    Potentiometer();

    Potentiometer(uint8_t pot_pin);

    operator int() {return analogRead(pot_pin);}

    void setPin(uint8_t pot_pin);

    int readPot();
};

#endif
