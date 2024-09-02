#include "Sensors.h"

Sensor::Sensor(int pin) : sensorPin(pin) {
    pinMode(sensorPin, INPUT);
}

Sensor::~Sensor() {
    // Destructor
}

AnalogSensor::AnalogSensor(int pin) : Sensor(pin) {
    // Constructor específico para sensores analógicos
}

int AnalogSensor::readValue() {
    return analogRead(sensorPin); // Leer el valor analógico
}

DigitalSensor::DigitalSensor(int pin) : Sensor(pin) {
    // Constructor específico para sensores digitales
}

int DigitalSensor::readValue() {
    return digitalRead(sensorPin); // Leer el valor digital
}

AnalogHumiditySensor::AnalogHumiditySensor(int pin, int wetSoilValue, int drySoilValue)
    : AnalogSensor(pin), wetValue(wetSoilValue) ,dryValue(drySoilValue) {
    // Constructor específico para el sensor de humedad analógico
}

int AnalogHumiditySensor::getHumidity() {
    int sensorValue = readValue();
    return map(sensorValue, wetValue, dryValue, 0, 100); // Mapear el valor a un porcentaje
}