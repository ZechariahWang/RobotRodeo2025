#include "DriverControl/vision.hpp"
#include "Globals/globals.hpp"
#include "pros/llemu.hpp"
#include "pros/ai_vision.hpp"

#define EXAMPLE_SIG 1

std::string visionData() {
    std::string data = "";
    auto objects = aivision.get_all_objects();
    int line = 2;
    for (const auto &object : objects) {
        if (pros::AIVision::is_type(object, pros::AivisionDetectType::color)) {
            data += "Color ID: " + std::to_string(object.id) + "\n";
            data += "X: " + std::to_string(object.object.color.xoffset) + " Y: " + std::to_string(object.object.color.yoffset) + "\n";
            data += "Size: " + std::to_string(object.object.color.width) + "x" + std::to_string(object.object.color.height) + "\n";
            data += "Angle: " + std::to_string(object.object.color.angle) + "\n\n";
        }
        
        for (int i = line; i < 8; i++) {
            pros::lcd::print(i, "");
        }
    }

    return data;
}

bool is_tracking = false;
void track_vision() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) is_tracking = !is_tracking;

    if (is_tracking) {
        aivision.reset();
        aivision.enable_detection_types(pros::AivisionModeType::colors);
        pros::AIVision::Color color = {.id = 1, .red = 180, .green = 3, .blue = 50, .hue_range = 21, .saturation_range = 1};
        pros::AIVision::Color color2 = {.id = 2, .red = 242, .green = 94, .blue = 86, .hue_range = 10, .saturation_range = 0.51};
        pros::AIVision::Color color3 = {.id = 3, .red = 255, .green = 0, .blue = 0, .hue_range = 10, .saturation_range = 0.51};
        aivision.set_color(color);
        aivision.set_color(color2);
        aivision.set_color(color3);
        
        pros::lcd::initialize();
        pros::lcd::print(0, "Vision Tracking Started");
        
        auto objects = aivision.get_all_objects();
        pros::lcd::print(1, "Objects found: %d", (int)objects.size());
        
        int line = 2;
        for (auto &object : objects) {
            if (pros::AIVision::is_type(object, pros::AivisionDetectType::color)) {
                pros::lcd::print(line++, "Color ID: %d", object.id);
                pros::lcd::print(line++, "X: %d Y: %d", object.object.color.xoffset, object.object.color.yoffset);
                pros::lcd::print(line++, "Size: %dx%d", object.object.color.width, object.object.color.height);
                pros::lcd::print(line++, "Angle: %d", object.object.color.angle);
                
                if (line > 7) break;
            }
            
            // Clear remaining lines if fewer objects
            for (int i = line; i < 8; i++) {
                pros::lcd::print(i, "");
            }
            
            pros::delay(100);
        }
    } else {
        pros::lcd::print(0, "Vision Tracking Stopped");
    }
}