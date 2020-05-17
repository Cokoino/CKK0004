#include <DHT10.h>
#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DHT10 DHT;
//////////////////////////////////////////////////////////
void setup(){
  Wire.begin();
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("hello cokoino!");
  delay(1000);
  lcd.clear();
}
//////////////////////////////////////////////////////////
void loop(){
  int status = DHT.read();
  if(status == DHT10_OK){
    lcd.setCursor(1, 0);
    lcd.print("H:");
    lcd.print(DHT.humidity);
    lcd.print("   OK   ");
    lcd.setCursor(1, 1);
    lcd.print("T:");
    lcd.print(DHT.temperature);
  }
  delay(2000);  //recommend delay 2 second
}
