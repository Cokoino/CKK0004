/*only used for UNO R3*/
#ifndef MyServo_h
#define MyServo_h

class MyServo{
  public:
  MyServo();
  void Attach(int pin);
  void delayUS(int us);
  void Write(int anlge);
  private:
  int servo_pin;
};
#endif
