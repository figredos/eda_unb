# Filas

## O QUE SÃO

Uma fila é uma estutura de dados dinâmica que admite remoção de elementos e inserção de novos objetos. Mais especificamente, uma fila (queue) é uma estrutura sujeita à seguinte regra de operação: cada remoção remove o elemento mais antigo da fila, isto é, o elemento que está na estrutura há mais tempo.

Em outras palavras, o primeiro objeto inserido na fila é também o primeiro a ser removido. Essa política é conhecida pela sigla FIFO (_*First-In-First-Out*_).

## Implementação com vetor

Suponha que a fila se encontra em um vetor fila[0...N-1]. Digamos que a parte ocupada pela fila é:
<p align="center">
fila[p...u-1]
</p>

O primeiro elemento da fila está na posição p, e o último na posição u-1. A fila está vazia se p==u e cheia se u==N. 

![Alt text](imagens\image.png)

Para tirar/remover um elemento da fila, basta fazer:

~~~C
x = fila[p++];
~~~

Para colocar/inserir um objeto y na fila, basta fazer:

~~~C
y = fila[u++];
~~~

Para realizar essas operações é necessário fazer algumas checagens, por exemplo se a fila está vazia (para remoção) e se a fila não estiver cheia (para inserção). Ambos os casos geram erros, caso a fila estiver cheia e ocorrer uma inserção, acaba ocorrendo um transbordamento (ou _overflow_).

## Implementação circular

Na implementação vetorial simples, a fila "anda para a direita" dentro do vetor que a abriga. Isso pode tornar difícil prever o valor que o parâmetro N deve ter para evitar que a fila transborde. Uma implementação "circular" pode ajudar a tornar um transbordamento menos provável.

A seguir, definimos duas filas, uma fila[0...N-1] e outra fila[0...u][p...N-1]

![Alt text](imagens\image-1.png)

Teremos sempre 0<= p< N e 0<= u < N, mas não podemos supor que p <= u. Assim, podemos definir que a fila está vazia se u==p, e cheia se u+1 = p, ou u+1==N e p==0 (ou seja, se (u+1)%N==p). A posição anterior a p ficará sempre desocupada para que possamos distinguir uma fila cheia de uma fila vazia. Com essas convenções, a remoção de um elemento da fila pode ser escrita como segue.

~~~C
int tira_da_fila()
{
    int x = fila[p++];

    if (p == N)
        p = 0;
    
    return x
}

//Desde que a fila não esteja vazia.

void coloca_na_fila(int y)
{
    fila[u++] = y;
    
    if(u == N)
        u = 0;
}

//Desde que a fila não esteja cheia.
~~~

## Implementação em vetor com redimensionamento

Nem sempre é possível prever a quantidade de espaço que deve ser reservada para a fila de modo a evitar transbordamentos. Se o vetor que abriga a fila foi alocado dinamicamente (usando a função malloc), é possível resolver essa dificuldade _*redimensionando*_ o vetor. Ou seja, toda vez que a fila ficar cheia, aloque um vetor maior e transfira a fila para esse novo vetor. Para evitar redimensionamentos frequentes, convém que o novo vetor seja pelo menos duas vezes maior que o original.

~~~C
void redimensiona()
{
    N *= 2;
    fila = realloc(fila, N * sizeof(int));
}

// OU (sem usar realloc)

void redimensiona()
{
    N *= 2;
    int *novo;

    novo = malloc(N * sizeof(int));

    for (int i = p; i < u; i++)
        novo[i] = fila[i];

    fila = novo;
}
~~~

## Fila implementada em uma lista encadeada

Suponhamos que as células da lista são do tipo célula a seguir;

~~~C
typedef struct celula
{
    int conteúdo;
    struct celula *prox;
} celula;
~~~

É preciso tomar algumas decisões de projeto sobre como a fila vai morar na lista. Vamos supor que nossa lista encadeada é circular, com a última célula pontando para a primeira. Vamos supor também que a lista tem uma célula-cabeça, que não é removida nem se a lista ficar vazia. Assim, o primeiro elemento da fila fica na segunda célula e o último elemento fica na célula anterior à cabeça.

Um ponteiro "fi" aponta a célula cabeça. A fila está vazia se fi->prox == fi. Uma fila vazia pode ser criada e inicializada assim:

~~~C
celula *fi;
fi = malloc(sizeof(celula));

fi->prox = fi;
~~~

Feito isso, podemos definir as funções de manipulação da fila.

~~~C
/*Tira um elemento da fila fi e 
devolve o conteúdo do elemento não removido.
Supõe que a fila não está vazia
*/

int tira_da_fila(celula *fi)
{
    celula *lixo = fi->prox;
    int x = lixo->conteúdo;

    fi->prox = lixo->prox;

    return x;
}

/*Coloca um novo elemento com conteúdo y
na fila fi. Devolve o endereço da 
cabeça da fila resultante.
*/

celula *coloca_na_fila(int y, celula *fi)
{
    celula *nova = malloc(sizeof(celula));

    nova->prox = fi->prox;

    fi->prox = nova;
    fi->conteudo = y;

    return nova;
}
~~~
