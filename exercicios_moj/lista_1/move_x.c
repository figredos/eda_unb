#include <stdio.h>
#include <string.h>

void move_x(char* string, int indice, int contador)
{
    char temp;

    if (indice < strlen(string))
    {
        if (string[indice] == "\0")
            return;

        else if (string[indice] != 'x')
        {
            temp = string[contador];
            string[contador] = string[indice];
            string[indice] = temp;

            move_x(string, indice + 1, contador + 1);
        }
        else
            move_x(string, indice + 1, contador);
    }
}

int main()
{
    char str[100];

    scanf("%s", str);

    move_x(str, 0, 0);

    printf("%s\n", str);

    return 0;
}