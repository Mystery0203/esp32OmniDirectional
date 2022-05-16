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
    // vTaskDelay(50/portTICK_RATE_MS);
    // square.Stop();
    // v = 0.0;
    // w = 0.0;
  // square.Move(100,0);
  // delay(5000);
  // square.Stop();
  // delay(1000);
  // square.Move(-100,0);
  // delay(5000);
  // square.Stop();
  // delay(1000);
  // square.Move(0,100);
  // delay(5000);
  // square.Stop();
  // delay(1000);
  // square.Move(100,60);
  // delay(5000);
  // square.Stop();
  // square.Move(100,-60);
  // delay(5000);
  // square.Stop();
  }
}

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  xTaskCreatePinnedToCore(chassyMove,"move chassy",10240,NULL,1,NULL,1);
}
void loop(){
  
}
