#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <DHT_U.h>
#include "bme280.h"
#include "rainSensor.h"
#include "soilHumidity.h"
#include "dht22.h"

//Wifi and server configs to use MQTT
const char* ssid = "RVT_UHTRED";
const char* password = "0390sharpe";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];

//functions mqtt

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("tempHum/publisher", "hello world");
      // ... and resubscribe
      client.subscribe("tempHum/subscriber");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() {
  
  Serial.begin(115200);
  setup_wifi();
  
  dht22_setup();
  //bme_setup();
  //rainSensor_setup();
  //soil_setup();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  dht22_loop(); 
  //bme_loop();
  //rainSensor_loop();
  //soil_loop();

  snprintf (msg, MSG_BUFFER_SIZE, "Umidade: %f", hum);
  client.publish("tempHum/hum", msg); 
  snprintf (msg, MSG_BUFFER_SIZE, "Temperatura %f", temp);
  client.publish("tempHum/temp", msg);

   if (!client.connected()) {
      reconnect();
    }
  client.loop();
}

