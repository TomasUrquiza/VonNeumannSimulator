# Von Neumann Simulator

Simulador de CPU basado en la arquitectura de Von Neumann, escrito en C++.

## Set de Instrucciones (OpCodes de 3 dígitos)
* `1XX`: ADD (Suma el valor de la memoria XX al acumulador)
* `2XX`: SUB (Resta el valor de la memoria XX al acumulador)
* `3XX`: STORE (Guarda el acumulador en la memoria XX)
* `5XX`: LOAD (Carga el valor de la memoria XX al acumulador)
* `901`: INPUT (Pide un valor por consola y lo guarda en el acumulador)
* `902`: OUTPUT (Imprime el valor actual del acumulador)
* `000`: HALT (Detiene la ejecución)
