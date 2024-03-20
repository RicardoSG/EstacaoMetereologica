#include <Arduino.h>

int soilPin = 15;
int umidade;
 
void soil_setup()
{
    pinMode(13, OUTPUT);
    pinMode(soilPin, INPUT);
}
void soil_loop()
{
 umidade = analogRead(soilPin);
 Serial.print(umidade);
 int Porcento = map(umidade, 1023, 0, 0, 100);
 
 Serial.print(Porcento);
 Serial.println("%");

 if(Porcento <=70){
    Serial.println("Irrigando...");
    digitalWrite(13, HIGH);
 }
 
    else{
        digitalWrite(13, LOW);
    }
 
 delay(1000);
}