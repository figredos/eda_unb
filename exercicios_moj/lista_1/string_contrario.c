//Incluindo pacotes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função que inverte a string passada como argumento
void string_contrario(char *string, char *string_nova, int indice, int indice_reverso)
{
    //Inserimos o valor do final da string antiga no inicio da string nova
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
