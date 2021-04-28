#pragma once

namespace water_sprinkler {

    const int VALVE_PIN = 9;
    const int PUMP_PIN = 11;

    void initialize();

    void start_sprinkling();

    void stop_sprinkling();

}