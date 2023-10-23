# Busca

## Busca binária em vetores ordenados

### Paradigma da divisão e conquista

A ideia é dividir o vetor no meio, procuramos o elemento da esquerda caso o elemento seja menor que o elemento central, ou procurar na direita caso seja maior. Repetimos, recursivamente, até o elemento procurado ser o elemento central (ou não, caso haja uma falha na busca).

~~~C
#define key(A) (A.chave)

typedef int Key;
typedef struct data Item;
struct data
{
    Key chave;
    char info[100];
};

Item binary_search(Item *v, int I, int r, Key k)
{
    if(l >= r)
        return NULL;

    int m = (l + r) / 2;

    if(k == key(v[m]))
        return v[m];
    
    if(k < key(v[m]))
        return binary_search(v, l, m-1, k);

    return binary_search(v, m+1, r, k);
}
~~~

Complexidade até $\lfloor \lg(n) \rfloor + 1$ comparações (acerto ou falha).

### Interpolation search

Mais próximo do início ou fim do vetor

$l + (r - l) \times (1/2)$

- 1/2: posição do elemento do meio
- (k - inicio) / (fim - inicio) (proporção dos k elementos iniciais em relação ao total)

$l + (r - l) \times (k - key(v[l]) / key(v[r]) - key(v[l]))$

~~~C
