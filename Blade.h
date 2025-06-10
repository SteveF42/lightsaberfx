// Blade.h
#ifndef BLADE_H
#define BLADE_H
#include <Adafruit_NeoPixel.h>

void setupBlade();
void enableSaber();
void disableSaber();
void changeColors();
void setSaberToColor(uint8_t color[3]);
void setRainbowBlade();
uint8_t lerp(uint8_t a, uint8_t b, float t);

#endif