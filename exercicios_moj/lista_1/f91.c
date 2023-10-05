#include <stdio.h>
#include <stdlib.h>

int f91(int numero)
{
    if (numero <= 100)
        return f91(f91(numero + 11));

    else
        return numero - 10;
}

int main()
{
    int numero = 1;

    do
    {
        scanf("%d", &numero);
        if (numero != 0)
            printf("f91(%d) = %d\n", numero, f91(numero));
    }
    while (numero != 0);
    
    return 0;
}