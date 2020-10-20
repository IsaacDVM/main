void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(hipot(4,3));
  

}

float hipot(int alpha,int beta){
  float a = sqrt(alpha*alpha+beta*beta);
  return a;
}
