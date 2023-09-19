#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_inicial = 3;
    int num_fatoriando = num_inicial;
    int total_fatorial = 1;

    while (num_fatoriando > 0)
    {
        total_fatorial *= num_fatoriando;
        num_fatoriando--; 
    }
    printf("%d! = %d\n", num_inicial, total_fatorial);
}
