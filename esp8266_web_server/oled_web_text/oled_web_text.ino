#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <U8g2lib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define ssid "Pakdiyaa2"
#define password "belikodata"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

ESP8266WebServer server(80);

// Variables
unsigned long prevMillis = 0;
short xPos = SCREEN_WIDTH;
String textFromClient = "";
short speedFromClient = 0;

// Functions
void server_setup();
void handle_root();
void handle_send();
void display_text();


void setup(){
    Serial.begin(115200);
    Wire.begin();  // Inisialisasi koneksi I2C
    u8g2.begin();
    server_setup();
}

void loop(){
    server.handleClient();
    display_text();
}