#include "iostream"
#include "main.h"
#include "Globals/globals.hpp"

#define EXAMPLE_SIG 1

void track_vision() {
    pros::AIVision aivision(2);
    aivision.reset();
    aivision.enable_detection_types(pros::AivisionModeType::colors);
    pros::AIVision::Color color = {.id = 1, .red = 180, .green = 3, .blue = 50, .hue_range = 21, .saturation_range = 1};
    pros::AIVision::Color color2 = {.id = 2, .red = 242, .green = 94, .blue = 86, .hue_range = 10, .saturation_range = 0.51};
    aivision.set_color(color);
    aivision.set_color(color2);
    while (true) {
        auto objects = aivision.get_all_objects();
        for (auto &object : objects) {
            if (pros::AIVision::is_type(object, pros::AivisionDetectType::color)) {
                printf("color\n");
                printf("id %d\n", object.id);
                printf("%d %d %d %d %d\n", object.object.color.xoffset, object.object.color.yoffset, object.object.color.width, object.object.color.height, object.object.color.angle);
            }
        }
        pros::delay(20);
    }





    // pros::vision_signature_s_t RED_SIG =
    // pros::Vision::signature_from_utility(EXAMPLE_SIG, 8973, 11143, 10058, -2119, -1053, -1586, 5.4, 0);
    // vision_sensor.set_signature(EXAMPLE_SIG, &RED_SIG);
    // pros::vision_object_s_t obj = vision_sensor.get_by_sig(0, 1);
    // if (obj.signature == EXAMPLE_SIG) {
    //     std::cout << "Object detected with signature: " << obj.signature << std::endl;
    //     std::cout << "Coordinates: (" << obj.x_middle_coord << ", " << obj.y_middle_coord << ")" << std::endl;
    //     std::cout << "Dimensions: " << obj.width << "x" << obj.height << std::endl;
    // } else {
    //     std::cout << "No object detected with signature: " << EXAMPLE_SIG << std::endl;
    // }
    // std::cout << "Tracking vision data..." << std::endl;
}