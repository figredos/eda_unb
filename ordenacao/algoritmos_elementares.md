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

