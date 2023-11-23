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

bool ehAbertura(char caractere){
   string delimitadores = "{[(";
   for(int i = 0; i < delimitadores.length(); i++){
        if(delimitadores[i] == caractere){
            return true;
        }
   }
   return false;
}

bool ehFechador(char caractere){
   string delimitadores = "}])";
   for(int i = 0; i < delimitadores.length(); i++){
        if(delimitadores[i] == caractere){
            return true;
        }
   }
   return false;
}

bool verificaDelimitadores(string expressao){
    Pilha pilha = Pilha();

        for(int i = 0; i < expressao.length(); i++){
            if(ehAbertura(expressao[i])){
                pilha.push(expressao[i]);
            }
            else if(ehFechador(expressao[i])){
                if(pilha.isEmpty()){
                    return false;
                }
                if(expressao[i] != pilha.pop()){
                    pilha.desempilha();
                    return false;
            }
        }
    return pilha.isEmpty();
}

int main(){
    string expressao;
    cout << "> Insira uma expressão númerica";
    cin >> expressao;

    if(verificaDelimitadores(expressao)){
        cout << "Correto" << endl;
    } else {
        cout << "ERRO" << endl;
    }

    return 0;
}
