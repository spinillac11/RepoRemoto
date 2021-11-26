#include <iostream>

int main(int argc, char *argv[]) {
    int N = std::atoi(argv[1]);
    double * data = nullptr;
    data = new double [N]; // ask for memory en el heap para expander el numero de elementos del arreglo
    for(int ii = 0; ii < N; ++ii) {
        data[ii] = 2*ii/(2*ii + 1.0);
    }
    std::cout << data[N/2] << std::endl;

    delete [] data; // return memory, si no devolvemos la memoria puede haber una fuga de memoria

    return 0;
}
