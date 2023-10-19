//Incluindo pacotes
#include <stdio.h>
#include <stdlib.h>

//Definindo struct celula
typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

//Função que junta duas listas de forma crescente
void mescla_listas (celula *l1, celula *l2, celula *l3)
{
    //Criando células temporárias
    celula *atual_l1 = l1->prox;
    celula *atual_l2 = l2->prox;
    celula *atual_l3= l3;

    while (atual_l1 != NULL && atual_l2 != NULL)
    {
        //Verificando se o valor do dado da primeira lista é menor que o da segunda
        if (atual_l1->dado < atual_l2->dado)
        {
            //Mudando os ponteiros
            atual_l3->prox = atual_l1;
            atual_l1 = atual_l1->prox;
        }
        else
        {
            //Mudando os ponteiros
            atual_l3->prox = atual_l2;
            atual_l2 = atual_l2->prox;
        }

        //Mudando o valor do ponteiro da lista 3
        atual_l3 = atual_l3->prox;
    }

    //Caso a lista 1 tenha sido interrompida pelo final da lista 2
    while (atual_l1 != NULL)
    {
        //Adicionando os valores ao final da lista
        atual_l3->prox = atual_l1;
        atual_l1 = atual_l1->prox;
        atual_l3 = atual_l3->prox;
    }

    //Caso a lista 2 tenha sido interrompida pelo final da lista 1
    while (atual_l2 != NULL)
    {
        //Adicionando os valores ao final da lista
        atual_l3->prox = atual_l2;
        atual_l2 = atual_l2->prox;
        atual_l3 = atual_l3->prox;
    }

    //Mudando o valor do último ponteiro
    atual_l3->prox = NULL;

    //Quebrando laços das listas
    l1->prox = NULL;
    l2->prox = NULL;
}
    