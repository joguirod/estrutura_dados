#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    Data data;
} Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
} No;

Pessoa lerPessoa(){
    Pessoa p;

    printf("\nDigite o nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimirPessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, &p.data.dia, &p.data.mes, &p.data.ano); 
}

// Função para a opção PUSH (Empilhar ou adicionar no topo)
No* empilhar(No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = lerPessoa();
        novo->proximo = topo;
        return novo;
    } else {
        printf("\nErro ao alocar memória\n");
    }
    return NULL;
}

No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else {
        printf("\nPilha vazia\n");
    }
    return NULL;
}

void imprimirPilha(No *topo){
    printf("\n------------ PILHA ------------\n");
    while(topo){
        imprimirPessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n---------- FIM PILHA ----------\n");
}

int main(){
    No *remover, *topo = NULL;
    int opcao;
    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover != NULL){
                printf("Elemento removido com sucesso!");
                imprimirPessoa(remover->p);
            } else {
                printf("Sem nó a ser removido!");
            }
            break;
        case 3:
            imprimirPilha(topo);
            break;
        default:
            if(opcao !=0){
                printf("\nOpção inválida!\n");
            }
            break;
        }
    } while(opcao != 0);
    
    return 0;
}