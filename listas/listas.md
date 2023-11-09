# Listas

## Estrutura de Dados Elementares

Para entender o que são listas e quais seus tipos, é necessário primeiramente entender o que é uma estrutura de dados.

Uma estrutura de dados nada mais é do que uma forma de se organizar uma coleção de dados. Essas estruturas, muitas vezes, possuem um conjunto de operações com os dados que organizam, como busca, troca, adição entre outros.

Estruturas elementares são aquelas usadas dentro de outras estruturas.

## Listas estáticas

São listas que contém o mesmo tipo de dados, com espaço consecutivo na memória RAM. Essas estruturas possuem acesso aleatório, ou seja, qualquer posição pode ser acessada facilmente através de um index (índice). O nome da estrutura corresponde ao seu endereço na memória. Podem ter tamanho fixo (stack) ou alocado dinâmicamente (heap).

Listas estáticas em C são representadas por vetores (ou arrays), que como citado acima, contém dados de um tipo, ocupam espaço consecutivo na memória e podem ser acessados usando índices.

Listas estáticas possuem algumas vantagens como proporcionarem fácil acesso, e desvantagens, como difícil manipulação. Como alternativa, podemos usar LISTAS ENCADEADAS.

## Listas simplesmente encadeadas

Representam um conjunto de nós (ou células). Cada nó contém um item e um link para outro nó. Essa estrutura é mais adequada para manipulações do que acessos, possuindo maior eficiência para rearranjar os itens (reapontamentos), contudo, não tem acesso direto a esses itens.

Algumas das operações possibilitadas por listas simplesmente encadeadas são, busca, inserção e remoção de nós.

### _**-Lista sem cabeça**_

~~~~C
//typedef struct item Item;
typedef int Item;
~~~~

~~~~C
typedef struct registro node;
struct registro
{
    Item info;
    node *prox;
}
~~~~

![Alt text](imagens\image-1.png)

### _**-Lista com cabeça**_

Em listas com cabeça, o primeiro nó e chamado de cabeça, ele é responsável por marcar o início da lista. Pode ser do mesmo tipo dos outros nós, tendo seu conteúdo completamente ignorado. Ou pode ter um tipo específico, aproveitando para guardar meta-dados, como o tamanho da lista, seu fim, etc.

Nesse tipo de lista, os elementos começam a partir do segundo nó, com o último nó apontando para NULL.

![Alt text](imagens\image-2.png)

~~~C
typedef int Item;

// Igual o restante da lista
typedef struct node no;
struct node
{
    Item info;
    no *prox;
}

// Específico para cabeça
typedef struct cabeca head;
struct cabeca
{
    int num_itens;
    no *proximo;
    no *ultimo;
}
~~~

![Alt text](imagens\image-3.png)

Listas simplesmente encadeads são implementadas na STL(Standard Template Library) do C++. Também implementado na <sys/queue.h> da libc.

## Listas duplamente encadeadas

Diferentemente das listas simplesmente encadeadas, essa estrutura de dados armazena informação do nó anterior e posterior. São muito úteis quando ocorrem muitas inserções e remoções, principalmente de elementos intermediários.

Nós anteriores ao primeiro e posteriores ao último tem valor NULL.


## Outras listas encadeadas

### -> Lista circular

Simplesmente o último nó aponta para o primeiro. Listas duplamente circulares são quando o último nó aponta para o primeiro e vice-versa.

### -> Multilista

Apontamentos para o próximo e anterior são independentes, não necessariamente um nó aponta de volta para o nó que aponta ele