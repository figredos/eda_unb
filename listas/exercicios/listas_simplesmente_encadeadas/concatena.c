// Escreva uma função que concatene duas listas encadeadas. Faça duas versões, uma iterativa e uma recursiva.
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int info;
    node *prox;
};

node *cria_lista()
{
    node *lista = malloc(sizeof(node));

    lista->prox = NULL;

    return lista;
}

node *cria_no(int valor)
{
    node *novo = malloc(sizeof(node));

    novo->prox = NULL;

    novo->info = valor;

    return novo;
}

void concatena_iterativo(node *lista_1, node *lista_2)
{
    node *temp = lista_1;

    while (temp->prox != NULL)
        temp = temp->prox;

    temp->prox = lista_2;
}

void concatena_recursivo(node *lista_1, node *lista_2)
{
    node *temp = lista_1;

    if (temp->prox != NULL)
        concatena_recursivo(temp->prox, lista_2);
    else
        temp->prox = lista_2;
}

int numero_celulas(node *no)
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

int main()
{
    int numero;
    node *lista_1 = cria_lista();
    node *novo_1 = cria_no(5);

    concatena_recursivo(lista_1, novo_1);

    node *lista_2 = cria_lista();
    node *novo_2 = cria_no(6);

    concatena_recursivo(lista_2, novo_2);

    concatena_recursivo(lista_1, lista_2);

    numero = numero_celulas(lista_1);

    printf("%d\n", numero);

    return 0;
}
