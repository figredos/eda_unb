#include <stdio.h>

void shell_sort(int *v, int l, int r)
{
    int h = 1;

    while (h < (r - l + 1)/3)
        h = 3*h + 1;

    while (h >= 1)
        for (int i = l + h; i <= r; i++)
        {
            for (int j = i; j >= i + h && v[j] < v[j - h]; j -= h)
            {
                int t = v[j];
                v[j] = v[j - h];
                v[j - h] = t;
            }
            h /= 3;
        }
}