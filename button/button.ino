#define PIN_LED 33 
#define PIN_BUTTON 34

// the setup function runs once when you press reset or power the board

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  Serial.begin(115200);


}

// the loop function runs over and over again forever

void loop() {
  bool button_status = digitalRead(PIN_BUTTON);
  Serial.println(button_status);

  if (button_status){
    digitalWrite(PIN_LED, HIGH);
  }
  else {
    digitalWrite(PIN_LED, LOW);
  }
  delay(100);
}