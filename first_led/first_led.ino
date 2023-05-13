void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(0, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(0, LOW);
  delay(1000);
}
