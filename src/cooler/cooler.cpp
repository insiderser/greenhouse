#include "Arduino.h"
#include "cooler.h"

namespace cooler {

    void initialize() {
        pinMode(PIN, OUTPUT);
    }

    void start_cooling() {
        digitalWrite(PIN, HIGH);
    }

    void stop_cooling() {
        digitalWrite(PIN, LOW);
    }

}