#ifndef Pilha_h
#define Pilha_h

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

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
            if(!this->isEmpty()){
                char nome = topo->nome;
                desempilha();
                return nome;
            }
            return topo->nome;
        }
        
        bool isEmpty(){
            return topo == NULL;
        }
        
        void desempilha(){
            topo = topo->prox;
        }

        bool pilhaCheia(){
            return topo != NULL && topo->prox != NULL;
        }
    
};


#endif