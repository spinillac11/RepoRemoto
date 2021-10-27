#include <iostream>
// Encontrar la suma de todos los multiplos de 3 y 5 menores que 100

int main(void)
{
    int x = 1;
    int suma = 0;
    const int MMAX = 1000; // optimizo el programa para que sea mas facil introducir valores

    for (x = 1; x < MMAX; x++){ // loop for (Condicion de inicio; de final; de incremento), x++ --> x=x+1
        if ((x%3 == 0) || (x%5 == 0)){
            suma += x; // suma = suma + x
        }
    }

    std::cout << suma << std::endl;

    return 0;
}
