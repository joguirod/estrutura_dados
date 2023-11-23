#include <stdio.h>
#include "PilhaC.h" // pilha de int
int main (void) {
    Pilha P = pilha (3);
    empilha (1, P) ;
    empilha (2, P) ;
    printf ("%d\n", desempilha (P)) ;
    printf ("%d\n", desempilha (P)) ;
    printf ("%d\n", desempilha (P)) ;
    return 0;
}

/*

/*considerando uma implementação básica de uma pilha
 a saída deve ser = 
 2
 1
 Erro: Pilha vazia -> a pilha só tem 2 elementos e o programa tenta desempilhar um terceiro, resultando em "pilha vazia!"
 */