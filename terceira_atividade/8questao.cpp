#include <iostream>

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

    No* Desempilhar() {
        if (topo) {
            No* remover = topo;
            topo = remover->proximo;
            return remover;
        } else {
            std::cout << "\tErro: a pilha está vazia\n";
            return nullptr;
        }
    }

    bool EstaVazia() const {
        return topo == nullptr;
    }
};

bool FormaPar(char f, char d) {
    switch(f) {
        case ')':
            return d == '(';
        case ']':
            return d == '[';
        case '}':
            return d == '{';
        default:
            return false;
    }
}

bool IdentificaFormacao(const std::string& expressao) {
    Pilha pilha;
    for (char caractere : expressao) {
        if (caractere == '[' || caractere == '(' || caractere == '{') {
            pilha.Empilhar(caractere);
        } else if (caractere == ']' || caractere == ')' || caractere == '}') {
            if (pilha.EstaVazia()) {
                std::cout << "\tEXPRESSAO MAL FORMADA\n";
                return false; // expressao mal formada
            }
            No* remover = pilha.Desempilhar();
            if (!FormaPar(caractere, remover->Caracter)) {
                std::cout << "\tEXPRESSAO MAL FORMADA\n";
                delete remover;
                return false; // expressao mal formada
            }
            delete remover;
        }
    }
    if (pilha.EstaVazia()) {
        std::cout << "\tEXPRESSAO BEM FORMADA\n";
        return true;
    } else {
        std::cout << "\tEXPRESSAO MAL FORMADA\n";
        return false;
    }
}

int main() {
    std::string expressao;
    std::cout << "Digite uma expressao: ";
    std::getline(std::cin, expressao);
    std::cout << "\tEXPRESSAO: " << expressao << std::endl;
    IdentificaFormacao(expressao);
    return 0;
}