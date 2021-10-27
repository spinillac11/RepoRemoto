#include <iostream>
// Encontrar el divisor mas grande de N=600851475147, que no sea el mismo N

int main(void)
{
    long int x = 1;
    long int N = 0;
    std::cout << "Introduzca el numero: ";
    std::cin >> N;

    for (long int i = 1; i <= N/2; i++){

        if (N%i == 0){
            std::cout << i << std::endl;
            x = i;
        }
    }

    std::cout << "El divisor mas grande de " << N << " es " << x << std::endl;
    
    return 0;
}
