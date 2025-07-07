#ifndef _GLOBALS_HPP_
#define _GLOBALS_HPP_

#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "pros/vision.hpp"
#include "Utility/utils.hpp"

extern pros::Motor left_front_motor;
extern pros::Motor left_back_motor;     
extern pros::Motor right_front_motor;
extern pros::Motor right_back_motor;

extern pros::Controller controller;
extern pros::Vision vision_sensor;

extern utility utils;

#endif // _GLOBALS_HPP_