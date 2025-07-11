#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <cstdint> 

class utility {
    public:
        void engage_left_motors(int32_t value, int32_t multiplier);
        void engage_right_motors(int32_t value, int32_t multiplier);
};

#endif // _UTILS_HPP_    