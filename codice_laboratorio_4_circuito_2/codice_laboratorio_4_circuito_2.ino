#include <Wire.h>
#include <ds3231.h>
struct ts t;
void setup() {
Serial.begin(9600);
Wire.begin();
t.hour=11;
t.min=12;
t.sec=0;
t.mday=06;
t.mon=03;
t.year=2022;
DS3231_set(t);
}
void loop() {
DS3231_get(&t);
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
Serial.println(t.sec);
delay(1000);
}
