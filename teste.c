#include <stdio.h>
#include <stdlib.h>

void shellsort(int *v, int l, int r)
{
    int h;
    for (h = 1; h <= (r - l) / 9; h = 3 * h + 1)
        ;
    for (; h > 0; h /= 3)
        for (int i = l + h; i <= (r - l); i++)
        {
            int j = i;
            int tmp = v[j];
            while (j >= l + h && tmp < v[j - h])
            {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = tmp;
        }
}

void shell_sort(int *v, int l, int r)
{
    int h;
    for (h = 1; h <= (r - l) / 9; h = 3 * h + 1)
        ;

    for (; h > 0; h /= 3)
        for (int i = l + h; i <= (r - l); i++)
        {
            int j = i;
            int tmp = v[j];
            while (j >= l + h && tmp < v[j - h])
            {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = tmp;
        }
}

int main()
{
    // int *vetor = malloc(50001 * sizeof(int));
    int vetor[] = {7, 3, 2, 5, 4, 3};
    int numero;
    // int i;
    int i = 5;

    // for (i = 0; scanf("%d", &numero) != EOF; i++)
    //     vetor[i] = numero;

    shell_sort(vetor, 0, i);

    printf("%d", vetor[0]);

    for (int j = 1; j <= i; j++)
        printf(" %d", vetor[j]);

    printf("\n");

    return 0;
}