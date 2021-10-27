#include <iostream>

int main (void)
{
  std::cout << ((5==5) && (3>6)) << std::endl; // Variable booleana, operador and, se tienen que cumplir las dos condiciones
  std::cout << ((5==5) || (3>6)) << std::endl; // operador OR (||), al menos una d elas dos condiciones se cumple

  int flag = (5>4) ? -1 : 32; // Operdor ternario (if basico) ? "true" : "false"
  std::cout << flag << std::endl; 

  // Operadores a nivel de bit
  int m = 2, n = 17, k = 0;
  k = m & n; // ej: 2=00010 y 17=10001 -> 2&17 = 00010&10001 = 00000 (se compara bit por bit con el operador and)
  std::cout << k << std::endl;
  k = m | n; // 2 = 00010 y 17 = 10001 -> 2 | 17 = 00010|10001 = 10011 = 19
  std::cout << k << std::endl;
  k = m << 2; // Los bits se corren n numero de veces hacia la izquierda 10 -> 1000
  std::cout << k << std::endl;
  k = m >> 2; // Los bits se corren n numero de veces hacia la derecha 10 -> 0000
  std::cout << k << std::endl;

  return 0;
}
