// g++ -g -fsanitize=address
#include <iostream>
#include <vector>

int main(void)
{
    const int N = 5;
    //double data[N] {0};
    std::vector<double> data; // NO tiene un tamano definido a priori
    data.reserve(15); //realizar reserva de memoria
    data.resize(N); // real size, cambio en el limite maximo

    std::cout << "size: " << data.size() << std::endl;
    std::cout << "capacity: " << data.capacity() << std::endl;
    std::cout << "max_size: " << data.max_size() << std::endl;

    //std::cout << data[-1] << std::endl; // detected by sanitizers address

// initialize the array with even numbers
    int ii = 0;
    for(auto & x : data){
        x = 2*ii;
        ++ii;
    }

// print the array
    for(auto x : data){
        std::cout << x << std::endl;
    }

// compute mean
    double sum = 0.0;
    for(auto x : data){
        sum += x;
    }
    std::cout << "Average = " << sum/data.size() << std::endl;

    data.push_back(200.0987); // Aumento el tamano del array size 6
    data.push_back(300.0987); //Agrego valores al final, size 5 --> size 7
    data.push_back(400.0987); // size 8 --> si excedo la capacidad esta se duplica

    return 0;
}
