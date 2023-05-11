#include <iostream>
#include "libs/square_root.h"

int main()
{
    std::cout << "square_root_stl(42) = " << square_root_stl(42) << "\n";
    std::cout << "square_root_pow(42) = " << square_root_pow(42) << "\n";
    std::cout << "square_root_log(42) = " << square_root_log(42) << "\n";
    std::cout << "square_root_log10(42) = " << square_root_log10(42) << "\n";

    try
    {
        std::cout << "square_root_newton(42) = " << square_root_newton(42) << "\n";
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << ex.what() << '\n';
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << ex.what() << '\n';
    }

    return 0;
}
