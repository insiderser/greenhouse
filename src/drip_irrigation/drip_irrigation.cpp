#include <Arduino.h>
#include "drip_irrigation.h"

namespace drip_irrigation {

    const int VALVE_PIN = 12;

    void initialize() {
        pinMode(VALVE_PIN, OUTPUT);
    }

    void start_irrigating() {
        digitalWrite(VALVE_PIN, HIGH);
    }

    void stop_irrigating() {
        digitalWrite(VALVE_PIN, LOW);
    }

}
