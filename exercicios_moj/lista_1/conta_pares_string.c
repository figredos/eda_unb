// Importando pacotes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função que conta pares
void conta_pares_string(char *string, int indice, int *conta_pares)
{
    if (string[indice + 1] != 0)    //Verifica se a string acabou
    {
        if (string[indice + 2] == string[indice])   //Compara o índice atual, com dois índices a frente na string
        {
            (*conta_pares)++;   //Aumenta o ponteiro

            conta_pares_string(string, indice + 1, conta_pares);    //Faz recursão aumentando o índice
        }
        else
            conta_pares_string(string, indice + 1, conta_pares);    //Faz recursão aumentando o índice
    }
}

int main()
{
    char *string =  malloc(201 * sizeof(char)); //Cria string alocando memória suficiente
    int conta_pares = 0, indice = 0;    //Inicializa variáveis referente ao número de pares e ao índice

    fgets(string, 201, stdin);  //Obtém input

    conta_pares_string(string, indice, &conta_pares);   //Executa a função

    printf("%d\n", conta_pares);  //Imprime o número de pares

    return 0;
}
// Tenho que primeiramente checar se a string[indice + 2] corresponde à string[indice]
