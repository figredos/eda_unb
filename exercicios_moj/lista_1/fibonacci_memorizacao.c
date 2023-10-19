#include <stdio.h>
#include <stdlib.h>

//Função que retorna o número de fibonacci para o número passado como argumento
//Fazer de forma recursiva simples gera um algoritmo muito lento
//Portanto é necessário usar o método de divisão e conquista, definido a seguir
//Caso par: f(2k) = f(k) * (2 * f(k + 1) - f(k)), onde k = numero / 2
//Caso impar: f(2k) = f(k)^2 + f(k + 1)^2, onde k = (numero - 1) / 2

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
