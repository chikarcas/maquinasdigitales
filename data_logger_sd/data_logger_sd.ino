#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <Adafruit_BMP085.h>

// Registramos la información del sensor barometrico y LDR.
#define LED_PIN 33
#define LDR_PIN 35

File readings; // Creamos el objeto readings.
Adafruit_BMP085 bmp; // Creamos el objeto bmp.

char payload[80]; // Payload donde guardamos las lecturas.

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  bmp.begin(); // Inicializamos el sensor por default está en la dirección 0x77.
  //Montarlo. Si falla, manda mensaje de error
  if(!SD.begin()){
    Serial.println("Card Mount Failed");
    return;
  }
}

void loop() {

  // Creamos la variables donde guardaremos las lecturas de nuestros sensores.
  float pressure = bmp.readPressure();
  float temperature = bmp.readTemperature();
  int luminosity = analogRead(LDR_PIN);

  // Guardamos en el payload las lecturas de los sensores.
  sprintf(payload,"%6.2f,%3.2f,%d", pressure, temperature, luminosity);

  digitalWrite(LED_PIN,HIGH);
    readings = SD.open("/lecturas_sensor.csv", FILE_APPEND);
    readings.println(payload);
    readings.close();
    Serial.println(payload);
  digitalWrite(LED_PIN,LOW);

  delay(500); // Introducimos un retraso de 500 ms entre cada lectura.

}
