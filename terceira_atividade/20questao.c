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

int recursive_binary_search(int x, int v[], int p, int u){
    int i = (p + u) / 2; // i = meio

    if(p > u) return 0; // Não está no vetor

    if(v[i] == x) return 1; // Encontrado

    if(x > v[i]) return recursive_binary_search(x, v, i+1, u); // Se o item procurado é maior que o escolhido atualmente, logo o procurado está à direita
    
    else return recursive_binary_search(x, v, p, i-1); // Se o item procurado é menor que o escolhido atualmente, logo o procurado está à esquerda.
}