#include <stdio.h>
#include <stdlib.h>

void troca_x_y(char *string, int indice)
{
    if (string[indice] != 0)
    {
        if (string[indice] == 120)
        {
            string[indice] = 121;
            troca_x_y(string, indice + 1);
        }
        else
            troca_x_y(string, indice + 1);
    }
}

int main()
{
    char *string = malloc(sizeof(char) * 80);

    scanf("%s", string);

    troca_x_y(string, 0);

    printf("%s\n", string);

    return 0;
}