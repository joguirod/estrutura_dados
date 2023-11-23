#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeadaChr.h"

Lista substitui(int x, int y, Lista L){
    if(!pertence(x, L)) return NULL; // x é o caractere a ser substituido, se esse caractere não estiver presente, a função retorna NULL.
    if(L->item == x) { 
        L->item = y; // o caractere do nó atual é igual ao que precisa ser substituido, logo ele é substituido pelo novo caractere.
    }
    L->prox = substitui(x, y, L->prox); // enquanto não satisfazer nenhum dos casos bases, a função chamará a si mesmo mas com o próximo nó.
    return L;
}

int main(){
    Lista L = no('b', no('o', no('b', no('o', NULL))));
    substitui('o', 'a', L);
    exibe(L);
}