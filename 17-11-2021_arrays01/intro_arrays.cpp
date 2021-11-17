// calcular el producto punto de vectores de n-dimensiones

#include <iostream>

int main(int argc, char **argv)
{
    //primitive arrays
    int N = 10;
    double v1[N]{1.220, -0.28, 5.32}, v2[10]{-5.2373, -0.26121, -0.261}; //Arreglo homogeneo (todos tipo double) con N elemmentos
    //CUando inicializo alguno de los componentes del array los demas quedan inicializados en 0
    double dot = 0;

    for (int ii = 0; ii < N; ii++){
        dot += v1[ii]*v2[ii];
    }
    std::cout << dot << std::endl;

    return 0;
}
