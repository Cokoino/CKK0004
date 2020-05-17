#include <MsTimer2.h>
int clockPin = 8;  //SH_CP 
int latchPin = 9;  //ST_CP
int dataPin = 10;  //DS 
int bit1 = 4;
int bit2 = 5;
int bit3 = 6;
int bit4 = 7;
int key1 = 2;
int key2 = 3;
int count = 0;
int newtime=0;
int oldtime=0;
int dat_bit[4]={0x08,0x04,0x02,0x01}; 
int dat[10]={0x05,0x7d,0x46,0x54,0x3c,0x94,0x84,0x5d,0x04,0x14}; 
/*********************bit*****************
                  -- -- --
               6 |    5   | 7
                 |    0   |
                  -- -- --
               4 |        | 1
                 |    3   |
                  -- -- --  。 2
 ******************************************/
////////////////////////////////////////////////////////////
void digital_clear(void){                    //清数码管
 digitalWrite(latchPin,LOW);                         
 shiftOut(dataPin, clockPin, MSBFIRST ,0xff);
 shiftOut(dataPin, clockPin, MSBFIRST ,0x00);
 digitalWrite(latchPin,HIGH); 
}
////////////////////////////////////////////////////////////
void shift_bit(int D,int B){
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST ,dat[D]);
  shiftOut(dataPin, clockPin, MSBFIRST ,dat_bit[B]);
  digitalWrite(latchPin,HIGH);
}
////////////////////////////////////////////////////////////
void digital_display(void){
  digitalWrite(bit1,HIGH);
  shift_bit(count%10,0);
  delay(3); 
  digital_clear();
  digitalWrite(bit1,LOW);
  
  digitalWrite(bit2,HIGH);
  shift_bit(count%100/10,1);
  delay(3); 
  digital_clear();
  digitalWrite(bit2,LOW);
  
  digitalWrite(bit3,HIGH);
  shift_bit(count%1000/100,2);
  delay(3);
  digital_clear();
  digitalWrite(bit3,LOW);
   
  digitalWrite(bit4,HIGH);
  shift_bit(count/1000,3);
  delay(3);
  digital_clear();
  digitalWrite(bit4,LOW); 
}
////////////////////////////////////////////////////////////
void count1(void){
 newtime=millis();
 if(newtime-oldtime>100)
    count++; 
 oldtime=newtime;
 if(count>=9999)
    count=9999;
}
////////////////////////////////////////////////////////////
void count2(void){
 newtime=millis();
 if(newtime-oldtime>100)
    count--; 
 oldtime=newtime;
 if(count<=0)
    count=0;
}
////////////////////////////////////////////////////////////
void setup (){
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); 
  pinMode(bit1,OUTPUT);
  pinMode(bit2,OUTPUT);
  pinMode(bit3,OUTPUT);
  pinMode(bit4,OUTPUT);
  pinMode(key1,INPUT);    
  pinMode(key2,INPUT);   
  MsTimer2::set(10, digital_display);
  MsTimer2::start(); 
  attachInterrupt(0, count1, CHANGE);
  attachInterrupt(1, count2, CHANGE);
  oldtime=millis();
}
////////////////////////////////////////////////////////////  
void loop(){
}

