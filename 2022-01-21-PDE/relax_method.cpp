#include <iostream>
#include <vector>
#include <cmath>

// constants
const double DELTA = 0.05;
const double L = 1.479;
const int M = int(L/DELTA)+1; 
const int N = 1.4*M; 
const int STEPS = 200;

typedef std::vector<double> Matrix; // alias

void initial_conditions(Matrix & m);
void boundary_conditions(Matrix & m);
void evolve(Matrix & m);
void print(const Matrix & m);
void init_gnuplot(void);
void plot_gnuplot(const Matrix & m);

int main(void)
{
  Matrix data(M*N);
  initial_conditions(data);
  boundary_conditions(data);

  init_gnuplot();
  for (int istep = 0; istep < STEPS; ++istep) {
    evolve(data);
    plot_gnuplot(data);
  }

  return 0;
}
void initial_conditions(Matrix & m)
{
  for(int ii=0; ii<M; ++ii) {
    for(int jj=0; jj<N; ++jj) {
      m[ii*N + jj] = 1.0;
    }
  }
}
void boundary_conditions(Matrix & m)
{
  int ii = 0, jj = 0;

  ii = 0;
  for (jj = 0; jj < N; ++jj)
    m[ii*N + jj] = 100; 

  //placa en Lx/3
  ii = (M/3)-1;  
  for (jj = (N/4)-1; jj < 3*N/4; ++jj)
    m[ii*N + jj] = 75;  

  //placa en 2Lx/3 
  ii = (2*M/3)-1;  
  for (jj = (N/4)-1; jj < 3*N/4; ++jj)
    m[ii*N + jj] = -75;  

  ii = M-1; 
  for (jj = 0; jj < N; ++jj)
    m[ii*N + jj] = 0;

  jj = 0;
  for (ii = 1; ii < M-1; ++ii)
    m[ii*N + jj] = 0;

  jj = N-1;
  for (ii = 1; ii < M-1; ++ii)
    m[ii*N + jj] = 0;  
}

void evolve(Matrix & m)
{
  for(int ii=0; ii<M; ++ii) {
    for(int jj=0; jj<N; ++jj) {
      // check if boundary
      if(ii == 0) continue;
      if(ii == M-1) continue;
      if(jj == 0) continue;
      if(jj == N-1) continue;
      if(ii == (M/3)-1 && (N/4)-1 <= jj && jj < 3*N/4) continue;
      if(ii == (2*M/3)-1 && (N/4)-1 <= jj && jj < 3*N/4) continue;
      // evolve non boundary
      m[ii*N+jj] = (m[(ii+1)*N + jj] +
                    m[(ii-1)*N + jj] +
                    m[ii*N + jj + 1] +
                    m[ii*N + jj - 1] )/4.0;
    }
  }
}

void print(const Matrix & m)
{
  for(int ii=0; ii<M; ++ii) {
    for(int jj=0; jj<N; ++jj) {
      std::cout << ii*DELTA << " " << jj*DELTA << " " <<  m[ii*N + jj] << "\n";
    }
    std::cout << "\n";
  }  
}

//comandos gnuplot: compilar usando ./a.out | gnuplot
void init_gnuplot(void) 
{
  std::cout << "set contour " << std::endl;
  std::cout << "set terminal gif animate " << std::endl;
  std::cout << "set out 'anim.gif' " << std::endl;
}

void plot_gnuplot(const Matrix & m)
{
  std::cout << "splot '-' w pm3d " << std::endl;
  print(m);
  std::cout << "e" << std::endl;
}