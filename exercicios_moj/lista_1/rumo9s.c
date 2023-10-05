#include <stdio.h>

void rumo_9_char(char* numero, int *multiplo, int *profundidade)
{

}


void rumo_9(int numero, int *multiplo, int *profundidade)
{
    int soma = 0;

    while (numero != 0)
    {
        soma = soma + (numero % 10);
        numero = (numero - (numero % 10))/10;
    }

    if (soma >= 10)
    {
        *profundidade = *profundidade + 1;
        rumo_9(soma, multiplo, profundidade);
    }      
    else
    {
        if((soma % 9 )== 0)
            *multiplo = 1;
    }
}

// int main()
// {
//     int numero, multiplo = 0, profundidade = 1;
//     do
//     {
//         scanf("%d", &numero);
//         if (numero != 0)
//             rumo_9(numero, &multiplo, &profundidade);
//             printf("%d %d %d\n", numero, multiplo, profundidade);
//     }
//     while (numero != 0);
    
//     return 0;
// }

int main()
{
    int numero[1000] = 999999999999999999999, multiplo = 0, profundidade = 1;

    rumo_9 (numero, &multiplo, &profundidade);

    printf("%d %d %d\n", numero, multiplo, profundidade);

    return 0;
}