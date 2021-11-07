/* Variacion de h para ver como varia el error
f'(x) = lim h-> 0 (f(x+h)-f(x))/h, Suponiendo que h es igual a cero o muy pequenho existe un gran margen de error

f'(x, h) = (f(x+h)-f(x))/h + O(h), funcion de x y h en donde cuando h se aproxima mas a 0 la derivada es mas precisa
*/

#include <cmath>
#include <iostream>

using fptr = double(double);
using fptrderiv = double(double, double, fptr); // Puntero que guarda la memroria de una funcion que recibe dos duble y un fptr y retorna un double -> funciones foward y central.
double fun(double x);
double g(double x);
double forward(double x, double h, fptr f);
double central(double x, double h, fptr f);
double richardson(double x, double h, fptr f, fptrderiv alg); //Ademas de recivir la funcion tambien recibe un algoritmo para calcular la derivada y optimizarlo 

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double X = std::atof(argv[1]);

    for (double h = 1.0e-1; h >= 1.0e-15; h /= 10.0) {
        std::cout << h << "\t"
                  << std::fabs(1 - forward(X, h, fun)/std::cos(X)) << "\t"
                  << std::fabs(1 - central(X, h, fun)/std::cos(X)) << "\t"
                  << std::fabs(1 - richardson(X, h, fun, forward)/std::cos(X)) << "\t" //optimizacion de foward
                  << std::fabs(1 - richardson(X, h, fun, central)/std::cos(X)) << "\n"; //optimizacion de la central
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

double richardson(double x, double h, fptr f, fptrderiv alg) //para h grandes el erros disminuye 
{
    double val1 = alg(x, h, f);
    double val2 = alg(x, h/2, f);
    return (4*val2 - val1)/3;
}