#include <stdio.h>
#include "FilaEmC.h"

int main(void){
    Fila F = fila(5);
    for(int i = 0; i<=3; i++) enfileira('A'+i, F); // enfileira os caracteres A B C D
    while(!vaziaf(F)) printf("%c", desenfileira(F)); // enquanto a fila não estiver vazia, o programa desenfilera o PRIMEIRO item (FIFO) da fila e o imprime na tela
    destroif(&F);
    return 0;
}

// A saída exibida será ABCD.