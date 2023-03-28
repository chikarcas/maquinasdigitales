#define PIN_LED 33  // Pin de PWM (Pulse Widt Modulation).
#define PIN_PO 32   // Pin de ADC (Analog to Digital Converter) Potenciometro.
#define PIN_LDR 35  // Pin de ADC (Analog to Digital Converter) LDR.

int po_in = 0;
int ldr_in = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);  // Configuración para el LED
}

void loop() {
  po_in = analogRead(PIN_PO);
  ldr_in = analogRead(PIN_LDR);

  Serial.println(po_in);
  Serial.println(ldr_in);


  analogWrite(PIN_LED, po_in / 16);

  //analogWrite(PIN_LED, ( 255 - (ldr_in/16) ));

  // for(int i = 0; i < 255; i++){
  //   analogWrite(PIN_LED, i);
  //   delay(10);
  // }
  // for(int i = 255; i > 0; i--){
  //   analogWrite(PIN_LED, i);
  //   delay(10);
  // }

  delay(100);
}
