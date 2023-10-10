#include <stdio.h>
#include <stdlib.h>

void ultrapassa_minimamente(int *numeros, int limite, int *indice, int tamanho)
{
    if ((*indice) < tamanho)
    {
        int soma = 0;

        do
        {
            if (numeros[*indice] != 0)
            {
                soma += numeros[*indice];
                (*indice)++;
            }
        } while (soma <= limite);

        (*indice)--;

        ultrapassa_minimamente(numeros, limite, indice, tamanho);

        printf("%d\n", numeros[*indice]);
    }
}

// void ultrapassa_minimamente(int *numeros, int limite, int indice, int tamanho)
// {

//     if (indice < tamanho)
//     {
//         int soma = 0;

//         for (int i = 0; soma <= limite; i++)
//         {
//             soma += numeros[indice];
//             indice++;
//         }

//         ultrapassa_minimamente(numeros, limite, indice - 1, tamanho);

//         printf("%d\n", numeros[indice - 1]);
//     }
// }

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
    ultrapassa_minimamente(numeros, limite, &indice, tamanho);

    return 0;
}