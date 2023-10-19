#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y)
{
    if(f->p == f->u)
        return 0;
    if(f->u == f->N-1)
    {
        f->N *= 2;
        f->dados = realloc(f->dados, f->N * sizeof(int));
    }

    *y = f->dados[f->p];
    f->p++;

    return 1;
}
