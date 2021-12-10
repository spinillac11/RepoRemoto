#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <cmath>

double trace(const std::vector<double> & data);

int main(int argc, char *argv[])
{
  // read command line parameters
  const int N = std::atoi(argv[1]);

  // setup random generator to fill the vector
  std::mt19937 gen(0);
  std::normal_distribution<double> dis(0.0, 1.0); // mu, sigma

  // declare and fill the array
  std::vector<double> arr(N*N);
  for (auto & x : arr) {
    x = dis(gen);
  }
  //Print the matrix
  std::cout << "Original matrix:\n";
  for (int ii = 0; ii < N; ++ii) {
    for (int jj = 0; jj < N; ++jj) {
      std::cout << arr[ii*N + jj] <<  "  ";
    }
      std::cout << "\n";
  }
  // call the pnorm function
  std::cout << trace(arr) << std::endl;

  return 0;
}
double trace(const std::vector<double> & data)
{
  double sum = 0.0;
  for(int ii = 0; ii < std::sqrt(data.size()); ii++){ //Filas 
    for(int jj = 0; jj < std::sqrt(data.size()); jj++){ //Columnas
      if (ii == jj){
        sum += data[ii*std::sqrt(data.size()) + jj];
      }
    }
  } 
  return sum;
}
