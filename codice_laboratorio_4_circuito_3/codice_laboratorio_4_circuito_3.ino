#include <Wire.h>
#include <ds3231.h>
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
struct ts t;
void setup() {
Serial.begin(9600);
Wire.begin();
t.hour=9;
t.min=30;
t.sec=0;
t.mday=15;
t.mon=03;
t.year=2022;
DS3231_set(t);
}
void loop() {
DS3231_get(&t);
long duration, cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
cm = microsecondsToCentimeters(duration);
Serial.print("");
Serial.print(t.mday);
Serial.print(",");
Serial.print(t.mon);
Serial.print(",");
Serial.print(t.year);
Serial.print(",");
Serial.print(t.hour);
Serial.print(",");
Serial.print(t.min);
Serial.print(",");
Serial.print(t.sec);
Serial.print(",");
Serial.print(cm);
Serial.print("");
Serial.println();
delay(1000);
}
long microsecondsToCentimeters(long microseconds) {
return microseconds / 29 / 2;
}
