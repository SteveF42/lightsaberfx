#include "Printable.h"
#include "HardwareSerial.h"

#include "audio.h"
#include <SoftwareSerial.h>
#include <stdlib.h>
#include <time.h>
#include <DFRobotDFPlayerMini.h>


SoftwareSerial speakerSerial(10, 11);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;
bool dfPlayerAvailable = false;

int randomInRange(int min, int max) {
  return rand() % (max - min + 1) + min;
}

void setupAudio() {
  speakerSerial.begin(9600);

  if (!myDFPlayer.begin(speakerSerial)) {
    Serial.println("DFPlayer not found");
    dfPlayerAvailable = false;
  } else {
    dfPlayerAvailable = true;
    Serial.println("DFPLAYER FOUND");
  }

  myDFPlayer.volume(15);  // 0 to 30
}

void playEffect(SaberState state) {
  if (!dfPlayerAvailable) {
    return;
  }

  switch (state) {
    case SaberState::POWER_ON:
      playOn();
      break;
    case SaberState::POWER_OFF:
      playOff();
      break;
    default:
      break;
  }
}

void playOn() {
  uint8_t onSound = getPowerOnSound();
  uint8_t humm = gethummSound();
  myDFPlayer.play(onSound);

  while (true) {
    if (myDFPlayer.available()) {
      uint8_t type = myDFPlayer.readType();

      if (type == DFPlayerPlayFinished) {
        Serial.println("Playback finished");
        break;
      }
    }
  }

  delay(950);
  myDFPlayer.loop(humm);
}

void playOff() {
  uint8_t offSound = getPowerOffSound();
  myDFPlayer.play(offSound);
}
