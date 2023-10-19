//Inclui pacotes
#include <stdio.h>
#include <stdlib.h>

//Cria função f91
int f91(int numero)
{
    if (numero <= 100)  //Se o número for maior ou igual que 100, faz-se a recursão da função do número + 11
        return f91(f91(numero + 11));

    else    //Caso o número seja menor que 100, retornamos o número - 10
        return numero - 10;
}

int main()
{
    int numero = 1; //Inicializando a função

    do  // Enquanto o número dado como input for diferente de 0, faz a chamada da função e imprime o resultado
    {
        scanf("%d", &numero);
        if (numero != 0)
            printf("f91(%d) = %d\n", numero, f91(numero));
    }
    while (numero != 0);
    
    return 0;
}