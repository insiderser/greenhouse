#include "Arduino.h"
#include "uv_lamp.h"

namespace uv_lamp {

    void initialize_pin() {
        pinMode(PIN_NUMBER, OUTPUT);
    }

    void turnOn() {
        digitalWrite(PIN_NUMBER, 255);
    }

    void turnOff() {
        digitalWrite(PIN_NUMBER, 0);
    }

}