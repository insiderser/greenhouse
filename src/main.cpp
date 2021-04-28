#include <Arduino.h>
#include "uv_lamp/uv_lamp.h"
#include "soil_moisture/soil_moisture.h"
#include "soil_temp/soil_temp.h"
#include "water_vent/water_vent.h"
#include "water_pump/water_pump.h"
#include "cooler/cooler.h"
#include "air_sensor/air_sensor.h"
#include "light_sensor/light_sensor.h"

void air_sensor_logic();

void light_sensor_logic();

void setup() {
    uv_lamp::initialize_pin();
    soil_moisture::initialize_pin();
    soil_temp::initialize_pin();
    water_vent::initialize();
    water_pump::initialize();
    cooler::initialize();
    air_sensor::initialize();
    light_sensor::initialize();
}

void loop() {
    air_sensor_logic();
    light_sensor_logic();
    delay(10000L);
}

void air_sensor_logic() {
    // Checks air humidity and start process depending on its value
    switch (air_sensor::get_air_humidity()) {
        case air_sensor::NOT_ENOUGH_HUMIDITY:
            cooler::stop_cooling();
            water_vent::open();
            water_pump::pump_water();
            break;
        case air_sensor::HIGH_HUMIDITY:
            water_pump::stop_pumping();
            water_vent::close();
            cooler::start_cooling();
            break;
        case air_sensor::NORMAL_HUMIDITY:
            //skip
            break;
    }

    // Checks air temperature and start process depending on its value
    switch (air_sensor::get_air_temperature()) {
        case air_sensor::NOT_ENOUGH_TEMPERATURE:
            // raise temperature level (how??? we dont have heater)
            cooler::stop_cooling();
            break;
        case air_sensor::HIGH_TEMPERATURE:
            cooler::start_cooling();
            break;
        case air_sensor::NORMAL_TEMPERATURE:
            //skip
            break;
    }
}

void light_sensor_logic() {
    // Checks illuminance level and start process depending on its value
    switch (light_sensor::get_illuminance()) {
        case light_sensor::NOT_ENOUGH_ILLUM:
            uv_lamp::turnOn();
            break;
        case light_sensor::HIGH_ILLUM:
            uv_lamp::turnOff();
            break;
        case light_sensor::NORMAL_ILLUM:
            //skip
            break;
    }
}
