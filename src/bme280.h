#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>


#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;
float bme_temp;
float bme_patm;
float bme_seaLevel;
float bme_hum;

void bme_setup() {
  
  bool status;

  // default settings
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  Serial.println("-- Default Test --");
  Serial.println();
}


void bme_loop() { 
  
  Serial.print("Temperature (bme) = ");
  bme_temp = bme.readTemperature();
  Serial.print(bme_temp);
  Serial.println(" *C");
  
  // Convert temperature to Fahrenheit
  /*Serial.print("Temperature = ");
  Serial.print(1.8 * bme.readTemperature() + 32);
  Serial.println(" *F");*/
  
  Serial.print("Pressure = ");
  bme_patm = bme.readPressure() / 100.0F;
  Serial.print(bme_patm);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  bme_seaLevel = bme.readAltitude(SEALEVELPRESSURE_HPA);
  Serial.print(bme_seaLevel);
  Serial.println(" m");

  Serial.print("Humidity (bme) = ");
  bme_hum = bme.readHumidity();
  Serial.print(bme_hum);
  Serial.println(" %");

  Serial.println();
}
