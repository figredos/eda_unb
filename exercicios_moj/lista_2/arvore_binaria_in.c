#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz)
{
    if (raiz == NULL) //retornando caso a raiz esteja vazia
        return;

    no *atual = raiz;   //variável que será manipulada ao fazer a leitura da árvore
    no *pilha[100]; //construiremos uma pilha de nós para fazer a recursão  
    int topo = -1;  //variável que acompanha o topo da pilha

    while (1)   //enquanto o "break" não for acionado, vai rodar esse código
    {
        while (atual != NULL)   //chega no nó mais a esquerda
        {
            pilha[++topo] = atual;  //empilha os nós
            atual = atual->esq; //atualiza o nó atual para o da esquerda    
        }
        if (topo >= 0)  //checa se voltou para o topo
        {
            atual = pilha[topo--];
            printf("%d ", atual->dado);
            atual = atual->dir;
        }
        else
            break;
    }
    printf("\n");
}