#include "../libs/square_root.h"
#include "UnitTest.h"
#include <cmath>
#include <iostream>

bool summary_flag = false;
double tolerance = 1.0e-10;
double epsilon = 1.0e-10;

int main()
{
    std::cout << "UnitTest version: " << UnitTest::version() << "\n";

    UnitTest u("UnitTest");
    u.summary(summary_flag);

    std::cout << "\nTesting square_root_stl -----\n";

    u.test("positive int", std::abs(square_root_stl(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_stl(42.5) - std::sqrt(42.5)) < tolerance);
    u.test("zero", std::abs(square_root_stl(0)) < epsilon);
    u.test("negative int", std::isnan(square_root_stl(-42)));
    u.test("infinity", std::isinf(square_root_stl(INFINITY)));

    std::cout << "\nTesting square_root_pow -----\n";

    u.test("positive int", std::abs(square_root_pow(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_pow(42.5) - std::sqrt(42.5)) < tolerance);
    u.test("zero", std::abs(square_root_pow(0)) < epsilon);
    u.test("negative int", std::isnan(square_root_pow(-42)));
    u.test("infinity", std::isinf(square_root_pow(INFINITY)));

    std::cout << "\nTesting square_root_log -----\n";

    u.test("positive int", std::abs(square_root_log(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_log(42.5) - std::sqrt(42.5)) < tolerance);
    u.test("zero", std::abs(square_root_log(0)) < epsilon);
    u.test("negative int", std::isnan(square_root_log(-42)));
    u.test("infinity", std::isinf(square_root_log(INFINITY)));

    std::cout << "\nTesting square_root_log10 -----\n";

    u.test("positive int", std::abs(square_root_log10(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_log10(42.5) - std::sqrt(42.5)) < tolerance);
    u.test("zero", std::abs(square_root_log10(0)) < epsilon);
    u.test("negative int", std::isnan(square_root_log10(-42)));
    u.test("infinity", std::isinf(square_root_log10(INFINITY)));

    std::cout << "\nTesting square_root_newton -----\n";

    u.test("positive int", std::abs(square_root_newton(42) - std::sqrt(42)) < tolerance);
    u.test("positive small double", std::abs(square_root_newton(1.0 / 42.5) - std::sqrt(1.0 / 42.5)) < tolerance);
    u.test("positive double", std::abs(square_root_newton(84.5) - std::sqrt(84.5)) < tolerance);
    u.test("zero", std::abs(square_root_newton(0)) < epsilon);
    u.test("negative int", std::isnan(square_root_newton(-42)));
    u.test("infinity", std::isinf(square_root_newton(INFINITY)));

    std::cout << "\nTesting square_root_newton invalid argument error -----\n";

    bool inv_arg_err_test = false;
    int in_arg_err_max_iterations = -1;
    try
    {
        square_root_newton(42, in_arg_err_max_iterations);
    }
    catch (std::invalid_argument const &ex)
    {
        inv_arg_err_test = true;
    }
    u.test("invalid argument error", inv_arg_err_test);

    std::cout << "\nTesting square_root_newton runtime convergence error -----\n";

    bool conv_err_test = false;
    int conv_err_max_iterations = 1;
    try
    {
        square_root_newton(42, conv_err_max_iterations);
    }
    catch (std::runtime_error const &ex)
    {
        conv_err_test = true;
    }
    u.test("runtime convergence error", conv_err_test);

    u.report();

    return 0;
}
