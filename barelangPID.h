#ifndef ARDUINO_PID_BARELANG63_HEADER
#define ARDUINO_PID_BARELANG63_HEADER

class PID {
private:
  float errorPrev, errorIntegral, PIDVal;
public:
  float Kp, Ki, Kd;
  PID()
    : Kp(1), Ki(0), Kd(0) {}
  PID(float Kp, float Ki, float Kd)
    : Kp(Kp), Ki(Ki), Kd(Kd) {}

  void setKPID(float Kp, float Ki, float Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
  }

  float errorCalc(float current, float target) {
    return target - current;
  }

  float calculateP(float current, float target);

  float calculatePI(float current, float target, float dTime);

  float calculatePD(float current, float target, float dTime);

  float calculatePID(float current, float target, float dTime);

  float getPIDVal() {
    return PIDVal;
  }
};

#endif 
