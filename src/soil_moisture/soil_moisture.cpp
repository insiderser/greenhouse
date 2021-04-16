#include "Arduino.h"
#include "soil_moisture.h"

namespace soil_moisture {

    void initialize_pin() {
        pinMode(PIN_NUMBER, INPUT);
    }

    state getMoistureLevel() {
        int moisture = analogRead(PIN_NUMBER);
        if (moisture < LOWER_MOISTURE_BOUND) {
            return NOT_ENOUGH_MOISTURE;
        } else if (moisture > UPPER_MOISTURE_BOUND) {
            return TOO_MOIST;
        } else return NORMAL;
    }

}
