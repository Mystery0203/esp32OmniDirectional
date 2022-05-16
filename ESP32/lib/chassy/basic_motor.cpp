#include <Arduino.h>
#include <analogWrite.h>
#include <basic_motor.h>

basic_motor::basic_motor(int Pin1,int Pin2){
    this->Pin1 = Pin1;
    this->Pin2 = Pin2;
    pinMode(Pin1,OUTPUT);
    pinMode(Pin2,OUTPUT);
}
void basic_motor::initPin(){
    pinMode(Pin1,OUTPUT);
    pinMode(Pin2,OUTPUT);
}
void basic_motor::runSpeed(int pwm){
    if(pwm<256 && pwm>-256){
        if(pwm>minTreshold){
            analogWrite(Pin1,pwm);
            analogWrite(Pin2,0);
        }
        else if(pwm<-minTreshold){
            int r = -pwm;
            analogWrite(Pin1,0);
            analogWrite(Pin2,r);
        }
        else{
            analogWrite(Pin1,0);
            analogWrite(Pin2,0);
        }
    }
    
    else{
        if(pwm>minTreshold){
        analogWrite(Pin1,pwm);
        analogWrite(Pin2,0);
        }
    else if(pwm<-minTreshold){
        int r = -pwm;
        analogWrite(Pin1,0);
        analogWrite(Pin2,r);
        }
    else{
        analogWrite(Pin1,0);
        analogWrite(Pin2,0);
        }
    }
}
void basic_motor::stop(){
    analogWrite(Pin1,0);
    analogWrite(Pin2,0);
} 

void basic_motor::revConnections(){
    int temp = Pin1;
    Pin1 = Pin2;
    Pin2 = temp;
}