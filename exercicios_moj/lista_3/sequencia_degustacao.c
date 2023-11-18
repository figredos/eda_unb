// Criar uma struct para conter os dados de cada letra (tamanho da sequência, a letra e a posição inicial)
// Criar um vetor de structs para segurar os dados
// Ordenar os dados de forma decrescente com base no tamanho da sequência
// Imprimir todos os dados
#include <stdio.h>
#include <stdlib.h>

//Struct dado que contém as características de cada letra
typedef struct dado
{
    int qtd, p;
    char c;
} dados;

//Funções merge e merge_sort que ordenam com base na quantidade de vezes que alguma letra aparece
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
    //Inicializando vetor de dados e string
    dados vetor[100001];
    char string[100001];

    scanf("%s", string);

    int tamanho = 0, k = 0;
    int posicao = 0;
    int contador = 0;
    char anterior = string[0];
    char *caractere = &string[0];

    //Enquanto não chegar ao fim da string
    while (*caractere != '\0')
    {
        //Enquanto a letra atual for igual a anteriorm aumentamos a o tamanho (quantidade) e mudamos o ponteiro para
        //a próxima letra
        for (; *caractere == anterior; caractere++, tamanho++)
            ;

        //Criando um struct letra
        dados letra;
        letra.qtd = tamanho, letra.p = posicao, letra.c = *(caractere - 1);

        //Adicionando letra ao vetor
        vetor[k++] = letra;

        //Incrementando variáveis de modo a continuar a leitura
        posicao += tamanho;
        tamanho = 0;
        contador++;
        anterior = *caractere;
    }

    //Ordenando o vetor
    merge_sort(vetor, 0, contador);

    //Imprimindo 
    for (int j = 0; j < contador; j++)
        printf("%d %c %d\n", vetor[j].qtd, vetor[j].c, vetor[j].p);

    return 0;
}