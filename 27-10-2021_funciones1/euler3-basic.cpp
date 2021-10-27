#include <iostream>
#include <cmath>
/*
N->
Calcular los divisores primos:
calcular los divisores
verificar si es primo

*/


int main(void)
{
    const long long N = 600851475143; //No hay que darle tantas libertades al codigo de modificar variables
    
    for(long long ii = 2; ii < N; ii++){ //Los divisores vienen de a pares por lo que solo necesito verificar hasta el sqrt(N) 
        if(N%ii == 0){
            //Divisores
            //std::cout << ii << std::endl;
            long long largedivisor = N/ii;
            bool isprime = true; //Supongo que es primo

            for(long long jj = 2; jj < largedivisor; jj++){
                if(largedivisor%jj == 0){ 
                    isprime = false; //Si no cumple la condicion cambio la bandera
                    break;
                }
            }

            if(isprime){
            std::cout << largedivisor << std::endl;
            break;
            } 

        }
    }

    return 0;
}
  
