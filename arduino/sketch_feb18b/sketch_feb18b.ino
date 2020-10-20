
void setup() {
  pinMode(11,OUTPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.println(digitalRead(8));
  if(digitalRead(8)==1){
    melodia();  
  }
  
  
}

void melodia(){
  tone(11,500);
  delay(100);
  noTone(11);
  delay(100);
  tone(11,1500);
  delay(200);
  tone(11,2500);
  delay(50);
  noTone(11);
  delay(40);
  tone(11,400);
  delay(100);
  noTone(11);
}
