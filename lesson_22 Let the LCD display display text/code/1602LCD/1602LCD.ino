#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//////////////////////////////////////////////////
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(1, 0);
  lcd.print("hello, world!");
  lcd.setCursor(1, 1);
  lcd.print("cokoino!");
}
//////////////////////////////////////////////////
void loop() {
  // Turn off the display:
  lcd.noDisplay();
  delay(1000);
  // Turn on the display:
  lcd.display();
  delay(1000);
}
