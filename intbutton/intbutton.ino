#define PIN_BUTTON 34
// Definimos la variable que guardará el numero de veces que hemos presionado el botón.
int numberKeyPresses = 0;
// Definimos la variable que guardara la última lectura de tiempo registrada (es un entero sin signo de 32 bits).
uint32_t lastMillis = 0;

// Definimos la función de interrupción la cual es del tipo void y se almacena en la RAM interna.
void IRAM_ATTR isrButton() {
  // Definimos  un condicional para establecer un debouncing para nuestro botón y que no registre el ruido propio de este dispositivo mecánico.
  if (millis() - lastMillis > 125) {
    numberKeyPresses += 1;
    lastMillis = millis(); 
  }
}

void setup() {
    Serial.begin(115200);
    pinMode(PIN_BUTTON, INPUT);
    attachInterrupt(PIN_BUTTON, isrButton, RISING);
}

void loop() {
    // Imprimimos el número de veces que hemos presionado el botón en el monitor serial.
    Serial.printf("El botón se ha presionado %u veces\n", numberKeyPresses);
}
