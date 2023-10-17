# Filas

## O QUE É

Filas são um tipo de TAD que consiste no alinhamento de uma série de indivíduos ou objetos em sequência, de modo que um esteja imediatamente atrás do outro.

Filas processam dados que estão na frente primeiro, ou _"First In First Out"_ (_FIFO_). O primeiro a entrar é o primeiro a sair, é um modelo "justo" o processamento de dados obedece a ordem de chegada (usado para sistema de inscrições, julgadores automáticos, etc.). Fila de impressão, transmissão de mensagens/pacotes em redes de computadores, aplicações cliente x servidor (fila de requisições), fila de processos no sistema operacional, gravação de mídias (ordem dos dados importa), busca (varredura pelos mais próximos primeiro).

Inserções são feitas no fim, e remoções são feitas no início. Possui complexidade constante. 

Operações básicas:
    - vazia
    - tamanho
    - primeiro - busca_inicio
    - ultimo - busca_fim
    - enfileira - insere_fim
    - desenfileira - remove_inicio

## Implementação

Filas podem ser implementadas de uma série de maneiras, veremos a implementação usando listas estáticas e usando listas encadeadas.

### Fila - lista estática

#### Criando uma fila

~~~C
#define N 7

int fila[N];
int p, u;

void criar_fila()
{
    p = u = 0;
}
~~~

#### Fila vazia

~~~C
#define N 7

int fila[N];
int p, u;

void criar_fila()
{
    p == u;
}
~~~

#### Remoção no início da fila

Objetivo é desenfileirar, o início da fila "p" é deslocado para mais próximo do fim ("removendo" logicamente o elemento da fila).

~~~C
#define N 7

int fila[N];
int p, u;

int desenfileira()
{
    return fila[p++];
}
~~~

### Inserção no fim da fila

Objetivo é enfileirar, o elemento é colocado na posição indicada por "u" (ultimo elemento), com o fim da fila sendo deslocado.

~~~C
#define N 7

int fila[N];
int p, u;

void enfileira(int y)
{
    fila[u++] = y;
}
~~~

### Fila cheia

É um fenômeno que ocorre quando todos os elementos alocados pela fila estática estão ocupados. Identificamos se a fila está cheia quando u = N. Caso tentemos fazer uma inserção em uma lista cheia, ocorre o transbordamento da lista