#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maior_substring(char *string, char *substring, int *indice, int *tamanho, int *flag)
{
    if ((*indice) < strlen(string))
    {
        if (!strncmp(string + *indice, substring, strlen(substring)))
        {
            (*indice) += strlen(substring);

            if (*tamanho == 0)
                *flag = 1;
            else
                *flag = 0;

            (*tamanho) += strlen(substring);

            maior_substring(string, substring, indice, tamanho, flag);
        }
        if (*flag > 0)
            (*tamanho)++;
        (*indice)++;
        maior_substring(string, substring, indice, tamanho, flag);
    }
}

// int main()
// {
//     char *string = "catcowcat";
//     char *substring = "cat";
//     int indice = 0;
//     int tamanho = 0;
//     int flag = 0;

//     maior_substring(string, substring, &indice, &tamanho, &flag);

//     printf("%d\n", tamanho);

//     return 0;
// }

int main()
{
    char *string = malloc(sizeof(char) * 100);
    char *substring = malloc(sizeof(char) * 100);
    int indice = 0;
    int tamanho = 0;
    int flag = 0;

    scanf("%s", string);
    scanf("%s", substring);

    maior_substring(string, substring, &indice, &tamanho, &flag);

    printf("%d\n", tamanho);

    return 0;
}

// Tem que checar se o tamanho achado é o maior