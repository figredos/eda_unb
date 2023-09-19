#include <stdio.h>
#include <stdlib.h>

int maior(int tamanho, int vetor[])
{
    if (tamanho == 1)
        return vetor[0];

    int numero = maior(tamanho - 1, vetor);

    if (numero > vetor[tamanho - 1])
        return numero;

    return vetor[tamanho - 1];
}

int main()
{
    int vetor[3] = {1, 3, 2};

    printf("%d", maior(3, vetor));

    return 0;
}