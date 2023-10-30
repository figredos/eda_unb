#include <stdio.h>

typedef struct pilha
{
    int *dados;
    int N, topo;
} pilha;

// int desempilha(pilha *p, int *y)
// {
//     if (p->topo == -1)
//         return 0;

//     *y = p->dados[p->topo];
//     p->topo--;

//     return 1;
// }

int desempilha (pilha *p, int *y) {
    if (p->topo == NULL) 
        return 0;
    *y = p->dados[p->topo];
    p->topo--;
    return 1;
}