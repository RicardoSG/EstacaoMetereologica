#include <DHT_U.h>
#include "RMaker.h"
#include "WiFi.h"
#include "WiFiProv.h"
#include <SimpleTimer.h>
#include <Insights.h>


//const char *service_name = "PROV_12345";
//const char *pop = "1234567";

//static uint8_t gpio_reset = 0;
//bool wifi_connected = 0;

//SimpleTimer Timer;


//definitions to dht22 (humidity and temperature sensor)
#define DHTPIN 4     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

//static TemperatureSensor temperature("Temperature");
//static TemperatureSensor humidity("Humidity");

/*
void sysProvEvent(arduino_event_t *sys_event)
{
  switch (sys_event->event_id) {
    case ARDUINO_EVENT_PROV_START:
#if CONFIG_IDF_TARGET_ESP32
      Serial.printf("\nProvisioning Started with name \"%s\" and PoP \"%s\" on BLE\n", service_name, pop);
      printQR(service_name, pop, "ble");
#else
      Serial.printf("\nProvisioning Started with name \"%s\" and PoP \"%s\" on SoftAP\n", service_name, pop);
      printQR(service_name, pop, "softap");
#endif
      break;
    case ARDUINO_EVENT_WIFI_STA_CONNECTED:
      Serial.printf("\nConnected to Wi-Fi!\n");
      wifi_connected = 1;
      delay(500);
      break;
    case ARDUINO_EVENT_PROV_CRED_RECV: {
        Serial.println("\nReceived Wi-Fi credentials");
        Serial.print("\tSSID : ");
        Serial.println((const char *) sys_event->event_info.prov_cred_recv.ssid);
        Serial.print("\tPassword : ");
        Serial.println((char const *) sys_event->event_info.prov_cred_recv.password);
        break;
      }
  }
}
*/

void dht22_setup() {
    
    //pinMode(gpio_reset, INPUT);
    dht.begin();

/*
  Node my_node;
  my_node = RMaker.initNode("Microcontrollerslab");

  //Add devices
  my_node.addDevice(temperature);
  my_node.addDevice(humidity);

  Serial.printf("\nStarting ESP-RainMaker\n");
  RMaker.start();

  // Timer for Sending Sensor Data
  Timer.setInterval(5000);

  WiFi.onEvent(sysProvEvent);

#if CONFIG_IDF_TARGET_ESP32
  WiFiProv.beginProvision(WIFI_PROV_SCHEME_BLE, WIFI_PROV_SCHEME_HANDLER_FREE_BTDM, WIFI_PROV_SECURITY_1, pop, service_name);
#else
  WiFiProv.beginProvision(WIFI_PROV_SCHEME_SOFTAP, WIFI_PROV_SCHEME_HANDLER_NONE, WIFI_PROV_SECURITY_1, pop, service_name);
#endif
*/  
}

void dht22_loop() {

 // if (Timer.isReady() && wifi_connected) {                    
 //   Serial.println("Sending Sensor Data");

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
 
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println("");

 // temperature.updateAndReportParam("Temperature", t);
 // humidity.updateAndReportParam("Temperature", h);
 // Timer.reset();                        
 //}

/*
  // Read GPIO0 (external button to reset device
  if (digitalRead(gpio_reset) == LOW) { //Push button pressed
    Serial.printf("Reset Button Pressed!\n");
    // Key debounce handling
    delay(100);
    int startTime = millis();
    while (digitalRead(gpio_reset) == LOW) delay(50);
    int endTime = millis();

    if ((endTime - startTime) > 10000) {
      // If key pressed for more than 10secs, reset all
      Serial.printf("Reset to factory.\n");
      wifi_connected = 0;
      RMakerFactoryReset(2);
    } else if ((endTime - startTime) > 3000) {
      Serial.printf("Reset Wi-Fi.\n");
      wifi_connected = 0;
      // If key pressed for more than 3secs, but less than 10, reset Wi-Fi
      RMakerWiFiReset(2);
    }
  }
  delay(100);
*/
}