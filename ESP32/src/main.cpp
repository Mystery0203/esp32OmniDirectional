/*
MIT License

Copyright (c) 2022 Mystery0203

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

directly contact:- rahulagnel@gmail.com
for any changes if to be made
*/

#include <Arduino.h>
#include <analogWrite.h>
#include <chassy.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;
float v;
float w;
void received(const geometry_msgs::Twist& cmd){
  v = cmd.linear.x;
  w = cmd.angular.z;
}

ros::Subscriber <geometry_msgs::Twist> sub("/cmd_vel",received);

int basic_motor::minTreshold = 40;

int motor1[] = {27,26};//top left
int motor2[] = {25,33};//top right
int motor3[] = {16,17};//bottom left
int motor4[] = {18,19};//bottom right

chassy square(motor1,motor3,motor2,motor4);
void chassyMove(void* PvParameters){
  while(1){
    nh.spinOnce();
    square.Move((int)v,(int)w);
    
  }
}

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  xTaskCreatePinnedToCore(chassyMove,"move chassy",10240,NULL,1,NULL,1);
}
void loop(){
  
}
