
// Mandar las lecturas del BMP por BT Serial cada 100 ms

#include <Adafruit_BMP085.h>
#include "BluetoothSerial.h"

//#define USE_PIN // Uncomment this to use PIN during pairing. The pin is specified on the line below
const char *pin = "1234"; // Change this to more secure PIN.

String device_name = "ESP32-BT-Slave";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

// Registramos la información del sensor barometrico y LDR.
#define LED_PIN 33
#define LDR_PIN 35

Adafruit_BMP085 bmp; // Creamos el objeto bmp.

char payload[80]; // Payload donde guardamos las lecturas.

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  //Serial.printf("The device with name \"%s\" and MAC address %s is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str(), SerialBT.getMacString()); // Use this after the MAC method is implemented
  #ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
  #endif
  bmp.begin(); // Inicializamos el sensor por default está en la dirección 0x77.
}

void loop() {

  // Creamos la variables donde guardaremos las lecturas de nuestros sensores.
  float pressure = bmp.readPressure();
  float temperature = bmp.readTemperature();
  int luminosity = analogRead(LDR_PIN);

  // Guardamos en el payload las lecturas de los sensores.
  sprintf(payload, "%6.2f,%3.2f,%d", pressure, temperature, luminosity);
  
  // Imprimimos en el serial monitor de BT.
  digitalWrite(LED_PIN, HIGH);
    SerialBT.println(payload);
  digitalWrite(LED_PIN, LOW);

  delay(100); // Introducimos un retraso de 100 ms entre cada lectura.

}
