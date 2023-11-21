#include <stdio.h>

void shell_sort(int *v, int l, int r)
{
    int h = 1;

    for(; h < (r - l) / 9; h = 3 * h + 1)
        ;
    
    for(; h > 0; h /= 3)
        for (int i = l + h; i < (r - l); i++)
            for (int j = i; j >= l + h && v[j] < v[j - h]; j -= h)
            {
                int t = v[j];
                v[j] = v[j - h];
                v[j - h] = t;
            }  
}
