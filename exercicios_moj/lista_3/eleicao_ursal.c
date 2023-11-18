#include <stdio.h>
#include <stdlib.h>

typedef struct candidato
{
    long long votos, digitos;
} candidato;

void merge(candidato *v, int l, int m, int r)
{
    candidato *auxiliar = malloc(sizeof(candidato) * (r - l));

    int i = l, j = m, k = 0;

    while (i < m && j < r)
        auxiliar[k++] = v[i].votos <= v[j].votos ? v[i++] : v[j++];

    while (i < m)
        auxiliar[k++] = v[i++];
    while (j < r)
        auxiliar[k++] = v[j++];

    for (i = l; i < r; i++)
        v[i] = auxiliar[i - l];

    free(auxiliar);
}
void merge_sort(candidato *v, int l, int r)
{
    if (r - 1 <= l)
        return;

    int meio = l + (r - l) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio, r);
    merge(v, l, meio, r);
}

int main()
{
    candidato *vetor = malloc(sizeof(candidato) * 100001);
    long long s, f, e, voto, votos_validos = 0, votos_invalidos = 0;
    long long votos_totais = 0;

    scanf("%lld %lld %lld", &s, &f, &e);

    for (long long i = 10; i < 100000; i++)
        vetor[i].digitos = i;

    while (scanf("%lld", &voto) != EOF)
        if (voto >= 10)
        {
            votos_validos++;
            vetor[voto].votos++;
        }
        else
            votos_invalidos++;

    for (int i = 0, m = 10; i < 4; i++, m *= 10)
        merge_sort(vetor, m, m * 10);

    for (long long i = 99; i >= 10; i--)
        votos_totais += vetor[i].votos;

    printf("%lld %lld\n", votos_validos, votos_invalidos);

    int percentual = (float)vetor[99].votos / (float)votos_totais >= 0.51 ? 1 : 0;

    if (percentual)
        printf("%lld\n", vetor[99].digitos);
    else
        printf("Segundo turno\n");

    for (long long i = 999; s; i--, s--)
        printf("%lld ", vetor[i].digitos);
    printf("\n");

    for (long long i = 9999; f; i--, f--)
        printf("%lld ", vetor[i].digitos);
    printf("\n");

    for (long long i = 99999; e; i--, e--)
        printf("%lld ", vetor[i].digitos);
    printf("\n");

    printf("\n");
    
    return 0;
}