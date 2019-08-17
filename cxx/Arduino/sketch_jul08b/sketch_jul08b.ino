#include <ButtonDebounce.h>

#define BUZZER 13
#define BUTTON 10

bool play = true;
ButtonDebounce button(BUTTON, 150);

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  //pinMode(BUTTON, INPUT);
  noTone(BUZZER);
}


void flip(const int state){
  
  
}

void loop() {
  button.update();
  if (button.state() == LOW) noTone(BUZZER);
  else tone(BUZZER, 1000);
}
