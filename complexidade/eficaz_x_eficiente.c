#include <stdio.h>
#include <stdlib.h>

int eficaz(int numero)
{
    if (numero == 1 || numero == 2)
        return 1;

    else
        return eficaz(numero - 1) + eficaz(numero - 2);
}

int eficiente(int numero)
{
    int i, f_ant = 1, f_ant_ant = 1, f_atual = 1;

    for (i = 3; i <= numero; i++)
    {
        f_atual = f_ant + f_ant_ant;
        f_ant_ant = f_ant;
        f_ant = f_atual;
    }

    return f_atual;
}

int main()
{
    printf("%d == %d", eficaz(5), eficiente(5));

    return 0;
}