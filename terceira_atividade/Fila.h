#ifndef Fila_h
#define Fila_h

#include <iostream>
#include <string>

using namespace std;

class No{
	public:
		char nome;
		No *prox;
		No(char n){
			nome = n;
			prox = NULL;
		}
};

class Fila{
	public:
		No *inicio;
		No *fim;
		
		Fila(){
			inicio = NULL;
			fim = NULL;
		}
		
		void append(char n){
			No *novo = new No(n);
			if (isEmpty()){
				inicio = novo;
				fim = novo;
			} else{
				fim->prox = novo;
				fim = novo;
			}
		}
		
		char pop(){
			if(!isEmpty()){
				No *saida = inicio;
				inicio = inicio->prox;
				return saida->nome;
			}
			return NULL;
		}
		
		bool isEmpty(){
			return (inicio == NULL);
		}

		No* getUltimo(){
			return fim;
		}

		No* getPrimeiro(){
			return inicio;
		}

};

#endif
