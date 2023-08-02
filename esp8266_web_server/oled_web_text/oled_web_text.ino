#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Pakdiyaa2";
const char *password = "belikodata";

ESP8266WebServer server(80);

void server_setup();
void handleRoot();
void handleSend();

void setup()
{
    Serial.begin(115200);
    server_setup();
}

void loop()
{
    server.handleClient();
}

