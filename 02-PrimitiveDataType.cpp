/*
 * Ref:
 * - https://en.cppreference.com/w/cpp/language/types
 * - https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-places-with-cout
 */

#include <iostream>
#include <iomanip>

int main() {
    // Primitive data types is the basic data types in C++ that contain a value
    short short_dt = 32767;
    int int_dt = 2147483647;
    long long_dt = 9223372036854775807;
    char char_dt = 'C';                                // char value is enclosed by '...'          
    bool bool_dt = true;
    double double_dt = 123456789012345e-15;
    float float_dt = 1234567e-7f;                      // 'f' means that is is a float number

    std::cout << short_dt << std::endl;
    std::cout << int_dt << std::endl;
    std::cout << long_dt << std::endl;
    std::cout << char_dt << std::endl;
    std::cout << bool_dt << std::endl;

    std::cout << std::setprecision(15) << std::fixed;  // set the precision of the floating number
    std::cout << double_dt << std::endl;

    std::cout << std::setprecision(7) << std::fixed;  // set the precision of the floating number
    std::cout << float_dt << std::endl;

    return 0;
}
