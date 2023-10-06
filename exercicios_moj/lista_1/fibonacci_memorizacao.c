#include <stdio.h>
#include <stdlib.h>

long int fibonacci(int numero)
{
    if (numero == 0)
        return 0;

    else if (numero <= 2)
        return 1;

    long int k = 0;

    if (numero % 2)
    {
        k = (numero - 1) / 2;
        return fibonacci(k) * fibonacci(k) + fibonacci(k + 1) * fibonacci(k + 1);
    }

    else
    {
        k = numero / 2;
        return fibonacci(k) * (2 * fibonacci(k + 1) - fibonacci(k));
    }
}

// int main()
// {
//     int numero;

//     scanf("%d", &numero);

//     long int resultado = fibonacci(numero);

//     printf("%ld", resultado);

//     return 0;
// }
