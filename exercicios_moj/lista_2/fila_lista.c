#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x)
{
    celula *nova_celula = malloc(sizeof(celula));
    celula *temp = malloc(sizeof(celula));
    temp = *f;
    nova_celula->dado = x;

    if(temp != NULL)
    {
        while (temp->prox != temp)
            temp = temp->prox;

        temp->prox = nova_celula;
        nova_celula->prox = *f;
    }
    else    
        *f = nova_celula;
}

int desenfileira(celula *f, int *y)
{
    celula *celula_removida = f->prox;
    *y = celula_removida->dado;

    if (f->prox == f)
        return 0;
    else
        f->prox = celula_removida->prox;

    return 1;
}