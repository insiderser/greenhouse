#include "Arduino.h"
#include "soil_temp.h"

namespace soil_temp {

    void initialize_pin() {
        pinMode(PIN_NUMBER, INPUT);
    }

    state getTemperatureLevel() {
        int temp = analogRead(PIN_NUMBER);
        if (temp < LOWER_TEMP_BOUND) {
            return TOO_COLD;
        } else if (temp > UPPER_TEMP_BOUND) {
            return TOO_HOT;
        } else return NORMAL;
    }

}
