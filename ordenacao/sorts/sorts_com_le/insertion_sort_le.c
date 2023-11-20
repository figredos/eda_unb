#include <stdio.h>

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} elemento;

void insert_ordenado(elemento **lista, elemento *novo)
{
    if ((*lista) == NULL || (*lista)->dado >= novo->dado)
    {
        novo->prox = (*lista);
        (*lista) = novo;
    }
    else
    {
        elemento *temp = *lista;
        while (temp->prox != NULL && temp->prox->dado < novo->dado)
            temp = temp->prox;

        novo->prox = temp->prox;
        temp->prox = novo;
    }
}

void insertion_sort(elemento **h)
{
    elemento *atual = *h;
    elemento *h_ordenada = NULL;

    while (atual)
    {
        elemento *prox = atual->prox;

        insert_ordenado(&h_ordenada, atual);

        atual = prox;
    }

    *h = h_ordenada;
}
