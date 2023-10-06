#include <stdio.h>
#include <stdlib.h>

int soma_digitos(long long int numero, int soma)
{
    if (numero == 0)
        return soma;

    else
    {
        soma = soma + (numero % 10);
        numero = (numero - (numero % 10)) / 10;
        return soma_digitos(numero, soma);
    }
}

int main()
{
    long long int numero;
    int soma;

    scanf("%lld", &numero);

    soma = soma_digitos(numero, 0);

    printf("%d\n", soma);

    return 0;
}