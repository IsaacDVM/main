void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int var = digitalRead(8);
  Serial.println(var);
  if (var == 0){
    noTone(12);
  }
  if (var == 1){
    tone(12,750);
  }
  
}
