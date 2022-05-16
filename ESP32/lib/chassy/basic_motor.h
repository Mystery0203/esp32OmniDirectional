#ifndef BASIC_MOTOR_H
#define BASIC_MOTOR_H

#include <Arduino.h>
#include <analogWrite.h>
class basic_motor
{
private:
    int Pin1;
    int Pin2;
   
public:
    static int minTreshold;
    basic_motor(int Pin1,int Pin2);
    void initPin();
    void runSpeed(int pwm);
    void stop();
    void revConnections();
    // ~basic_motor();
};

#endif