#include <Arduino.h>
#include <DHT_U.h>
#include "dht22.h"
#include "bme280.h"
#include "rainSensor.h"

void setup() {
  
  Serial.begin(115200);
  dht22_setup();
  bme_setup();
  rainSensor_setup();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  dht22_loop(); 
  bme_loop();
  rainSensor_loop();
}