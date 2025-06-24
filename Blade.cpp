// Blade.cpp
#include "Blade.h"
#define LED_PIN 13
#define NUMPIXELS 235
#define FADE_STEPS 100
#define DELAY_MS 20
#define LIGHTING_STEPS 2


Adafruit_NeoPixel strip(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
uint8_t colors[][3] = {
  { 255, 0, 0 },      // Red
  { 0, 255, 0 },      // Green
  { 0, 0, 255 },      // Blue
  { 255, 255, 0 },    // Yellow
  { 0, 255, 255 },    // Cyan
  { 255, 0, 255 },    // Magenta
  { 255, 255, 255 },  // White
};
int colorArrSize = sizeof(colors) / sizeof(colors[0]);
int brightness = 50;
int8_t colorIdx = 0;

void setupBlade() {
  strip.begin();
  strip.setBrightness(brightness);
  uint8_t off[] = { 0, 0, 0 };
  setSaberToColor(off);
}

void enableSaber() {
  for (int i = 0; i <= NUMPIXELS/2; i++) {
    uint8_t* color = colors[colorIdx];
    strip.setPixelColor(i, strip.Color(color[0], color[1], color[2]));
    strip.setPixelColor(NUMPIXELS-i,strip.Color(color[0],color[1],color[2]));
    if (i % LIGHTING_STEPS == 0) strip.show();
  }
  strip.show();
}

void disableSaber() {
  for (int i = NUMPIXELS/2; i >= 0; i--) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.setPixelColor(NUMPIXELS-i,strip.Color(0,0,0));
    if (i % LIGHTING_STEPS == 0) strip.show();
  }
  strip.show();
}

void setSaberToColor(uint8_t color[3]) {
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(color[0], color[1], color[2]));
  }
  strip.show();
}

void changeColors() {
  colorIdx = (colorIdx + 1) % colorArrSize;
  setSaberToColor(colors[colorIdx]);
}

void setRainbowBlade() {
  int nextColor = (colorIdx + 1) % colorArrSize;
  for (int step = 0; step <= FADE_STEPS; step++) {
    float t = (float)step / FADE_STEPS;
    uint8_t r = lerp(colors[colorIdx][0], colors[nextColor][0], t);
    uint8_t g = lerp(colors[colorIdx][1], colors[nextColor][1], t);
    uint8_t b = lerp(colors[colorIdx][2], colors[nextColor][2], t);
    for (int i = 0; i < NUMPIXELS; i++) {
      strip.setPixelColor(i, strip.Color(r, g, b));
    }
    strip.show();
  }
  colorIdx = nextColor;
}

uint8_t lerp(uint8_t a, uint8_t b, float t) {
  return a + (b - a) * t;
}
