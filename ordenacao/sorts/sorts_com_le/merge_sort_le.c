#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} elemento;

elemento *merge_ordenado(elemento *a, elemento *b)
{
    elemento *resultado = NULL;

    if (!a)
        return b;
    else if (!b)
        return a;

    if (a->dado <= b->dado)
    {
        resultado = a;
        resultado->prox = merge_ordenado(a->prox, b);
    }
    else
    {
        resultado = b;
        resultado->prox = merge_ordenado(a, b->prox);
    }
    return resultado;
}

void separa(elemento *h, elemento **frente, elemento **fim)
{
    elemento *rapido = h->prox;
    elemento *lento = h;

    while (rapido)
    {
        rapido = rapido->prox;
        if(rapido)
        {
            lento = lento->prox;
            rapido = rapido->prox;
        }
    }
    
    *frente = h;
    *fim = lento->prox;
    lento->prox = NULL;
}

void merge_sort(elemento **h)
{
    elemento *head = *h;
    elemento *a, *b;

    if(!head || !head->prox)
        return;
    
    separa(head, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *h = merge_ordenado(a, b);
}