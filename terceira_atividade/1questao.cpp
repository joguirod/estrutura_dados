#include <iostream>
#include <string>
#include ".\Pilha.h"

using namespace std;

bool ehAbertura(char caractere){
   string delimitadores = "{[(";
   for(char delimitador : delimitadores){
        if(delimitador == caractere){
            return true;
        }
   }
   return false;
}

bool ehFechador(char caractere){
   string delimitadores = ")}]";
   for(char delimitador : delimitadores){
        if(delimitador == caractere){
            return true;
        }
   }
   return false;
}

bool corresponde(char caractere, char caractereCorrespondente){
    return (caractere == ')' && caractereCorrespondente == '(') 
        || (caractere == ']' && caractereCorrespondente == '[')
        || (caractere == '}' && caractereCorrespondente == '{');
}

bool verificaDelimitadores(string expressao){
    Pilha pilha = Pilha();

        for(char c : expressao){
            if(ehAbertura(c)){
                pilha.push(c);
            }
            else if(ehFechador(c)){
                if(pilha.isEmpty()){
                    return false;
                }
                if(!corresponde(c, pilha.pop())){
                    return false;
                }
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