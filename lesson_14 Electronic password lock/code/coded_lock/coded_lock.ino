#include <Keypad.h>
#define buzzer 11
#define led 10
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
char passWord[7]="123456";
char temp_password[7]="      ";
int count=0;
void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  setPwmFrequency(11, 8);
} 
void loop(){
  char customKey = customKeypad.getKey(); 
  if (customKey){
    analogWrite(buzzer,30);
    if(count<=5 && customKey!='#' && customKey!='*')
      temp_password[count]=customKey;
    count++;
    if(count>=100)
       count=100;
    delay(100);
    analogWrite(buzzer,0);
    Serial.println(customKey);
  }
  if(customKey=='#'){    //confirm password
    int a=0;
    for(int b=0;b<6;b++){
      if(temp_password[b]==passWord[b])
        a=a+1;
    }
  if(a==6)
    digitalWrite(led,HIGH);
  count=0;
  }
  if(customKey=='*'){   //reset password
    for(int c=0;c<6;c++){
      temp_password[c]=' ';
    }
    count=0;
    digitalWrite(led,LOW);
  }
}

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
