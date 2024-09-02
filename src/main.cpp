#include <Arduino.h>
#include "Sensors.h"
#include "Actuadores.h"

// Constantes globales
const int soilSensorPin = A0;
const int pumpPin = 2;
const int drySoilValue = 450;
const int wetSoilValue = 130;
const int dryThreshold = 40;
const int wetThreshold = 60;
const unsigned long wateringDuration = 10000;

// Dispositivos
AnalogHumiditySensor soilMoisture(soilSensorPin, drySoilValue, wetSoilValue);
Rele bombaAgua(pumpPin);

// VARS: Humedad del suelo
int humedad = soilMoisture.getHumidity();
bool isWatering = false;

void setup() {
  Serial.begin(9600);
}

void verPorcentaje(int valor, String nombre){
  Serial.print("Porcentaje de ");
  Serial.print(nombre);
  Serial.print(": ");
  Serial.print(valor);
  Serial.println("%");
}

void loop() {
  
  bombaAgua.apagar();
  delay(5000);
  bombaAgua.encender();
  delay(2000);
}


