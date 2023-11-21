#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} elemento;

elemento *particao(elemento *h, elemento *r)
{
    elemento *pivo = h;
    elemento *inicio = h;
    int j = 0;

    while (inicio != NULL && inicio != r)
    {
        if (inicio->dado < r->dado)
        {
            pivo = h;

            j = h->dado;
            h->dado = inicio->dado;
            inicio->dado = j;

            h = h->prox;
        }

        inicio = inicio->prox;
    }

    j = h->dado;
    h->dado = r->dado;
    r->dado = j;

    return pivo;
}

void quick_sort(elemento *h, elemento *r)
{
    if (h == r)
        return;

    elemento *pivo = particao(h, r);

    if (pivo && pivo->prox)
        quick_sort(pivo->prox, r);

    if (pivo && h != pivo)
        quick_sort(h, pivo);
} 

