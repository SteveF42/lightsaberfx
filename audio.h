#ifndef AUDIO_H
#define AUDIO_H


enum class SaberState {
  HUM = 1,
  SWING = 2,
  POWER_ON = 3,
  POWER_OFF = 4,
  CLASH = 5,
  BLASTER = 6
};

enum class FileCount {
  HUM = 1,
  SWING = 17,
  POWER_ON = 3,
  POWER_OFF = 2,
  CLASH = 8,
  BLASTER = 4
};

void setupAudio();

void playEffect(SaberState state);

void playOn();

void playOff();

#endif