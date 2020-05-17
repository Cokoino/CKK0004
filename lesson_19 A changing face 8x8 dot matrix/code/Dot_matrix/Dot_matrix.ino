int leds[8] = {6, 11, 2, 9, 14, 3, 15, 5};  //Lattice screen the anode pin
int gnds[8] = {10, 16, 17, 7, 4, 8, 12, 13}; //Lattice screen negative pins
int Display_data[8][8]={
                  { 0, 1, 0, 0, 0, 0, 1, 0 },
                  { 1, 0, 1, 0, 0, 1, 0, 1 },
                  { 1, 0, 1, 0, 0, 1, 0, 1 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 1, 0, 0, 0, 0, 1, 0 },
                  { 0, 0, 1, 0, 0, 1, 0, 0 },
                  { 0, 0, 0, 1, 1, 0, 0, 0 },
                  }; 
///////////////////////////////////// 
void ledopen(){
  for (int i = 0; i < 8; i++){     //Higher dot matrix screen to the anode,  
    digitalWrite(leds[i], HIGH);   //cathode down,open display
    digitalWrite(gnds[i], LOW);
  }
}
///////////////////////////////////// 
void ledclean(){
  for (int i = 0; i < 8; i++){     //The positive ladies will lattice screen,
    digitalWrite(leds[i], LOW);    // negative up, turn off display
    digitalWrite(gnds[i], HIGH);
  }
}
/////////////////////////////////////
void Display(void){
  for(int a=0;a<8;a++){
    for(int b=0;b<8;b++){
      if(Display_data[a][b]==1){
        digitalWrite(gnds[a],LOW);
        digitalWrite(leds[b],HIGH);
        delayMicroseconds(50);
        digitalWrite(gnds[a],HIGH);
        digitalWrite(leds[b],LOW);
      }
    }
  }
}
/////////////////////////////////////
void setup() {
  for (int i = 0; i < 8; i++){
    pinMode(leds[i], OUTPUT);
    pinMode(gnds[i], OUTPUT);
    digitalWrite(gnds[i], HIGH); //The cathode pin up, put out all the LED
  }
  ledopen();   //All open
  delay(500);
  ledclean();  //All closed
  delay(500);
}
/////////////////////////////////////
void loop() {
 Display();
}

