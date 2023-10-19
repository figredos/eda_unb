#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x)
{
    if (f == NULL)
        return NULL;
    celula *nova = malloc(sizeof(celula));
    nova->prox = f->prox;
    f->prox = nova;
    f = nova;
    f->dado = x;
    return nova;
}
