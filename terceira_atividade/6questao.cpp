#include <iostream>
#include <string>
#include <sstream>

class No {
public:
    char Caracter;
    No* proximo;

    No(char valor) : Caracter(valor), proximo(nullptr) {}
};

class Pilha {
private:
    No* topo;

public:
    Pilha() : topo(nullptr) {}

    void Empilhar(char valor) {
        No* novo = new No(valor);
        if (novo) {
            novo->proximo = topo;
            topo = novo;
        } else {
            std::cout << "\tErro ao alocar memória\n";
        }
    }

    void Desempilhar() {
        if (topo) {
            std::cout << topo->Caracter;
            No* remover = topo;
            topo = remover->proximo;
            delete remover;
        } else {
            std::cout << "\tErro: a pilha está vazia\n";
        }
    }

    bool EstaVazia() const {
        return topo == nullptr;
    }
};

int main() {
    std::string frase;
    std::cout << "Digite uma frase: ";
    std::getline(std::cin, frase);

    Pilha pilha;
    for (char c : frase) {
        if (c != ' ') {
            pilha.Empilhar(c);
        } else {
            while (!pilha.EstaVazia()) {
                pilha.Desempilhar();
            }
            std::cout << ' ';
        }
    }
    while (!pilha.EstaVazia()) {
        pilha.Desempilhar();
    }
    return 0;
}