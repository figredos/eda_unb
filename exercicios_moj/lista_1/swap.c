#include <stdio.h>
#include <stdlib.h>

// Função recebe dois ponteiros (tem que passar o endereço com '&')
void swap(int *a, int *b)
{
    int temp;   // Criando variável temporária

    // Trocando os valores
    temp = *a;
    *a = *b;
    *b = temp;
}

