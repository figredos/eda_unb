#include <stdio.h>

int a = 0;  //Variável global, alocação estática 

void incrementa(void){
    int b = 0;  //Variável local, alocação automática
    static int c = 0;   //variável local, alocação estática

    printf("a: %d, b: %d, c: %d\n", a, b, c);

    a++;
    b++;
    c++;
}

int main(void){
    int i;

    for(i = 0; i < 5; i++){
        incrementa();
    }
    
    return 0;
}