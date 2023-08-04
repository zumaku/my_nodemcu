void server_setup(){
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
      delay(1000);
      Serial.println("Connecting to WiFi...");
  }

  Serial.println("Wifi Connected.");
  Serial.print("Server running on http://");
  Serial.println(WiFi.localIP());

  // Routing
  server.on("/", HTTP_GET, handle_root);
  server.on("/send", HTTP_POST, handle_send);
  server.begin();
}