#include <stdio.h>
#include <stdlib.h>

int street_parade(int *order, int n)
{
    // ordenar com base na entrada, retornar 1 caso possível
    int esperado = 1;
    int *pilha = malloc(sizeof(int) * n);
    int topo = 0;
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (order[i] == esperado)
            esperado++;
        else if (topo > 0 && pilha[topo - 1] == esperado)
        {
            topo--;
            esperado++;
            i--;
        }
        else
            pilha[topo++] = order[i];
    }

    while (topo > 0)
    {
        if(pilha[topo - 1] == esperado)
        {
            topo--;
            esperado++;
        }
        else
            return 0;
    }
    
    return 1;
}

int main()
{
    int n;

    while (scanf("%d", &n) != 0)
    {
        if(n == 0)
            break;

        int *order = malloc(sizeof(int) * (n + 1));
        for (int i = 0; i < n; i++)
            scanf("%d", &order[i]);

        int possible = street_parade(order, n);

        if (possible)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}

