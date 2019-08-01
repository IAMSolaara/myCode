#include <pitches.h>
#include <PlayRtttl.h>



#define SPK_1 13
int delTime = 20;


class scores{
  public:
    void two(){
      for (int x=0; x<8; x++){
        playNote(SPK_1, NoteC4ToC7[random(0, 37)]);
        delay(delTime);
      }  
    }
    void one(){
      for (int x=0; x < 4; x++) {
        playNote(SPK_1, NOTE_A4);
        delay(delTime);
        playNote(SPK_1, NOTE_CS5);
        delay(delTime);
        playNote(SPK_1, NOTE_E5);  
        delay(delTime);
      }
      for (int x=0; x < 4; x++) {
        playNote(SPK_1, NOTE_A4);
        delay(delTime);
        playNote(SPK_1, NOTE_D5);
        delay(delTime);
        playNote(SPK_1, NOTE_F5);  
        delay(delTime);
      } 
    for (int x=0; x < 4; x++) { 
      playNote(SPK_1, NOTE_G4);
      delay(delTime);
      playNote(SPK_1, NOTE_B4);
      delay(delTime);
      playNote(SPK_1, NOTE_D5);  
      delay(delTime);
    }
    for (int x=0; x < 4; x++) {
      playNote(SPK_1, NOTE_F4);
      delay(delTime);
      playNote(SPK_1, NOTE_A4);
      delay(delTime);
      playNote(SPK_1, NOTE_C5);  
      delay(delTime);
    }
    for (int x=0; x < 4; x++) {
      playNote(SPK_1, NOTE_E4);
      delay(delTime);
      playNote(SPK_1, NOTE_A4);
      delay(delTime);
      playNote(SPK_1, NOTE_B4);  
      delay(delTime);
    }
    for (int x=0; x < 4; x++) {
      playNote(SPK_1, NOTE_E4);
      delay(delTime);
      playNote(SPK_1, NOTE_GS4);
      delay(delTime);
      playNote(SPK_1, NOTE_B4);  
      delay(delTime);
    }
  }
  void playNote(int out, int note){
  resetPins();
  Serial.println(note);
  switch (note) {
    case NOTE_C1:
    case NOTE_C2:
    case NOTE_C3:
    case NOTE_C4:
    case NOTE_C6:
    case NOTE_C7:
    case NOTE_C8:
    case NOTE_C5:  digitalWrite(2, HIGH);
                   break;
    case NOTE_CS1:
    case NOTE_CS2:
    case NOTE_CS3:
    case NOTE_CS4:
    case NOTE_CS6:
    case NOTE_CS7:
    case NOTE_CS8:
    case NOTE_CS5: digitalWrite(2, HIGH);
                   break;
    case NOTE_D1:
    case NOTE_D2:
    case NOTE_D3:
    case NOTE_D4:
    case NOTE_D6:
    case NOTE_D7:
    case NOTE_D8:
    case NOTE_D5:  digitalWrite(3, HIGH);
                   break;
    case NOTE_DS1:
    case NOTE_DS2:
    case NOTE_DS3:
    case NOTE_DS4:
    case NOTE_DS6:
    case NOTE_DS7:
    case NOTE_DS8:
    case NOTE_DS5: digitalWrite(3, HIGH);
                   break;
    case NOTE_E1:
    case NOTE_E2:
    case NOTE_E3:
    case NOTE_E4:
    case NOTE_E6:
    case NOTE_E7:
    case NOTE_E5:  digitalWrite(4, HIGH);
                   break;
    case NOTE_F1:
    case NOTE_F2:
    case NOTE_F3:
    case NOTE_F4:
    case NOTE_F6:
    case NOTE_F7:
    case NOTE_F5:  digitalWrite(5, HIGH);
                   break;
    case NOTE_FS1:
    case NOTE_FS2:
    case NOTE_FS3:
    case NOTE_FS4:
    case NOTE_FS6:
    case NOTE_FS7:
    case NOTE_FS5: digitalWrite(5, HIGH);
                   break;
    case NOTE_G1:
    case NOTE_G2:
    case NOTE_G3:
    case NOTE_G5:
    case NOTE_G6:
    case NOTE_G7:
    case NOTE_G4:  digitalWrite(6, HIGH);
                   break;
    case NOTE_GS1:
    case NOTE_GS2:
    case NOTE_GS3:
    case NOTE_GS5:
    case NOTE_GS6:
    case NOTE_GS7:
    case NOTE_GS4: digitalWrite(6, HIGH);
                   break;
    case NOTE_A1:
    case NOTE_A2:
    case NOTE_A3:
    case NOTE_A5:
    case NOTE_A6:
    case NOTE_A7:
    case NOTE_A4:  digitalWrite(7, HIGH);
                   break;
    case NOTE_AS1:
    case NOTE_AS2:
    case NOTE_AS3:
    case NOTE_AS5:
    case NOTE_AS6:
    case NOTE_AS7:
    case NOTE_AS4: digitalWrite(7, HIGH);
                   break;
    case NOTE_B0:
    case NOTE_B1:
    case NOTE_B2:
    case NOTE_B3:
    case NOTE_B5:
    case NOTE_B6:
    case NOTE_B7:
    case NOTE_B4:  digitalWrite(8, HIGH);
                   break;
  }
  delTime = analogRead(A0);
  tone(out, note);
}
void resetPins(){
    for (int i = 2;i <= 12; i++){
      digitalWrite(i, LOW);
    }
  }
void startup(){
  playNote(SPK_1, NOTE_C4);  
  delay(200);
  playNote(SPK_1, NOTE_D4);  
  delay(200);
  playNote(SPK_1, NOTE_E4);  
  delay(200);
  playNote(SPK_1, NOTE_F4);  
  delay(200);
  playNote(SPK_1, NOTE_G4);  
  delay(200);
  playNote(SPK_1, NOTE_A4);  
  delay(200);
  playNote(SPK_1, NOTE_B4);  
  delay(200);
  playNote(SPK_1, NOTE_C5);  
  delay(200);
}
};

scores Scores;

void setup(){
  Serial.begin(9600);
  pinMode(SPK_1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Scores.startup();
}


void loop(){  Scores.two();  }



void pinsTest(){
  for (int i = 2;i <= 8; i++){
    digitalWrite(i-1, LOW);
    digitalWrite(i, HIGH);
    digitalWrite(i+1, LOW);
    delay(200);
  }
}
