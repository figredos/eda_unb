#include <stdio.h>
#include <stdlib.h>

int main(){
    // Declarando as variáveis
    int numero;
    int *ponteiro;

    // Atribuido valores ao ponteiro
    ponteiro = NULL;
    ponteiro = &numero;

    // Atribuindo valor à variável 'numero'
    numero = 5;

    printf("%d\n", *ponteiro);  // *p == i (valor presente na posição da memória do valor de 'p')

    printf("%ld\n", sizeof(ponteiro));  // Buscando o tamanho da variável ponteiro

    // Fazendo retorno da função
    return 0;
}
