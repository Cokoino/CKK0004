#include <MyServo.h>
MyServo Servo1;
void setup(){
  Serial.begin(9600);
  Servo1.Attach(A0);
}
/////////////////////////////////////
void loop(){
  int i=0;
  for(i=0;i<180;i++){
    Servo1.Write(i);
    }
}
