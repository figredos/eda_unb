#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} elemento;

void bubble_sort(elemento **h, int l, int r)
{
    elemento **c;
    int swap = 1;

    for (int i = 0; i < r && swap; i++)
    {
        c = h;
        swap = 0;

        for (int j = 0; j < r - i && (*c)->prox; j++)
        {
            elemento *p1 = *c;
            elemento *p2 = p1->prox;

            if (p1->dado > p2->dado)
            {
                elemento *t = p2->prox;
                p2->prox = p1;
                p1->prox = t;

                *c = p2;
                swap = 1;
            }

            c = &(*c)->prox;
        }
    }
}


