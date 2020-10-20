/*Prueba de LCD por protocolo I2C 
Mostraremos un mensaje y lo borraremos continuamente haciendo parpadear el backlight*/
// Importamos las librerias necesarias 
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>  // F Malpartida's NewLiquidCrystal library

/*-----( Declare Constants )-----*/
#define I2C_ADDR    0x20  // Direccion I2C para PCF8574A que es el que lleva nuestra placa diseñada por MJKDZ
//definimos las constantes para esta placa

#define  LED_OFF  0
#define  LED_ON  1

//mjkdz i2c LCD board
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(I2C_ADDR, 4, 5, 6, 0, 1, 2, 3, 7, NEGATIVE);

void setup()  
{
  lcd.begin (16,2);  // inicializar lcd 
// Activamos la retroiluminacion
  lcd.setBacklight(LED_ON);
}

void loop()
{

// Reset the display  
  lcd.clear();
  lcd.setBacklight(LED_OFF);//Backlight OFF 
  delay(500); 

  lcd.backlight(); //Backlight ON 
  lcd.setCursor(0,0);
  lcd.print("Hola Geekytheory"); 
  lcd.setCursor(0,1);
  lcd.print("LCD por I2C"); 
  delay(2000); 
}
