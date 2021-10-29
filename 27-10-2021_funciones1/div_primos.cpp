#include <iostream>
#include <cmath> // Operaciones matematicas
#include <cstdlib> // Convertir strings en integers
/*
N-> 600851475147
Calcular el factor primo mas grande:
calcular los divisores
calcular la suma de los divisores
*/

long long largestprimediv (long long n); //DEclaracion: Retorno de int long long 
bool isprime (long long n); // declaracion, funcion que retorna un bool
long long sumprimefactors (long long n);

int main(int argc, char **argv) //Introducir argumentos al programa
{
    const long long N = std::atoll(argv[1]); //N sera igual al argumento 1 introducido en la consola (El arg[0] siempre es el ./a.out)
    std::cout << largestprimediv(N) << std::endl;
    std::cout << sumprimefactors(N) << std::endl;
    
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
            if(isprime(largedivisor) == true){ //Llamo a la funcion e introduzco largedivisor como parametro inicial
            result = largedivisor;
            break;
            } 
        }
    }
    return result;
}
// Verifico que son primos
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
//Suma de factores primos
long long sumprimefactors (long long n)
{
    long long suma = 0;

    for(long long ii = 2; ii < n/2; ii++){ 
        if(n%ii == 0 && isprime(ii)){
            suma += ii;
            n /= ii; // reduzco el campo de busqueda
            /*
            Ejemplo: 105/3 = 35, 3 OK
            35/5 = 7, 5 OK
            7/7 = 1, OK, cuando llega a 1 ;a iteracion para
            */
        }
    }

    return suma;
}
