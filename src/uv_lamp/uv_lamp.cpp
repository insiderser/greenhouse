#include "Arduino.h"
#include "uv_lamp.h"

namespace uv_lamp {

    void initialize_pin() {
        pinMode(PIN_NUMBER, OUTPUT);
    }

}