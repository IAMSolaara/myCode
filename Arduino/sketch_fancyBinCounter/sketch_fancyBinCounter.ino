byte out;

void setup () {
  Serial.begin(1200);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  bootAnimation();
  Serial.print("Waiting for number to be sent...\n\r");
}

void encodeTo8(byte send) {
  resetPins();
  for (byte x = 0; x <= send; x++){
    for (int i = 0; i <= 7; i++) {
      digitalWrite(13, 1);
      int fPin = x & (0x80 >> i);
      digitalWrite(i + 2, fPin);
      digitalWrite(13, 0);
    } 
    delay(50);
  }
  tone(13, 1000);
  delay(100);
  noTone(13);
}

void bootAnimation() {
  for (int i = 2; i <= 9; i++) {
    digitalWrite(13, 1);
    digitalWrite(i, 1);
    delay(100);
    digitalWrite(13, 0);
  }
  for (int i = 2; i <= 9; i++) {
    digitalWrite(13, 1);
    digitalWrite(i, 0);
    delay(100);
    digitalWrite(13, 0);
  }
  tone(13,500);
  delay(200);
  tone(13,732);
  delay(200);
  tone(13, 1000);
  delay(200);
  noTone(13);
}

void loop() {
  while (Serial.available() > 0) {
    out = lowByte(Serial.parseInt());
    if (Serial.read() == '\n') {
      Serial.print("Received ");
      Serial.print(out);
      Serial.print("\n\r");
      Serial.print(out, BIN);
      Serial.print(" should appear.\n\r");
      encodeTo8(out);
      Serial.print("Waiting for number to be sent...\n\r");
    }
  }
}

void count(){
  Serial.print("Binary Counter mode engaged!\n\r");
  for(byte x; x <= 255; x++){
      encodeTo8(x);
      delay(50);
  }
}
void resetPins(){
  for (int i = 2;i <= 9; i++){
    digitalWrite(i, LOW);
  }
}
