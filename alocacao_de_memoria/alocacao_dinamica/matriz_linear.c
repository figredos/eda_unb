/*
 * Criando uma matriz linear usando alocação de memória
 *
 * Objetivo é alocar uma matriz de 6 colunas e 4 linhas da seguinte forma:
 *
 *   0 1 2 3 4 5/0 1 2 3 4 5/0 1 2 3 4 5/0 1 2 3 4 5
 */

#include <stdio.h>
#include <stdlib.h>
#define LINHA 4
#define COLUNA 6

int main()
{
    // Criando um ponteiro
    int *matriz;

    // Alocando na memória
    matriz = malloc(LINHA * COLUNA * sizeof(int));

    if (matriz)
    {
        // Definindo os elementos da matriz
        for (int i = 0; i < LINHA; i++)
            for (int j = 0; j < COLUNA; j++)
                matriz[i * COLUNA + j] = j;

        // Imprime a matriz
        for (int i = 0; i < 24; i++)
            printf("%d ", matriz[i]);

        // Libera memória alocada para a matriz
        free(matriz);
    }

    return 0;
}