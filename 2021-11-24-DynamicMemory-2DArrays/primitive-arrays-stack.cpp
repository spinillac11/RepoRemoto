#include <iostream>
#include<array>

int main(void)
{
  const int N = 1046399; //En el stack tengo un espacio de memoria limitado (Segmentation fault)
  std::array<int, N> data; //Array moderno que maneja la memoria del stack automaticamente
  //double data[N] = {0};
  //std::cout << data << std::endl; data ya no es un arreglo primitivo por lo que ya no lo puedo llamar solamente por el nombre
  std::cout << &data[0] << std::endl; // Acceder a la direccion de memoria del primer dato
  //std::cout << data[N/2] << std::endl;

  return 0;
}
