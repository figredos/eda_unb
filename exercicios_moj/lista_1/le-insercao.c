//Incluindo pacotes
#include <stdio.h>
#include <stdlib.h>

//Definindo struct celula
typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

//Função que insere uma célula com valor x no início da lista
void insere_inicio(celula *le, int x)
{
    //Criando nova célula e adicionando valor e prox
    celula *novo = malloc(sizeof(celula));
    novo->dado = x; 
    novo->prox = le->prox;

    //Mudando o ponteiro da cabeça da lista
    le->prox = novo;
}

//Função que insere uma célula na posição anterior à da posição y
void insere_antes(celula *le, int x, int y)
{
    //Criando nova célula e definindo seu valor
    celula *nova = malloc(sizeof(celula));  
    nova->dado = x;

    //Criando celula anterior (representando a cabeça da célula) e prox
    celula *anterior = le, *atual = le->prox;

    //Buscando a célula com valor y
    while (atual != NULL && atual->dado != y)
    {
        //Alterando o valor do nó anterior e do nó atual (andando pela lista)
        anterior = atual;
        atual = anterior->prox;
    }

    //Alterando os ponteiros da célula anterior e da nova
    nova->prox = atual;
    anterior->prox = nova;
}
