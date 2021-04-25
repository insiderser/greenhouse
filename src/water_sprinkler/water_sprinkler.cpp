#include "Arduino.h"
#include "water_sprinkler.h"

namespace water_sprinkler {

    void initialize() {
        // TODO
        pinMode(PIN, OUTPUT);
    }

    void start_sprinkling() {
        digitalWrite(PIN, HIGH);
    }

    void stop_sprinkling() {
        digitalWrite(PIN, LOW);
    }

}
