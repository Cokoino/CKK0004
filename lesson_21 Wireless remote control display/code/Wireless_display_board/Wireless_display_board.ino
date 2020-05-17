#include <IRremote.h>
int RECV_PIN = A5;
IRrecv irrecv(RECV_PIN);
decode_results results;
int leds[8] = {6, 11, 2, 9, 14, 3, 15, 5};  //Lattice screen the anode pin
int gnds[8] = {10, 16, 17, 7, 4, 8, 12, 13}; //Lattice screen negative pins
int Display_data[8][8]={
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  { 0, 0, 0, 0, 0, 0, 0, 0 },
                  };
////////////////////////////////////////////////
void Clean(void){
  for(int a=0;a<8;a++){
    for(int b=0;b<8;b++)
      Display_data[a][b]=0;
  }
}
////////////////////////////////////////////////
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
////////////////////////////////////////////////
void face1(void){
  Clean();
  Display_data[0][1]=1;Display_data[0][6]=1;
  Display_data[1][0]=1;Display_data[1][2]=1;
  Display_data[1][7]=1;Display_data[1][5]=1;
  Display_data[2][0]=1;Display_data[2][2]=1;
  Display_data[2][7]=1;Display_data[2][5]=1;
  Display_data[5][1]=1;Display_data[5][6]=1;
  Display_data[6][2]=1;Display_data[6][5]=1;
  Display_data[7][3]=1;Display_data[7][4]=1;
}
////////////////////////////////////////////////
void face2(void){
  Clean();
  face1();
  Display_data[3][1]=1;
  Display_data[3][6]=1;
}
////////////////////////////////////////////////
void face3(void){
  Clean();
  face1();
  face2();
  Display_data[0][1]=0;
  Display_data[0][6]=0;
}
////////////////////////////////////////////////
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  for (int i = 0; i < 8; i++){
    pinMode(leds[i], OUTPUT);
    pinMode(gnds[i], OUTPUT);
    digitalWrite(gnds[i], HIGH); //The cathode pin up, put out all the LED
  }
  Clean();  //All closed
}
////////////////////////////////////////////////
void loop() {
  if (irrecv.decode(&results)) {
    switch(results.value){
      case 0xffa25d : face1();break;
      case 0xff629d : face2();break;
      case 0xffe21d : face3();break;
      case 0xff38c7 : Clean();break;
      default : break;
    }
    Serial.println(results.value,HEX);
    irrecv.resume(); // Receive the next value
  }
  Display();
}
