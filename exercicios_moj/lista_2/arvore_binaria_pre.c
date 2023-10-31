#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

void pre_ordem(no* raiz) {
    if (raiz == NULL)
        return;

    no* atual = raiz;
    no* pilha[100]; // Tamanho arbitrário da pilha
    int topo = -1;   // Inicializa o topo da pilha

    while (1) {
        while (atual != NULL) {
            printf("%d ", atual->dado); // Imprime o nó atual antes de empilhá-lo
            pilha[++topo] = atual;
            atual = atual->esq;
        }

        if (topo >= 0) {
            atual = pilha[topo--];
            atual = atual->dir;
        } else {
            break;
        }
    }
}