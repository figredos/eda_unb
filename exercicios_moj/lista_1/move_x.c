//Incluindo pacotes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função que move todas as instâncias da letra "x" em uma string para o seu fim (recursiva)
void move_x(char* string, int indice, int contador)
{
    char temp;

    if (indice < strlen(string))
    {
        if (string[indice] == 0)    //Se o indice da string for "\0"
            return;

        else if (string[indice] != 120) //Se o índice da string for diferente de "x", bota a letra no início
        {
            temp = string[contador];    
            string[contador] = string[indice];
            string[indice] = temp;

            move_x(string, indice + 1, contador + 1);
        }
        else    //Se o índice for igual a "x", mantém sua posição
            move_x(string, indice + 1, contador);
    }
}

int main()
{
    char *str = malloc(sizeof(char) * 101);

    scanf("%s", str);

    move_x(str, 0, 0);

    printf("%s\n", str);

    return 0;
}