#include <stdio.h>
#include <stdlib.h>

// entrada: 33 51 23 94 66 28 11 73 19 8 31 0
// saida: 19 28 94 23

void ultrapassa_minimamente(int *numeros, int limite, int indice, int tamanho)
{
    if ((indice) < tamanho)
    {
        int soma = numeros[indice];

        if (soma > limite)
        {
            indice++;
            soma = 0;
        }

        while (soma <= limite)
        {
            if (indice < tamanho)
            {
                (indice)++;
                soma += numeros[indice];
            }
        }

        ultrapassa_minimamente(numeros, limite, indice, tamanho);

        if ((indice) < tamanho)
            printf("%d\n", numeros[indice]);
    }
}

// int main()
// {
//     int *numeros = malloc(100 * sizeof(int));

//     for (int i = 0; numeros[i] != 0; i++)
//     {
//         scanf("%d ", numeros);
//     }

//     ultrapassa_minimamente(numeros, 90, 0);

//     return 0;
// }

int main()
{
    int numeros[12] = {33, 51, 23, 94, 66, 28, 11, 73, 19, 8, 31, 0};
    int limite = 90;
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int indice = 0;

    // printf("%d", sizeof(numeros)/sizeof(numeros[0]));
    ultrapassa_minimamente(numeros, limite, indice, tamanho);

    return 0;
}