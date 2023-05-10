#include <iostream>
#include "UnitTest.h"
#include "../libs/square_root.h"

bool summary_flag = false;

int main()
{
    std::cout << "UnitTest version: " << UnitTest::version() << "\n";

    UnitTest u("UnitTest");
    u.summary(summary_flag);

    std::cout << "\nTesting square_root -----\n";

    u.test("positive int", square_root((int)42) == sqrt(42));

    u.report();

    return 0;
}
