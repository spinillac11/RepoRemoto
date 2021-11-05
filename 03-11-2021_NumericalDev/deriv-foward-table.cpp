/* Variacion de h para ver como varia el error
f'(x) = lim h-> 0 (f(x+h)-f(x))/h, Suponiendo que h es igual a cero o muy pequenho existe un gran margen de error

f'(x, h) = (f(x+h)-f(x))/h + O(h), funcion de x y h en donde cuando h se aproxima mas a 0 la derivada es mas precisa

*/

#include <cmath>
#include <iostream>

double fun(double x); // Usar siempre variables double (mayor presicion) y no float
double fderiv(double x, double h);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific); 
    const double X = std::atof(argv[1]);
    for (double h = 1.0e-1; h >= 1.0e-15; h /= 10.0) { //Bucle para dividir h de 10 en 10 y ver como varia el error
        std::cout << h << "\t"
                << std::fabs(1 - fderiv(X, h)/std::cos(X)) << "\n"; //fabs: valor absoluto de un float
        // calculo el valor absoluto del error porcentual entre los dos valores: |exacto - exp|/exacto
    } 
    return 0; // segun el algoritmo el h mas optimo en este caso es 1.0e-8, antes de esto el error es matematico y despues es  
}

double fun(double x)
{
    return std::sin(x);
}

double fderiv(double x, double h)
{
    return (fun(x+h) - fun(x))/h;
}//Cuando h es demasiado pequenho el error comienza a amuentar pues practicamente fun(x+h) = fun(x)