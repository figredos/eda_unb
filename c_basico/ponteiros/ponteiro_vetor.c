#include <stdio.h>
#include <stdlib.h>


int main(){
    // Criando variáveis
    int vetor[2] = {5, 4};
    int *ponteiro;

    // Atribuindo o ponteiro ao vetor
    ponteiro = vetor;

    // Mostrando a equivalência dos valores do ponteiro e do vetor (array)
    printf("%d\n", vetor[0]);
    printf("%d\n", *ponteiro);

    printf("%d\n", vetor[1]);
    printf("%d\n", *(ponteiro + 1));

    return 0;
}