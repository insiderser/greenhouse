#pragma once
#include "Arduino.h"

namespace light_sensor {

    const int PIN_NUMBER = 10;

    const int LOWER_LIGHT_BOUND = 5;
    const int UPPER_LIGHT_BOUND = 25;

    enum state { NOT_ENOUGH_ILLUMINANCE, HIGH_ILLUMINANCE, NORMAL_ILLUMINANCE};

    void initialize();
        
    state get_illuminance();
}