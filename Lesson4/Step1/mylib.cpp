#include "mylib.h"

#include <cmath>
#include <limits>

namespace Mylib {

double exponentiation(double value, int exponent)
{
    double result{1.0};

    if(exponent == 0)
    {
        return result;
    }

    int temp_exp = (exponent > 0) ? exponent : -exponent;

    for(int i{0};i < temp_exp;++i)
    {
        result *= value;
    }

    if(exponent < 0)
    {
        result = 1. / result;
    }

    return result;
}

double exponentiation(double, double)
{
    double result{1.0};

    return result;
}

bool fuzzyCompare(double left, double right)
{
    bool result{false};

    double diff{std::fabs(left - right)};

    result = diff < std::numeric_limits<double>::epsilon();

    return result;
}

} // namespace Mylib
