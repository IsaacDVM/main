// Importante: instalar Dallas Temperature y OneWire antes!!!!
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <SD.h>
File logFile;
// Pin donde se conecta el bus 1-Wire
const int pinDatosDQ = 7;
const int pinRele = 6;
float tempMax = 32.00;  //temperatura límite
unsigned long previousTime = 0;
const unsigned long varTime = 10000; //cada cuanto mide y graba datos
// Instancia a las clases OneWire y DallasTemperature
OneWire oneWireObjeto(pinDatosDQ);
DallasTemperature sensorDS18B20(&oneWireObjeto);
// El 1 es el de líquidos y el 0 es el de aire
void setup() {
  Serial.begin(9600);
  Serial.print(F("Iniciando SD ..."));
  if (!SD.begin(10))
  {
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));
  // Iniciamos el bus 1-Wire
  sensorDS18B20.begin();
  pinMode(pinDatosDQ,INPUT);
  pinMode(pinRele,OUTPUT); 
}
  
void loop() {
  unsigned long currentTime = millis();
  if (sensorDS18B20.getTempCByIndex(0) <= tempMax) {
      digitalWrite(pinRele, LOW);
    }
    else {
      digitalWrite(pinRele, HIGH);
    }
  if (currentTime - previousTime >= varTime) {
  // cada vartime leer temp y guardar en tarjeta. si temp es baja darle al relé
    previousTime = currentTime;
    sensorDS18B20.requestTemperatures();
    logFile = SD.open("datos.txt", FILE_WRITE);
    if (logFile) { 
    // Mandamos comandos para toma de temperatura a los sensores
    // Leemos y mostramos los datos de los sensores DS18B20
    // logFile.print("Temperatura sensor 0: ");
        logFile.print(millis());
        logFile.print(",");
        logFile.print(sensorDS18B20.getTempCByIndex(0));
        logFile.print(",");
        logFile.println(sensorDS18B20.getTempCByIndex(1));
        logFile.close();
    }
    else {
        Serial.println("Error al abrir el archivo");
    }
  }
}
