#include <Arduino.h>

int soilPin = 15;
int umidade;
 
void soil_setup()
{
    //pinMode(13, OUTPUT);
    pinMode(soilPin, INPUT);
}
void soil_loop()
{
umidade = analogRead(soilPin);
Serial.print(umidade);
  
int porcento = map(umidade, 1023, 0, 0, 100);
 
 Serial.print(porcento);
 Serial.println("%");
 
 if(porcento <= 70){
    Serial.println("Irrigando...");
 }
    else{
         Serial.println("Parou de irrigar...");
    }
 
 delay(1000);
}