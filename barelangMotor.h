#ifndef ARDUINO_MOTOR_BARELANG63_HEADER
#define ARDUINO_MOTOR_BARELANG63_HEADER

#include "Arduino.h"
#include "barelangPID.h"
/////////////////////////// Class Motor ///////////////////////////////////////
class Motor
{
private:
    uint8_t pinA, pinB;

public:
    Motor();

    Motor(uint8_t pinA, uint8_t pinB);

    void initMotor(uint8_t pinA, uint8_t pinB);

    void Run(int pwm, bool dir);

    void Run(int pwm);
};

////////////////////////// Class Encoder ////////////////////////////////////

class Encoder
{
private:
    uint8_t encA, encB;

    volatile bool encAVal = 0, encBVal = 0;

    volatile int counter = 0;

public:
    Encoder();

    Encoder(uint8_t encA, uint8_t encB, void (*userFunc)(void));

    Encoder(uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode);

    void initEncoder(uint8_t encA, uint8_t encB, void (*userFunc)(void));

    void initEncoder(uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode);

    void readPin();

    void readPulse();

    void readPulseReverse();

    int getCounter();

    void setCounter(int newCounter);

    void resetCounter();
};

///////////////////////////// Class Motor Encoder //////////////////////////////

class MotorEnc : public Motor, public Encoder
{
public:
    MotorEnc();

    MotorEnc(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void));

    MotorEnc(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode);

    void init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode);

    void init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void));
};

//////////////////////// Class Motor Position PID //////////////////////////////

class MotorPos : public Motor, public Encoder, private PID
{
    int target;
    int pos;
    int maxSpeed = 255;

public:
    MotorPos();

    MotorPos(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void));

    MotorPos(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode);

    void init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void));

    void init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int mode);

    void setK(float Kp, float Ki);

    void goTo(int target);

    void setPos(int pos_change);

    void setMax(int maxSpeed);
};

// ///////////////////////////// Class Motor PID //////////////////////////////////

class MotorSpeed : public Motor, public Encoder, private PID
{
private:
    int ppr = 7;
    float Vraw;
    float Vfilt = 0, Vraw_prev = 0;
    float Vtarget = 0;

    unsigned long tick;
    // float errorPrev, Vraw_prev;
    // float eIntegral = 0;
    // float PIDVal;

public:
    MotorSpeed();

    MotorSpeed(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void));

    MotorSpeed(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int ppr);

    void init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void));

    void init(uint8_t pinA, uint8_t pinB, uint8_t encA, uint8_t encB, void (*userFunc)(void), int ppr);

    void setppr(int ppr);

    void setK(float Kp, float Ki);

    void CalcVelocity();

    void CalcVelocity(float dTime);

    void RunPID();

    void RunPID(float dTime);

    void setSpeed(int Vtarget);
};
#endif
