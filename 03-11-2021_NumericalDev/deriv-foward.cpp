/* Drivada foward
f'(x) = lim h-> 0 (f(x+h)-f(x))/h, Suponiendo que h es igual a cero o muy pequenho existe un gran margen de error

f'(x, h) = (f(x+h)-f(x))/h + O(h), funcion de x y h en donde cuando h se aproxima mas a 0 la derivada es mas precisa

*/

#include <cmath>
#include <iostream>

double fun(double x); // Usar siempre variables double (mayor presicion) y no float
double fderiv(double x, double h);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific); //Configuracion de iostream para imprimir con presicion de 15 cifras decimales
    // e imprimir con notacion cientifica
    const double X = 2.7;
    const double H = 1.0e-7;
    std::cout << X << "\t" << H << "\t" // \t: tabulador para separar uniformente los resultados
              << fderiv(X, H) << "\t"
              << std::cos(X) << "\n"; //Para llamar funciones
    return 0;
}

double fun(double x)
{
    return std::sin(x);
}

double fderiv(double x, double h)
{
    return (fun(x+h) - fun(x))/h;
}