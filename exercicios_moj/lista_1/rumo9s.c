#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char *str)
{
    // if the string is empty
    if (!str)
    {
        return;
    }
    // pointer to start and end at the string
    int i = 0;
    int j = strlen(str) - 1;

    // reversing string
    while (i < j)
    {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

void rumo_9(char numero[], int *multiplo, int *profundidade)
{
    int soma = 0;
    char *soma_final = malloc(sizeof(char) * 9000);

    for (int i = 0; i < strlen(numero); i++)
    {
        soma = soma + (numero[i] - 48);
    }

    if (soma >= 10)
    {
        for (int i = 0; soma > 0; i++)
        {
            soma_final[i] = 48 + (soma % 10);
            soma = (soma - (soma % 10)) / 10;
        }

        strrev(soma_final);

        (*profundidade)++;

        rumo_9(soma_final, multiplo, profundidade);
    }
    else
    {   
        if ((soma % 9) == 0)
            *multiplo = 1;
    }
}

int main()
{
    char *numero = malloc(sizeof(char) * 9000);

    int multiplo = 0, profundidade = 1;

    do
    {
        scanf("%s", numero);
        if (numero[0] != '0')
        {
            char *numero_novo = numero;

            rumo_9(numero, &multiplo, &profundidade);

            printf("%s %d %d\n", numero_novo, multiplo, profundidade);

            multiplo = 0;

            profundidade = 1;
        }

    } while (numero[0] != '0');

    return 0;
}

// int main()
// {
//     char *numero = "999999";
//     // scanf("%s", numero) malloc(sizeof(char) * 9000);

//     char *numero_novo = numero;

//     int multiplo = 0, profundidade = 0;

//     rumo_9(numero_novo, &multiplo, &profundidade);

//     printf("%s %d %d\n", numero_novo, multiplo, profundidade);

//     return 0;
// }