/*
 * Criando uma matriz de vetores usando alocação de memória
 *
 * Objetivo é alocar uma matriz de 6 colunas e 4 linhas da seguinte forma:
 *
 *   0 1 2 3 4 5
 *   0 1 2 3 4 5
 *   0 1 2 3 4 5
 *   0 1 2 3 4 5
 */

#include <stdio.h>
#include <stdlib.h>
#define LINHA 4
#define COLUNA 6

int main()
{
    // Criando ponteiro de ponteiro
    int **matriz;

    // Alocando vetor para as linhas
    matriz = malloc(LINHA * sizeof(int));

    if (matriz)
    {
        // Alocando vetores para as colunas
        for (int i = 0; i < LINHA; i++)
            matriz[i] = malloc(COLUNA * sizeof(int));

        // Definindo os elementos da matriz
        for (int i = 0; i < LINHA; i++)
            for (int j = 0; j < COLUNA; j++)
                matriz[i][j] = j;

        // Imprimindo a matriz
        for (int i = 0; i < LINHA; i++)
        {
            for (int j = 0; j < COLUNA; j++)
                printf("%d ", matriz[i][j]);

            printf("\n");
        }

        // Libera memória alocada para a matriz
        for (int i = 0; i < LINHA; i++)
            free(matriz[i]);

        free(matriz);
    }

    return 0;
}