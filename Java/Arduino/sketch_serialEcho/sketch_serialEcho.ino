void setup() {
  Serial.begin(1200);
  Serial.print("Running...");
}

void loop(){
  char echo[] = Serial.read();
  Serial.print(echo);
  
}
