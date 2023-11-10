#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *v, int l, int r)
{
    for (int i = l + 1; i < r; i++)
    {
        for (int j = i; j > l && v[j] < v[j - 1]; j--)
        {
            int t = v[j];
            v[j] = v[j - 1];
            v[j - 1] = t;
        }
    }
}

int main()
{
    int *vetor = malloc(50001 * sizeof(int));
    int numero;
    int i;

    for (i = 0; scanf("%d", &numero) != EOF; i++)
        vetor[i] = numero;

    insertion_sort(vetor, 0, i);

    printf("%d", vetor[0]);

    for (int j = 1; vetor[j] != '\0'; j++)
        printf(" %d", vetor[j]);

    printf("\n");

    return 0;
}