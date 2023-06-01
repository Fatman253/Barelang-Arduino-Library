#include "Arduino.h"
#include "barelangPID.h"

float PID::calculateP(float current, float target) {
  const float error = target - current;
  PIDVal = Kp * error;
  return PIDVal;
}

float PID::calculatePI(float current, float target, float dTime) {
  const float error = target - current;
  errorIntegral += (errorIntegral * dTime);
  errorIntegral = constrain(errorIntegral, -255 / Ki, 255 / Ki);
  PIDVal = (Kp * error) + (Ki * errorIntegral);
  errorPrev = error;
  return PIDVal;
}

float PID::calculatePD(float current, float target, float dTime) {
  const float error = target - current;
  const float errorD = (error - errorPrev) / dTime;

  PIDVal = (Kp * error) + (Kd * errorD);
  errorPrev = error;
  return PIDVal;
}

float PID::calculatePID(float current, float target, float dTime) {
  const float error = target - current;
  const float errorD = (error - errorPrev) / dTime;
  errorIntegral += (errorIntegral * dTime);
  errorIntegral = constrain(errorIntegral, -255 / Ki, 255 / Ki);
  PIDVal = (Kp * error) + (Ki * errorIntegral) + (Kd * errorD);
  errorPrev = error;
  return PIDVal;
}
