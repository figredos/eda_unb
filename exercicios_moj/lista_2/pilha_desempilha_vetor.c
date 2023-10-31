#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int *dados;
    int N, topo;
} pilha;


int desempilha (pilha *p, int *y)
{
    if (p->topo == 0) 
        return 0;

    p->topo--;
    *y = p->dados[p->topo]; //O topo indica a posição livre, então eu tenho que diminuir antes de salvar em y
    return 1;
}