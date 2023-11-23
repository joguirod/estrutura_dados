#include <stdio.h>
#include "ListaEncadeadaChr.h"

Lista enesimo(int n, Lista L){
    if(L == NULL | n < 1) abort();
    if(n == 1){
        return L;
    } 
    return enesimo(n-1, L->prox); 
    
}

int main(){
    Lista L = no('a', no('b', no('c', no('d', NULL))));
    int index = 3;
    printf("%c", enesimo(index, L)->item);

    /*
        utilizando esse exemplo, a função terá o seguinte comportamento:
            começara com n = 3 e L apontando para 'a';
            como não satisfará o caso base(n == 1), a recursividade acontecerá
            assim, os valores ficarão n = 2 e L apontando para 'b', já que a nova chamada tem como parâmetro o L->prox(prox item)
            novamente o caso base não foi "encotrado"
            os valores ficarão n = 1 e L apontando para 'c'
            agora o caso base estará satisfeito e a função retornará L que atualmente está apontado para 'c'.
    */
}
