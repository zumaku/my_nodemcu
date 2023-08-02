#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Pakdiyaa2";
const char* password = "belikodata";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  server.on("/", HTTP_GET, handleRoot);
  server.on("/send", HTTP_POST, handleSend);
  server.begin();
}

void loop() {
  server.handleClient();
  // Kode loop lainnya di sini
}

void handleRoot() {
  String message = "Welcome to ESP8266 Web Server<br>";
  message += "<form action='/send' method='POST'>";
  message += "Text: <input type='text' style='background-color: red;' name='inputText'><input type='submit' value='Send'>";
  message += "</form>";

  server.send(200, "text/html", message);
}

void handleSend() {
  if (server.hasArg("inputText")) {
    String text = server.arg("inputText");
    Serial.print("Received Text: ");
    Serial.println(text);
    server.send(200, "text/html", "<p>Text received: " + text + "</p><script>setTimeout(function() { window.location.href = '/'; }, 3000);</script>");
  } else {
    server.send(400, "text/plain", "Bad Request");
  }
}
