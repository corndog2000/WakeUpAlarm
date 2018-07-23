#include <SimpleSDAudio.h>

const int SETPIN = 2;
int SETPINStatus = 0;

const int RESETPIN = 3;
int RESETPINStatus = 0;

const int sensorPin = 8;
int sensorStatus = 0;

bool armedCondition = false;

void playMusic() {
  SdPlay.play(); // play music

  while (!SdPlay.isStopped())

  { ;

  }
}

void readButtons() {
  SETPINStatus = digitalRead(SETPIN);
  RESETPINStatus = digitalRead(RESETPIN);
  sensorStatus = digitalRead(sensorPin);
}

void setup() {

  Serial.begin(2000000);

  pinMode(SETPIN, INPUT_PULLUP);
  pinMode(RESETPIN, INPUT_PULLUP);
  pinMode(sensorPin, INPUT_PULLUP);

  SdPlay.setSDCSPin(10); // sd card cs pin

  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_STEREO | SSDA_MODE_AUTOWORKER))

  {
    while (1);
  }

  if (!SdPlay.setFile("music.wav")) // music name file

  { while (1);

  }

}

void loop(void) {
  readButtons();

  if (sensorStatus == HIGH && SETPINStatus == HIGH) {
    Serial.println("Bed alarm armed");
    armedCondition = true;
  }
  else if (sensorStatus == LOW) {

  }
}
