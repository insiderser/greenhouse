#include "Arduino.h"
#include "soil_temp.h"
#include "../../lib/OneWire-2.3.5/OneWire.h"

namespace soil_temp {

    OneWire sensor(PIN_NUMBER);

    void initialize_pin() {
        // Ignored
    }

    state getTemperatureLevel() {
        byte data[2];

        sensor.reset();
        sensor.write(0xCC);
        sensor.write(0x44);

        delay(1000);

        sensor.reset();
        sensor.write(0xCC);
        sensor.write(0xBE);

        data[0] = sensor.read();
        data[1] = sensor.read();

        float temperature = ((data[1] << 8) | data[0]) * 0.0625;

        if (temperature < LOWER_TEMP_BOUND) {
            return TOO_COLD;
        }
        else if (temperature > UPPER_TEMP_BOUND) {
            return TOO_HOT;
        }
        else return NORMAL;
    }

}
