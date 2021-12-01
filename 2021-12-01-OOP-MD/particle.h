#pragma once // avoids multiple inclusions
struct Particle
{
  double rad = 0.0;
  double mass = 0.0;
  double Rx = 0.0, Ry = 0.0, Rz = 0.0;
  double Vx = 0.0, Vy = 0.0, Vz = 0.0;
  double Fx = 0.0, Fy = 0.0, Fz = 0.0;
  // we could also add some internal functions here
  //Constructor - No retorna nada
  //Particle(); // Constructor por defecto
  //Particle(doubel m); //Constructor con argumento
  //~Particle();//Destructor
};
/*
Particle::Particle(double m){ //Indicador que el constructor pertenece a particle, no es una funcion normal
}
*/