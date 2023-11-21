#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *v, int l, int r)
{
    int pivo = v[r];
    int j = l;

    for (int i = 0; i < r; i++)
        if (v[i] < pivo)
        {
            swap(&v[i], &v[j]);
            j++;
        }

    swap(&v[j], &v[r]);

    return pivo;
}

void quick_sort(int *v, int l, int r)
{
    if (r < l)
        return;
    
    if (v[(l + r) / 2] > v[r])
        swap(&v[(l + r) / 2], &v[r]);
    if (v[l] > v[(l + r) / 2])
        swap(&v[(l + r) / 2], &v[l]);
    if (v[r] > v[(l + r) / 2])
        swap(&v[(l + r) / 2], &v[r]);

    int p = partition(v, l, r);

    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}