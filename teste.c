#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int *dado;
    int tamanho;
    int inicio;
    int fim;
} celula;

void empilha(celula *lista, int numero)
{
    if (lista->fim == lista->tamanho)
    {
        lista->tamanho *= 2;
        lista->dado = realloc(lista->dado, sizeof(int) * lista->tamanho);
    }

    lista->dado[lista->fim] = numero;
    lista->fim++;
}

void desempilha(celula *lista)
{
    lista->dado[lista->inicio++];
}

celula *cria_baralho(int numero)
{
    celula *lista = malloc(sizeof(celula));

    lista->tamanho = numero;
    lista->dado = malloc(sizeof(int) * numero);
    lista->fim = 0;
    lista->inicio = 0;

    for (int i = 0; i < numero; i++)
        lista->dado[i] = i + 1;
    
    return lista;
}

void descarta(celula *lista)
{
    for(int i = 0; i < lista->tamanho - 1; i++)
    {
        printf("%d ", lista->dado[i]);
        desempilha(lista);
    }
}

void imprime(celula *lista)
{
    for(int i = lista->inicio; i < lista->tamanho; i++)
        printf("%d -> ", lista->dado[i]);

    printf("NULL");
}

int main()
{
    celula *lista = cria_baralho(7);

    desempilha(lista);

    imprime(lista);

    return 0;
}

//faz todas as operações em cima do vetor, transformando ele em ex: 1 3 5 6 2 6 4 