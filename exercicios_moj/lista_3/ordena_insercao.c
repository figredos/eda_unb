#include <stdio.h>
#include <stdlib.h>

//Função shell sort (otimização do insertion_sort)
void shell_sort(int *v, int l, int r)
{
    int h = 1;

    for (; h <= (r - l) / 9; h = 3 * h + 1)
        ;

    for (; h > 0; h /= 3)
        for (int i = l + h; i <= (r - l); i++)
            for (int j = i; j >= l + h && v[j] < v[j - h]; j -= h)
            {
                int t = v[j];
                v[j] = v[j - h];
                v[j - h] = t;
            }
}

int main()
{
    int *vetor = malloc(50001 * sizeof(int));
    int numero;
    int i;

    for (i = 0; scanf("%d", &numero) != EOF; i++)
        vetor[i] = numero;

    shell_sort(vetor, 0, i);

    printf("%d", vetor[1]);

    for (int j = 2; j <= i; j++)
        printf(" %d", vetor[j]);

    printf("\n");

    return 0;
}