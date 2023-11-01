#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

void pre_ordem(no* raiz)
{
    if (raiz == NULL)
        return;

    no *atual = raiz;
    no *pilha[100];
    int topo = -1;

    while (1)
    {
        while (atual != NULL)
        {
            pilha[++topo] = atual;
            printf("%d ", atual->dado);
            atual = atual->esq;
        }
        
        if (topo >= 0)
        {
            atual = pilha[topo--];
            atual = atual->dir;
        }
        else
            break;
    }
    printf("\n");
}