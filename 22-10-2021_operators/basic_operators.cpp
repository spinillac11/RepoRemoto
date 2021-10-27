#include <iostream>

int main (void)
{

    double x = 9.7, y = -1.87;
    double z = 0;

    z = x + y;
    std::cout << z << std::endl;
    z = x - y;
    std::cout << z << std::endl;
    z = x * y;
    std::cout << z << std::endl;
    z = x / y;
    std::cout << z << std::endl;
    int m = 9 / 4; // como es una variable entera cuando lo imprima se elimina la parte decimal
    std::cout << m << std::endl;

    std::cout << 3*2-4.0/5 << std::endl; // Trunco el 4 para que localmente sea un variable double y no entera 

    std::cout << 3%3 << std::endl; // % operador de resto
    std::cout << -4%3 << std::endl;

    y += 0.9; // ES lo mismo que decir y = y + 0.9;
    // tambien se puede con -=, *=, /=.
    std::cout << y << std::endl;

    int ii = 3, jj = 0;
    jj = ++ii; //preincremento
    std::cout << jj << std::endl;
    std::cout << ii << std::endl;
    ii = 3;
    jj = ii++; // Postincremento
    std::cout << jj << std::endl;
    std::cout << ii << std::endl;

    return 0;
}

