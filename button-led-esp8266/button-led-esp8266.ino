void setup() {
  Serial.begin(9600);
  pinMode(16, OUTPUT);
  pinMode(14, INPUT_PULLUP);  // D5
  pinMode(12, INPUT_PULLUP);  // D6
  pinMode(13, INPUT_PULLUP);  // D7
}

short btnstate, btnstate2, btnstate3;

void loop() {
  btnstate = digitalRead(14);
  btnstate2 = digitalRead(12);
  btnstate3 = digitalRead(13);
  if(btnstate == LOW || btnstate2 == LOW || btnstate3 == LOW){
    digitalWrite(16, LOW);
    Serial.println("LOW | Lampu Menyala");
  }
  else{
    digitalWrite(16, HIGH);
    Serial.println("HIGH | Lampu Mati");
  }
}
