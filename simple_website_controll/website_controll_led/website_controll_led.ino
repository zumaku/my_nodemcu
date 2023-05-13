/*
 Tolong jika menggunakan source code ini cantumkan :
 di buat oleh Ogi Sinatra
 dan di Upload https://www.youtube.com/atmoproduction_id
 
 ESP8266 NodeMCU LED Control over WiFi

 BERLANGGANAN GRATIS di AT-MO PRODUCTION
 https://goo.gl/M28DcR
 */

 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//ESP Web Server Library to host a web page
#include <ESP8266WebServer.h>

//---------------------------------------------------------------
//HTML CODE
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LED Controller</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
</head>
<body>
    
    <div class="container col-md-12 d-flex justify-content-center align-items-center" style="height: 100vh;">
        <div class="card d-flex justify-content-center align-items-center" style="width: 18rem; height: fit-content;">
            <img src="https://i.postimg.cc/KjK1wL3c/bulb-off.png" style="width: 180px;" alt="lamp-off" id="lamp">
            <div class="card-body">
                <h3 class="card-title text-center" id="cond">LED OFF</h3>
                <iframe name="myIframe" width="100" height="25" frameBorder="0" style="display: none;"></iframe>
                <div class="btn-group w-100 d-flex justify-content-center" role="group" id="btns">
                    <a href="ledOff" class="btn btn-danger px-5" target="myIframe">OFF</a>
                    <a href="ledOn" class="btn btn-warning px-5" target="myIframe">ON</a>
                </div>
            </div>
        </div>
    </div>

    <script>
        const btns = document.querySelector('#btns')
        const lamp = document.querySelector('#lamp')
        const cond = document.querySelector('#cond')

        btns.addEventListener('click', (e)=>{
            if(e.target.classList.contains('btn-warning')){
                lamp.src = "https://i.postimg.cc/6QyTynzr/bulb-on.png"
                cond.innerHTML = "ON"
            } else{
                lamp.src = "https://i.postimg.cc/KjK1wL3c/bulb-off.png"
                cond.innerHTML = "OFF"
            }
        })
    </script>
</body>
</html>
)=====";
//---------------------------------------------------------------


//menggunakan pin GPIO2 yang terhubung langsung dengan led di nodemcu
#define LED 2  

//SSID and Password of your WiFi router
const char* ssid = "PAKDIYAA"; // WAJIB DI GANTI
const char* password = "belikodata"; // WAJIB DI GANTI

//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 Serial.println("You called root page");
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleLEDon() { 
 Serial.println("LED on page");
 digitalWrite(LED,LOW); //LED is connected in reverse
 server.send(200, "text/html", "ON"); //Send ADC value only to client ajax request
}

void handleLEDoff() { 
 Serial.println("LED off page");
 digitalWrite(LED,HIGH); //LED off
 server.send(200, "text/html", "OFF"); //Send ADC value only to client ajax request
}


void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);       //Terhubung dengan WIFI router
  Serial.println("");

  //Onboard LED port Direction output
  pinMode(LED,OUTPUT); 
  //Power on LED state off
  digitalWrite(LED,HIGH);
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //Jika berhasil maka IP address akan di tampilkan di serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/ledOn", handleLEDon); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff", handleLEDoff);

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
