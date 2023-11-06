//Incluindo pacotes
#include <stdio.h>
#include <stdlib.h>

//Função que soma os dígitos de um número recursivamente
int soma_digitos(long long int numero, int soma)
{
    if (numero == 0)    //Condição de parada
        return soma;

    else    
    {
        /*Subtraímos o valor do módulo do número por 10 do valor do número, em seguida atualizamos o valor do 
        número com o valor do módulo do número por 10, finalmente dividimos esse valor por 10*/
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