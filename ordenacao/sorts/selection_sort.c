#include <stdio.h>

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} elemento;

void selection_sort(elemento *h)
{
    elemento *temp;
    
    while (temp)
    {
        elemento *menor;
        elemento *r;

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