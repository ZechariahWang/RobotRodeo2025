#include "Utility/utils.hpp"
#include "Globals/globals.hpp"

void utility::engage_left_motors(int32_t value) {
    left_front_motor.move_voltage(value * 12000 / 127);
    left_back_motor.move_voltage(value * 12000 / 127);
}

void utility::engage_right_motors(int32_t value) {
    right_front_motor.move_voltage(value * 12000 / 127);
    right_back_motor.move_voltage(value * 12000 / 127);
}