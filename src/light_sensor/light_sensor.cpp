#include "light_sensor.h"

namespace light_sensor {

    void initialize() {
        pinMode(PIN_NUMBER, INPUT);
        digitalWrite(PIN_NUMBER, HIGH);
    }

    state get_illuminance() {
        int val = analogRead(PIN_NUMBER);
        if (val < LOWER_ILLUM_BOUND) {
            return NOT_ENOUGH_ILLUM;
        }
        else if (val > UPPER_ILLUM_BOUND) {
            return HIGH_ILLUM;
        }
        else return NORMAL_ILLUM;
    }
}
