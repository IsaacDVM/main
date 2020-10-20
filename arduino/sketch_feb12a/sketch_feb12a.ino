/*
 Mi mamá me mima mucho
 */
const int pinLED = A0;

void setup() {
  
  Serial.begin(9600);
  pinMode(pinLED,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(analogRead(pinLED));
}
