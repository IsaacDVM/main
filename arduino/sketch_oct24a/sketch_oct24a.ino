String a;
void setup() {
  Serial.begin(9600);
  
}



void loop() {
  a = "paata";
  if (a == "patata"){
    Serial.println(a);
  }
  delay(500);
}

