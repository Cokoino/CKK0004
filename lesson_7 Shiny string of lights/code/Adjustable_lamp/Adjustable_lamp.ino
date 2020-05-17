#define LED_R 3
#define LED_G 5
#define LED_B 6
#define LED_W 9
int PWM_data=0;
void setup() {
  pinMode(LED_R,OUTPUT);  
  pinMode(LED_G,OUTPUT);  
  pinMode(LED_B,OUTPUT);  
  pinMode(LED_W,OUTPUT); 
  pinMode(A0,INPUT);
}
void loop() {
  PWM_data = analogRead(A0);           //read analog value of the potentiometer.
  PWM_data=map(PWM_data,0,1023,0,255); //map values from 0 to 1023 to 0 to 255.
  analogWrite(3,PWM_data);             //out put analog value.
  analogWrite(5,PWM_data);
  analogWrite(6,PWM_data);
  analogWrite(9,PWM_data);
}
