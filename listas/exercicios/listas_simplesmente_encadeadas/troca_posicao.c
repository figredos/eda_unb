// Escreva uma função que troque de posição duas células de uma mesma lista encadeada.

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
void cria_posicao(node *lista_1, int posicao, int valor);
void insere_final(node *lista_1, node *lista_2);
void insere_posicao(node *lista_1, int posicao, node *lista_2);
void troca_posicao(node *lista, int posicao_1, int posicao_2);
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

void troca_posicao(node *lista, int posicao_1, int posicao_2)
{
    int contador = 0;

    if (posicao_1 == posicao_2)
        return;

    node *atual_1 = lista, *anterior_1 = NULL;
    while (contador <= posicao_1 && atual_1 -> prox != NULL)
    {
        anterior_1 = atual_1;
        atual_1 = atual_1->prox;
    }

    contador = 0;

    node *atual_2 = lista, *anterior_2 = NULL;
    while (contador <= posicao_2 && atual_2 -> prox != NULL)
    {
        anterior_2 = atual_2;
        atual_2 = atual_2->prox;
    }

    if (anterior_1 != NULL)
        anterior_1->prox = atual_2;
    else   
        lista = atual_2;
    
    if (anterior_2 != NULL)
        anterior_2->prox = atual_1;
    else   
        lista = atual_1;

    node *temp = atual_2->prox;
    atual_2->prox = atual_1->prox;
    atual_1->prox = temp;
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
