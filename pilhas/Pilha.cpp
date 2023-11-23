#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

namespace PilhaSpc{

	class No{
		public:
			char nome;
			No *prox;
			No(char n){
				nome = n;
				prox = NULL;
			}
	};

	class Pilha{
		public:
			No *topo;
			
			Pilha(){
				topo = NULL;
			}
			
			void push(char n){
				No *novo = new No(n);
				novo->prox = topo;
				topo = novo;
			}
			
			char pop(){
				char nome = topo->nome;
				return nome;
			}
			
			bool isEmpty(){
				return topo == NULL;
			}
			
			void desempilha(){
				char nome = topo->nome;
				topo = topo->prox;
			}
		
	};
}
