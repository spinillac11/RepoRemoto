#include <iostream>
#include <cmath>
#include <cstdlib>

double f(double x);
template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter);
template <class fptr>
double bisection_recursive(double xl, double xu, fptr fun, double eps, int & niter);

int main(int argc, char **argv)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  
  const double XL = std::atof(argv[1]);
  const double XU = std::atof(argv[2]);
  const double EPS = std::atof(argv[3]);
  int counter = 0;
  std::cout << bisection(XL, XU, f, EPS, counter) << std::endl;
  std::cout << counter << std::endl;
  counter = 1;
  std::cout << bisection_recursive(XL, XU, f, EPS, counter) << std::endl;
  std::cout << counter << std::endl;

  return 0;
}

double f(double x)
{
  return 9.81*(68.1)*(1 - std::exp(-x*10/68.1))/x - 40;
}

template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter)
{
  double xr = xl;
  int iter = 1;
  while(std::fabs(fun(xr)) > eps) {
    if (fun(xr)*fun(xl) < 0) {
      xu = xr;
    } else {
      xl = xr;
    }
    xr = (xl + xu)/2; // bisection
    iter++;
  }
  niter = iter;
  return xr;
}

template <class fptr>
double bisection_recursive(double xl, double xu, fptr fun, double eps, int & niter)
{
  double xr = (xl + xu)/2; // bisection
  if (std::fabs(fun(xr)) <= eps) {
    niter++;
    return xr;
  } else {
    if (fun(xr)*fun(xl) < 0) {
      xu = xr;
    } else {
      xl = xr;
    }
    niter++;
    return bisection_recursive(xl, xu, fun, eps, niter);
  }
}