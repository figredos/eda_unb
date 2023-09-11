#include <stdio.h>
#include <stdlib.h>

int main(){
    // Alocando memória para um int
    int *p = malloc(sizeof(int));
    
    // Liberando a memória ocupada pelo ponteiro
    free(p);

    // Fazendo o retorno
    return 0;
}