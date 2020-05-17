#include "Arduino.h"        // for digitalWrite
#include "MyServo.h"

////////////////////////////////////////////
MyServo::MyServo(){
}
////////////////////////////////////////////
void MyServo::Write(int angle){
  if(angle>180) angle=180;
  if(angle<0) angle=0;
  for(char i=0;i<3;i++){
    digitalWrite(servo_pin,HIGH);
    delayUS(angle*11+500);
    digitalWrite(servo_pin,LOW);
    delayUS(24250-(angle*11+500));
    }
}
////////////////////////////////////////////
void MyServo::Attach(int pin){
  servo_pin=pin;
  pinMode(servo_pin,OUTPUT);
}
////////////////////////////////////////////
void MyServo::delayUS(int us){ 
  int t=0;
  for(;us>0;us--){
    for(;t<25;t++){
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
      asm("nop");
    }    
  } 
}
