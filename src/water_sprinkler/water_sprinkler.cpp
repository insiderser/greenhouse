#include "Arduino.h"
#include "water_sprinkler.h"

namespace water_sprinkler {

    void initialize() {
        pinMode(PUMP_PIN, OUTPUT);
        pinMode(VALVE_PIN, OUTPUT);
    }

    void start_sprinkling() {
        digitalWrite(VALVE_PIN, HIGH);
        digitalWrite(PUMP_PIN, HIGH);
    }

    void stop_sprinkling() {
        digitalWrite(PUMP_PIN, LOW);
        digitalWrite(VALVE_PIN, LOW);
    }

}
