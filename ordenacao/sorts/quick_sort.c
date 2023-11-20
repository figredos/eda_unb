#include <stdio.h>
#include <stdlib.h>

int particao(int *v, int l, int r)
{
    int pivo = v[r];
    int j = l;

    for(int i = l; i < r; i++)
    {
        if(v[i] < pivo)
        {
            int t = v[j];
            v[j] = v[i];
            v[i] = t;
        }
        else if(v[j] < pivo)
            j = i;
    }

    int t = v[j];
    v[j] = v[r];
    v[r] = t;

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
