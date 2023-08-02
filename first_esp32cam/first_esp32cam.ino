/*
  ESP32 WiFi Signal Test
  esp32-wifi-signal-test.ino
  Tests WiFi signal strength
  *Requires WiFi SSID and Password

  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/

// Include WiFi library
#include "WiFi.h"

// SSID and Password - modify for your WiFi network
const char* ssid     = "Pakdiyaa2";
const char* password = "belikodata";

void setup(){
  // Setup serial monitor
  Serial.begin(115200);
  // Start WiFi and conect to network
  WiFi.begin(ssid, password);
  // Wait while connection established
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }
  // WiFi is connected
  Serial.println("");
  Serial.print("Connected to network ");
  Serial.println(ssid);
  delay(100);
}

void loop(){
  Serial.print(ssid);
  Serial.print(" Signal Level: ");
  Serial.println(WiFi.RSSI());
  delay(2000);
}