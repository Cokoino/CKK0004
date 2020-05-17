#define LED_R 4
int PWM_data=0;
int ADJ_data=0;
void setup() {
  pinMode(LED_R,OUTPUT);  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}
void loop() {
  ADJ_data = analogRead(A1);
  PWM_data = analogRead(A0);
  if(PWM_data>ADJ_data ){
    digitalWrite(4,HIGH);
    delay(1000);
    }
  digitalWrite(4,LOW);
}
