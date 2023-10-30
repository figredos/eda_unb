#include <stdio.h>

int main() {
    int n = 7;
    // scanf("%d", &n);

    int pilha[n];
    int topo = 0; // Índice do topo da pilha
    int descartadas[n - 1];
    int descartadas_index = 0;

    // Inicializa a pilha com os valores de 1 até n
    for (int i = 0; i < n; i++) {
        pilha[i] = i + 1;
    }

    // Imprime as cartas descartadas
    printf("Cartas descartadas:");
    while (topo < n) {
        if (descartadas_index > 0) {
            printf(",");
        }
        printf(" %d", pilha[topo]);
        descartadas[descartadas_index] = pilha[topo];
        descartadas_index++;
        topo++;

        if (topo < n -1) {
            // Move a próxima carta para a base da pilha
            int carta_movida = pilha[topo];
            for (int i = topo; i < n - 1; i++) {
                pilha[i] = pilha[i + 1];
            }
            pilha[n - 1] = carta_movida;
        }
    }

    // Imprime a última carta restante
    printf("\nCarta restante: %d\n", pilha[0]);

    return 0;
}
