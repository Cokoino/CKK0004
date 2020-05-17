#include <LiquidCrystal.h>
#include <IRremote.h>
#include <DHT10.h>
#include <SPI.h>
#include <SD.h>  //MOSI - pin 11,MISO - pin 12,CLK - pin 13,CS - pin 10
File myFile;                            //used in sd card
DHT10 DHT;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  //lcd(rs, en, d4, d5, d6, d7)
const int ph=A0;
const int gas=A1;
const int buzzer=A2;
const int led=A3;
int RECV_PIN=8;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long oldtime=0;
int number=0;
/////////////////////////////////////////////////////
void book(void){
  number++;
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("book.txt", FILE_WRITE); 
  myFile.print(number); 
  myFile.print("     ");   
  myFile.print(DHT.temperature); 
  myFile.print("     ");   
  myFile.print(DHT.humidity); 
  myFile.print("     ");
  myFile.print(analogRead(ph)); 
  myFile.print("     ");
  myFile.println(analogRead(gas)); 
  myFile.close();   // close the file:
}
/////////////////////////////////////////////////////
void setup() { 
  Wire.begin();
  irrecv.enableIRIn();             // Start the receiver
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  lcd.begin(16, 2);                // set up the LCD's number of columns and rows:
  lcd.print("System init...  ");   // Print a message to the LCD.
  delay(500);
  if (!SD.begin(10)) {             //Set the pin of SD card CS to 10
    lcd.setCursor(0, 0);
    lcd.print("SD card error!  "); 
    while(1);
  }
  myFile = SD.open("book.txt", FILE_WRITE);
  if (myFile) {
    myFile.println("number:     temperature:     humidity:     light:    gas:");
    myFile.close();
  } 
  else {
    lcd.setCursor(0, 0);
    lcd.print("book error!     "); 
    while(1);
  }
  int status = DHT.read();
  if (status != DHT10_OK){
    lcd.setCursor(0, 0);
    lcd.print("dht10 error!    ");
    while(1);
  }
  lcd.setCursor(0, 0);
  lcd.print("succeed         "); 
  delay(500);
}
/////////////////////////////////////////////////////
void loop() {
  int status = DHT.read();
  lcd.setCursor(0, 0);
  lcd.print("T:"); 
  lcd.print(DHT.temperature); 
  lcd.print("  ");
  lcd.setCursor(9, 0);
  lcd.print("H:"); 
  lcd.print(DHT.humidity);
  lcd.setCursor(0, 1);
  lcd.print("L:"); 
  lcd.print(analogRead(ph)+0.0); 
  lcd.print("  ");
  lcd.setCursor(9, 1);
  lcd.print("G:"); 
  lcd.print(analogRead(gas)+0.00);  
/***********************************************************/
  if((analogRead(gas)<=250)||(analogRead(ph)>=900)){
    digitalWrite(buzzer,HIGH);
  }
  if((analogRead(gas)>=280)&&(analogRead(ph)<=850)){
    digitalWrite(buzzer,LOW);
  }
/***********************************************************/
  if((millis()-oldtime)>=60000){
    oldtime=millis();  //Acquisition system running time(milliseconds)
    book();            //Record once per minute
  }
/***********************************************************/
  if (irrecv.decode(&results)) {
    if(results.value==0xff6897)   //*
      digitalWrite(led,HIGH);
    if(results.value==0xffb04f)   //#
      digitalWrite(led,LOW);
    irrecv.resume(); // Receive the next value
    delay(100);
  }  
}

