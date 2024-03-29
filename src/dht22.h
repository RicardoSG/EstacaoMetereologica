#include <DHT_U.h>
#include "RMaker.h"
#include "WiFi.h"
#include "WiFiProv.h"
#include <Insights.h>


//definitions to dht22 (humidity and temperature sensor)
#define DHTPIN 4     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

float hum;
float temp;
// Read temperature as Celsius (the default)

void dht22_setup() {
    
   dht.begin();
}

void dht22_loop() {

  hum = dht.readHumidity();
  temp = dht.readTemperature();


  // Check if any reads failed and exit early (to try again).
  if (isnan(hum) || isnan(temp)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(hum);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp);
  Serial.print(F("°C "));
  Serial.println("");
 
}