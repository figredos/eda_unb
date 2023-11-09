# Alocação de memória

## O QUE É

 A alocação de memória consiste no processo de solicitar/utilizar memória durante o processo de execução de um programa. É uma das bases da ciência da computação, e envolve uma série de conhecimentos, como os abordados abaixo.

OBS.: Cada byte tem 8 bits, e possui um local específico na memória.

## PROCESSO

É um programa em execução, cada processo possuo uma porção de memória, cada porção separada por segmentos, esses são:

Text: contém o código do programa e suas constantes. Esse segmento é alocado durante a criação do processo ("exec") e permanece do mesmo tamanho durante toda a vida do processo.

Data: este segmento é a memória de trabalho do processo, aonde ficam alocadas as variáveis globais e estáticas. Tem tamanho fixo ao longo da execução do processo.

Stack: Contém a pilha de execução, onde são armazenados os parâmetros, endereços de retorno e variáveis locais de funções. Pode variar de tamanho durante a execução do processo.

Heap: contém blocos de memória alocadas dinamicamente, a pedido do processo, durante sua execução. Varia de tamanho durante a vida do processo.

OBS.: Comando é um size executável. Lista os tamanhos de seção e tamanhos totais dos arquivos binários.

## TIPOS DE ALOCAÇÃO

A linguagem de programação "C" suporta apenas 3 tipos de alocação:

Alocação estática: ocorre quando são declaradas variáveis globais ou estáticas, geralmente alocadas em "Data"

Alocação automática: ocorre quando são declaradas variáveis locais e parâmetros de funções. O espaço para aloca-
ção dessas variáveis é reservado quando a função é invocada, e liberado quando a função termina. Geralmente é usada a pilha (stack).

Alocação dinâmica: quando o processo requisita explicitamente um bloco de memória para armazenar dados. O controle das áreas alocadas dinamicamente é manual, ou semi-automático: O programador é responsável por liberar as áreas alocadas dinamicamente. A alocação dinâmica geralmente se usa a área de heap.

### ALOCAÇÃO ESTÁTICA

Alocação estáticaocorre com variáveis globais (alocadas fora de funções) ou quando variáveis locais (internas de uma função) são alocadas usando o modificador "static". Uma variável alocada estaticamente mantém seu valor durante toda da vida do programa, exceto quando explicitamente modificada.

~~~C
int a = 0;  //Variável global, alocação estática 

void incrementa()
{
    int b = 0;  //Variável local, alocação automática
    static int c = 0;   //variável local, alocação estática
    printf("a: %d, b: %d, c: %d\n", a, b, c);
    a++;
    b++;
    c++;
}

int main()
{
    int i;
    for(i = 0; i < 5; i++)
        incrementa();
    return 0;
}
~~~

A pilha de execução do programa normalmente é pequena (8MB ou menos). Por isso a tentativa de alocar variáveis locais muito grandes pode resultar em erro de compilação, ou de execução (SIGSEGV - Segmentation Fault). Para tais situações devem ser usadas variáveis globais (estáticas) ou variáveis dinâmicas.

### ALOCAÇÃO AUTOMÁTICA

Por padrão, as variáveis definidas dentro de uma função (variáveis locais e parâmetros) são alocadas de forma automática na pilha de execução do programa (stack) a cada chamada da função, sendo descartadas quando a função encerra. Isso é o que ocorre com a variável 'b' vista no exemplo 'alocacao_estatica.c'.

~~~C
long int fatorial(int numero){
    long int parcial;   //Criando a variável 'parcial' que armazenará o valor parcial do fatorial

    printf("Antes: %d\n", numero);  //Imprimindo o valor inicial do número

    //Verificando o valor do número
    if(numero < 2)
        parcial = 1;
    else
        parcial = numero * fatorial(numero - 1);    //Fazendo uma chamada recursiva da função

    printf("Depois: %ld, Parcial: %ld\n", numero, parcial); //Imprimindo o valor final do número e o valor parcial

    //Fazendo o retorno do valor parcial
    return parcial; 
}

