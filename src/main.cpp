#include <Arduino.h>
#include "uv_lamp/uv_lamp.h"
#include "soil_moisture/soil_moisture.h"

void setup() {
    uv_lamp::initialize_pin();
    soil_moisture::initialize_pin();
}

void loop() {
// write your code here
}