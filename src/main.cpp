#include <Arduino.h>
#include "uv_lamp/uv_lamp.h"
#include "soil_moisture/soil_moisture.h"
#include "soil_temp/soil_temp.h"
#include "water_sprinkler/water_sprinkler.h"
#include "drip_irrigation/drip_irrigation.h"
#include "cooler/cooler.h"
#include "air_sensor/air_sensor.h"

void air_sensor_logic();
void light_sensor_logic();

void setup() {
    uv_lamp::initialize_pin();
    soil_moisture::initialize_pin();
    soil_temp::initialize_pin();
    water_sprinkler::initialize();
    drip_irrigation::initialize();
    cooler::initialize();
    air_sensor::initialize();
    light_sensor::initialize();

    // example usage
    uv_lamp::turnOn();
    water_sprinkler::start_sprinkling();
    drip_irrigation::start_irrigating();
    cooler::start_cooling();
}

void loop() {
    air_sensor_logic();
    light_sensor_logic();
}

void air_sensor_logic() {
    // Checks air humidity and start process depending on its value
    switch (air_sensor::get_air_humidity()) 
    {
    case air_sensor::NOT_ENOUGH_HUMIDITY:
            cooler::stop_cooling();
            water_sprinkler::start_sprinkling();
            break;
    case air_sensor::HIGH_HUMIDITY:
            water_sprinkler::stop_sprinkling();
            cooler::start_cooling();
            break;
    case air_sensor::NORMAL_HUMIDITY:
            //skip
            break;
    }   
    
    // Checks air temperature and start process depending on its value
    switch (air_sensor::get_air_temperature()) 
    {
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
    switch (light_sensor::get_illuminance()) 
    {
    case light_sensor::NOT_ENOUGH_ILLUMINANCE:
        uv_lamp::turnOn();
        break;
    case light_sensor::HIGH_ILLUMINANCE:
        uv_lamp::turnOff();
        break;
    case light_sensor::NORMAL_ILLUMINANCE:
        //skip
        break;
    }   
}
