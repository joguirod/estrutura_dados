#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
} No;

typedef struct{
    No *primeiro;
    No *ultimo;
    int tam;
}Fila;

void criarFila(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tam = 0;
}

void inserirNaFila02(Fila *fila, int num){
    No *atual, *novo = malloc(sizeof(No));
    if(novo){
        novo->dado = num;
        novo->prox = NULL;
        if(fila->primeiro == NULL){
            fila->primeiro = novo;
            fila->ultimo = novo;
        } else {
            fila->ultimo->prox = novo;
            fila->ultimo = novo;
        }
        fila->tam++;
    }
}

void inserirNaFila(No **fila, int num){
    No *atual, *novo = malloc(sizeof(No));
    if(novo){
        novo->dado = num;
        novo->prox = NULL;
        if(*fila == NULL){
            *fila = novo;
        } else {
            atual = *fila;
            while(atual->prox){
                atual = atual->prox;
            }
            atual->prox = novo;
        }
    } else {
        printf("\nErro ao alocar memória\n");
    }
}

No* removerDaFila(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->prox;
    } 
    return remover;
}

No* removerDaFila2(Fila *fila){
    No *remover = NULL;

    if(fila->primeiro){
        remover = fila->primeiro;
        fila->primeiro = remover->prox;
        fila->tam--;
    } 
    return remover;
}

void imprimir(No *fila){
    if(fila){
        printf("\n--------- FILA ---------\n");
        while(fila){
            printf("%d\n", fila->dado);
            fila = fila->prox;
        }
        printf("------- FIM FILA -------\n");
    } else {
        printf("\nNão há nenhum elemento na fila!\n");
    }

}

void imprimir2(Fila *fila){
    if(fila){
        No *atual = fila->primeiro;
        printf("\n--------- FILA ---------\n");
        while(fila){
            printf("%d\n", atual->dado);
            atual = atual->prox;
        }
        printf("------- FIM FILA -------\n");
    } else {
        printf("\nNão há nenhum elemento na fila!\n");
    }

}


int main(){
    /*
    duas operações: inserir e remover
    insere apenas no FINAL
    remoção apenas no INICIO
    */
   No *removido, *fila = NULL;
   int opcao, valor;
   do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirNaFila(&fila, valor);
                break;
            case 2:
                removido = removerDaFila(&fila);
                if(removido){
                    printf("Removido: %d\n", removido->dado);

                    free(removido);
                } else {
                    printf("\nNão há elementos na fila!\n");
                }
                break;
            case 3:
                imprimir(fila);
                break;
            default:
                if(opcao != 0){
                    printf("\nOpção inválida!\n");
                }
                break;    
        }
   } while(opcao != 0);
    return 0;
}