// Leer Json desde Serial, SD o SPIFFS 
// Serializar un Json e imprimirlo por serial

#include <Adafruit_BMP085.h>
#include <ArduinoJson.h>

//Payload creado con snprintf
#define BUFFER_LEN  256
char payload[BUFFER_LEN]; //Payload Serializado
String json_string;

//Payload crearon con Json parser
//Doc: https://arduinojson.org/
//Ticket: Usar reservación de memoria en stack
//Usar el json assistant para calcular el LEN necesario para cada documento
#define JSON_BUFFER_OUTGOING_LEN 200
DynamicJsonDocument payload_out(JSON_BUFFER_OUTGOING_LEN);//Json hacia SPIFFS,SD,Serial o MQTT (Stream)

//Configuración de BMP y LED
#define LDR_PIN 35
Adafruit_BMP085 bmp;

void setup() {
  
  //Inicializar perifericos
  Serial.begin(115200);
  bmp.begin(); 
}

void loop() {

  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure()/100;
  int luminosity = analogRead(LDR_PIN);

   // Json Serializer
   payload_out["origen"] = "json_serializer";
   payload_out["temp_C"] = String(temperature,2);
   payload_out["press_hPa"] = String(pressure,2);
   payload_out["lumin_12bitRes"] = String(luminosity);

   serializeJson(payload_out, payload);
        
   Serial.print("Json serializado: ");
   Serial.println(payload);
   delay(5000);              
}
