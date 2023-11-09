# PONTEIROS

## O QUE SÃO

São variáveis capazes de armazenar e manipular endereços de memória, ou seja, são o endereço direto de uma variável na memória. Como qualquer outra variável, um ponteiro deve ser declarado, isso é feito pelo uso de um '*' antes do nome da variável. Ponteiros possuem tamanho fixo, com seu valor dependendo da arquitetura do OS. Pode ser NULL, valor 0, definido na interface stdlib. Além disso, quando queremos que um ponteiro possua o valor do endereço de uma variável qualquer, usamos '&':

~~~C
int main(){
    // Declarando as variáveis
    int numero;
    int *ponteiro;

    // Atribuido valores ao ponteiro
    ponteiro = NULL;
    ponteiro = &numero;

    // Atribuindo valor à variável 'numero'
    numero = 5;

    printf("%d\n", *ponteiro);  // *p == i (valor presente na posição da memória do valor de 'p')

    printf("%ld\n", sizeof(ponteiro));  // Buscando o tamanho da variável ponteiro

    // Fazendo retorno da função
    return 0;
}
~~~

Para imprimir ponteiros, usamos o especificador de formatação '%p'

## PONTEIROS DE PONTEIROS

São assim como ponteiros, usados para armazenar e manipular endereços de memória, sendo a grande diferença, seu uso voltado para ponteiros. Para criar um ponteiro de ponteiro, ao invés de '*', usamos '**' antes do nome do ponteiro.

~~~C
int main(){
    // Declarado as variáveis
    int numero = 1234;
    int *ponteiro;
    int **ponteiro_ponteiro;

    // Atribuindo valores aos ponteiros
    ponteiro = &numero;     // Conteúdo de 'ponteiro' é o valor na memória da posição de 'numero'
    ponteiro_ponteiro = &ponteiro;  // Conteúdo de 'ponteiro_ponteiro' é o valor na memória da posição de 'ponteiro'

    // Imprimindo o valor da variável e os valores que os conteúdos dos ponteiros apontam
    printf("%d\n", numero);
    printf("%d\n", *ponteiro);
    printf("%d\n", **ponteiro_ponteiro);
    
    // Imprimindo o valor na memória da posição de 'numero' e de 'ponteiro' e os valores contidos nos ponteiros
    printf("%d\n", &numero);
    printf("%d\n", ponteiro);
    printf("%d\n", &ponteiro);
    printf("%d\n", ponteiro_ponteiro);

    // Fazendo retorno
    return 0;
}
~~~

## VETORES X PONTEIROS

Vetores (arrays) são uma estrutura de dados em C. Quando declaramos um vetor em python, o que estamos fazendo 
efetivamente, é apontando para o endereço de memória da variável na primeira posição do array, mudando a posição
ao adicionar o número correspondente à posição do dado no array.

~~~C

int main(){
    // Criando variáveis
    int vetor[2] = {5, 4};
    int *ponteiro;

    // Atribuindo o ponteiro ao vetor
    ponteiro = vetor;

    // Mostrando a equivalência dos valores do ponteiro e do vetor (array)
    printf("%d\n", vetor[0]);
    printf("%d\n", *ponteiro);

    printf("%d\n", vetor[1]);
    printf("%d\n", *(ponteiro + 1));

    return 0;
}
~~~

O que acaba realmente sendo feito, é a soma de valores ao valor na memória gravado no ponteiro. 

## MATRIZ (multidimensional array) X PONTEIROS

Uma matriz em C, nada mais é do que um vetor (array) multidimensional, ou seja, matrizes se tratam de uma combinação de uma série de vetores. Assim como vetores podem ser tratados com ponteiros. Ao atribuirmos um ponteiro a uma matriz, o ponteiro consegue acessar todos os valores de todas as dimensões da matriz, simplesmente somando valores até o último valor presente da matriz.

~~~C
int main(){
    int matriz[3][2] = {{1, 2}, {3, 4}, {2, 2}};
    int *ponteiro;

    ponteiro = matriz[0];

    for (int i = 0; i < 6; i++){
        printf("%2d", *(ponteiro + i));
    }

    return 0;
}
~~~

## STRUCT X PONTEIROS

Structs são estruturas de dados que contém uma série de valores. Diferentemente de classes, structs não podem conter funções dentro de seu escopo (métodos). Para atribuir um ponteiro ao struct, é necessário usar seu local na memória, diferentemente de arrays. Para manipular algum valor dentro do struct usamos '->'.

~~~C
struct point{
    int value;
};

int main(){
    struct point s;
    struct point *ponteiro = &s;

    // Atribuindo valor ao struct 's'
    s.value = 20;

    printf("%2d\n", s.value);
    printf("%2d\n", (*ponteiro).value);

    // Mudando o valor para 40
    (*ponteiro).value = 40;

    printf("%2d\n", s.value);
    printf("%2d\n", (*ponteiro).value);

    // Mudando o valor para 30
    ponteiro->value = 30;
    
    printf("%2d\n", s.value);
    printf("%2d", (*ponteiro).value);

    // Fazendo o retorno
    return 0;
}
~~~

## FUNÇÕES X PONTEIROS

Assim como outras estruturas de C, podemos usar ponteiros em funções. Ponteiros de função não alocam memória, ou
seja, quando usados, apontam para o início do código executável. Diferentemente de outros ponteiros, os de fun-
ção, são declarados usando parênteses junto ao nome, e em seguida, são usados para descrever o tipo de dado que
será recebido por determinada função.

~~~C
// Criando funções que retornam prints
void funcao_1(int a){
    printf("%d\n", a);
}

void funcao_2(int a){
    printf("%d\n", a + 1);
}

// Função principal
int main(){
    // Declarando o ponteiro de funções, que recebe dados tipo int
    void (*f_ponteiro)(int);

    // Associando o ponteiro à função 1 
    f_ponteiro = &funcao_1;
    (*f_ponteiro)(10);  // Usando a função a partir do ponteiro
    printf("%d\n", f_ponteiro); // Imprimindo a localização na memória da função

    // Associando o ponteiro à função 2 
    f_ponteiro = &funcao_2;
    (*f_ponteiro)(10);  // Usando a função a partir do ponteiro
    printf("%d\n", f_ponteiro); // Imprimindo a localização na memória da função

    // Fazendo o retorno
    return 0;
}
~~~

O tipo do ponteiro é dado a partir da função.