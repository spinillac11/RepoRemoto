// g++ -g -fsanitize=address
#include <iostream>
#include <array>

int main(void)
{
    const int N = 10;
    //double data[N] {0};
    std::array<double, N> data{0}; //Tamano definido, hay que inicializar el arreglo
    data.fill(-1); //funcion para llenar el arrglo

    std::cout << "size: " << data.size() << std::endl;
    std::cout << "max_size: " << data.max_size() << std::endl;

    //std::cout << data[-1] << std::endl; // detected by sanitizers address

// initialize the array with even numbers
    int ii = 0;
    for(auto & x : data){
        x = 2*ii;
        ++ii;
    }

// print the array
    for(auto x : data){ //Valor de x va cambiando a medida que nos movemos en el arreglo, auto--> identifica tipo de dato
        std::cout << x << std::endl;
    }

// compute mean
    double sum = 0.0;
    for(auto x : data){
        sum += x;
    }
    std::cout << "Average = " << sum/data.size() << std::endl;
}
