#define LED_R 3
#define LED_G 5
#define LED_B 6
#define LED_W 9
int PWM_data=0;
int ADJ_data=0;
void setup() {
  pinMode(LED_R,OUTPUT);  
  pinMode(LED_G,OUTPUT);  
  pinMode(LED_B,OUTPUT);  
  pinMode(LED_W,OUTPUT); 
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}
void loop() {
  ADJ_data = analogRead(A1);
  PWM_data = analogRead(A0);
  if(PWM_data>ADJ_data ){
    digitalWrite(3,HIGH);
    delay(200);
    digitalWrite(5,HIGH);
    delay(200);
    digitalWrite(6,HIGH);
    delay(200);
    digitalWrite(9,HIGH);
    delay(200);
    }
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
}
