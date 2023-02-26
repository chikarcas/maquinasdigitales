
#define PIN_LED 33 
#define PIN_PO 32
#define THRLD 800

// the setup function runs once when you press reset or power the board

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever

void loop() {
  int po_signal = analogRead(PIN_PO);

  if(po_signal>THRLD){
    digitalWrite(PIN_LED, HIGH);
  }
  else{
    digitalWrite(PIN_LED, LOW);
  }

  Serial.println(po_signal);
  delay(50);
}