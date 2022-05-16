# esp32OmniDirectional
currently active repo on making a omnidirectional bot on esp32 potentially using rtos to achieve highly efficient motion 

# prerequisite

before using this repo first install ros_lib into it follow the steps from this link
http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup

next run rosrun rosserial_arduino makeLibrary.py into lib folder
then go into ros.h replace 

"#if defined(ESP8266) or defined(ESP32) or defined(ROSSERIAL_ARDUINO_TCP)"

to

"#if defined(ROSSERIAL_ARDUINO_TCP)"
