#include <stdio.h>

int main()
{
    int vetor[1000];
    for (int i = 0; i < 1000; i++)
        vetor[i] = rand();

    for (int i = 0; i < 1000; i++)
        printf("%d ", vetor[i]);

    return 0;
}