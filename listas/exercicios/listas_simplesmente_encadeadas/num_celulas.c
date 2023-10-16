// Escreva uma função que conte o número de células de uma lista encadeada, faça uma versão iterativa e uma recursiva.
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int info;
    node *prox;
};

int numero_celulas_iterativo(node *no)
{

    node *temp = no;

    int contador = 0;

    while (temp != NULL)
    {

        temp = temp->prox;
        contador++;
    }

    return contador;
}

void numero_celulas_recursivo(node *no, int *contador)
{
    node *temp = no;

    if (temp != NULL)
    {
        (*contador)++;
        numero_celulas_recursivo(temp->prox, contador);
    }
}

int main()
{
    int numero;
    node *lista = malloc(sizeof(node));
    node *novo = malloc(sizeof(node));
    node *novo_1 = malloc(sizeof(node));
    novo->prox = novo_1;
    novo->info = 2;
    novo_1->prox = NULL;
    novo_1->info = 1;

    lista->prox = novo;

    numero = numero_celulas_iterativo(lista);

    printf("%d\n", numero);

    numero = 0;

    numero_celulas_recursivo(lista, &numero);

    printf("%d\n", numero);

    return 0;
}
