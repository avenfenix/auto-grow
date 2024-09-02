#include "Actuadores.h"

Rele::Rele(int pin) : relePin(pin) {
    pinMode(relePin, OUTPUT);
}

Rele::~Rele(){

}

void Rele::encender(){
    digitalWrite(relePin, HIGH);
}

void Rele::apagar(){
    digitalWrite(relePin, LOW);
}
