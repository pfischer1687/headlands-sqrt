#include "../libs/square_root.h"
#include "UnitTest.h"
#include <cmath>
#include <iostream>

bool summary_flag = true;
double tolerance = 0.000005;

int main()
{
    std::cout << "UnitTest version: " << UnitTest::version() << "\n";

    UnitTest u("UnitTest");
    u.summary(summary_flag);

    std::cout << "\nTesting square_root_stl -----\n";

    u.test("positive int", std::abs(square_root_stl(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_stl(42.1) - std::sqrt(42.1)) < tolerance);
    u.test("zero", std::abs(square_root_stl(0)) < tolerance);
    u.test("negative int", std::isnan(square_root_stl(-42)));

    std::cout << "\nTesting square_root_pow -----\n";

    u.test("positive int", std::abs(square_root_pow(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_pow(42.1) - std::sqrt(42.1)) < tolerance);
    u.test("zero", std::abs(square_root_pow(0)) < tolerance);
    u.test("negative int", std::isnan(square_root_pow(-42)));

    std::cout << "\nTesting square_root_log -----\n";

    u.test("positive int", std::abs(square_root_log(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_log(42.1) - std::sqrt(42.1)) < tolerance);
    u.test("zero", std::abs(square_root_log(0)) < tolerance);
    u.test("negative int", std::isnan(square_root_log(-42)));

    std::cout << "\nTesting square_root_log10 -----\n";

    u.test("positive int", std::abs(square_root_log10(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_log10(42.1) - std::sqrt(42.1)) < tolerance);
    u.test("zero", std::abs(square_root_log10(0)) < tolerance);
    u.test("negative int", std::isnan(square_root_log10(-42)));

    std::cout << "\nTesting square_root_newton -----\n";

    u.test("positive int", std::abs(square_root_newton(42) - std::sqrt(42)) < tolerance);
    u.test("positive double", std::abs(square_root_newton(42.1) - std::sqrt(42.1)) < tolerance);
    u.test("zero", std::abs(square_root_newton(0)) < tolerance);
    u.test("negative int", std::isnan(square_root_newton(-42)));

    u.report();

    return 0;
}
