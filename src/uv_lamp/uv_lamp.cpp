#include "Arduino.h"
#include "uv_lamp.h"

namespace uv_lamp {

    void initialize_pin() {
        pinMode(PIN_NUMBER, OUTPUT);
    }

    void turnOn() {
        digitalWrite(PIN_NUMBER, HIGH);
    }

    void turnOff() {
        digitalWrite(PIN_NUMBER, LOW);
    }

}