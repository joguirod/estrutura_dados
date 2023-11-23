#include <iostream>
#include <vector>

class Pilha {
private:
    std::vector<double> elementos;

public:
    void Empilhar(double valor) {
        elementos.push_back(valor);
    }

    double Desempilhar() {
        double topo = elementos.back();
        elementos.pop_back();
        return topo;
    }

    double Topo() const {
        return elementos.back();
    }

    bool EstaVazia() const {
        return elementos.empty();
    }
};

int main() {
    int n;
    std::cout << "Digite o número de elementos: ";
    std::cin >> n;

    Pilha A, B;
    double valor;

    std::cout << "Digite os elementos:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> valor;
        while (!A.EstaVazia() && A.Topo() < valor) {
            B.Empilhar(A.Desempilhar());
        }
        A.Empilhar(valor);
        while (!B.EstaVazia()) {
            A.Empilhar(B.Desempilhar());
        }
    }

    std::cout << "Elementos ordenados:\n";
    while (!A.EstaVazia()) {
        std::cout << A.Desempilhar() << ' ';
    }
    
    return 0;
}