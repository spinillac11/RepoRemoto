/* Template para realizar un codigo generico sin la sintaxix de fptr
f'(x) = lim h-> 0 (f(x+h)-f(x))/h, Suponiendo que h es igual a cero o muy pequenho existe un gran margen de error

f'(x, h) = (f(x+h)-f(x))/h + O(h), funcion de x y h en donde cuando h se aproxima mas a 0 la derivada es mas precisa
Como lograr que la funcion derivada acepte otor tipo de funciones y no solo sin(x)?
*/

/*
f'(x) = lim h-> 0 (f(x+h)-f(x))/h
f'(x, h) = (f(x+h)-f(x))/h + O(h)
*/

#include <cmath>
#include <iostream>

using fptr = double(double); //Tambien se podria poner como un template

double fun(double x);
double g(double x);
double forward(double x, double h, fptr f);
double central(double x, double h, fptr f);

template <typename typefun, typename typealg> //Plantillas para que el compilador genere codigo e identifique el tipo de variable
double trichardson(double x, double h, typefun f, typealg alg);//Defino un tipo de variable sin especificar cual es type para tener datos genericos

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double X = std::atof(argv[1]);

    for (double h = 1.0e-1; h >= 1.0e-15; h /= 10.0) {
        std::cout << h << "\t"
                  << std::fabs(1 - forward(X, h, fun)/std::cos(X)) << "\t"
                  << std::fabs(1 - central(X, h, fun)/std::cos(X)) << "\t"
                  << std::fabs(1 - trichardson(X, h, fun, forward)/std::cos(X)) << "\t"
                  << std::fabs(1 - trichardson(X, h, fun, central)/std::cos(X)) << "\n";
    }
    return 0;
}

double fun(double x)
{
    return std::sin(x);
}

double g(double x)
{
    return x*x;
}

double forward(double x, double h, fptr f)
{
    return (f(x+h) - f(x))/h;
}

double central(double x, double h, fptr f)
{
    return (f(x+h) - f(x-h))/(2*h);
}

template <typename typefun, typename typealg>
double trichardson(double x, double h, typefun f, typealg alg) // template de richardson
{
    double val1 = alg(x, h, f);
    double val2 = alg(x, h/2, f);
    return (4*val2 - val1)/3;
}