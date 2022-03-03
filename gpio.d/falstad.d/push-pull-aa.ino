// Thu  3 Mar 13:09:25 UTC 2022

// initially unrelated code - avr8js boilerplate program

void setup() {
  Serial.begin(115200);

  // add external voltage (Javascript) with name "pin n" to access output pins
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  int i;
  Serial.println("looping");
  for (i = 8; i != 12; i++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
  }
  for (i = 12; i != 8; i--) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
  }
}

// END.
