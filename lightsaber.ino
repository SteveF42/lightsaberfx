// main.ino
#include "Blade.h"
#include "Button.h"

void setup() {
  setupBlade();
  setupButton();
}

void loop() {
  handleButton();
}