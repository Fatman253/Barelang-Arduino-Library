#include "barelangMotor.h"
// ############################### Motor Classes ############################################

Motor::Motor()
{
}

void Motor::initMotor(uint8_t pinA, uint8_t pinB)
{
    this->pinA = pinA;
    this->pinB = pinB;

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
}
Motor::Motor(uint8_t pinA, uint8_t pinB)
{
    this->pinA = pinA;
    this->pinB = pinB;

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
}

inline void Motor::Run(int pwm, bool dir)
{
    if (dir == true)
    {
        analogWrite(pinA, pwm);
        digitalWrite(pinB, 0);
    }
    else
    {
        analogWrite(pinB, pwm);
        digitalWrite(pinA, 0);
    }
}

inline void Motor::Run(int pwm)
{
    if (pwm >= 0)
    {
        analogWrite(pinA, pwm);
        digitalWrite(pinB, 0);
    }
    else
    {
        analogWrite(pinB, -pwm);
        digitalWrite(pinA, 0);
    }
}

////////////////////////////////// Motor Class End ////////////////////////////////////////////

////////////////////////////////// Encoder Class   ////////////////////////////////////////////
Encoder::Encoder()
{
}

Encoder::Encoder(uint8_t encA, uint8_t encB, void (*userFunc)(void))
    : encA(encA), encB(encB)
{
    pinMode(encA, INPUT);
    pinMode(encB, INPUT);

    attachInterrupt(digitalPinToInterrupt(encA), userFunc, RISING);
}

Encoder::Encoder(uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode)
    : encA(encA), encB(encB)
{
    pinMode(encA, INPUT);
    pinMode(encB, INPUT);

    attachInterrupt(digitalPinToInterrupt(encA), userFunc, mode);
}

void Encoder::initEncoder(uint8_t encA, uint8_t encB, void (*userFunc)(void))
{
    this->encB = encB;
    this->encA = encA;
    pinMode(encA, INPUT);
    pinMode(encB, INPUT);

    attachInterrupt(digitalPinToInterrupt(encA), userFunc, RISING);
}

void Encoder::initEncoder(uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode)
{
    this->encB = encB;
    this->encA = encA;

    pinMode(encA, INPUT);
    pinMode(encB, INPUT);

    attachInterrupt(digitalPinToInterrupt(encA), userFunc, mode);
}

void Encoder::readPin()
{
    encAVal = digitalRead(encA);
    encBVal = digitalRead(encB);
}

void Encoder::readPulse()
{
    readPin();
    if (encAVal != encBVal)
        counter++;
    else
        counter--;
}

void Encoder::readPulseReverse()
{
    readPin();
    if (encAVal == encBVal)
        counter++;
    else
        counter--;
}

int Encoder::getCounter()
{
    return counter;
}

void Encoder::setCounter(int newCounter)
{
    counter = newCounter;
}

void Encoder::resetCounter()
{
    counter = 0;
}

/////////////////////////////  Encoder Class End //////////////////////////////////////////

////////////////////////////  Motor Encoder Class /////////////////////////////////////////

MotorEnc::MotorEnc()
{
}

MotorEnc::MotorEnc(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void))
    : Motor(pinA, pinB), Encoder(encA, encB, userFunc)
{
}

MotorEnc::MotorEnc(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode)
    : Motor(pinA, pinB), Encoder(encA, encB, userFunc, mode)
{
}

void MotorEnc::init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void))
{
    initMotor(pinA, pinB);
    initEncoder(encA, encB, userFunc);
}

void MotorEnc::init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode)
{
    initMotor(pinA, pinB);
    initEncoder(encA, encB, userFunc, mode);
}

// //////////////////////////// Motor Encoder Class End /////////////////////////////////////////

MotorPos::MotorPos()
{
}

MotorPos::MotorPos(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void))
    : Motor(pinA, pinB), Encoder(encA, encB, userFunc)
{
}
MotorPos::MotorPos(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode)
    : Motor(pinA, pinB), Encoder(encA, encB, userFunc, mode)
{
}

void MotorPos::init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void))
{
    initMotor(pinA, pinB);
    initEncoder(encA, encB, userFunc);
}

void MotorPos::init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode)
{
    initMotor(pinA, pinB);
    initEncoder(encA, encB, userFunc, mode);
}

void MotorPos::setK(float Kp, float Ki){
    setKPID(Kp, Ki, 0);
}

void MotorPos::goTo(int target)
{
    pos = getCounter();
    float value = calculateP(pos, target);
    value = constrain(value, -maxSpeed, maxSpeed);
    if (abs(value) < 5)
        value = 0;
    Run(value);
}

void MotorPos::setPos(int pos_change)
{
    setCounter(pos_change);
}

void MotorPos::setMax(int maxSpeed)
{
    this->maxSpeed = maxSpeed;
}

MotorSpeed::MotorSpeed()
{
}

MotorSpeed::MotorSpeed(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void))
    : Motor(pinA, pinB), Encoder(encA, encB, userFunc)
{
}
MotorSpeed::MotorSpeed(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int ppr)
    : Motor(pinA, pinB), Encoder(encA, encB, userFunc)
{
    this->ppr = ppr;
}

void MotorSpeed::init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void))
{
    initMotor(pinA, pinB);
    initEncoder(encA, encB, userFunc);
}

void MotorSpeed::init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int ppr)
{
    initMotor(pinA, pinB);
    initEncoder(encA, encB, userFunc);
    this->ppr = ppr;
}

void MotorSpeed::setppr(int ppr){
    this->ppr = ppr;
}

void MotorSpeed::setK(float Kp, float Ki)
{
    setKPID(Kp, Ki, 0);
}

void MotorSpeed::CalcVelocity()
{
    float dTime = micros() - tick;
    dTime = (float)dTime / 1000000.0;

    const int pulse = getCounter();
    resetCounter();

    tick = micros();

    Vraw = pulse * 60 / ppr / dTime;

    Vfilt = (0.854 * Vfilt) + (0.0728 * Vraw) + (0.0728 * Vraw_prev);
    Vraw_prev = Vraw;
}

void MotorSpeed::CalcVelocity(float dTime)
{
    const int pulse = getCounter();
    resetCounter();

    Vraw = pulse * 60 / ppr / dTime;

    Vfilt = (0.854 * Vfilt) + (0.0728 * Vraw) + (0.0728 * Vraw_prev);
    Vraw_prev = Vraw;
}

void MotorSpeed::RunPID(float dTime)
{
    CalcVelocity(dTime);

    float hasil = calculatePI(Vfilt, Vtarget, dTime);

    hasil = constrain(hasil, -255, 255);

    Run(hasil);
}

void MotorSpeed::RunPID(){
    float dTime = micros() - tick;
    dTime = (float)dTime / 1000000.0;
    tick = micros();
    CalcVelocity(dTime);

    float hasil = calculatePI(Vfilt, Vtarget, dTime);

    if(Vtarget * hasil > 0)
    hasil = constrain(hasil, -255, 255);
    else hasil = 0;

    Run(hasil);
}

void MotorSpeed::setSpeed(int Vtarget){
    this->Vtarget = Vtarget;
}