#include <iostream>
#include <queue>

class PilhaDuasFilas {
private:
    std::queue<int> fila1;
    std::queue<int> fila2;

public:
    void Empilhar(int elemento) {
        // Mover todos os elementos da fila1 para a fila2
        while (!fila1.empty()) {
            fila2.push(fila1.front());
            fila1.pop();
        }

        // Adicionar o novo elemento à fila1
        fila1.push(elemento);

        // Mover todos os elementos de volta para a fila1
        while (!fila2.empty()) {
            fila1.push(fila2.front());
            fila2.pop();
        }
    }

    int Desempilhar() {
        if (PilhaVazia()) {
            std::cout << "Erro: A pilha está vazia\n";
            return -1; // Valor padrão para indicar pilha vazia
        }

        int elementoDesempilhado = fila1.front();
        fila1.pop();
        return elementoDesempilhado;
    }

    bool PilhaVazia() const {
        return fila1.empty();
    }
};

int main() {
    PilhaDuasFilas pilha;

    // Empilhar alguns elementos
    pilha.Empilhar(1);
    pilha.Empilhar(2);
    pilha.Empilhar(3);

    // Desempilhar e imprimir elementos
    std::cout << "Elemento desempilhado: " << pilha.Desempilhar() << std::endl;
    std::cout << "Elemento desempilhado: " << pilha.Desempilhar() << std::endl;

    // Empilhar mais elementos
    pilha.Empilhar(4);
    pilha.Empilhar(5);

    // Desempilhar e imprimir elementos restantes
    while (!pilha.PilhaVazia()) {
        std::cout << "Elemento desempilhado: " << pilha.Desempilhar() << std::endl;
    }

    return 0;
}

/*
Classe No: Representa um nó que contém um elemento inteiro e um ponteiro para o próximo nó.
Classe PilhaDuasFilas:Possui dois ponteiros, frente e fundo, representando o início e o final da fila.
Método Empilhar: Adiciona um elemento no final da fila, simulando a operação de empilhar na pilha.
Método Desempilhar: Remove o elemento do final da fila, simulando a operação de desempilhar na pilha.
Método PilhaVazia: Verifica se a pilha está vazia.

Função main:
Cria uma instância da classe PilhaDuasFilas chamada pilha.
Empilha alguns elementos, desempilha e imprime elementos, empilha mais elementos e desempilha o restante.
A lógica principal está na manipulação dos elementos nas filas para simular as operações de empilhar e desempilhar. 
Os métodos Empilhar e Desempilhar utilizam as operações de entrar e sair da fila, respectivamente, 
garantindo que os elementos sejam manipulados na ordem correta.*/