// Escreva uma função que insira uma nova célula com conteúdo x imediatamente depois da k-ésima célula de uma lista encadeada. Faça duas versões, uma iterativa e uma recursiva
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int info;
    node *prox;
};

// Protótipos de funções
node *cria_lista();
node *cria_no(int valor);
void insere_final(node *lista_1, node *lista_2);
void cria_posicao(node *lista_1, int posicao, int valor);
void insere_posicao(node *lista_1, int posicao, node *lista_2);
int numero_celulas(node *no);

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

void insere_final(node *lista_1, node *lista_2)
{
    node *temp = lista_1;

    while (temp->prox != NULL)
        temp = temp->prox;

    temp->prox = lista_2;
}

void cria_posicao(node *lista_1, int posicao, int valor)
{
    node *no = cria_no(valor);

    insere_posicao(lista_1, posicao, no);
}
void insere_posicao(node *lista_1, int posicao, node *lista_2)
{
    node *temp = lista_1;

    for (int i = 0; i < posicao; i++)
        if (temp->prox != NULL)
            temp = temp->prox;

    if (temp->prox != NULL)
    {
        node *resto = temp->prox;
        temp->prox = lista_2;

        insere_final(lista_2, resto);
    }
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

    insere_final(lista_1, novo_1);

    node *lista_2 = cria_lista();
    node *novo_2 = cria_no(6);

    insere_final(lista_2, novo_2);

    cria_posicao(lista_1, 2, 10);

    numero = numero_celulas(lista_1);

    printf("%d\n", numero);

    return 0;
}
