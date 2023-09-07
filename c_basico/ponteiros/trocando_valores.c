#include <stdio.h>
#include <stdlib.h>

// Criando a função troca, que troca os ponteiros de duas variáveis
void troca(int *ponteiro_1, int *ponteiro_2){
    int troca;  // Variável temporária

    // Realizando a troca
    troca = *ponteiro_1;
    *ponteiro_1 = *ponteiro_2;
    *ponteiro_2 = troca;
}

// Função main
int main(){
    // Declarando variáveis
    int a = 3, b = 4;

    // Usando a função
    troca(&a, &b);

    // Imprimindo os valores trocados
    printf("a: %d, b: %d", a, b);

    // Fazendo o retorno
    return 0;
}