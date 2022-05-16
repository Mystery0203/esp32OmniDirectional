#ifndef CHASSY_H
#define CHASSY_H
#include <Arduino.h>
#include "basic_motor.h"
#include <math.h>



class chassy{
    basic_motor TLMotor,BLMotor,TRMotor,BRMotor;
    public:
    chassy(int TLpins[],int BLpins[],int TRpins[],int BRpins[]):TLMotor(TLpins[0],TLpins[1]),BLMotor(BLpins[0],BLpins[1]),TRMotor(TRpins[0],TRpins[1]),BRMotor(BRpins[0],BRpins[1]){};
    void Move(int v,int w);
    void Stop();

};
#endif