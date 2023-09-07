#include <stdio.h>
#include <stdlib.h>


int main(){
    // Declarado as variáveis
    int numero = 1234;
    int *ponteiro;
    int **ponteiro_ponteiro;

    // Atribuindo valores aos ponteiros
    ponteiro = &numero;     // Conteúdo de 'ponteiro' é o valor na memória da posição de 'numero'
    ponteiro_ponteiro = &ponteiro;  // Conteúdo de 'ponteiro_ponteiro' é o valor na memória da posição de 'ponteiro'

    // Imprimindo o valor da variável e os valores que os conteúdos dos ponteiros apontam
    printf("%d\n", numero);
    printf("%d\n", *ponteiro);
    printf("%d\n", **ponteiro_ponteiro);
    
    // Imprimindo o valor na memória da posição de 'numero' e de 'ponteiro' e os valores contidos nos ponteiros
    printf("%d\n", &numero);
    printf("%d\n", ponteiro);
    printf("%d\n", &ponteiro);
    printf("%d\n", ponteiro_ponteiro);

    // Fazendo retorno
    return 0;
}