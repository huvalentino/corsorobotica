const int analogPin = A0; // the pin that the potentiometer is attached to
const int ledCount = 8; // the number of LEDs in the bar graph
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // an array of pin numbers to which LEDs are attached
void setup() {
// loop over the pin array and set them all to output:
for (int thisLed = 0; thisLed < ledCount; thisLed++) {
pinMode (ledPins [thisLed], OUTPUT);
}
}
void loop() {
// read the potentiometer:
int sensorReading = analogRead (analogPin) ;
// map the result to a range from 0 to the number of LEDs:
int ledLevel = map (sensorReading, 0, 1023, 0, ledCount);
// 200p over the LED array!
for (int thisLed = 0; thisLed < ledCount; thisLed++) {
// 4£ the array element's index is less than ledLevel,
// turn the pin for this element on:
if (thisLed < ledLevel) {
digitalWrite (ledPins [thisLed], HIGH);
}else { // turn off all pins higher than the ledLevel:
digitalWrite (ledPins[thisLed], LOW);
}
}
}
