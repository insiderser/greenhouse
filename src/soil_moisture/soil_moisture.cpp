#include "Arduino.h"
#include "soil_moisture.h"

namespace soil_moisture {

    void initialize_pin() {
        pinMode(PIN_NUMBER, INPUT);
    }

    state getMoistureLevel() {
        int moisture = analogRead(PIN_NUMBER);
        if (moisture < NORMAL_MOISTURE_VALUE) {
            return NOT_ENOUGH_MOISTURE;
        } else if (moisture > NORMAL_MOISTURE_VALUE) {
            return TOO_MOIST;
        } else return NORMAL;
    }

}