//Criando a função principal
int main(){
    //Imprimindo o valor obtido com a função 'fatorial(6)'
    printf("6! = %ld\n", fatorial(6));

    //Fazendo o retorno
    return 0;
}
~~~

### ALOCAÇÃO DINÂMICA

Na alocação dinâmica, o programa solicita explicitamente áreas de memória ao sistema operacional, as utiliza e depois as libera quando não forem mais necessárias, ou quando o programa encerrar. A memória é alocada durante a execução do programa, possibilitando também, alocar tamanhos maiores do que o permitido pela stack. Essa alocação é feita no segmento heap de cada processo. A alocação dinâmica possibilita a maior organização dos dados, que vão diminuindo/aumentando com novas entradas. No C, a alocação dinâmica não existe nativamente, a biblioteca 'stdlib.h' é responsável pela implementação dessa alocação na linguagem.

#### OPERADOR SIZEOF

É uma ferramenta do C que mostra o tamanho em bytes de determinado dado. Recebe dois parâmetros, primeiramente recebe o tipo do dado, em seguida o nome da variável. É muito usada para "informar" funções de alocação dinâmica o quanto de memória a ser usado, dado que virá conforme a variável e seu tipo.

#### FUNÇÕES MALLOC

Alocam uma quantidade de bytes, e retornam um ponteiro da memória alocada. A memória não é inicializada, retorna NULL em caso de erro, sendo também, uma estratégia otimista, visto que, não é garantida a disponibilidade da memória. Se a quantidade requerida for zero, retorna um valor que pode ser passado para a função que libera a memória. A função malloc recebe como argumento o tamanho em bytes para alocação de memória.

~~~C
int main(){
    // Alocando memória com malloc
    int *p = malloc(sizeof(int));   // 1 int
    char *nome = malloc(sizeof(char)*50);   // String de 50 posições
    float *f = malloc(sizeof(float)*10);    // Vetor float de 10 posições
    int *i = (int *)malloc(5*sizeof(int));  // typecast dos retornos das funções

    // Usando a memória alocada previamente
    if (f){
        f[1] = 4;
        printf("%f\n", f[1]);
    }
    
    // Criando um struct
    struct endereco{
        char rua[100];
        int numero;
    };
    
    // Alocando memória dinamicamente
    struct endereco *ponteiro = malloc(sizeof(struct endereco));

    // Usando a memória alocada previamente
    if (ponteiro){
        ponteiro->numero = 324;
    }   

    // Fazendo retorno
    return 0;
}
~~~

#### FUNÇÕES FREE

São responsáveis por liberar o espaço previamente alocado dinamicamente, apontado por um ponteiro. A função não retorna valor, e libera uma porção para novas alocações. Chamadas repetidas para o mesmo ponteiro causam erros inesperados.

~~~C
int main(){
    // Alocando memória para um int
    int *p = malloc(sizeof(int));
    
    // Liberando a memória ocupada pelo ponteiro
    free(p);

    // Fazendo o retorno
    return 0;
}
~~~

#### FUNÇÕES CALLOC

Alocam a memória para um array de A elementos de tamanho N bytes (calloc(A, N)), retornando um ponteiro da memória alocada (NULL caso erro). Caso a memória necessária seja 0, retorna um valor que pode ser passado para a função 'FREE'.

#### FUNÇÕES REALLOC

Altera o tamanho do bloco de memória apontado por um ponteiro, o conteúdo anterior não é afetado. Caso o tamanho seja maior, a memória adicionada não é inicializada, se o ponteiro for NULL, é alocado como uma nova porção de memória (malloc). Retorna um ponteiro para a nova área alocada (pode ser a mesma ou maior que a original). Retorna Null em caso de erro (bloco original não é afetado, ficando inalterado), se o ponteiro não for NULL, e for requisitado 0 bytes, o espaço apontado é liberado (FREE).