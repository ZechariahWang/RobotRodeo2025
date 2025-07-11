#include "iostream"
#include "main.h"
#include "utility/utils.hpp"
#include <algorithm>

const u_int16_t forwardCurve       = 10;
const u_int16_t turnCurve          = 3;
const double euler                 = 2.71828;
static bool toggleRedCurve         = false; // toggle red curve
static bool turningRed             = false; // turning curve
static bool forwardRed             = false; // linear curve

int32_t joystick_accelerator(bool red, int8_t input, const double t){
    int16_t value = 0;
    // exponential formula
    if (red) { value = (std::exp(-t / 10) + std::exp((std::abs(input) - 100) / 10) * (1 - std::exp(-t / 10))) * input; } 
    else { value = std::exp(((std::abs(input) - 100) * t) / 1000) * input; }
    return value;
}

static bool standardMode = true; // true = 500, false = 1500
static bool maxOverride = false;
void dt_control() {
    int32_t rightXjoystick = (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)); // Axis 1
    int32_t rightYjoystick = (controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)); // Axis 2
    int32_t leftYjoystick  = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)); // Axis 3
    int32_t leftXjoystick  = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X)); // Axis 4
    if(abs(leftYjoystick) < 20) leftYjoystick = 0;
    if(abs(rightYjoystick) < 20) rightYjoystick = 0;

    double left;
    double right;
    double speedMultiplier;

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
        if (maxOverride) {
            maxOverride = false;
        } else {
            standardMode = !standardMode;
        }
    }
    
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        maxOverride = true;
    }

    if (maxOverride) {
        speedMultiplier = 1500.0 / 127;
    } else if (standardMode) {
        speedMultiplier = 3000.0 / 127;
    } else {
        speedMultiplier = 1500.0 / 127;
    }

    left = (leftYjoystick + rightXjoystick) * speedMultiplier;
    right = (leftYjoystick - rightXjoystick) * speedMultiplier;

    utils.engage_left_motors(left, 1000);
    utils.engage_right_motors(right, 1000);
}

void intake(int32_t &power) {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
        power += 10;
        controller.print(0, 0, "Power UP: %d", power);
    }
    
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
       power -= 10;
       controller.print(0, 0, "Power DOWN: %d", power);
    }

    if (power < 0) {
        power = 0;
    }
    if (power > 127) {
        power = 127;
    }
       
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        int32_t voltage = power * 12000 / 127;
        left_intake.move_voltage(voltage);
        right_intake.move_voltage(voltage);
        controller.print(1, 0, "L1 Voltage: %d", voltage);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        int32_t voltage = -power * 12000 / 127;
        left_intake.move_voltage(voltage);
        right_intake.move_voltage(voltage);
        controller.print(1, 0, "L2 Voltage: %d", voltage);
    } else {
        left_intake.move_voltage(0);
        right_intake.move_voltage(0);
        controller.print(1, 0, "Intake OFF");
    }
}

void arm_control(int32_t power) {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        left_arm.move_voltage(power * 12000 / 127);
        right_arm.move_voltage(power * 12000 / 127);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        left_arm.move_voltage(-power * 12000 / 127);
        right_arm.move_voltage(-power * 12000 / 127);
    } else {
        left_arm.move_voltage(0);
        right_arm.move_voltage(0);
    }
}
