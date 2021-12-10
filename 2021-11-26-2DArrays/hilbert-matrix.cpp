#include <iostream>

void fill(double *data, int nx, int ny);
double trace(const double *data, int nx, int ny);

int main(int argc, char *argv[]) {
  int nrows = 3;
  int ncols = 4;

  // get memory
  double * matrix = new double [nrows*ncols] {0.0};

  // fill the matrix
  fill(matrix, nrows, ncols);

  //Print the matrix
  std::cout << "Original matrix:\n";
  for (int ii = 0; ii < nrows; ++ii) {
    for (int jj = 0; jj < ncols; ++jj) {
      std::cout << matrix[ii*nrows + jj] <<  "  ";
    }
      std::cout << "\n";
  }

  // compute and print the trace
  std::cout << trace(matrix, nrows, ncols) << std::endl;

  // release memory
  delete [] matrix;

  return 0;
}

void fill(double *data, int nx, int ny)
{
    for (int ii = 0; ii < nx; ++ii) {
        for (int jj = 0; jj < ny; ++jj) {
            data[ii*nx + jj] = 1.0/(ii+jj+1);
        }
    }
}


double trace(const double *data, int nx, int ny) {
    double sum = 0.0;
    for(int ii = 0; ii < nx; ii++){ //Filas 
        for(int jj = 0; jj < ny; jj++){ //Columnas
            if (ii == jj){
                sum += data[ii*nx + jj];
            }
        }
    } 
return sum;
}