#include "iostream"
#include "main.h"
#include "Utility/utils.hpp"
#include "pros/ai_vision.hpp"

pros::Motor left_front_motor(-11);
pros::Motor left_back_motor(-12);
pros::Motor right_front_motor(20);
pros::Motor right_back_motor(19);    

pros::Motor left_intake(1);
pros::Motor right_intake(-10); 

pros::Motor left_arm(13);
pros::Motor right_arm(-9); 

pros::AIVision aivision(2);
pros::Vision vision_sensor(30);

pros::Controller controller(pros::E_CONTROLLER_MASTER);

utility utils;