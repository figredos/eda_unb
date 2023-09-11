#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[3][2] = {{1, 2}, {3, 4}, {2, 2}};
    int *ponteiro;

    ponteiro = matriz[0];

    for (int i = 0; i < 6; i++){
        printf("%2d", *(ponteiro + i));
    }

    return 0;
}