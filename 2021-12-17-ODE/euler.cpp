// funcion para evolucion del numero de pasos f(ti, tf, dt)
// funcion para calcular las derivadas
// funcion para las condiciones iniciales y para imprimir

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

typedef std::vector<double> state_t; // alias for a double class vector

// constants OAS
const double W = 3.1237;

void initial_conditions(state_t & y); // llamo a el vector por referencia para poder asignar las condiciones iniciales
void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer);


int main(void)
{
  const double DT = 0.01;
  const double TF = 4*2*M_PI/W;
  const int N = 2;
  state_t y(N);
  initial_conditions(y);
  integrate_euler(fderiv, y, 0.0, TF, DT, print);

  return 0;
}

void initial_conditions(state_t & y)
{
  y[0] = 0.9876; // posicion inicial
  y[1] = 0.0; // velocidad inicial
}

void print(const state_t & y, double time) // llamo por referencia para no crear copias y hacer el codigo mas eficiente
{
  std::cout << time << "\t" << y[0] << "\t" << y[1] << std::endl;
}

void fderiv(const state_t & y, state_t & dydt, double t)
{
  dydt[0] = y[1]; // Velocidad
  dydt[1] = -W*W*y[0]; // Aceleracion
}

template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer)
{
  int N = y.size(); // Orden del sistema
  system_t dydt(N, 0.0);
  double time = 0;
  int nsteps = (tend - tinit)/dt;
  for(int it = 0; it < nsteps; ++it) {
	time = tinit + it*dt;
    deriv(y, dydt, time); // Actualizo las derivadas antes de modificar el y
    for (int ii = 0; ii < N; ++ii) {
      y[ii] += dt*dydt[ii];
    }
	  print(y, time);
  }
}
