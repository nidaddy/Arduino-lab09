#include <Ultrasonic.h>
#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(11,10,9, 7, 6,5 ); // initialize interface pins
#define TRIGGER_PIN 12
#define ECHO_PIN 13
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() {
   lcd.begin(20, 2); // set up the LCD's number of columns and rows:
Serial.begin(9600);
}
void loop(){
float cmMsec, inMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
Serial.print("MS: "); Serial.print(microsec);
Serial.print(", CM: "); Serial.print(cmMsec);
Serial.print(", IN: "); Serial.println(inMsec);
lcd.print("CM:");
lcd.print(ultrasonic.convert(microsec, Ultrasonic::CM));
delay(1000);
lcd.clear();
}
