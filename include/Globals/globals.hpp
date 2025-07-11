#ifndef _GLOBALS_HPP_
#define _GLOBALS_HPP_

#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "pros/vision.hpp"
#include "Utility/utils.hpp"
#include "pros/ai_vision.hpp"

extern pros::Motor left_front_motor;
extern pros::Motor left_back_motor;     
extern pros::Motor right_front_motor;
extern pros::Motor right_back_motor;

extern pros::Motor left_intake; // Assuming this is a motor for the left intake
extern pros::Motor right_intake; 

extern pros::Motor left_arm;
extern pros::Motor right_arm; 

extern pros::Controller controller;
extern pros::Vision vision_sensor;
extern pros::AIVision aivision;

extern utility utils;

#endif // _GLOBALS_HPP_