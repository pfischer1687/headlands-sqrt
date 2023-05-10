#include "UnitTest.h"

UnitTest::UnitTest(const char *tstr)
{
    init(tstr);
}

void UnitTest::init(const char *tstr)
{
    _tstr = tstr;
    _pass_count = _fail_count = 0;
}

void UnitTest::test(const char *description, const int flag)
{
    const char *pf = nullptr;
    if (flag)
    {
        pf = _pstr;
        ++_pass_count;
    }
    else
    {
        pf = _fstr;
        ++_fail_count;
    }
    if (_summary_flag)
        std::cout << _tstr << ": " << description << " -> " << pf << "\n";
}

void UnitTest::report() const
{
    std::cout << "\n"
              << _tstr << ": pass: " << pass_count() << ", fail: " << fail_count() << "\n";
}
