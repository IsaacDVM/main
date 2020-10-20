int a = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(9) == 1){
    while (digitalRead(9) == 1){
      delay(10);
    }
    a++;
    if (a == 4){
      a = 0;
    }
  }
  if (a == 0){
    digitalWrite(8,0); //apago el pin 8
  }
  if (a == 1){
    digitalWrite(8,1); //enciendo el pin 8
  }
  if (a == 2){
    digitalWrite(8,1);//enciendo el pin 8
    delay(50);
    digitalWrite(8,0);//apago el pin 8
    delay(50);
  }
  if (a == 3){
    digitalWrite(8,1);//enciendo el pin 8
    delay(50);
    digitalWrite(8,0);//apago el pin 8
    delay(50);
    digitalWrite(8,1);//enciendo el pin 8
    delay(150);
    digitalWrite(8,0);//apago el pin 8
    delay(150);
  }
}
