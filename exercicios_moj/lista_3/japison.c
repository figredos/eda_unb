#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tradutor
{
    char japones[100];
    char portugues[100];
} tradutor;

void merge(tradutor *v, int l, int m, int r)
{
    tradutor *auxiliar = malloc(sizeof(tradutor) * (r - l));

    int i = l, j = m, k = 0;
    while (i < m && j < r)
        auxiliar[k++] = strcmp(v[i].japones, v[j].japones) <= 0 ? v[i++] : v[j++];

    while (i < m)
        auxiliar[k++] = v[i++];
    while (j < r)
        auxiliar[k++] = v[j++];

    for (i = l; i < r; i++)
        v[i] = auxiliar[i - l];

    free(auxiliar);
}

void merge_sort(tradutor *v, int l, int r)
{
    if (r - 1 <= l)
        return;

    int meio = l + (r - l) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio, r);
    merge(v, l, meio, r);
}

int busca_binaria(tradutor *v, int n, char *dado)
{
    int l = 0, h = n;

    while (h >= l)
    {
        int meio = l + (h - l) / 2;
        if (!strcmp(v[meio].japones, dado))
            return meio;
        else if (strcmp(v[meio].japones, dado) > 0)
            h = meio - 1;
        else
            l = meio + 1;
    }
    return -1;
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--)
    {
        int m, n;

        scanf("%d %d", &m, &n);

        tradutor *vetor = malloc(sizeof(tradutor) * m);
        char frase[100];

        for (int i = 0; i < m; i++)
        {
            scanf("\n");
            fgets(vetor[i].japones, sizeof(vetor[i].japones), stdin);
            fgets(vetor[i].portugues, sizeof(vetor[i].portugues), stdin);

            vetor[i].japones[strcspn(vetor[i].japones, "\n")] = '\0';
            vetor[i].portugues[strcspn(vetor[i].portugues, "\n")] = '\0';
        }

        merge_sort(vetor, 0, m);

        // printf("\n");
        // for (int i = 0; i < m; i++)
        // {
        //     printf("%s %s\n", vetor[i].japones, vetor[i].portugues);
        // }

        while (n--)
        {
            int indice = 0;
            int i_palavra = 0;

            scanf("\n");
            fgets(frase, sizeof(frase), stdin);
            frase[strcspn(frase, "\n")] = '\0';

            while (1)
            {
                char palavra[100];
                while (frase[indice] != ' ' && frase[indice] != '\0')
                    palavra[i_palavra++] = frase[indice++];

                palavra[i_palavra] = '\0';
                indice++;

                int resposta = busca_binaria(vetor, m, palavra);

                if (resposta == -1)
                    printf("%s", palavra);
                else
                    printf("%s", vetor[resposta].portugues);

                if (frase[indice] == '\0')
                    break;
                else
                    printf(" ");
                
                i_palavra = 0;
            }
            printf("\n");
        }
    }

    return 0;
}