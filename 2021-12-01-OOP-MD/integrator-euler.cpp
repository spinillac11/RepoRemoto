#include "integrator.h" //llamo as funciones declaradas
void start_integration(Particle & body, const double & dt)
{
  // not needed for euler: las condiciones iniciales son nulas pro lo que no hace nada en Euler
}

void time_integration(Particle & body, const double & dt)
{
  // euler
  body.Rx = body.Rx + body.Vx*dt + body.Fx*dt*dt*0.5/body.mass; //El orden es importante
  body.Ry = body.Ry + body.Vy*dt + body.Fy*dt*dt*0.5/body.mass; //Para la posicion R necesito V(t) y no V(t+dt)
  body.Rz = body.Rz + body.Vz*dt + body.Fz*dt*dt*0.5/body.mass;
  body.Vx = body.Vx + body.Fx*dt/body.mass;
  body.Vy = body.Vy + body.Fy*dt/body.mass;
  body.Vz = body.Vz + body.Fz*dt/body.mass;
}
