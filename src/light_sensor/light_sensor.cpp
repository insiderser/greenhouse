#include "light_sensor.h"

namespace air_sensor {

    void initialize() {
        pinMode(PIN_NUMBER, INPUT);
        digitalWrite(PIN_NUMBER, HIGH);
    }

    state get_illuminance() {
        
    }
}
