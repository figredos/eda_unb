#include <stdio.h>
#include <stdlib.h>

void troca(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particao(int *v, int l, int r)
{
    int pivo = v[r];
    int j = l;

    for(int i = l; i < r; i++)
    {
        if(v[i] < pivo)
        {
            troca(&v[i], &v[j]);
            j++;
        }
    }

    troca(&v[r], &v[j]);

    return j;
}

void quick_sort(int *v, int l, int r)
{
    if(l > r)
        return;
    
    int p = particao(v, l, r);

    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}
