#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bota_esq[61] = {0};
    int bota_dir[61] = {0};
    int conta_pares = 0;
    int tamanho;
    char pe;

    while (scanf("%d %c", &tamanho, &pe) != EOF)
    {
        if (pe == 68)
            bota_dir[tamanho]++;
        else
            bota_esq[tamanho]++;
    }

    for (int i = 30; i < 61; i++)
    {
        if (bota_dir[i] < bota_esq[i])
            conta_pares += bota_dir[i];
        else
            conta_pares += bota_esq[i];
    }

    printf("%d\n", conta_pares);

    return 0;
}
