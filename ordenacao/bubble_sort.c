#include <stdio.h>

void bubble_sort(int *v, int l, int r)
{
    for (; r > l; r--)
    {
        for (int j = l + 1; j < r; j++)
            if (v[j] > v[j + 1])
            {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
    }
}