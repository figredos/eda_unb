# Ordenação

## O QUE É

Ordenação é organização. Utilizamos ordenação, pois uma vez que um conjunto de dados está ordenado, buscas são otimizadas, isso ocorre pois é criada uma lógica de sequencialidade, assim gerando previsibilidade. 

Para fazer a ordenação, utilizamos a chave do item. Chave é a parte do item utilizada como parâmetro/controle de ordenação. Isso ocorre para arquivos, estruturas, etc.

## ALGORITMOS DE ORDENAÇÃO

Para entender algoritmos de ordenação elementares, é preciso entender algumas características que os definem.

- ***COMPLEXIDADE***:
- 
    Idealmente complexidade dos algoritmos deve ser ou quadrática ou linearítmica. Algoritmos quadráticos são mais simples e suficientes para arquivos pequenos. Enquanto algoritmos linearítmicos são mais complexos e eficientes para arquivos grandes.

- ***ESTABILIDADE***:
  
    Algoritmos de ordenação estáveis são aqueles que mantém a ordem relativa dos elementos:

    2 4 1 6 7 *1*

    *1* 1 2 4 6 7 - não estável

    1 *1* 2 4 6 7 - estável

- ***ADAPTATIVIDADE***:
  
    Devem aproveitar a ordenação existente.

- ***MEMÓRIA EXTRA***:
  
    Algoritmos que utilizam a própria estrutura e memória extra com pilhas de execução e variáveis auxiliares são chamados de ***in-place***.

    Algoritmos que utilizam mais uma estrutura e cópias são chamados ***não in-place***.

- ***LOCALIZAÇÃO***
  
    Quando todos os dados cabem na memória principal, tem localização ***interna***. Caso contrário tem localização ***externa***.

Assim como qualquer estrutura de dados, convém entender a eficiência dos algoritmos. Nesse caso a divisão é feita entre algoritmos elementares e algoritmos eficientes. 

Algoritmos elementares tem custos maiores, mas são mais simples. Lidam bem com qualquer implementação, seja feita com arrays ou listas encadeadas.

Algoritmos eficientes tem custos menores, mas são mais complexos, utilizando estratégias. Com arrays tem mais fácil manipulação com acesso direto, enquanto com estruturas encadeadas são gerenciadas com árvores ordenadas.

Algumas macros importantes para o entendimento dos códigos abaixo:

~~~C
#define exch(A, B) (int t = A; A = B; B = t)

~~~

## ALGORITMOS DE ORDENAÇÃO ELEMENTARES

### SELECTION SORT

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

