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

#if 0

$ 1 0.000005 10.20027730826997 50 5 50 5e-11
g 336 448 336 496 0 0
R 224 64 160 64 0 0 40 5 0 0 0.5
R 192 256 144 256 0 2 20 5 0 0 0.5
p 192 256 192 320 1 0 0
f 272 208 336 208 33 1.5 0.02
w 224 64 336 64 0
f 272 304 336 304 32 1.5 0.02
r 336 320 336 400 0 10
w 272 208 272 256 0
w 272 304 272 256 0
w 192 256 272 256 0
w 336 224 336 256 0
w 336 288 336 256 0
w 336 256 464 256 0
p 464 256 464 320 1 0 0
162 576 256 576 320 2 default-led 1 0 0 0.01
w 464 256 576 256 0
r 576 320 576 400 0 2200
g 576 448 576 496 0 0
162 576 64 576 128 2 default-led 1 0 0 0.01
r 576 128 576 208 0 2200
370 336 112 336 160 1 0 0
370 336 400 336 448 1 0 0
370 576 208 576 256 1 0 0
370 576 400 576 448 1 0 0
w 336 64 576 64 0
w 336 160 336 192 0
w 336 112 336 64 0
o 3 64 0 4098 5 0.1 0 1

#endif
// END.
