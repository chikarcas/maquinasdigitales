#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp; // Creamos el objeto bmp.

char payload[80]; // Payload donde guardamos las lecturas.

void setup() {
  bmp.begin(); // Inicializamos el sensor por default está en la dirección 0x77.
  Serial.begin(115200); // Inicializamos el monitor serial.
}

void loop() {

  // Creamos la variables donde guardaremos las lecturas de nuestro sensor.
  float pressure = bmp.readPressure();
  float temperature = bmp.readTemperature();

  // Guardamos en el payload las lecturas de los sensores.
  sprintf(payload,"%6.2f,%3.2f", pressure, temperature);

  Serial.println(payload); // Imprimimos en el monitor serial el payload.

  delay(200); // Introducimos un retraso de 200 ms entre cada lectura.
}
