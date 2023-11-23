#include <stdio.h>
#include "PilhaC.h"

int main(void) {
    Pilha P = pilha(100);
    empilha(8, P);

    while (topo(P) > 0) {
        empilha(topo(P) / 2, P);
    }

    while (!vaziap(P)) {
        printf("%f\n", desempilha(P));
    }

    return 0;
}

/* Considerando a estrutura básica de uma pilha
o resultado seria o desempilhamento do 8/2 em cada loop, ate que o P seja menor ou igual a 0
retornando assim os elementos desempilhados do 0 ate o 8*/