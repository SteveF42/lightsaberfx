#include "Arduino.h"
#include "audio.h"
#include <SoftwareSerial.h>
#include <stdlib.h>
#include <time.h>
#include <DFRobotDFPlayerMini.h>


SoftwareSerial speakerSerial(10, 11);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int randomInRange(int min, int max) {
  return rand() % (max - min + 1) + min;
}

void setupAudio() {
  speakerSerial.begin(9600);

  if (!myDFPlayer.begin(speakerSerial)) {
    Serial.println("DFPlayer not found");
    while (true)
      ;
  }
  Serial.println("DFPLAYER FOUND");

  srand(time(NULL));
  myDFPlayer.volume(5);  // 0 to 30
}

void playEffect(SaberState state) {

  switch (state) {
    case SaberState::SWING: break;
    case SaberState::CLASH: break;
    default:
      break;
  }
}

void playOn() {
  uint8_t folder = static_cast<uint8_t>(SaberState::POWER_ON);
  uint8_t fileCount = static_cast<uint8_t>(FileCount::POWER_ON);
  uint8_t fileIdx = randomInRange(1, 3);
  myDFPlayer.playFolder(folder, fileIdx);

  delay(900);
  uint8_t humm = static_cast<uint8_t>(SaberState::HUM);
  myDFPlayer.loopFolder(humm);
}

void playOff() {
  if (!myDFPlayer.available()) return;
  uint8_t folder = static_cast<uint8_t>(SaberState::POWER_OFF);
  uint8_t fileCount = static_cast<uint8_t>(FileCount::POWER_OFF);
  uint8_t fileIdx = randomInRange(1, fileCount);
  myDFPlayer.playFolder(folder, fileIdx);
}
