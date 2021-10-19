#include <iostream>

float x;
float y = 1.0e40; 
bool a = false;  
double z;

int main()
{
    std::cout <<"x= " << x << "\n"; 
    std::cout <<"y= " << y << "\n";
    std::cout <<"a= " << a << "\n";
    std::cout << "Direccion de z= " << &z << "\n";
    std::cout << "Tamaño de z= " << sizeof(double);
}

 /* 
 La variable float permite definir numeros decimales que no ocupen demasiado 
 espacio en la memoria, es decir que hay un limite en la cantidad de digitos 
 que se pueden almacenar con esta variable, por lo que posiblemente el numero
 1.0e40 sea demasiado grande y por defecto la consola imprime que es un numero infinito.
 */

