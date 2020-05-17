#define LED_R 3
#define LED_G 5
#define LED_B 6
#define LED_W 9

void setup() {
  pinMode(LED_R,OUTPUT);  
  pinMode(LED_G,OUTPUT);  
  pinMode(LED_B,OUTPUT);  
  pinMode(LED_W,OUTPUT);  
}

void loop() {
  digitalWrite(LED_R,HIGH);  // turn the LED on
  delay(500);                // wait for a second
  digitalWrite(LED_G,HIGH);  
  delay(500);
  digitalWrite(LED_B,HIGH);  
  delay(500);
  digitalWrite(LED_W,HIGH);  
  delay(500);                        
  digitalWrite(LED_R,LOW);     // turn the LED off
  delay(500); 
  digitalWrite(LED_G,LOW);   
  delay(500);    
  digitalWrite(LED_B,LOW);   
  delay(500);  
  digitalWrite(LED_W,LOW);   
  delay(500);          
}
