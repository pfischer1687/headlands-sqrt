#include "square_root.h"
#include <limits>

double square_root_stl(double num)
{
    return std::sqrt(num);
}

double square_root_pow(double num)
{
    return std::pow(num, 0.5);
}

double square_root_log(double num)
{
    return std::exp(std::log(num) / 2);
}

double square_root_log10(double num)
{
    return std::pow(10.0, std::log10(num) / 2.0);
}

double square_root_newton(double num)
{
    /* Return the square root calculated by the Newton-Raphson method */
    if (num == 0)
        return num;
    if (num < 0)
        return std::numeric_limits<double>::quiet_NaN();

    return sqrt(num);
}
