
#include "math_function.hpp"

#include <iostream>
double power(double base, int exponent)
{
    #if DEBUG_TEST
    std::cout << "DEBUG power!!!" << std::endl;
    #endif
    
    int result = base;
    int i;

    if (exponent == 0)
    {
        return 1;
    }

    for(i = 1; i < exponent; ++i)
    {
        result = result * base;
    }
    return result;
}
