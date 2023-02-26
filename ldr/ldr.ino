
#define PIN_LED 33 
#define PIN_LDR 35
#define THRLD 800

// the setup function runs once when you press reset or power the board

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever

void loop() {
  int ldr_signal = analogRead(PIN_LDR);

  if(ldr_signal>THRLD){
    digitalWrite(PIN_LED, LOW);
  }
  else{
    digitalWrite(PIN_LED, HIGH);
  }

  Serial.println(ldr_signal);
  delay(50);
}