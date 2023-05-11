#ifndef SquareRoot_
#define SquareRoot_

#include <cmath>
#include <limits>
#include <stdexcept>
#include <string>

double square_root_stl(double num);
double square_root_pow(double num);
double square_root_log(double num);
double square_root_log10(double num);
double square_root_newton(double num, int max_iterations = 100, double x0 = 6.5, double tolerance = 1.0e-10, double epsilon = 1.0e-10);

#endif /* #ifndef SquareRoot_ */
