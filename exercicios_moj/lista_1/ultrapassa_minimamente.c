#include <stdio.h>
#include <stdlib.h>

void ultrapassa_minimamente(int *numeros, int limite, int indice, int tamanho)
{
    if ((indice) < tamanho)
    {
        int soma = 0;

        while (soma <= limite && indice < tamanho)
        {
                soma += numeros[indice];
                (indice)++;
        }

        ultrapassa_minimamente(numeros, limite, indice, tamanho);

        if ((indice) < tamanho)
        {
            printf("%d\n", numeros[indice - 1]);
    }
}
}

int main()
{
    int *numeros = NULL;
    int numero = 1;
    int capacidade = 0;
    int limite, indice = 0;

    while (numero != 0)
    {
        capacidade++;
        scanf("%d", &numero);
        numeros = realloc(numeros, capacidade * sizeof(int));
        numeros[capacidade - 1] = numero;
    }

    scanf("%d", &limite);

    ultrapassa_minimamente(numeros, limite, indice, capacidade);

    return 0;
}
