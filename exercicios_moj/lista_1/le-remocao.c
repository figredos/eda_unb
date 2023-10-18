#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p == NULL || p->prox == NULL)
        return 0;

    celula *temp = p->prox;
    p->prox = temp->prox;

    return 1;
}

void remove_elemento(celula *le, int x)
{
    celula *ant = le, *atual = le->prox;
    
    while (atual != NULL && atual->dado != x)
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
        ant->prox = atual->prox;
}

void remove_todos_elementos(celula *le, int x)
{
    celula *ant = le, *atual = le->prox;
    
    while (atual != NULL)
    {
        if (atual->dado == x)
            ant->prox = atual->prox;
        else
            ant = atual;
        atual = atual->prox;
    }
}