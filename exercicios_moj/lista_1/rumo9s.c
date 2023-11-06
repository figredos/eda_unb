// Incluindo pacotes
#include <stdio.h>
#include <string.h>

int main()
{
    char number[1001]; // Inicializando vetor numero

    while (1)
    {
        scanf("%s", number);

        if (number[0] == '0') // Se o número for 0, quebra o programa
            break;

        int len = strlen(number);
        int sum = 0;
        int degree = 0;

        for (int i = 0; i < len; i++)
            sum += number[i] - '0'; // Calcula a soma dos digitos

        if (sum % 9 == 0)   //Se a soma for divisível por 9 executa o programa e conta o grau
        {
            while (sum > 9)
            {
                int newSum = 0;
                while (sum > 0)
                {
                    newSum += sum % 10;
                    sum /= 10;
                }
                sum = newSum;
                degree++;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n", number, degree + 1);
        }
        else    //Caso o número não for divisível por 9 imprima
            printf("%s is not a multiple of 9.\n", number);
    }

    return 0;
}
