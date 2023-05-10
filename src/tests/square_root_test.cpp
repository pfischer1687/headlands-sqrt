#include "../libs/square_root.h"
#include "UnitTest.h"
#include <cmath>
#include <iostream>

bool summary_flag = true;

int main()
{
    std::cout << "UnitTest version: " << UnitTest::version() << "\n";

    UnitTest u("UnitTest");
    u.summary(summary_flag);

    std::cout << "\nTesting square_root -----\n";

    u.test("positive int", square_root((int)42) == sqrt((int)42));
    u.test("positive float", square_root((float)42.1) == sqrt((float)42.1));
    u.test("positive double", square_root((double)42.2) == sqrt((double)42.2));
    u.test("positive long double", square_root((long double)42.3) == sqrt((long double)42.3));
    u.test("zero", square_root(0) == sqrt(0));
    u.test("negative int", std::isnan(square_root(-42)));

    u.report();

    return 0;
}
