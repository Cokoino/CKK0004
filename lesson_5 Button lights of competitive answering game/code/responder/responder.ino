boolean key_1=false,key_2=false,key_3=false,key_4=false;
void setup() {
  pinMode(3,INPUT);
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
   if(digitalRead(7)==LOW){
     delay(10);
     if(digitalRead(7)==LOW){
       key_1=false,key_2=false,key_3=false,key_4=false;
       while(digitalRead(7)==LOW);
       }  
     }
  if(key_1==false&&key_2==false&&key_3==false&&key_4==false){
    if(digitalRead(3)==LOW){
      delay(10);
      if(digitalRead(3)==LOW){
        key_1 = !key_1;
        }
      }
    if(digitalRead(4)==LOW){
      delay(10);
      if(digitalRead(4)==LOW){
        key_2 = !key_2;
        }   
      }
    if(digitalRead(5)==LOW){
      delay(10);
      if(digitalRead(5)==LOW){
        key_3 = !key_3;
        }  
      }
    if(digitalRead(6)==LOW){
      delay(10);
      if(digitalRead(6)==LOW){
        key_4 = !key_4;
        }  
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
