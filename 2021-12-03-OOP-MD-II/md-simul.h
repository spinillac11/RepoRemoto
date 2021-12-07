#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "particle.h"
#include "integrator.h"

// This could on itws own class: Config
const double G = -9.81;
const int NSTEPS = 1000;
const double DT = 0.01;
const double K = 253.57; // we will model the floor as a spring
const double LR = 0.9; 
const double LL = -0.25; 


// function declarations
void initial_conditions(Particle & body);
void compute_force(Particle & body);
void compute_energy(Particle & body);
void print(Particle & body, double time);
