#define AM312 2
#define buzzer 6
boolean somebody = false;
void setup() {  
  pinMode(buzzer,OUTPUT); 
  pinMode(AM312,INPUT);
}
void loop()   //main loop function
{
  if(digitalRead(AM312)==HIGH){
    digitalWrite(buzzer,HIGH);
    delay(500);
    }
  else{
    digitalWrite(buzzer,LOW);
    }
}

