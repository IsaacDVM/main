#include <SD.h>
#include <SPI.h>
#include <DHT.h>
#define DHTPIN 2     // Pin donde está conectado el sensor
//#define DHTTYPE DHT11   // Descomentar si se usa el DHT 11
#define DHTTYPE DHT22   // Sensor DHT22
DHT dht(DHTPIN, DHTTYPE);

File logFile;
 
void setup()
{
  Serial.begin(9600);
  Serial.print(F("Iniciando SD ..."));
  if (!SD.begin(9))
  {
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));

  dht.begin();
}
 
void loop()
{
  // Abrir archivo y escribir valor
  logFile = SD.open("datalog.txt", FILE_WRITE);

 int UVvalue;
 long sumUV=0;

 for(int i=0;i<1024;i++){ 
  UVvalue=analogRead(A0);
  sumUV=UVvalue+sumUV;
  delay(2);
 }

  sumUV = sumUV >> 10;

  delay(2000);
  float h = dht.readHumidity(); //Leemos la Humedad
  float t = dht.readTemperature(); //Leemos la temperatura en grados Celsius
  
  if (logFile) { 
        logFile.print("Nuevos datos: ");
        logFile.print("Tiempo(ms)=");
        logFile.print(millis());
        logFile.print(", UV (mV) =");
        logFile.print(sumUV*4980.0/1023.0);
        logFile.print(", humedad (%t) =");
        logFile.print(h);
        logFile.print(", temperatura (Cº) =");
        logFile.print(t);

        logFile.close();

        if (Serial.available() > 0){
          int cerrar = Serial.parseInt ();
          if (cerrar == 0){
            logFile.println("");
            logFile.close();
            Serial.println ("Archivo cerrado");
            while (true){
              
            }
          }
        }
  
  } 
  else {
    Serial.println("Error al abrir el archivo");
  }
  delay(600);
}
