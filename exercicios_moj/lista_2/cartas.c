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
    lista->inicio++;
}

int desempilha(celula *lista)
{
    int salva = lista->dado[lista->inicio];

    lista->inicio++;
    lista->dado[lista->inicio];

    return salva;
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

void descarta(celula *lista, int descarte[])
{
    for(int i = 0; i < lista->tamanho - 1; i++)
    {
        descarte[i] = desempilha(lista);
        empilha(lista, lista->dado[lista->inicio]);
    }
}

void imprime(celula *lista)
{
    for(int i = 0; i < lista->tamanho; i++)
        printf("%d -> ", lista->dado[i]);

    printf("NULL");
}

void imprime_vetor(int *lista, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
        printf("%d -> ", lista[i]);

    printf("NULL\n");
}

int main()
{
    celula *lista = cria_baralho(7);
    int *descarte = malloc(sizeof(int) * lista->tamanho);

    descarta(lista, descarte);

    imprime_vetor(descarte, lista->tamanho);

    imprime(lista);

    return 0;
}

//fazer as operações do vetor (empilhando as cartas que não são descartadas) e armazenando as cartas descartadas (desempilhando o vetor) em um segundo vetor "descarte".
