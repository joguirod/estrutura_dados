#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct lista {
    Item item;
    struct lista* prox;
} Lista;

Lista* novo = NULL;
Lista* inicio = NULL;
Lista* ultimo = NULL;
Lista* atual = NULL;


int tamanho = 0;

Lista* inserirLetra(Item letra){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->item = letra;
    novo->prox = NULL;
}

Lista* inserir(Item letra){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->item = letra;
    novo->prox = NULL;
    return novo;
}

void inserirInicio(Item x){
    novo = inserir(x);
    if (inicio == NULL){
        inicio = novo;
        ultimo = novo;
        novo->prox = NULL;
        tamanho++;
    } else {
        novo->prox = inicio;
        ultimo = inicio;
        inicio = novo;
        tamanho++;
    }
}

void inserirFinalPercorrendo(Item x){
    atual = inicio;
    for (int i = 0; i < tamanho; i++){
        if (atual->prox == NULL){
            novo = inserir(x);
            novo->prox = NULL;
            atual->prox = novo;
            tamanho++;
        } else {
            atual = atual->prox;
        }
    }
}

void inserirFinal(Item x){
    novo = inserir(x);

    if (inicio == NULL){
        inicio = novo;
        ultimo = novo;
    } else {
        ultimo->prox = novo;
        ultimo = novo;
        tamanho++;
    }
}

void furarFila(int pos){
    atual = inicio;
    for (int i = 0; i <= pos; i++){
        if (i != pos){
            atual = atual->prox;
        } else {
            novo->prox = atual->prox;
            atual->prox = novo;
            tamanho++;
        }
    }
}

void mostrar(){
    atual = inicio;
    int contador = 1;
    while(atual != NULL){
        printf("%d Item - %d\n", contador, atual->item);
        atual = atual->prox;
        contador++;
    }
}

int main(){
    int opcao;
    char letra;
    int pos;
    do {
        printf("\n\n1 - Inserir Letra ");
      	printf("\n2 - Furar a fila ");
      	printf("\n3 - Mostrar letras ");
      	printf("\n5 - Sair ");
      	printf("\nDigite a Opcao Desejada: ");
      	scanf("%d",&opcao);

      	getchar();

      	switch(opcao) {
         	case 1:
			 	printf("Digite uma letra: ");
			 	scanf("%c", &letra);
			 	inserirLetra(letra);
				break;
         	case 2:
			 	printf("Digite uma letra: ");
			 	scanf("%c", &letra);

			 	printf("Digite a posicao: ");
				scanf("%d", &pos);

                inserirLetra(letra);
                furarFila(pos);
				break;

         	case 3:mostrar(); break;

         	case 5:break;

         	default: printf("Opcao invalida! tente de novo! ");
        }

      } while (opcao != 5);
}
