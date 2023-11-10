#include <stdio.h>

void insertion_sort(int *v, int l, int r)
{
    for (int i = l + 1; i < r; i ++)
    {
        for (int j = i; j > l && v[j] < v[j - 1]; j--)
        {
            int t = v[j];
            v[j] = v[j - 1];
            v[j - 1] = t;
        }
    }
}