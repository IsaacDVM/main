const int red = 11;
const int green = 10;
const int blue = 9;

void setup() {
  for (int i = 9; i < 12;i++){
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int r = 0; r<255;r = r + 10){
    for (int g = 0; g<255;g = g + 10){
      for (int b = 0; b<255;b = b + 10){
        color(r,g,b);
        Serial.print(r);
        Serial.print("  ");
        Serial.print(g);
        Serial.print("  ");
        Serial.println(b);
      }
    }
  }
}

void azul (){
  digitalWrite(blue,0);
  digitalWrite(red,1);
  digitalWrite(green,1);
}
void rojo (){
  digitalWrite(blue,1);
  digitalWrite(red,0);
  digitalWrite(green,1);
}
void verde (){
  digitalWrite(blue,1);
  digitalWrite(red,1);
  digitalWrite(green,0);
}
void surprise(){
  digitalWrite(blue,0);
  digitalWrite(red,0);
  digitalWrite(green,0);
}
void surprise2(){
  digitalWrite(blue,1);
  digitalWrite(red,0);
  digitalWrite(green,0);
}
void color(int r,int g,int b){
  map (r,0,255,750,0);
  map (g,0,255,750,0);
  map (b,0,255,750,0);
  analogWrite(red,r); 
  analogWrite(green,g); 
  analogWrite(blue,b);
}
