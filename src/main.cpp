#include <Arduino.h>
#include <DHT_U.h>
#include "dht22.h"
#include "bme280.h"

void setup() {
  
  Serial.begin(115200);
  dht22_setup();
  bme_setup();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  dht22_loop(); 
  bme_loop();
}