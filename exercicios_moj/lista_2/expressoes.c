#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// caso bem definida, retorna 1, caso contrário, retorna 0
int bem_definida(char *cadeia)
{
    int aberto = 0;
    int *pilha = malloc(sizeof(int) * strlen(cadeia));
    int topo = 0;

    if (strlen(cadeia) <= 1 || (strlen(cadeia) % 2) != 0)
        return 0;

    pilha[topo] = cadeia[0];
    aberto++;

    if (pilha[0] == 41 || pilha[0] == 93 || pilha[0] == 125)
        return 0;

    for (int i = 1; i < strlen(cadeia); i++)
    {
        int atual = cadeia[i];
        if (cadeia[i] == 40 || cadeia[i] == 91 || cadeia[i] == 123)
        {
            pilha[++topo] = cadeia[i];
            aberto++;
        }
        else
        {
            if (cadeia[i] == 41 && pilha[topo] == 40)
            {
                pilha[topo--];
                aberto--;
            }
            else if (cadeia[i] == 93 && pilha[topo] == 91)
            {
                pilha[topo--];
                aberto--;
            }
            else if (cadeia[i] == 125 && pilha[topo] == 123)
            {
                pilha[topo--];
                aberto--;
            }
            else
                break;
        }
    }
    if (aberto)
        return 0;
    else
        return 1;
}

int main()
{
    int t;
    char *cadeia = malloc(sizeof(char) * 100001);
    int flag;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%s", cadeia);

        flag = bem_definida(cadeia);

        if (flag == 0)
            printf("N\n");
        else
            printf("S\n");
    }

    return 0;
}