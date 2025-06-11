// Button.cpp
#include <Arduino.h>
#include "Blade.h"
#include "Button.h"
#include "audio.h"

#define BTN_PIN 3
#define DOUBLE_CLICK_TIME 400
#define DEBOUNCE_DELAY 200

bool lastButtonPress = HIGH;
unsigned long lastButtonTime = 0;
uint8_t clickedTimes = 0;
bool saberEnabled = false;

void setupButton() {
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void handleButton() {
  int reading = digitalRead(BTN_PIN);
  unsigned long currentTime = millis();

  if (reading != lastButtonPress) {
    if (reading == LOW) {
      clickedTimes++;
      Serial.print("BUTTON PRESSED: ");
      Serial.println(clickedTimes);
    }
    lastButtonTime = currentTime;
  }

  if ((currentTime - lastButtonTime) > DEBOUNCE_DELAY) {
    if (clickedTimes == 1) {
      if (saberEnabled) {
        disableSaber();
        playOff();
        saberEnabled = false;
      } else {

        enableSaber();
        playOn();
        saberEnabled = true;
      }
    } else if (clickedTimes == 2 && saberEnabled) {
      changeColors();
    }
    clickedTimes = 0;
  }
  lastButtonPress = reading;
}
