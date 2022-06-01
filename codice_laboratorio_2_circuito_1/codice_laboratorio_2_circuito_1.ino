const int analogPin = A0; // pin that the sensor is attached to
// variables:
const int ledCount = 4 ; // the number of LEDs in the bar graph
int ledPins[] = {2, 3, 4, 5}; // an array of pin numbers to which LEDs are attached
int sensorValue; // the sensor value
int sensorMin = 1023; // minimum sensor value
int sensorMax = 0; // maximum sensor value
void setup() {
Serial.begin(9600);
for (int thisLed = 0; thisLed < ledCount; thisLed++) {
pinMode(ledPins[thisLed], OUTPUT);
}
while (millis() < 5000) {
sensorValue = analogRead(analogPin);
// record the maximum sensor value
if (sensorValue > sensorMax) {
sensorMax = sensorValue;
}
// record the minimum sensor value
if (sensorValue < sensorMin) {
sensorMin = sensorValue;
}
}
}
void loop() {
// read the sensor:
sensorValue = analogRead(analogPin);
Serial.println("sensorMin");
Serial.println(sensorMin);
Serial.println("sensorMax");
Serial.println(sensorMax);
Serial.println("sensorValue");
Serial.println(sensorValue);
int ledLevel = map(sensorValue, sensorMin, sensorMax, 0, ledCount);
// loop over the LED array:
for (int thisLed = 0; thisLed < ledCount; thisLed++) {
// if the array element's index is less than ledLevel,
// turn the pin for this element on:
if (thisLed < ledLevel) {
digitalWrite(ledPins[thisLed], LOW);
}else { // turn off all pins higher than the ledLevel:
digitalWrite(ledPins[thisLed], HIGH);
}
}
delay(500);
}
