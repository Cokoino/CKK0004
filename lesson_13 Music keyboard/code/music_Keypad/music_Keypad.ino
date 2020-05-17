#include <Keypad.h>
#define buzzer 11
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
void setup(){
  Serial.begin(9600);
} 
void loop(){
  char customKey = customKeypad.getKey(); 
  if (customKey){
    switch(customKey){
      case '0':setPwmFrequency(11, 8);analogWrite(buzzer,10);break;
      case '1':setPwmFrequency(11, 8);analogWrite(buzzer,20);break;
      case '2':setPwmFrequency(11, 8);analogWrite(buzzer,30);break;
      case '3':setPwmFrequency(11, 32);analogWrite(buzzer,40);break;
      case '4':setPwmFrequency(11, 32);analogWrite(buzzer,50);break;
      case '5':setPwmFrequency(11, 32);analogWrite(buzzer,60);break;
      case '6':setPwmFrequency(11, 64);analogWrite(buzzer,70);break;
      case '7':setPwmFrequency(11, 64);analogWrite(buzzer,80);break;
      case '8':setPwmFrequency(11, 64);analogWrite(buzzer,90);break;
      case '9':setPwmFrequency(11, 128);analogWrite(buzzer,100);break;
      case 'A':setPwmFrequency(11, 128);analogWrite(buzzer,110);break;
      case 'B':setPwmFrequency(11, 128);analogWrite(buzzer,120);break;
      case 'C':setPwmFrequency(11, 256);analogWrite(buzzer,130);break;
      case 'D':setPwmFrequency(11, 256);analogWrite(buzzer,140);break;
      case '#':setPwmFrequency(11, 256);analogWrite(buzzer,150);break;
      case '*':setPwmFrequency(11, 1024);analogWrite(buzzer,160);break;
      default : break;
    }
    delay(500);
    analogWrite(buzzer,0);
    Serial.println(customKey);
  }
}

/* 
* Set pin 9's PWM frequency to 3906 Hz (31250/8 = 3906)
* Note that the base frequency for pins 3, 9, 10, and 11 is 31250 Hz
*setPwmFrequency(9, 8);

* Set pin 6's PWM frequency to 62500 Hz (62500/1 = 62500)
* Note that the base frequency for pins 5 and 6 is 62500 Hz
*setPwmFrequency(6, 1);
*
* Divides a given PWM pin frequency by a divisor.
* 
* The resulting frequency is equal to the base frequency divided by
* the given divisor:
*   - Base frequencies:
*      o The base frequency for pins 3, 9, 10, and 11 is 31250 Hz.
*      o The base frequency for pins 5 and 6 is 62500 Hz.
*   - Divisors:
*      o The divisors available on pins 5, 6, 9 and 10 are: 1, 8, 64,
*        256, and 1024.
*      o The divisors available on pins 3 and 11 are: 1, 8, 32, 64,
*        128, 256, and 1024.
* 
* PWM frequencies are tied together in pairs of pins. If one in a
* pair is changed, the other is also changed to match:
*   - Pins 5 and 6 are paired on timer0
*   - Pins 9 and 10 are paired on timer1
*   - Pins 3 and 11 are paired on timer2
* 
* Note that this function will have side effects on anything else
* that uses timers:
*   - Changes on pins 3, 5, 6, or 11 may cause the delay() and
*     millis() functions to stop working. Other timing-related
*     functions may also be affected.
*   - Changes on pins 9 or 10 will cause the Servo library to function
*     incorrectly.
* 
* Thanks to macegr of the Arduino forums for his documentation of the
* PWM frequency divisors. His post can be viewed at:
*   http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1235060559/0#4
*/
void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
