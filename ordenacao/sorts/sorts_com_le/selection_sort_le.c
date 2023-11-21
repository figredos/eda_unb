#include <stdio.h>

void selection_sort(int *v, int l, int r)
{
    int menor;

    for (int i = l; i < r; i++)
    {
        menor = i;
        for (int j = l + 1; j < r; i++)
            if(v[j] < v[menor])
                menor = j;

        if (menor != i)
        {
            int t = v[menor];
            v[menor] = v[i];
            v[i] = t;
        }
    }
}