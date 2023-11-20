#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} elemento;

void insert_ordenado(elemento **lista, elemento *novo)
{
    if ((*lista) == NULL || (*lista)->dado >= novo->dado)
    {
        novo->prox = (*lista);
        (*lista) = novo;
    }
    else
    {
        elemento *temp = *lista;
        while (temp->prox != NULL && temp->prox->dado < novo->dado)
            temp = temp->prox;

        novo->prox = temp->prox;
        temp->prox = novo;
    }
}

void insertion_sort(elemento **h)
{
    elemento *atual = *h;
    elemento *h_ordenada = NULL;

    while (atual)
    {
        elemento *prox = atual->prox;

        insert_ordenado(&h_ordenada, atual);

        atual = prox;
    }

    *h = h_ordenada;
}

void imprime(elemento *v)
{
    for (elemento *i = v; i != NULL; i = i->prox)
        printf("%d -> ", i->dado);

    printf("NULL\n");
}

int main()
{
    // Create a linked list with the given numbers: 4, 4, 1, 3, 2
    elemento *head = NULL;
    elemento *atual = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        elemento *novo_elemento = (elemento *)malloc(sizeof(elemento));
        scanf("%d", &novo_elemento->dado);
        novo_elemento->prox = NULL;
        if (head == NULL)
        {
            head = novo_elemento;
            atual = head;
        }
        else
        {
            atual->prox = novo_elemento;
            atual = novo_elemento;
        }
    }

    // Print the original list
    printf("Original:\n");
    imprime(head);

    // Sort the list using bubble sort
    insertion_sort(&head);

    // Print the sorted list
    printf("\nOrdenada:\n");
    imprime(head);

    // Free allocated memory
    elemento *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->prox;
        free(temp);
    }

    return 0;
}