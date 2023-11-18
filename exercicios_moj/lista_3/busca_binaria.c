#include <stdio.h>
#include <stdlib.h>

//Função busca binária, retorna o indice v[j] >= x > v[j - 1] 
int busca_binaria(int *v, int tam, int dado)
{
    int l = 0, h = tam;

    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (dado <= v[m])
            h = m;
        else
            l = m + 1;
    }

    return l;
}

int main()
{
    int n, m, dado;
    scanf("%d %d", &n, &m);

    int *v = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    while (m--)
    {
        scanf("%d", &dado);
        int r = busca_binaria(v, n, dado);

        printf("%d\n", r);
    }
    return 0;
}
