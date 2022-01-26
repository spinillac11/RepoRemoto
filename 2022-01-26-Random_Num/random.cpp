#include <iostream>

//Constantes
const long a = 1664525;
const long c = 1013904223;
const long m = 4294967296;

//Funcion numeros aleatorios 
long get_random(long &current){
    current = (a*current + c) % m;
    return current; 
}

int main (int argc, char** argv){
    long seed = 1;
    for(int ii = 0; ii < 10000; ii++){
        std::cout << get_random(seed)/double(m-1) 
        << '\t' << get_random(seed)/double(m-1) 
        << '\t' << get_random(seed)/double(m-1) << std::endl;
    }
    return 0;
}