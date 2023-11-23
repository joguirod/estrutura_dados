#include <stdlib.h>
#include <stdio.h>
#include "FilaEmC.h"

int main(){
    Fila F = fila(5);
    enfileira(1, F); // FILA até aqui: 1
    enfileira(2, F); // FILA até aqui: 1, 2
    enfileira(3, F); // FILA até aqui: 1, 2, 3
    enfileira(desenfileira(F),F); // FILA até aqui: 2, 3, 1
    enfileira(desenfileira(F),F); // FILA até aqui: 3, 1, 2
    printf("%d\n", desenfileira(F)); // desinfileira(F) retornará o primeiro item da fila, logo 3.
}

// A saída esperada será 3.