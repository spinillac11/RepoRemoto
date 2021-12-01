//v(t+dt/2) = v(t-dt/2) + F*dt/m --> O(dt^3)
//R(t+dt) = R(t) + v(t+dt/2)dt
#include "integrator.h"
void start_integration(Particle & body, const double & dt)
{
  body.Vx -= body.Fx*dt/(2*body.mass); // v(0 - dt/2) = v(0) - dt*f/(2*m) velocidad inicial
  body.Vy -= body.Fy*dt/(2*body.mass);
  body.Vz -= body.Fz*dt/(2*body.mass);
}

  void time_integration(Particle & body, const double & dt)
{
  // leap-frog
  body.Vx += body.Fx*dt/(body.mass);
  body.Vy += body.Fy*dt/(body.mass);
  body.Vz += body.Fz*dt/(body.mass);
  body.Rx += body.Vx*dt;
  body.Ry += body.Vy*dt;
  body.Rz += body.Vz*dt;
}
