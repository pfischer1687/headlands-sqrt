#include "../libs/square_root.h"
#include "UnitTest.h"
#include <iostream>
#include <cmath>

bool summary_flag = true;

int main()
{
    std::cout << "UnitTest version: " << UnitTest::version() << "\n";

    UnitTest u("UnitTest");
    u.summary(summary_flag);

    std::cout << "\nTesting square_root -----\n";

    u.test("positive int", square_root((int)42) == sqrt(42));
    u.test("positive float", square_root((float)42) == sqrt(42));
    u.test("positive double", square_root((double)42) == sqrt(42));
    u.test("positive long double", square_root((long double)42) == sqrt(42));

    u.report();

    return 0;
}
