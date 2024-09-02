#ifndef ACTUADORES_H
#define ACTUADORES_H

#include <Arduino.h>

class Rele {
public:
    Rele(int pin);
    ~Rele();
    void encender();
    void apagar();
protected:
    int relePin;
};

#endif