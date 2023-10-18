#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;   

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *atual = l->prox;
    celula *prev_l1 = l1;
    celula *prev_l2 = l2;

    while (atual != NULL) {
        // Salva o próximo nó antes de movê-lo
        celula *proximo = atual->prox;

        if (atual->dado % 2 == 0) {  // Número par
            prev_l2->prox = atual;
            prev_l2 = atual;
            prev_l2->prox = NULL;
        } else {  // Número ímpar
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


// void divide_lista(celula *l, celula *l1, celula *l2)
// {
//     celula *impar_ant = l1, *impar = l1->prox;
//     celula *par_ant = l2, *par = l2->prox;

//     while (l != NULL)
//     {
//         if (l->info % 2)
//         {
//             celula *salva = l->prox;
//             impar_ant = l;
//             impar = impar_ant->prox;
//             impar_ant = impar;
//             impar = NULL;
//             l = salva;
//         }
//         else
//         {  
//             celula *salva = l->prox;
//             par_ant = l;
//             par = par_ant->prox;
//             par_ant = par;
//             par = NULL;
//             l = salva;
//         }
//     }
// }