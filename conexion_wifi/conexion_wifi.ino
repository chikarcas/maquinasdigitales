#include <WiFi.h>
#include <Credentials.h>

//const char* SSID     = "internet-gratis_2.4"; // Change this to your WiFi SSID
//const char* PASSWORD = "sTJh7/hg@7!9ypT"; // Change this to your WiFi password

void setup() {
  Serial.begin(115200);
  while(!Serial){delay(100);}

  Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");
  Serial.println(SSID);

  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
