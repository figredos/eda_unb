//Incluindo pacotes
#include <stdio.h>
#include <stdlib.h>

//Definindo struct celula
typedef struct celula 
{
    int dado;
    struct celula *prox;
} celula;

//Função que imprime uma lista le
void imprime(celula *le)
{
    celula *temp = le->prox;

    while (temp != NULL)
    {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    
    printf("NULL\n");
}

//Função que imprime uma lista recursivamente
void imprime_rec(celula *le)
{
    if (le->prox != NULL)
    {
        printf("%d -> ", (le->prox)->dado);
        imprime_rec(le->prox);
    }
    else
        printf("NULL\n");
}
