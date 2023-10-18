// // Incompleto mas funciona 0% de acerto
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void rumo_9(char numero[], int *multiplo, int *profundidade)
// {
//     int soma = 0;
//     char *soma_final = calloc(sizeof(char), strlen(numero));

//     for (int i = 0; i < strlen(numero); i++)
//     {
//         soma = soma + (numero[i] - 48);
//     }

//     if (soma >= 10)
//     {
//         for (int i = 0; soma > 0; i++)
//         {
//             soma_final[i] = 48 + (soma % 10);
//             soma = (soma - (soma % 10)) / 10;
//         }

//         (*profundidade)++;

//         rumo_9(soma_final, multiplo, profundidade);
//     }
//     else
//     {   
//         if ((soma % 9) == 0)
//             *multiplo = 1;
//     }
// }

// int main()
// {
//     char *numero = malloc(sizeof(char) * 1000);

//     int multiplo = 0, profundidade = 1;

//     do
//     {
//         fgets(numero, 1000, stdin);

//         numero[strlen(numero) - 1] = 0;

//         if (numero[0] != 0)
//         {
//             char *numero_novo = numero;

//             rumo_9(numero, &multiplo, &profundidade);

//             if (multiplo == 1)
//                 printf("%s is a multiple of 9 and has 9-degree %d. \n", numero_novo, profundidade);
//             else
//                 printf("%s is not a multiple of 9. \n", numero_novo);

//             multiplo = 0;
//             profundidade = 1;
//         }

//     } while (numero[0] != 0);

//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main() {
    char number[1001];

    while (1) {
        scanf("%s", number);

        if (number[0] == '0') {
            break;
        }

        int len = strlen(number);
        int sum = 0;
        int degree = 0;

        for (int i = 0; i < len; i++) {
            sum += number[i] - '0';
        }

        if (sum % 9 == 0) {
            while (sum > 9) {
                int newSum = 0;
                while (sum > 0) {
                    newSum += sum % 10;
                    sum /= 10;
                }
                sum = newSum;
                degree++;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n", number, degree + 1);
        } else {
            printf("%s is not a multiple of 9.\n", number);
        }
    }

    return 0;
}
