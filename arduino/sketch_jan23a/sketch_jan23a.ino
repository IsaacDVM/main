int pinboton = 8;
int valor;

void setup(){
  Serial.begin(9600);
  pinMode(pinboton, INPUT);

   
}


void loop(){
  valor = digitalRead(pinboton);
  Serial.println(valor);
}
