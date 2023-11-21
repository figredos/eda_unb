#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} elemento;

void selection_sort(elemento *h)
{
    elemento *temp = h;

    while (temp)
    {
        elemento *menor = temp;
        elemento *r = temp->prox;

        while (r)
        {
            if(menor->dado > r->dado)
                menor = r;
            r = r->prox;
        }

        int t = temp->dado;
        temp->dado = menor->dado;
        menor->dado = t;
        
        temp = temp->prox;
    }
    
}

void imprime(elemento *h)
{
    for (elemento *t = h; t; t = t->prox)
        printf("%d -> ", t->dado);

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

    printf("Original:\n");
    imprime(head);

    selection_sort(head);

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