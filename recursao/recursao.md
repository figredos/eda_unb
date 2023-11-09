# RECURSÃO

## O QUE É

É a propriedade de algo que pode se repetir várias vezes, onde há dependência entre os elementos do conjunto. Ou seja, o elemento atual depende da determinação de um elemento anterior ou posterior. Para o bom funcionamento de uma recursão, é necessário a presença de uma chamada 'condição de parada'. Essa condição é a representação de um requerimento necessário para a parada, o fim, daquela recursão.

O conceito de recursão é um que existe muito antes da programação, sendo extremamente presente, por exemplo, em alguns elementos da matemática. Alguns exemplos de recursão matemática, são o cálculo do Fatorial de um número, e a sequência de Fibonacci.

~~~C
//Fibonacci iterativo
int main()
{
    int n = 4;
    int f, f1, f2;
    f2 = 0;
    f1 = 1;
    f = n;

    for (int i = 2; i <= n; i++)
    {
        f = f1 + f2;

        f2 = f1;
        f1 = f;
    }

    printf("%d", f);

    return 0;
}
~~~

## FUNÇÕES RECURSIVAS

Na programação, a recursão vem do uso de funções dentro de si mesmas caso alguma condição seja, ou não, atingida sendo chamadas de funções recursivas. Essas funções recursivas contribuem na implementação de algoritmos complexos em códigos mais compactos. Sistemas atuais possibilitam uma execução eficiente das chamadas de funções recursivas (stacks, para empilhamento das funções, e compiladores eficientes, para otimizações).

Essas funções tem comportamento de uma pilha, onde em cada iteração, os dados são empilhados, inclusive o endereço de quem chamou a função (sendo na recursão, a função anterior quem fez essa chamada). Ao final das iterações o último invocado termina seu processamento e é retirado da pilha, com o topo dessa pilha retomando sua execução. O processo de desempilhamento continua até a base da pilha, assim possibilitando o invocador inicial a terminar seu processamento.

~~~C
//Fibonacci iterativo
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int a = fibonacci(3);

    printf("%d", a);

    return 0;
}
~~~

## VALIDADE DOS ALGORITMOS RECURSIVOS

A sequência recursiva precisa ser finita, tanto pela necessidade computacional (vez que um processo infinito pode ocupar memória de forma apenas finita), como também pela própria existência do código ser para atingir um objetivo finito. Para provar a validade de um algoritmo recursivo, podemos utilizar a indução matemática, mais especificamente, utilizando o método da indução finita. Esse método funciona de forma a provar as propriedades que são verdadeiras para uma sequência de objetos.

Como sempre, indução matemática é feita primeiramente testando um caso base, ou seja, testando se o algoritmo é valido para o menor caso possível, com o menor valor de 'x'. Em seguida, fazemos uma hipótese indutiva, onde assumimos que a função é verdadeira para todo x. Finalmente, testamos se a hipótese é válida para x + 1. Resumindo, usamos um caso base (condição de parada), e verificamos se em cada chamada, o valor da função recursiva tenda para o alcance da condição de parada (garantindo o término da função).

## USOS DA RECURSIVIDADE

Se uma instância for pequena, use força bruta, resolva diretamente, senão, reduza em instâncias menores do mesmo problema, resolvendo por partes e voltando para a instância original. Essa é a chamada técnica da divisão e conquista. 
