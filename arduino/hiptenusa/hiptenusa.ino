void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 for (int i = 1; 1 < 101; i++){
  Serial.println(hipotenusa(i,2)); 
 }
 
}
float hipotenusa(int cat1,int cat2){
  float a = sin(cat1*cat1+cat2*cat2);
  return a;
}
