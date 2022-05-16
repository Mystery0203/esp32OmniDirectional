#include <Arduino.h>
#include "chassy.h"
#include <math.h>

void chassy::Move(int v,int w){
    int tlspeed = v + w;
    int trspeed = v - w;
    int k =  255 - basic_motor::minTreshold;
    
    if(tlspeed>= k){
        int extra = tlspeed - k;
        trspeed -=extra;
    
    }
    if(tlspeed<=-k){
        int extra = tlspeed + k;
        trspeed +=extra;
        
    }
    if(trspeed>= k){
        int extra = trspeed - k;
        tlspeed -=extra;
        
    }
    if(trspeed<=-k){
        int extra = tlspeed + k;
        tlspeed +=extra;
    }


    if(tlspeed>2){
        tlspeed+=basic_motor::minTreshold;
    }
    if(tlspeed<-2){
        tlspeed-=basic_motor::minTreshold;
    }
    if(trspeed>2){
        trspeed+=basic_motor::minTreshold;
    }
    if(trspeed<-2){
        trspeed-=basic_motor::minTreshold;
    }


    TLMotor.runSpeed(tlspeed);
    BLMotor.runSpeed(tlspeed);
    TRMotor.runSpeed(trspeed);
    BRMotor.runSpeed(trspeed);
}
void chassy::Stop(){
    TLMotor.stop();
    BLMotor.stop();
    TRMotor.stop();
    BRMotor.stop();

}