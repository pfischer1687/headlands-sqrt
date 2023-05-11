#include "square_root.h"

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
    return std::exp(std::log(num) / 2.0);
}

double square_root_log10(double num)
{
    return std::pow(10.0, std::log10(num) / 2.0);
}

double square_root_newton(double num, int max_iterations /* = 100 */, double x0 /* = 6.5*/, double tolerance /* = 1.0e-10 */, double epsilon /* = 1.0e-10 */)
{
    /* Return the square root calculated by the Newton-Raphson method */
    if (num < 0)
        return std::numeric_limits<double>::quiet_NaN();
    if (epsilon <= 0.0 || epsilon > 1.0e-7)
        throw std::invalid_argument("error: condition not met: 0 < epsilon < 1e-7");
    if (num < epsilon)
        return num;
    if (std::isinf(num))
        return std::numeric_limits<double>::infinity();
    if (max_iterations <= 0.0)
        throw std::invalid_argument("error: condition not met: 0 < max_iterations < 1e6");
    if (x0 <= 0.0)
        throw std::invalid_argument("error: condition not met: x0 > 0");
    if (tolerance <= 0.0)
        throw std::invalid_argument("error: condition not met: tolerance > 0");

    double y;
    double yprime;
    double x1;

    /* solving for the root of x**2 - num */
    auto f = [num](double x)
    {
        return std::pow(x, 2.0) - num;
    };
    auto f_prime = [](double x)
    {
        return 2.0 * x;
    };

    /* x_{n+1} = x_n - f(x_n) / f'(x_n) */
    for (int i = 0; i < max_iterations; ++i)
    {
        y = f(x0);
        yprime = f_prime(x0);

        if (std::abs(yprime) < epsilon)
            break;

        x1 = x0 - y / yprime;

        if (std::abs(x1 - x0) <= tolerance)
            return x1;

        x0 = x1;
    }

    std::string err_msg = "error: square root did not converge after " + std::to_string(max_iterations) + " iteration(s).";
    throw std::runtime_error(err_msg);
}
