#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int dado;
    struct lista *prox;
} lista;

lista *cria_lista(int *valores_xi, int p)
{
    lista *cabeca = malloc(sizeof(lista));
    lista *temp = cabeca;

    for (int i = 0; i < p; i++)
    {
        lista *nova = malloc(sizeof(lista));
        temp->prox = nova;
        temp = temp->prox;
        temp->dado = valores_xi[i];
    }

    return cabeca;
}

void remove_depois(lista *p)
{
    if (p == NULL)
        return;
    else if (p->prox == NULL)
        p->prox = NULL;
    else
    {
        lista *temp = p->prox;
        p->prox = temp->prox;
    }
}

void elimina(lista *cabeca, int ordem, int *valores_ai)
{
    lista *temp = cabeca;

    for (int i = 0; temp->prox != NULL; i++)
    {
        if (valores_ai[i] != ordem)
            remove_depois(temp);
        else
            temp = temp->prox;
    }
}

int main()
{
    lista *lista = malloc(sizeof(lista));
    int p, r;
    int valores_xi[101];
    int n, j;
    int valores_ai[101];
    int teste = 1;

    while (1)
    {

        scanf("%d %d", &p, &r);

        if (p && r)
        {
            for (int i = 0; i < p; i++)
                scanf("%d", &valores_xi[i]);

            lista = cria_lista(valores_xi, p);

            for (int i = 0; i < r; i++)
            {
                scanf("%d %d", &n, &j);
                for (int k = 0; k < n; k++)
                    scanf("%d", &valores_ai[k]);

                elimina(lista, j, valores_ai);
            }
            printf("Teste %d\n", teste);
            teste++;
            printf("%d\n", lista->prox->dado);
        }
        else
            break;
    }

    return 0;
}
