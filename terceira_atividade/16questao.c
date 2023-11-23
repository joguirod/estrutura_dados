#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int soma(Lista L){
    if ( L == NULL ) return 0; // caso base
    return L->item + soma(L->prox); // uma interação básica que começa a ser realizada após o caso base acontecer.
}

int main(){
    Lista L = no(3, no(1, no(5, no(4, NULL))));
    int total = soma(L);
    printf("> %d", total);
}