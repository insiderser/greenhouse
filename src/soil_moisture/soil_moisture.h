#pragma once

namespace soil_moisture {

    const int PIN_NUMBER = 1;

    // this level of moisture is considered OK for the current plant
    // todo: think about noise
    const int LOWER_MOISTURE_BOUND = 80;
    const int UPPER_MOISTURE_BOUND = 120;

    enum state { NOT_ENOUGH_MOISTURE, NORMAL, TOO_MOIST };

    void initialize_pin();

    state getMoistureLevel();

}
