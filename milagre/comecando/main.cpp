#include <iostream>

using namespace std;

typedef struct aluno{
        char nome[81];
        int mat;
        char ender[121];
        char tel[21];
    } Aluno;

const int max_alunos = 100;
Aluno* tab[max_alunos];


void inicializa(){
    for (int i=0; i<max_alunos; i++){
        tab[i] == NULL;
    }
}

void preenche(int i){
    if (tab[i] == NULL){
        tab[i] = (Aluno*)malloc(sizeof(Aluno));
        cout << "Entre com o nome: ";
        cin >> tab[i]->nome;
        cout << "Entre com a matricula: ";
        cin >> tab[i]->mat;
        cout << "Entre com o endereço: ";
        cin >> tab[i]->ender;
        cout << "Entre com o telefone: ";
        cin >> tab[i]->tel;
    }
}

void remove(int i){
    if (tab[i] != NULL){
        free(tab[i]);
        tab[i] = NULL;
    }
}

int main()
{
    inicializa();
    preenche(0);
    remove(0);
}
