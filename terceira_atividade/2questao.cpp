#include <iostream>

class No {
public:
    int elemento;
    No* proximo;

    No(int valor) : elemento(valor), proximo(nullptr) {}
};

class FilaDuasPilhas {
private:
    No* topoEntrada;
    No* topoSaida;

public:
    FilaDuasPilhas() : topoEntrada(nullptr), topoSaida(nullptr) {}

    void Enfileirar(int elemento) {
        No* novo = new No(elemento);
        if (novo) {
            if (!topoSaida) {
                // Se a pilha de saída estiver vazia, transfere elementos da pilha de entrada para a de saída
                while (topoEntrada) {
                    No* temp = topoEntrada;
                    topoEntrada = topoEntrada->proximo;

                    temp->proximo = topoSaida;
                    topoSaida = temp;
                }
            }

            novo->proximo = topoEntrada;
            topoEntrada = novo;
        } else {
            std::cout << "Erro ao alocar memória\n";
        }
    }

    int Desenfileirar() {
        if (!topoEntrada && !topoSaida) {
            // Ambas as pilhas estão vazias, a fila está vazia
            std::cout << "Erro: A fila está vazia\n";
            return -1; // Valor padrão para indicar fila vazia
        }

        if (!topoSaida) {
            // Transfere elementos da pilha de entrada para a de saída
            while (topoEntrada) {
                No* temp = topoEntrada;
                topoEntrada = topoEntrada->proximo;

                temp->proximo = topoSaida;
                topoSaida = temp;
            }
        }

        // Desenfileira da pilha de saída
        No* remover = topoSaida;
        topoSaida = topoSaida->proximo;
        int elementoDesenfileirado = remover->elemento;
        delete remover;

        return elementoDesenfileirado;
    }

    bool FilaVazia() const {
        return !topoEntrada && !topoSaida;
    }
};

int main() {
    FilaDuasPilhas fila;

    // Enfileirar alguns elementos
    fila.Enfileirar(1);
    fila.Enfileirar(2);
    fila.Enfileirar(3);

    // Desenfileirar e imprimir elementos
    std::cout << "Elemento desenfileirado: " << fila.Desenfileirar() << std::endl;
    std::cout << "Elemento desenfileirado: " << fila.Desenfileirar() << std::endl;

    // Enfileirar mais elementos
    fila.Enfileirar(4);
    fila.Enfileirar(5);

    // Desenfileirar e imprimir elementos restantes
    while (!fila.FilaVazia()) {
        std::cout << "Elemento desenfileirado: " << fila.Desenfileirar() << std::endl;
    }

    return 0;
}



/*
Classe No: Representa um nó que contém um elemento inteiro e um ponteiro para o próximo nó.

Classe Pilha:

Método Empilhar: Adiciona um elemento no topo da pilha.
Método Desempilhar: Remove o elemento do topo da pilha.
Método PilhaVazia: Verifica se a pilha está vazia.
Método Topo: Retorna o elemento no topo da pilha sem removê-lo.
Classe FilaDuasPilhas:

Possui duas instâncias da classe Pilha chamadas entrada e saida.
Método Enfileirar: Utiliza a operação de empilhar da pilha de entrada para adicionar elementos à fila.
Método Desenfileirar:
Se a pilha de saída estiver vazia, transfere todos os elementos da pilha de entrada para a pilha de saída.
Utiliza a operação de desempilhar da pilha de saída para remover elementos da fila.
Método FilaVazia: Verifica se ambas as pilhas estão vazias, indicando que a fila está vazia.
Função main:

Cria uma instância da classe FilaDuasPilhas chamada fila.
Enfileira alguns elementos, desenfileira e imprime elementos, enfileira mais elementos e desenfileira o restante.
A lógica principal está na transferência de elementos da pilha de entrada para a pilha de saída quando necessário, 
garantindo que os elementos sejam desenfileirados na ordem correta. O uso de duas pilhas permite simular o comportamento de uma fila
, onde o primeiro elemento a entrar é o primeiro a sair (FIFO).
*/