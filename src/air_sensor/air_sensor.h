#pragma once

namespace air_sensor {

    //todo: change temperature and humidity bounds
    const int PIN_NUMBER = 3;

    const int LOWER_TEMPERATURE_BOUND = 5;
    const int UPPER_TEMPERATUR_BOUND = 25;

    const int LOWER_HUMIDITY_BOUND = 40;
    const int UPPER_HUMIDITY_BOUND = 55;

    enum state { NOT_ENOUGH_HUMIDITY, HIGH_HUMIDITY, NORMAL_HUMIDITY, NOT_ENOUGH_TEMPERATURE,
        HIGH_TEMPERATURE, NORMAL_TEMPERATURE};

    void initialize();

    state get_air_humidity();

    state get_air_temperature();

}