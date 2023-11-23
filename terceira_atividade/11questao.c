#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "PilhaC.h"

int prioridade(char o){
    switch(o){
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return -1;
}

char *posfixa(char *e){
    static char s[256];
    int j=0;
    Pilha P = pilha(256);
    for(int i = 0; e[i]; i++){
        if(e[i]=='(') empilha('(', P);
        else if (isalpha(e[i])){
            s[j++] = e[i];
        }
        else if (strchr("+-/*", e[i])){
            while(!vaziap(P) && prioridade(topo(P)) >= prioridade(e[i])){
                s[j++] = desempilha(P);
            }
            empilha(e[i], P);
        }
        else if(e[i] == ')') {
            while(topo(P) != '('){
                s[j++] = desempilha(P);
            }
            desempilha(P);
        }
    }
    while( !vaziap(P)){
        s[j++] = desempilha(P);
    }
    s[j] = '\0';
    destroip(&P);
    return s;
}

int main(){
    char e[256];
    int expressaoValida = 0;

    while (!expressaoValida) {
        printf("> Insira a expressão infixa com letras (sem espaços): ");
        fgets(e, sizeof(e), stdin);
        e[strcspn(e, "\n")] = '\0';

        expressaoValida = 1;
        for (int i = 0; e[i]; i++) {
            if (!isalpha(e[i]) && e[i] != '+' && e[i] != '-' && e[i] != '*' && e[i] != '/' && e[i] != '(' && e[i] != ')') {
                expressaoValida = 0;
                printf("Expressão inválida. Certifique-se de que a expressão contém apenas inteiros de um dígito e operadores válidos.\n");
                break;
            }
        }
    }

    printf("=> Essa é a versão pósfixa da expressão escrita: %s\n", posfixa(e));
    return 0;
}