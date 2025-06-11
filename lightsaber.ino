#include <DFRobotDFPlayerMini.h>
#include "audio.h"

// main.ino
#include "Blade.h"
#include "Button.h"


void setup() {
  Serial.begin(9600);
  setupBlade();
  setupButton();
  setupAudio();
}

void loop() {
  handleButton();
}
