# ALGORITMOS DE ORDENAÇÃO ELEMENTARES

Algumas macros importantes para o entendimento dos códigos abaixo:

~~~C
#define exch(A, B) (int t = A; A = B; B = t)

~~~



## SELECTION SORT

O algoritmo de Selection Sort consiste em selecionar e posicionar. Selecionamos o menor item, posicionamos esse item no inicio (trocando com o item na primeira posição). Selecionamos o segundo menor item, posicionamos esse item na segunda posição (trocando com o item presente nessa posição), repetimos esse processo para os *n* elementos do vetor.

~~~C
void selection_sort(int v[], int l, int r)
{
    int menor;
    for(int i = l; i < r; i++)
    {
        menor = i;

        for(int j = i + 1; j <= r; j++)
            if (v[j] < v[menor])
                menor = j;

        if (i != menor)
            exch(v[i], v[menor]);
    }
}
~~~

A complexidade assintótica do Selection Sort é O($N^2$), vez que são cerca de $\frac{N^2}{2}$ comparações e trocas.

Não é um algoritmo adaptativo, vez que se o primeiro item for o menor, implica que não é necessário percorrer o vetor na primeira passada.

Também não é um código estável pois não mantém a ordem relativa. Contudo, é possível gerar um Selection Sort estável, uma forma de fazer isso é não realizar o swap, abrindo um espaço na posição e empurrando os itens para frente. É valido questionar a qualidade dessa solução.

É um algoritmo in-place pois não copia os conteúdos para outra estrutura de dados e não utiliza memória extra significativa.

## BUBBLE SORT

O algoritmo do Bubble Sort funciona da seguinte maneira. Primeiramente "flutuamos" um item (geralmente o primeiro), ao acharmos uma "bolha" com valor maior que a primeira, essa passa a flutuar (trocamos). Ao final da execução, o maior (ou menor) está no topo. Executamos o código até o vetor inteiro estar ordenado.

~~~C
void bubble_sort(int v[], int l, int r)
{
    for(; r > l; r--)
    {
        for(int j = l; j < r; j++)
            if(v[j] > v[j + 1])
                exch(v[j], v[j + 1])
    }
}
~~~

A complexidade assintótica do Bubble Sort é O($N²$), tem cerca de $\frac{N²}{2} comparações e $\frac{N²}{2}$ trocas. Contudo no seu melhor caso é O(N).

É um código adaptativo, vez que a ordenação diminui o processamento.

É um algoritmo estável também, pois mantém a ordem dos elementos iguais.

É um algoritmo in-order pois não usa memória extra significativa nem copia os conteúdos para outra estrutura de dados.

O Bubble Sort é um algoritmo menos eficiente que o selection sort. A versão otimizada do Bubble Sort é chamada ***Shaker Sort*** e consiste em realizar uma iteração para colocar o menor elemento em cima, e na volta colocar o maior elemento no topo.

O vetor estar ordenado configura o pior caso para um bubble sort. Portanto, existe uma forma de melhorar esse código, de forma a evitar executar o algoritmo caso o vetor estiver ordenado:

~~~C
void bubble_sort(int v[], int l, int r)
{
    int swap = 1;
    for(; r > l && swap; r--)
    {
        swap = 0;
        for(int j = l; j < r; j++)
            if(v[j] > v[j + 1])
            {
                exch(v[j], v[j + 1]);
                swap = 1;
            }
    }
}
~~~

Ao usar a variável swap, verificamos se em algum momento foi feita alguma troca no vetor. Caso não tenha acontecido nenhuma troca, o laço é quebrado, fazendo com que o vetor não seja percorrido mais que uma vez. 

## Insertion Sort

O algoritmo do Insertion Sort consiste em inserir cada elemento na posição correta em relação aos seus antecessores. Compara todos os itens, um a um com os antecessores.

~~~C
void insertion_sort(int *v, int l, int r)
{
    for (int i = l + 1; i < r; i++)
    {
        for (int j = i; j > l && v[j] < v[j - 1]; j--)
        {
            int t = v[j];
            v[j] = v[j - 1];
            v[j - 1] = t;
        }
    }
}
~~~

No pior caso do insertion sort, são feitas cerca de $\frac{N^2}{2}$ comparações e trocas. Fazendo com que não seja indicado para grandes entradas totalmente desordenadas ou invertidas. Tem desempenho similar ao bubble sort e envolve trocas apenas com os adjacentes. Sua complexidade assintótica é de $O(N^2)$, com o melhor caso sendo $O(N)$.

É um algoritmo adaptativo, vez que o arquivo estar ordenado diminui a quantidade de comparações e trocas.

É um algoritmo estável, pois mantém a ordem relativa dos dados.

Configura também um código *in-place*, pois não usa estruturas de dados extras, mantendo o uso de memória proximo de constante

### Insertion Sort X Selection Sort

O algoritmo de selection sort funciona relativo a uma posição atual, onde os itens a esquerda estão ordenados e na sua posição final. Quanto ao insertion sort, os itens a esquerda estão ordenados, mas não necessariamente em sua posição final, podem ser movidos para abrir espaço para itens menores. O tempo de execução depende da ordenação inicial, sendo mais rápido quando mais ordenado (tendendo a linear), o selection sort continua quadrático independente da ordenação inicial.

### Insertion Sort X Bubble Sort

O posicionamento de um item não garante a ordenação dos outros elementos no bubble sort, garante que os elementos à esquerda sejam menores e os da direita maiores, mas não são necessariamente ordenados a cada passagem. Enquanto no insertion sort, o posicionamento de um item, garante a ordenação dos elementos a sua esquerda.


## Shell sort

O algoritmo do shell sort tenta melhorar o tempo de execução do insertion sort. Quando os dados estão muito desordenados, o insertion sort tem uma performance muito baixa, com isso em mente, Donanld Shell propôs que a comparação fosse feita com elementos diferentes dos vizinhos imediatos, com elementos a uma distância ***h*** dos elementos. Essa aplicação diminui muito o tempo de execução do insertion sort em determinados arquivos. Separa itens a uma distância *h* , rearranjando os itens e resultando em uma sequência ordenada para a distância *h*, ou ***h-ordenada***.

Quando *h = 1*, corresponde ao insertion sort. A maior dificuldade da implementação desse algoritmo, é determinar o tamanho de h. Donald Knuth (cientista da computação), recomenda algo em torno de 1/3 da entrada. Sequência múltiplas de 2 não performam bem, itens em posições pares não confrontam itens em posições ímpares até o fim do processo e vice-versa.

~~~C
void shell_sort(int *v, int l, int r)
{
    int h = 1;

    for(; h <= (r - l) / 9; h = 3 * h + 1)
        ;
    
    for(; h > 0; h /= 3)
        for (int i = l + h; i <= (r - l); i++)
            for (int j = i; j >= l + h && v[j] < v[j - h]; j -= h)
            {
                int t = v[j];
                v[j] = v[j - h];
                v[j - h] = v[j];
            }
    
}
~~~

A complexidade assintótica do shell sort é complicada. Não é possível determinar precisamente qual ***O*** representa a complexidade do algoritmo de forma média, contudo, sabemos que no pior caso é $O(N^2)$ e no melhor $O(n logn)$

Na maior parte dos casos é um algoritmo adaptativo, contudo, nem sempre se caracteriza assim.

Não é um algoritmo estável, pois não mantém a ordem relativa dos dados.

E finalmente, é um algoritmo in-place, vez que, não usa estruturas de dados extras nem memória significativa.