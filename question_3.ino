#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 13

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
LiquidCrystal lcd(11,10,9, 7, 6,5);

const byte intPin=2;
void setup() { 
  lcd.begin(20, 2);
  Serial.begin(9600);
  pinMode(intPin, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  attachInterrupt(0, int0, LOW); 
}
void loop() { 
  boolean val=digitalRead(5);
  if(val==LOW)
  {
    noInterrupts();
  }
  else
  {
    interrupts();
  }
}
void int0() { //interrupt handler 
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
  lcd.setCursor(0,0);
  lcd.print("CM:");
  lcd.print(cmMsec);
  Serial.print("CM: "); 
  Serial.println(cmMsec);
}

