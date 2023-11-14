#include <stdio.h>
#include <stdlib.h>

int menor_indice(int *v, int i, int j)
{
    if (i == j)
        return i;

    int k = menor_indice(v, i + 1, j);

    return (v[i] < v[k]) ? i : k;
}

void selection_sort_recursivo(int *v, int n, int i)
{
    if (n == i)
        return;

    int k = menor_indice(v, i, n - 1);

    if (i != k)
    {
        int t = v[i];
        v[i] = v[k];
        v[k] = t;
    }

    selection_sort_recursivo(v, n, i + 1);
}

void ordena(int *v, int n)
{
    selection_sort_recursivo(v, n, 0);
}

int main()
{
    int n = 6;

    int vetor[] = {7, 3, 2, 5, 4, 3};

    ordena(vetor, n);

    for (int j = 0; j < n; j++)
        printf(" %d", vetor[j]);

    printf("\n");
}