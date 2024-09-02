#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class Sensor {
public:
    Sensor(int pin);
    virtual ~Sensor();
    virtual int readValue() = 0; // Método virtual puro
    virtual String getType() = 0; // Método virtual puro para obtener el tipo de sensor
protected:
    int sensorPin;
};

class AnalogSensor : public Sensor {
public:
    AnalogSensor(int pin);
    virtual int readValue() override;
    virtual String getType() override { return "Analog"; }
};

class DigitalSensor : public Sensor {
public:
    DigitalSensor(int pin);
    virtual int readValue() override;
    virtual String getType() override { return "Digital"; }
};

class AnalogHumiditySensor : public AnalogSensor {
public:
    AnalogHumiditySensor(int pin, int wetSoilValue, int drySoilValue );
    int getHumidity();
    String getType() override { return "AnalogHumidity"; }

private:
    int wetValue;
    int dryValue;
};

#endif