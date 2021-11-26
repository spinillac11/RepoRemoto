#include <iostream>
// Adrees at ram memory
int main(int argc, char **argv) {
  double val = 0.987766;
  double *ptr = nullptr; // pointer. Only stores memory addresses - direccion
                         // pero no sabe de primeraso el contenido
  // Lo inicializo en nullpointer, apuntador nulo
  ptr = &val; // ptr stores x memory address, & extraemos la direccion de
              // memoria d eval y se la asigna a ptr
  // ptr = val; // error, cannot store common values
  std::cout << "val  : " << val << std::endl;
  std::cout << "&val : " << &val << std::endl;
  std::cout << "ptr  : " << ptr << std::endl; // prints val address
  std::cout << "*ptr : " << *ptr
            << std::endl; // prints val VALUE, con * apunto al valor de la
                          // dirreccion de memoria a la que apunta ptr
  std::cout << "&ptr : " << &ptr << std::endl; // prints ptr address
  std::cout << "*(ptr+0) : " << *(ptr + 0)
            << std::endl; // prints ptr address, muestra lo que esta guardadado
                          // en la posicion 0 del array
  std::cout << "*(ptr+1) : " << *(ptr + 1)
            << std::endl; // prints ptr address, realizo un salto del tamano del
                          // tipo de datos del puntero (Double --> 8 byites)
  // aqui me salgo de la memoria  porque
  std::cout << "ptr[0] : " << ptr[0]
            << std::endl; // prints ptr address, es lo mismo que *(ptr+0)

  return 0;
}
