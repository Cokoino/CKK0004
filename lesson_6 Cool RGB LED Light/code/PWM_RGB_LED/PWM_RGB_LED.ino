#define LED_B 3
#define LED_G 5
#define LED_R 6

int PWM_data;
void setup() {
  pinMode(LED_R,OUTPUT);  
  pinMode(LED_G,OUTPUT);  
  pinMode(LED_B,OUTPUT);    
}
void loop() {
for(PWM_data=255;PWM_data>=0;PWM_data--){
  analogWrite(LED_R,PWM_data);  // PWM
  analogWrite(LED_G,0);  
  analogWrite(LED_B,0);  
  delay(10);  
  }  
for(PWM_data=255;PWM_data>=0;PWM_data--){
  analogWrite(LED_R,0); 
  analogWrite(LED_G,PWM_data);  
  analogWrite(LED_B,0);   
  delay(10); 
  }  
for(PWM_data=255;PWM_data>=0;PWM_data--){
  analogWrite(LED_R,0); 
  analogWrite(LED_G,0);  
  analogWrite(LED_B,PWM_data);   
  delay(10); 
  }       
}
