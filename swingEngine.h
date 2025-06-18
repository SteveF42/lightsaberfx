#ifndef SWINGENGINE_H
#define SWINGENGINE_H


#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

void setupMPU();
void checkForSwing();

#endif