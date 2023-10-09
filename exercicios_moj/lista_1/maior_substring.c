#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maior_substring(char *string, char *substring, int indice, int *tamanho)
{
    if (indice < strlen(string))
    {
        if (!strncmp(string + indice, substring, strlen(substring)))
        {
            indice += strlen(substring);

            (*tamanho) += strlen(substring);

            maior_substring(string, substring, indice, tamanho);
        }
        indice++;
        maior_substring(string, substring, indice, tamanho);
    }
}

int main()
{
    char *string = "catcowcat";
    char *substring = "cat";
    int tamanho = 0;

    maior_substring(string, substring, 0, &tamanho);

    printf("%d\n", tamanho);

    return 0;
}

// int main()
// {
//     char *string = malloc(sizeof(char) * 100);
//     char *substring = malloc(sizeof(char) * 100);
//     int tamanho = 0;

//     scanf("%s", string);
//     scanf("%s", substring);

//     maior_substring(string, substring, 0, &tamanho, 0);

//     printf("%d\n", tamanho);

//     return 0;
// }

// Tem que checar se o tamanho achado é o maior