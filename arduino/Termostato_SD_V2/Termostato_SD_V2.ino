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
  sensorDS18B20.requestTemperatures();
  float tempAIRE = sensorDS18B20.getTempCByIndex(0);
  float tempAGUA = sensorDS18B20.getTempCByIndex(1);
  if (tempAGUA <= tempMax) {
      digitalWrite(pinRele, HIGH);
    }
    else {
      digitalWrite(pinRele, LOW);
    }
    logFile = SD.open("datos.txt", FILE_WRITE);
    if (logFile) { 
    // Mandamos comandos para toma de temperatura a los sensores
    // Leemos y mostramos los datos de los sensores DS18B20
    // logFile.print("Temperatura sensor 0: ");
        
        logFile.print (millis()/1000.0);
        logFile.print(",");
        logFile.print(tempAIRE);
        logFile.print(",");
        logFile.println(tempAGUA);
        logFile.close();
    }
    else {
        Serial.println("Error al abrir el archivo");
    }
    delay(5000);
}

