// Criar uma struct para conter os dados de cada letra (tamanho da sequência, a letra e a posição inicial)
// Criar um vetor de structs para segurar os dados
// Ordenar os dados de forma decrescente com base no tamanho da sequência
// Imprimir todos os dados
#include <stdio.h>
#include <stdlib.h>

typedef struct dado
{
    int qtd, p;
    char c;
} dados;

void merge(dados *v, int l, int m, int r)
{
    dados *auxiliar = malloc(sizeof(dados) * (r - l));

    int i = l;
    int j = m;
    int k = 0;

    while (i < m && j < r)
        if (v[i].qtd >= v[j].qtd)
            auxiliar[k++] = v[i++];
        else
            auxiliar[k++] = v[j++];

    while (i < m)
        auxiliar[k++] = v[i++];
    while (j < r)
        auxiliar[k++] = v[j++];

    for (i = l; i < r; i++)
        v[i] = auxiliar[i - l];
}
void merge_sort(dados *v, int l, int r)
{
    if (l >= r - 1)
        return;

    int meio = l + (r - l) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio, r);
    merge(v, l, meio, r);
}

int main()
{
    dados vetor[100001];
    char string[100001];

    scanf("%s", string);

    int tamanho = 0, k = 0;
    int posicao = 0;
    int contador = 0;
    char anterior = string[0];
    char *caractere = &string[0];
    while (*caractere != '\0')
    {
        for (; *caractere == anterior; caractere++, tamanho++)
            ;

        dados letra = {.qtd = tamanho, .p = posicao, .c = *(caractere - 1)};

        vetor[k++] = letra;

        posicao += tamanho;
        tamanho = 0;
        contador++;
        anterior = *caractere;
    }

    merge_sort(vetor, 0, contador);

    for (int j = 0; j < contador; j++)
        printf("%d %c %d\n", vetor[j].qtd, vetor[j].c, vetor[j].p);

    return 0;
}