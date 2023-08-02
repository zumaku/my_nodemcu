#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Pakdiyaa2";
const char *password = "belikodata";

ESP8266WebServer server(80);

void handleRoot();
void handleSend();

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi");

    server.on("/", HTTP_GET, handleRoot);
    server.on("/send", HTTP_POST, handleSend);
    server.begin();
}

void loop()
{
    server.handleClient();
}

