#include "Arduino.h"
#include "air_sensor.h"
#include "stDHT.h"

namespace air_sensor {

    void initialize() {
        // TODO: check operability
        DHT sens(DHT11);
        pinMode(PIN_NUMBER, INPUT);
        digitalWrite(PIN_NUMBER, HIGH);
    }

    state get_air_humidity() {
        int hum = sens.readHumidity(PIN_NUMBER);
        if (hum <= LOWER_HUMIDITY_BOUND){
            return NOT_ENOUGH_HUMIDITY; 
        }
        else if (hum >= UPPER_HUMIDITY_BOUND) {
            return HIGH_HUMIDITY;
        }
        else return NORMAL_HUMIDITY;
    }

    state get_air_temperature() {
        int temp = sens.readTemperature(PIN_NUMBER);
        if (temp < LOWER_TEMPERATURE_BOUND) {
            return NOT_ENOUGH_TEMPERATURE;
        }
        else if (temp > UPPER_TEMPERATUR_BOUND) {
            return HIGH_TEMPERATURE;
        }
        else return NORMAL_TEMPERATURE;
    }

}