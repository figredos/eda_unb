//Incluindo pacotes
#include <stdio.h>
#include <stdlib.h>

//Definindo struct celula
typedef struct celula
{
    int dado;
    struct celula *prox;
} celula; 


//Função de busca iterativa
celula *busca(celula *le, int x)
{
    celula *temp = le;  //Cria célula temporária
    while (temp != NULL && temp->dado !=x)  //Muda a celula temporária até encontrar a com valor x, ou chegar ao fim
        temp = temp->prox;
    return temp;
}

//Função de busca recursiva
celula *busca_rec(celula *le, int x)
{
    if (le == NULL) //Verifica se a célula acabou
        return NULL;
    if (le->dado == x)  //Verifica se encontramos o dado com valor x
        return le;
    return busca_rec(le->prox, x);  //Faz recursão
}