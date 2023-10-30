// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct fila
// {
//     char *dado;
//     int inicio, fim;
//     int tamanho;
// } fila;

// void string_reverso(fila *lista, char *string)
// {
//     char temp;
//     lista->tamanho = strlen(string);
//     lista->dado = malloc(sizeof(char) * lista->tamanho);
//     lista->fim = lista->tamanho - 1;

//     for (int i = 0; i < lista->tamanho; i++)
//     {
//         temp = string[i];
//         lista->dado[lista->fim] = temp;
//         lista->fim--;
//     }
// }

// int main()
// {
//     char *string = malloc(sizeof(char) * 501);
//     fila *lista = malloc(sizeof(fila));

//     scanf("%s", string);

//     string_reverso(lista, string);

//     printf("%s\n", lista->dado);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_contrario(char *string, char *string_nova, int indice, int indice_reverso)
{
    if (indice < strlen(string))
    {
        string_nova[indice] = string[indice_reverso];
        indice++;
        indice_reverso--;

        string_contrario(string, string_nova, indice, indice_reverso);
    }
}

int main()
{
    char *string = malloc(501 * sizeof(char));

    scanf("%s", string);

    char *string_nova = malloc(strlen(string) - 1 * sizeof(char));

    string_contrario(string, string_nova, 0, strlen(string) - 1);

    printf("%s\n", string_nova);

    return 0;
}