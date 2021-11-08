#include <cmath>
#include <iostream>
/*
funcion de la fuerza
funcion de la velocidad final
funcion de integracion trapezoide
funcion de integracion simpson 
diferencia porcentual de cada metodo
*/
using fptr = double(double);
using hptr = double(double, double, int);
double fun (double x);
double work (double x);
double interval (double a, double b, int n);
double trapezoid (double a, double b, int N, hptr H, fptr f);
double simpson (double a, double b, int N, hptr H, fptr f);
template <typename typealg>
double velocity (double a, double b, int N, double m, hptr H, fptr f, typealg alg);

int main (int argc, char **argv)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  const double XMIN = std::atof(argv[1]);
  const double XMAX = std::atof(argv[2]);
  const int N1 = std::atof(argv[3]);
  const int N2 = std::atof(argv[4]);
  const double m = 1.25;
  const double exact = std::sqrt((2*work(XMAX)/m) - (2*work(XMIN)/m)); // Velocidad final

  std::cout << N1 << "\t" << 100*std::fabs(1 - velocity(XMIN, XMAX, N1, m, interval, fun, trapezoid)/exact) << "\t"
            << 100*std::fabs(1 - velocity(XMIN, XMAX, N1, m, interval, fun, simpson)/exact) << "\n";

  std::cout << N2 << "\t" << 100*std::fabs(1 - velocity(XMIN, XMAX, N2, m, interval, fun, trapezoid)/exact) << "\t"
            << 100*std::fabs(1 - velocity(XMIN, XMAX, N2, m, interval, fun, simpson)/exact) << "\n";

  return 0;
}

double fun (double x)
{
  return 2* x * std::sin(x);
}

double work (double x)
{
  return (-2*x*std::cos(x))+(2*std::sin(x));
}

double interval (double a, double b, int n)
{
  return (b-a)/n;
}

double trapezoid(double a, double b, int N, hptr H, fptr f)
{
    const double h = H(a, b, N);
    double result = 0.0;
    const int n = std::floor((b-a)/h); 

    for(int ii = 1; ii <= n-1; ii++){
        double xi = a + ii*h; 
        result += f(xi);
    }
    result += 0.5*(f(a) + f(b));
    result *= h;

    return result;
}

double simpson (double a, double b, int N, hptr H, fptr f)
{
  const double h = H(a, b, N);
  const int n = std::floor((b-a)/h);
  double integ = f(a) + f(b);
  double sum = 0;

  for (int ii = 1; ii <= (n/2)-1; ii++){
    double xi = a + 2*ii*h;
    sum += f(xi);
  }
  integ += 2*sum;
  sum = 0;

  for (int ii = 1; ii <= (n/2); ii++){
    double xi = a + ((2*ii)-1)*h;
    sum += f(xi);
  }
  integ += 4*sum;
  
  return (h/3)*integ;
}

template <typename typealg>
double velocity (double a, double b, int N, double m, hptr H, fptr f, typealg alg)
{
  return std::sqrt(2* alg(a, b, N, H, f)/m);
}

