#include <Arduino.h>

int analogicPin = 2;
int digitalPin = 23; 
int LED = 13; 
int chuva; 
int chuvaD;
 
 
void rainSensor_setup() {

pinMode(analogicPin, INPUT);
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);
}
 
 
void rainSensor_loop() {

chuva = analogRead(analogicPin);
//chuvaD = digitalRead(digitalPin);
Serial.println(chuva);

if(chuva >= 1600) {
    Serial.println("Sem chuva");
}
    if(chuva > 1300 && chuva < 1599) {
        Serial.println("Chuva fraca");
    }
       if(chuva > 400 && chuva < 1299) {
            Serial.println("Chuva forte");
       }
      

delay(500);
}