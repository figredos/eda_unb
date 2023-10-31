#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

// void pos_ordem(no *raiz)
// {
//     if (raiz == NULL)
//         return;

//     no *atual = raiz;
//     no *pilha[100];
//     int topo = -1;

//     while (1)
//     {
//         while (atual != NULL)
//         {
//             pilha[++topo] = atual;
//             atual = atual->esq;
//         }

//         if(topo >= -1)
//         {
//             atual = pilha[topo--];
//             atual = atual->dir;
//             printf("%d ", atual->dado);
//         }
//         else
//             break;
//     }
// }

void pos_ordem(no* raiz) {
    if (raiz == NULL)
        return;

    no* atual = raiz;
    no* pilha1[100]; // Tamanho arbitrário da pilha
    no* pilha2[100]; // Tamanho arbitrário da pilha
    int topo1 = -1;  // Inicializa o topo da pilha 1
    int topo2 = -1;  // Inicializa o topo da pilha 2

    pilha1[++topo1] = atual;

    while (topo1 >= 0) {
        atual = pilha1[topo1--];
        pilha2[++topo2] = atual;

        if (atual->esq != NULL)
            pilha1[++topo1] = atual->esq;
        if (atual->dir != NULL)
            pilha1[++topo1] = atual->dir;
    }

    while (topo2 >= 0) {
        atual = pilha2[topo2--];
        printf("%d ", atual->dado);
    }
}


// visitar todos os nós filhos antes de visitar o nó pai