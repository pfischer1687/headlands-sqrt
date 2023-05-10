#ifndef UnitTest_
#define UnitTest_

#include <iostream>

#define UnitTest_VERSION "1.0.0"

constexpr const char *_pstr = "pass";
constexpr const char *_fstr = "fail";

class UnitTest
{
    const char *_tstr = nullptr;

    unsigned long int _pass_count = 0;
    unsigned long int _fail_count = 0;
    bool _summary_flag = false;

    UnitTest(UnitTest &);
    UnitTest operator=(UnitTest &);
    UnitTest() {}

public:
    UnitTest(const char *);
    void init(const char *);
    bool summary(bool flag) { return _summary_flag = flag; }
    bool summary() { return _summary_flag; }
    unsigned long int pass_count() const { return _pass_count; }
    unsigned long int fail_count() const { return _fail_count; }
    static const char *version() { return UnitTest_VERSION; }
    void test(const char *description, const int flag);
    void report() const;
};

#endif /* #ifndef UnitTest_ */
