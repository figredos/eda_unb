#include <stdio.h>
#include <stdlib.h>

int ultrapassa_minimamente(int *numeros, int limite, int indice)
{
    int soma = 0;

    do
    {
        if (numeros[indice] != 0)
        {
            soma += numeros[indice];
            indice++;
        }
    } while (soma <= limite);

    ultrapassa_minimamente(numeros, limite, indice);

    printf("%d\n", numeros[indice]);

    return indice;
}

int main()
{
    int *numeros = malloc(100 * sizeof(int));

    for (int i = 0; numeros[i] != 0; i++)
    {
        scanf("%d ", numeros);
    }
    
    ultrapassa_minimamente(numeros, 90, 0);

    return 0;
}