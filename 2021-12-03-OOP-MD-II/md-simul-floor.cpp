#include "md-simul.h"

void initial_conditions(Particle & body)
{
  body.Ry = 1.6598;
  body.Vx = 0.23698;

  body.rad = 0.235;
  body.mass = 0.29698;
}

void compute_force(Particle & body)
{
  // reset force
  body.Fx = body.Fy = body.Fz = 0.0;

  // reset potential energy
  body.Ep = 0.0;

  // gravitational force
  body.Fy += body.mass*G;

  // force with ground
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Fy += K*delta;
    body.Ep += K*delta*delta/2;
  }

  // force with right wall
  delta = body.Rx + body.rad - LR;
  if (delta > 0) {
    body.Fx -= K*delta; 
    body.Ep += K*delta*delta/2;
  }

  // force with left wall
  delta = LL - body.Rx + body.rad;
  if (delta > 0) {
    body.Fx += K*delta; //Rebote en direccion positiva
    body.Ep += K*delta*delta/2;
  }
}

void compute_energy(Particle & body)
{
  // velocity norm
  double V_norm = std::sqrt((body.Vx*body.Vx) + (body.Vy*body.Vy));

  // reset energy
  body.E = 0.0;

  // kinetic energy
  body.Ek = body.mass*V_norm*V_norm / 2;

  // potencial energy 
  body.Ep -= body.mass*body.Ry*G;

  // mechanical energy
  body.E = body.Ek + body.Ep;
}

void print(Particle & body, double time)
{
  std::cout << time << "  " 
	    << body.Rx << "  "
	    << body.Ry << "  "
	    << body.Rz << "  "
	    << body.Vx << "  "
	    << body.Vy << "  "
	    << body.Vz << "  "
	    << std::fabs(body.E - 4.84396)/4.84396 << "  " // initial mechanical energy = 4.84396
	    << "\n";
}
