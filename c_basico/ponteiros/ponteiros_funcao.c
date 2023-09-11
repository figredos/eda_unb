#include <stdio.h>
#include <stdlib.h>


// Criando funções que retornam prints
void funcao_1(int a){
    printf("%d\n", a);
}

void funcao_2(int a){
    printf("%d\n", a + 1);
}

// Função principal
int main(){
    // Declarando o ponteiro de funções, que recebe dados tipo int
    void (*f_ponteiro)(int);

    // Associando o ponteiro à função 1 
    f_ponteiro = &funcao_1;
    (*f_ponteiro)(10);  // Usando a função a partir do ponteiro
    printf("%d\n", f_ponteiro); // Imprimindo a localização na memória da função

    // Associando o ponteiro à função 2 
    f_ponteiro = &funcao_2;
    (*f_ponteiro)(10);  // Usando a função a partir do ponteiro
    printf("%d\n", f_ponteiro); // Imprimindo a localização na memória da função

    // Fazendo o retorno
    return 0;
}