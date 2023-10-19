//Incluindo pacotes
#include <stdio.h>
#include <stdlib.h>

//Definindo struct celula
typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;   

//Função que divide uma lista l em duas listas, l1 ímpar, l2 par 
void divide_lista(celula *l, celula *l1, celula *l2)
{
    //Cria células temporárias
    celula *atual = l->prox;
    celula *prev_l1 = l1;
    celula *prev_l2 = l2;
 
    while (atual != NULL) {
        // Salva o próximo nó antes de movê-lo
        celula *proximo = atual->prox;

        if (atual->dado % 2 == 0)
        {  // Número par
            prev_l2->prox = atual;
            prev_l2 = atual;
            prev_l2->prox = NULL;
        }
        else
        {  // Número ímpar
            prev_l1->prox = atual;
            prev_l1 = atual;
            prev_l1->prox = NULL;
        }

        // Move para o próximo nó na lista original
        atual = proximo;
    }

    // Garante que ambas as novas listas terminam em NULL
    prev_l1->prox = NULL;
    prev_l2->prox = NULL;
}

/*
O processo de mudança do ponteiro é o seguinte
1- Salvamos o próximo número na célula "proximo"
2- Mudamos o proximo das listas para a célula principal
3- Mudamos as listas para a célula principal
4- Mudamos o próximo das listas para nulo, os reiniciando 
5- Mudamos o valor da célula atual para o ponteiro "proximo"
6- Ao final do loop while mudar o valor do final das listas para NULL
*/