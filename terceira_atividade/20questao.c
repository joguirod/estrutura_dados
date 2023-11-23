#include <stdlib.h>
#include <stdio.h>

int binary_search(int x, int v[], int n){
    int p = 0;
    int u = n - 1;
    while(p <= u){
        int m = (p+u)/2;
        if(x == v[m]) return 1;
        if(x < v[m]) u = m-1;
        else p = m + 1;
    }
    return 0;
}

int recursive_binary_search(int procurado, int vetor[], int primeiro, int ultimo){
    int meio = (primeiro + ultimo) / 2;

    if(primeiro > ultimo) return 0; // Não está no vetor

    if(vetor[meio] == procurado) return 1; // Encontrado

    if(procurado > vetor[meio]) return recursive_binary_search(procurado, vetor, meio+1, ultimo); // Se o item procurado é maior que o escolhido atualmente, logo o procurado está à direita
    
    else return recursive_binary_search(procurado, vetor, primeiro, meio-1); // Se o item procurado é menor que o escolhido atualmente, logo o procurado está à esquerda.
}