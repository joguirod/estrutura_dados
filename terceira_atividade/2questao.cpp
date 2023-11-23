#include <iostream>
#include <string>
#include ".\Pilha.h"

using namespace std;

class FilaPorPilha{
    public:
        Pilha pilhaEntrada = Pilha();
        Pilha pilhaSaida = Pilha();

        void adicionarNaFila(char n){
            pilhaEntrada.push(n);
        }

        char removerDaFila(){
            if(!pilhaEntrada.isEmpty()){
                char atual;
                while(!pilhaEntrada.isEmpty()){
                    atual = pilhaEntrada.pop();
                    pilhaSaida.push(atual);
                }
                return pilhaSaida.pop();
            }
            return NULL;
        }
};