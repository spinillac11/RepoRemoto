#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <boost/numeric/odeint.hpp>

// constants
const double H = 0.05;
const double Ti = 200;

typedef std::vector<double> state_t; // alias for state type

void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);

int main(void)
{
  const double DX = 0.01; 
  const double X0 = 0.0; 
  const double XF = 10.0; 
  const double T0 = 300.0; 
  const double TF = 400.0; 
  const double Z1i = 10.0; 
  const double Z2i = 20.0; 
  const int N = 2;

  state_t y(N); // (T, z)

  // Use given inicial conditions z1i, to obtain TF1
  y[0] = T0; y[1] = Z1i; // dT/dt = Z
  boost::numeric::odeint::integrate(fderiv, y, X0, XF, DX);
  double TF1 = y[0];
  // Use given inicial conditions z2i, to obtain TF2
  y[0] = T0; y[1] = Z2i;
  boost::numeric::odeint::integrate(fderiv, y, X0, XF, DX);
  double TF2 = y[0];
  // Interpolate to gety correct zi
  double z0 = Z1i + (Z2i - Z1i)*(TF - TF1)/(TF2 -TF1);
  // Solve with correct zi
  y[0] = T0; y[1] = z0;
  boost::numeric::odeint::integrate(fderiv, y, X0, XF, DX, print);

  return 0;
}

void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << "\t" << y[1] << std::endl;
}

void fderiv(const state_t & y, state_t & dydt, double t)
{
   // vector is : y = (y0, y1) = (T, z)
  dydt[0] = y[1];
  dydt[1] = H*(y[0] - Ti);
}
