#include <Arduino.h>
#include "uv_lamp/uv_lamp.h"
#include "soil_moisture/soil_moisture.h"
#include "soil_temp/soil_temp.h"

void setup() {
    uv_lamp::initialize_pin();
    soil_moisture::initialize_pin();
    soil_temp::initialize_pin();
}

void loop() {
    // write your code here
}