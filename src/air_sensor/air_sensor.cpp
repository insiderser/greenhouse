#include "air_sensor.h"

namespace air_sensor {

    DHT sens(DHT11);

    void initialize() {
        pinMode(PIN_NUMBER, INPUT);
        digitalWrite(PIN_NUMBER, HIGH);
    }

    state_humidity get_air_humidity() {
        int hum = sens.readHumidity(PIN_NUMBER);
        if (hum <= LOWER_HUMIDITY_BOUND){
            return NOT_ENOUGH_HUMIDITY;
        }
        else if (hum >= UPPER_HUMIDITY_BOUND) {
            return HIGH_HUMIDITY;
        }
        else return NORMAL_HUMIDITY;
    }

    state_temperature get_air_temperature() {
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
