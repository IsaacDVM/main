
void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(9,INPUT);
}

void loop() {
  // si leo el pin 9 y está pulsado (HIGH) entonces quiero que se encienda el LED pin 8
  if (digitalRead(9)==HIGH){
    digitalWrite(8,HIGH); //enciendo el pin 8
  }
  else{
    digitalWrite(8,0); //apago el pin 8
  }
}
