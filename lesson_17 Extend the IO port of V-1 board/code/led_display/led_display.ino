int clockPin = 8;  //SH_CP 
int latchPin = 9;  //ST_CP
int dataPin = 10;  //DS 
int leds[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};      
////////////////////////////////////////////////////////////
void led_clear(void){                    
 digitalWrite(latchPin,LOW);                         
 shiftOut(dataPin, clockPin, MSBFIRST ,0xff);
 digitalWrite(latchPin,HIGH); 
}
////////////////////////////////////////////////////////////
void led_display(void){
  for(int i=0;i<8;i++)
     {
     digitalWrite(latchPin,LOW);   
     shiftOut(dataPin, clockPin, MSBFIRST ,leds[i]);   
     digitalWrite(latchPin,HIGH);
     delay(500);
     }
}
////////////////////////////////////////////////////////////
void setup (){
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); 
  led_clear();
}
////////////////////////////////////////////////////////////  
void loop(){
  led_display();                   
}

