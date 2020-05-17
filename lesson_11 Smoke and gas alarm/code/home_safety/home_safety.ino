#define analogGAS A1
#define digitalGAS 2
#define buzzer 6
int GAS_data=0;
void setup() {  
  pinMode(buzzer,OUTPUT); 
  pinMode(analogGAS,INPUT);
  pinMode(digitalGAS,INPUT);
  attachInterrupt(0, printData, LOW);
  Serial.begin(9600);
}
void loop() {
  GAS_data = analogRead(A1);
  digitalWrite(6,LOW);
}
void printData(){
  Serial.println(GAS_data);
  digitalWrite(6,HIGH);
}

