#include <iostream>
#include <cmath>
#include <cstdlib>

double f(double x);
template <class fptr>
double bisection(double xl, double xu, fptr fun, double eps, int & niter); //SI quiero que una variable que llamo dentro de la funcion cambie por fuera de esta
// Entonces no solo tengo que asignarle un valor sino en la funcion sino llamarla con su direccion de memoria, para esto se usa el &, para llamar a una variable por referencia 

int main(int argc, char **argv)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  
  const double XL = std::atof(argv[1]);
  const double XU = std::atof(argv[2]);
  const double EPS = std::atof(argv[3]);
  int counter = 0;
  std::cout << bisection(XL, XU, f, EPS, counter) << std::endl;
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
  double xr = 0;
  int iter = 1; //COntador para guardar el numero de iteraciones
  for( ;  ; ) { // while(true)
    xr = (xl + xu)/2; // bisection
    // encontre la raiz?
    if (std::fabs(fun(xr)) <= eps) break;
    // actualizar los limites
    iter++;
    if (fun(xr)*fun(xl) < 0) {
      xu = xr;
    } else {
      xl = xr;
    }
  }
  niter = iter; //Le asignamos el valor a la variable que llamamos de niter
  return xr;
}