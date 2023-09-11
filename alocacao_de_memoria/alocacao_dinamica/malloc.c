#include <stdio.h>
#include <stdlib.h>

int main(){
    // Alocando memória com malloc
    int *p = malloc(sizeof(int));   // 1 int
    char *nome = malloc(sizeof(char)*50);   // String de 50 posições
    float *f = malloc(sizeof(float)*10);    // Vetor float de 10 posições
    int *i = (int *)malloc(5*sizeof(int));  // typecast dos retornos das funções

    // Usando a memória alocada previamente
    if (f){
        f[1] = 4;
        printf("%f\n", f[1]);
    }
    
    // Criando um struct
    struct endereco{
        char rua[100];
        int numero;
    };
    
    // Alocando memória dinamicamente
    struct endereco *ponteiro = malloc(sizeof(struct endereco));

    // Usando a memória alocada previamente
    if (ponteiro){
        ponteiro->numero = 324;
    }   

    // Fazendo retorno
    return 0;
}
