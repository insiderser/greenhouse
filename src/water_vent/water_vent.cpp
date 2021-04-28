#include "Arduino.h"
#include "water_vent.h"

namespace water_vent {

    const int OPEN_PIN = 30;
    const int CLOSE_PIN = 31;

    int is_open;

    void initialize() {
        pinMode(OPEN_PIN, OUTPUT);
        pinMode(CLOSE_PIN, OUTPUT);

        // Make sure vent is always closed during initialization
        is_open = true;
        close();
    }

    void open() {
        if (!is_open) {
            digitalWrite(CLOSE_PIN, LOW);
            digitalWrite(OPEN_PIN, HIGH);
            is_open = true;
        }
    }

    void close() {
        if (is_open) {
            digitalWrite(OPEN_PIN, LOW);
            digitalWrite(CLOSE_PIN, HIGH);
            is_open = false;
        }
    }
}
