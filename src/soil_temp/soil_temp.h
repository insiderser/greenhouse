/**
 * Code for
 */

#pragma once

namespace soil_temp {

    const int PIN_NUMBER = 2;

    // this level of temperature is considered OK for the current plant
    // todo: think about noise
    const int LOWER_TEMP_BOUND = 80;
    const int UPPER_TEMP_BOUND = 120;

    enum state { TOO_COLD, TOO_HOT, NORMAL };

    void initialize_pin();

    state getTemperatureLevel();

}