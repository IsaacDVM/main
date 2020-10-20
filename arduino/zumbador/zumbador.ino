int a = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(9,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(9) == 1){
    while (digitalRead(9) == 1){
      delay(10);
    }
    a++; //a++ se suma a a 1 y se pisa el valor de a con el nuevo
    if (a == 4){
      a = 0;
    }
  }
  if (a == 0){
    noTone(11); //apago el pin 8
  }
  if (a == 1){
    tone(11,1500); //enciendo el pin 8
  }
  if (a == 2){
    tone(11,1500);//enciendo el pin 8
    delay(50);
    noTone(11);//apago el pin 8
    delay(50);
  }
  if (a == 3){
    tone(11,1500);//enciendo el pin 8
    delay(50);
    noTone(11);//apago el pin 8
    delay(50);
    tone(11,1000);//enciendo el pin 8
    delay(50);
    noTone(11);//apago el pin 8
    delay(50);
    tone(11,3500);//enciendo el pin 8
    delay(50);
    noTone(11);//apago el pin 8
    delay(50);
    tone(11,500);//enciendo el pin 8
    delay(50);
    noTone(11);//apago el pin 8
    delay(50);
  }
}
