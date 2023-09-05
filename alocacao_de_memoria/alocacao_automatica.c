#include <stdio.h>

//Criando a função 'fatorial'
long int fatorial(int numero){
    long int parcial;   //Criando a variável 'parcial' que armazenará o valor parcial do fatorial

    printf("Antes: %d\n", numero);  //Imprimindo o valor inicial do número

    //Verificando o valor do número
    if(numero < 2){
        parcial = 1;
    }
    else{
        parcial = numero * fatorial(numero - 1);    //Fazendo uma chamada recursiva da função
    }

    printf("Depois: %ld, Parcial: %ld\n", numero, parcial); //Imprimindo o valor final do número e o valor parcial

    //Fazendo o retorno do valor parcial
    return parcial; 
}

//Criando a função principal
int main(void){
    //Imprimindo o valor obtido com a função 'fatorial(6)'
    printf("6! = %ld\n", fatorial(6));

    //Fazendo o retorno
    return 0;
}