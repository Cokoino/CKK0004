#include <stdio.h>
#include <DS1302.h>
#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

namespace {
const int kCePin   = A5;  // Chip Enable
const int kIoPin   = A4;  // Input/Output
const int kSclkPin = A3;  // Serial Clock

  // Create a DS1302 object.
  DS1302 rtc(kCePin, kIoPin, kSclkPin);

  String dayAsString(const Time::Day day) {
    switch (day) {
      case Time::kSunday: return "Sunday";
      case Time::kMonday: return "Monday";
      case Time::kTuesday: return "Tuesday";
      case Time::kWednesday: return "Wednesday";
      case Time::kThursday: return "Thursday";
      case Time::kFriday: return "Friday";
      case Time::kSaturday: return "Saturday";
    }
  return "(unknown day)";
  }

  void printTime() {
  // Get the current time and date from the chip.
  Time t = rtc.time();

  // Name the day of the week.
  const String day = dayAsString(t.day);

  // Format the time and date and insert into the temporary buffer.
  char buf[50];
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           day.c_str(),
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);

  // Print the formatted string to LCD so we can see the time.
  lcd.setCursor(3, 0);
  lcd.print(t.yr);
  lcd.print("-");
  lcd.print(t.mon);
  lcd.print("-");
  lcd.print(t.date);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(3, 1);
  lcd.print(t.hr);
  lcd.print(":");
  lcd.print(t.min);
  lcd.print(":");
  lcd.print(t.sec);
  }
}  // end namespace

//////////////////////////////////////////////////////////
void setup(){
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("hello cokoino!");
  delay(1000);
  lcd.clear();

  // Initialize a new chip by turning off write protection and clearing the
  // clock halt flag. These methods needn't always be called. See the DS1302
  // datasheet for details.
  rtc.writeProtect(false);
  rtc.halt(false);

  // Make a new time object to set the date and time.
  // Sunday, September 8, 2020 at 12:38:10.
  Time t(2020, 9, 8, 12, 38, 10, Time::kSunday);

  // Set the time and date on the chip.
  rtc.time(t);
}
//////////////////////////////////////////////////////////
void loop(){
  printTime();
  delay(1000);
}
