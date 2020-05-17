#define LED_B 3
#define LED_G 5
#define LED_R 6

void setup() {
  pinMode(LED_R,OUTPUT);  
  pinMode(LED_G,OUTPUT);  
  pinMode(LED_B,OUTPUT);    
}

void loop() {
  digitalWrite(LED_R,LOW);    // red
  delay(1000);                // wait for a second
  digitalWrite(LED_R,HIGH);   // turn the LED off
  digitalWrite(LED_G,LOW);    //green
  delay(1000);
  digitalWrite(LED_G,HIGH);  
  digitalWrite(LED_B,LOW);  
  delay(1000); 
  digitalWrite(LED_R,LOW);    //white
  digitalWrite(LED_G,LOW);
  delay(1000);                       
  digitalWrite(LED_R,HIGH);    //off
  digitalWrite(LED_G,HIGH);     
  digitalWrite(LED_B,HIGH);           
}
