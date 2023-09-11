#include <stdio.h>
#include <stdlib.h>

struct point{
    int value;
};

int main(){
    struct point s;
    struct point *ponteiro = &s;

    // Atribuindo valor ao struct 's'
    s.value = 20;

    printf("%2d\n", s.value);
    printf("%2d\n", (*ponteiro).value);

    // Mudando o valor para 40
    (*ponteiro).value = 40;

    printf("%2d\n", s.value);
    printf("%2d\n", (*ponteiro).value);

    // Mudando o valor para 30
    ponteiro->value = 30;
    
    printf("%2d\n", s.value);
    printf("%2d", (*ponteiro).value);

    // Fazendo o retorno
    return 0;
}