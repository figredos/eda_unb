# RESUMO ALGORITMOS

Complexidade assintótica é o número de comparações e trocas para ordenar ***n*** números.

In-place é um algoritmo que não usa outras estruturas de dados em sua execução.

Adaptativo é um algoritmo que é beneficiado pela ordenação prévia dos dados.

Estável é um algoritmo que mantém a ordem relativa dos elementos. 

## BUBBLE SORT

~~~C
void bubble_sort(int *v, int l, int r)
{
    for(; r > l; r--)
        for(int i = l; i < r; i++)
            if(v[i] > v[i + 1])
            {
                int t = v[i];
                v[i] = v[i + 1];
                v[i + 1] = t;
            }
} 
~~~  

Complexidade Assintótica: $O(N^2)$

In-place: Sim

Estável: Sim

Adaptativo: Sim

## SELECTION SORT

~~~C
void selection_sort(int *v, int l, int r)
{
    int menor;
    for(int i = l; i < r; i++)
    {
        menor = i;

        for(int j = i + 1; j < r; j++)
            if(v[j] < v[menor])
                menor = j;

        if (menor != i)
        {
            int t = v[i];
            v[i] = v[menor];
            v[menor] = v[i];
        }
    }
}
~~~

Complexidade Assintótica: $O(N^2)$

In-place: Sim

Estável: Não

Adaptativo: Não

## INSERTION SORT

~~~C
void insertion_sort(int *v, int l, int r)
{
    int swap = 1;
    for(int i = l + 1; i < r && swap; i++)
        for(int j = i; j > l && v[j] < v[j - 1]; j--)
        {
            int t = v[j];
            v[j] = v[j - 1];
            v[j - 1] = t;
        }
}
~~~

Complexidade Assintótica: $O(N^2)$

In-place: Sim

Estável: Sim

Adaptativo: Sim

## SHELL SORT

~~~C
void shell_sort(int *v, int l, int r)
{
    int h = 1;

    for(; h < (r - l) / 9; h = 3 * h + 1)
        ;

    for(; h > 0; h /= 3)
        for(int i = l + h; i < r; i++)
            for(int j = i; j >= l + h && v[j] < v[j - h]; j -= h)
            {
                int t = v[j];
                v[j] = v[j - h];
                v[j - h] = t;
            }
}
~~~

Complexidade Assintótica: $O(n log n)$ no melhor caso e $O(N^2)$ no pior

In-place: Sim

Estável: Não

Adaptativo: Sim, mas nem sempre

## MERGE SORT

~~~C
void merge(int *v, int l, int m, int r)
{
    int *auxiliar = malloc(sizeof(int) * (r - l));

    int i = l, j = m, k = 0;

    while(i < m && j < r)
        auxiliar[k++] = v[i] <= v[j] ? v[i++] : v[j++];

    while(i < m)
        auxiliar[k++] = v[i++];
    while(j < r)
        auxiliar[k++] = v[j++];

    for(i = 0; i < r; i++)
        v[i] = auxiliar[i - l];

    free(auxiliar);
}

void merge_sort(int *v, int l, int r)
{
    if (r - 1 <= l)
        return;

    int meio = l + (r - l) / 2;

    merge_sort(v, l, m);
    merge_sort(v, m, r);
}
~~~

Complexidade Assintótica: $O(n log n)$ no melhor caso e $O(N^2)$ no pior

In-place: Não

Estável: Sim

Adaptativo: Não

## QUICK SORT

~~~C
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *v, int l, int r)
{
    int pivo = v[r];
    int j = l;

    for(int i = l; i < r; i++)
        if(v[i] < v[j])
        {    
            swap(&v[i], &v[j]);
            j++;
        }
    
    swap(&v[j], &v[r]);

    return j;
}
   
void quick_sort(int *v, int l, int r)
{
    if (r < l)
        return;

    if (v[(r + l) / 2] > v[r])
        swap(&v[(r + l) / 2], &v[r]);
    if (v[l] > v[(r + l) / 2])
        swap(&v[(r + l) / 2], &v[l]);
    if (v[r] > v[(r + l) / 2])
        swap(&v[(r + l) / 2], &v[r]);

    int p = partition(v, l, r);

    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}
~~~

Complexidade Assintótica: $O(n log n)$ no melhor e no caso médio

In-place: Não, apenas a parte recursiva é in-place

Estável: Não

Adaptativo: Não, ordenação pode piorar