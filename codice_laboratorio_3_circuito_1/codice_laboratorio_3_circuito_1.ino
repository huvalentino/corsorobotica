int pinMot = 3;
void setup() {
// put your setup code here, to run once:
pinMode(pinMot,OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
//analogWrite(pinMot,0);
//delay(1000);
digitalWrite(pinMot,HIGH);
delay(1000);
digitalWrite(pinMot,LOW);
delay(1000);
}
