// Incompleto, 91% de acerto.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conta_pares_string(char *string, int indice, int *conta_pares)
{
    if (string[indice + 1] != 0)
    {
        if (string[indice + 2] == string[indice])
        {
            (*conta_pares)++;

            conta_pares_string(string, indice + 1, conta_pares);
        }
        else
            conta_pares_string(string, indice + 1, conta_pares);
    }
}

int main()
{
    char *string =  malloc(200 * sizeof(char));
    int conta_pares = 0, indice = 0;

    fgets(string, 200, stdin);

    string[strlen(string) - 1] = '\0';

    conta_pares_string(string, indice, &conta_pares);

    printf("%d", conta_pares);

    return 0;
}
// Tenho que primeiramente checar se a string[indice + 2] corresponde à string[indice]
