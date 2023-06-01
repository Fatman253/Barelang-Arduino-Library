#include "barelangSensor.h"

Button::Button()
{
}

Button::Button(uint8_t buttonPin)
{
    this->buttonPin = buttonPin;
    pinMode(buttonPin, INPUT);
}

void Button::setPin(uint8_t buttonPin)
{
    this->buttonPin = buttonPin;
    pinMode(buttonPin, INPUT);
}

void Button::setPin(uint8_t buttonPin, uint8_t mode)
{
    this->buttonPin = buttonPin;
    pinMode(buttonPin, mode);
}

bool Button::Rising()
{
    bool buttonVal = readButton();
    if (buttonVal != PrevVal)
    {
        PrevVal = buttonVal;
        if (buttonVal)
            return true;
    }
    return false;
}

bool Button::readButton()
{
    return digitalRead(buttonPin);
}

ButtonPU::ButtonPU()
{
}

ButtonPU::ButtonPU(uint8_t buttonPin)
{
    this->buttonPin = buttonPin;
    pinMode(buttonPin, INPUT_PULLUP);
}

void ButtonPU::setPin(uint8_t buttonPin)
{
    this->buttonPin = buttonPin;
    pinMode(buttonPin, INPUT_PULLUP);
}

bool ButtonPU::Rising()
{
    bool buttonVal = readButton();
    if (buttonVal != PrevVal)
    {
        PrevVal = buttonVal;
        if (buttonVal)
            return true;
    }
    return false;
}

bool ButtonPU::readButton()
{
    return !digitalRead(buttonPin);
}

Potentiometer::Potentiometer() {}

Potentiometer::Potentiometer(uint8_t pot_pin)
{
    this->pot_pin = pot_pin;
}

void Potentiometer::setPin(uint8_t pot_pin){
    this->pot_pin = pot_pin;
}
int Potentiometer::readPot()
{
    return analogRead(pot_pin);
}