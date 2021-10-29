#include <iostream>
#include <cmath>
/*
N->
Calcular el factor primo mas grande:
calcular los divisores
encontrar el mas grande
verificar si es primo
*/

long long largestprimediv (long long n); //DEclaracion: Retorno de int long long 
bool isprime (long long n); // declaracion, funcion que retorna un bool
  

int main(void)
{
    const long long N = 600851475147; //No hay que darle tantas libertades al codigo de modificar variables
    std::cout << largestprimediv(N) << std::endl;
    
    return 0;
}

//Implemento despues de la funcion main para facilidad de lectura y no llenar el inicio de funciones
long long largestprimediv (long long n) //No importa que el parametro se repita por que son variables locales
{
    long long result = 0;

    for(long long ii = 2; ii < n; ii++){ //Los divisores vienen de a pares por lo que solo necesito verificar hasta el sqrt(N) 
        if(n%ii == 0){
            //Divisores
            //std::cout << ii << std::endl;
            long long largedivisor = n/ii;
            if(isprime(largedivisor) == true){ //Llamo a la funcion e introduzco largedivisor como parametro imicial
            result = largedivisor;
            break;
            } 

        }
    }
    return result;
}

bool isprime (long long n) // Funcion: Defino los parametros que 
{
    bool isprime = true; //Supongo que es primo

            for(long long jj = 2; jj <= std::sqrt(n); jj++){ //Como los divisores van de a apares al poner la raiz optimizo el codigo
                if(n%jj == 0){ 
                    isprime = false; //Si no cumple la condicion cambio la bandera
                    break;
                }
            }
    return isprime;
}