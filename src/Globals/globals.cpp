#include "iostream"
#include "main.h"
#include "Utility/utils.hpp"

pros::Motor left_front_motor(1);
pros::Motor left_back_motor(2);
pros::Motor right_front_motor(3);
pros::Motor right_back_motor(4);    

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Vision vision_sensor(3);

utility utils;