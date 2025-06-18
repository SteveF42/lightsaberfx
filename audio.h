#ifndef AUDIO_H
#define AUDIO_H

#include <Arduino.h>
#define SF_HUMM 1
#define SF_SWING 2
#define SF_POWERON 16
#define SF_POWEROFF 19
#define SF_CLASH 21
#define SF_BLASTER 29

#define SWING_OFFSET 14
#define POWERON_OFFSET 3
#define POWEROFF_OFFSET 2
#define CLASH_OFFSET 8
#define BLASTER_OFFSET 33

enum class SaberState {
  HUM = 1,
  SWING = 2,
  POWER_ON = 3,
  POWER_OFF = 4,
  CLASH = 5,
  BLASTER = 6
};


void setupAudio();

void playEffect(SaberState state);

void playOn();

void playOff();

inline uint8_t gethummSound(){
  return SF_HUMM;
}

inline uint8_t getswingSound(){
  return SF_SWING + random(0,SWING_OFFSET);
}

inline uint8_t getPowerOnSound(){
  return SF_POWERON + random(0,POWERON_OFFSET);
}

inline uint8_t getPowerOffSound(){
  return SF_POWEROFF + random(0, POWEROFF_OFFSET);
}

inline uint8_t getClashSound(){
  return SF_CLASH + random(0, CLASH_OFFSET);
}

inline uint8_t getBlasterSound(){
  return SF_BLASTER + random(0, BLASTER_OFFSET);
}

#endif