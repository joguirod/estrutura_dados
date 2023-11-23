#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int igual(Lista A, Lista B) {
    if (A == NULL && B == NULL) {
        return 1; // chegou ao fim da lista sem ter retornado 0 até então, logo a lista é igual.
    }
    if (A == NULL || B == NULL || A->item != B->item) { 
        return 0; // Uma das listas chegou ao final ou os itens são diferentes.
    }
    return igual(A->prox, B->prox); // caso recursivo, onde vamos acessando o próximo item da lista até satisfazermos o primeiro caso base.
}

int main(){
    Lista I = no(1, no(2, no(3, NULL)));
    Lista J = no(1, no(2, no(3, NULL)));
    Lista K = no(1, no(3, no(2, NULL)));
    printf("%d ", igual(I, J));
    printf("%d", igual(I, K));
}