#include "Adafruit_MPU6050.h"
#include "swingEngine.h"
#include "audio.h"
#include "audio.h"

Adafruit_MPU6050 mpu;
unsigned long lastSwingTime = 0;
const unsigned long swingCooldown = 300;  // milliseconds
const float swingThreshold = 2.5;         // rad/s

void setupMPU() {
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 Found!");
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_184_HZ);

  delay(100);
}

void checkForSwing() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float totalGyro = sqrt(g.gyro.x * g.gyro.x + g.gyro.y * g.gyro.y + g.gyro.z * g.gyro.z);

  if (totalGyro > swingThreshold) {
    unsigned long now = millis();
    if (now - lastSwingTime > swingCooldown) {
      Serial.println("swing detected");
      playEffect(SaberState::SWING);
      lastSwingTime = now;
    }
  }
}