#include <Arduino.h>
#include "uv_lamp/uv_lamp.h"
#include "soil_moisture/soil_moisture.h"
#include "soil_temp/soil_temp.h"
#include "water_sprinkler/water_sprinkler.h"
#include "drip_irrigation/drip_irrigation.h"
#include "cooler/cooler.h"
#include "air_sensor/air_sensor.h"

void setup() {
    uv_lamp::initialize_pin();
    soil_moisture::initialize_pin();
    soil_temp::initialize_pin();
    water_sprinkler::initialize();
    drip_irrigation::initialize();
    cooler::initialize();
    air_sensor::initialize();

    // example usage
    uv_lamp::turnOn();
    water_sprinkler::start_sprinkling();
    drip_irrigation::start_irrigating();
    cooler::start_cooling();
}

void loop() {
    switch (air_sensor::get_air_humidity()) 
    {
        case NOT_ENOUGH_HUMIDITY:
            water_sprinkler::start_sprinkling();
            break;
        case HIGH_HUMIDITY:
            cooler::start_cooling();
            break;
        case NORMAL_HUMIDITY:
            //skip
            break;

    }    
}
