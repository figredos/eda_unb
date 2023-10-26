#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *nova_celula = malloc(sizeof(celula));
    nova_celula->dado = x;
    
    if (*f == NULL) {
        nova_celula->prox = nova_celula; 
        *f = nova_celula; 
    } else {
        nova_celula->prox = (*f)->prox; 
        (*f)->prox = nova_celula; 
        *f = nova_celula; 
    }
}

int desenfileira(celula *f, int *y) {
    if (f == NULL) {
        return 0; 
    }
    
    celula *celula_removida = f->prox;
    *y = celula_removida->dado;
    
    if (f->prox == f) {
        free(f);
        f = NULL; 
    } else {
        f->prox = celula_removida->prox;
        free(celula_removida);
    }
    
    return 1;
}