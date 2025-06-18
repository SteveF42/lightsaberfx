#include <DFRobotDFPlayerMini.h>

// main.ino
#include "Blade.h"
#include "Button.h"
#include "audio.h"
#include "swingEngine.h"


void setup() {
  Serial.begin(9600);
  // setupAudio();
  // setupBlade();
  // setupButton();
  setupMPU();

}

void loop() {
  handleButton();  
  if(isEnabled()){
    // checkForSwing();
  }
}
