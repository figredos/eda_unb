#include <stdio.h>

void bubble_sort(int *v, int l, int r)
{
    for (; r > l; r--)
    {
        for (int j = l; j < r; j++)
            if (v[j] > v[j + 1])
            {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
    }
}

void bubble_sort_melhorado(int v[], int l, int r)
{
    int swap = 1;
    for (; r > l && swap; r--)
    {
        swap = 0;
        for (int j = l; j < r; j++)
            if (v[j] > v[j + 1])
            {
                exch(v[j], v[j + 1]);
                swap = 1;
            }
    }
}