#pragma once
#include "Arduino.h"

namespace light_sensor {

    const int PIN_NUMBER = 10;

    const int LOWER_ILLUM_BOUND = 300;
    const int UPPER_ILLUM_BOUND = 700;

    enum state { NOT_ENOUGH_ILLUM, HIGH_ILLUM, NORMAL_ILLUM};

    void initialize();
        
    state get_illuminance();
}