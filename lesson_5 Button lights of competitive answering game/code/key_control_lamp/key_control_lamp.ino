boolean key_1=false,key_2=false,key_3=false,key_4=false;
void setup() {
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  if(digitalRead(4)==LOW){    //detect if the key is pressed.
    delay(10);                //delay 10ms
    if(digitalRead(4)==LOW){  //detect again if the key is pressed.
      key_1 = !key_1;          //record the mark if the key is pressed.
      while(digitalRead(4)==LOW);  //wait for the button is released.
      }
    }
  if(digitalRead(5)==LOW){
    delay(10);
    if(digitalRead(5)==LOW){
      key_2 = !key_2;
      while(digitalRead(5)==LOW);
      }   
    }
  if(digitalRead(6)==LOW){
    delay(10);
    if(digitalRead(6)==LOW){
      key_3 = !key_3;
      while(digitalRead(6)==LOW);
      }  
    }
  if(digitalRead(7)==LOW){
    delay(10);
    if(digitalRead(7)==LOW){
      key_4 = !key_4;
      while(digitalRead(7)==LOW);
      }  
    }
  if(key_1==true) {digitalWrite(8,HIGH);}
  else            {digitalWrite(8,LOW);}
  if(key_2==true) {digitalWrite(9,HIGH);}
  else            {digitalWrite(9,LOW);}
  if(key_3==true) {digitalWrite(10,HIGH);}
  else            {digitalWrite(10,LOW);}
  if(key_4==true) {digitalWrite(11,HIGH);}
  else            {digitalWrite(11,LOW);}
}
