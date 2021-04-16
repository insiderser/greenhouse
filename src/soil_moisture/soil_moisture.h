#pragma once

namespace soil_moisture {

    const int PIN_NUMBER = 1;

    // this level of moisture is considered OK for the current plant
    const int NORMAL_MOISTURE_VALUE = 100;

    enum state { NOT_ENOUGH_MOISTURE, NORMAL, TOO_MOIST };

    void initialize_pin();

    state getMoistureLevel();

}
