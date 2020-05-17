#define LED_R 3
#define LED_G 5
#define LED_B 6
#define LED_W 9
int PWM_data;
void setup() {
  pinMode(LED_R,OUTPUT);  
  pinMode(LED_G,OUTPUT);  
  pinMode(LED_B,OUTPUT);  
  pinMode(LED_W,OUTPUT);  
}
void loop() {
for(PWM_data=0;PWM_data<=255;PWM_data++){
  analogWrite(LED_R,PWM_data);  // PWM
  analogWrite(LED_G,PWM_data);  
  analogWrite(LED_B,PWM_data);  
  analogWrite(LED_W,PWM_data);
  delay(10);  
  }  
for(PWM_data=255;PWM_data>=0;PWM_data--){
  analogWrite(LED_R,PWM_data); 
  analogWrite(LED_G,PWM_data);  
  analogWrite(LED_B,PWM_data);  
  analogWrite(LED_W,PWM_data);  
  delay(10); 
  }        
}
