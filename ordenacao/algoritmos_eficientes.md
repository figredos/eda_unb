# Algoritmos eficientes

## MERGE SORT

O algoritmo do Merge Sort consiste em dividir o arquivo em pequenas partes, ordenar as partes dividas, combiná-las, até que seja formada uma única sequência ordenada. A partir da lista inteira, dividimos em sub-listas. Em seguida, fazemos a chamada da função recursivamente, de forma que a cada chamada, dividimos a entrada em sub-vetores para serem ordenados. Quando chega a um tamanho unitário, está ordenado em 1, e retorna fazendo o merge do ordenado. Para fazer a divisão, usamos um vetor auxiliar. Existem algumas formas de realizar a divisão das listas, a citada acima é *Top-Down*.

~~~C
void merge_sort(int *v, int l, int r)
{
    if(l >= r)
        return;
    int meio = (r + l) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);
    merge(v, l, meio, r);
}

void merge(int *v, int l, int m, int r)
{
    // Variáveis que cuidam dos índices(até o meio e do meio pra frente respectivamente)
    int i = l;
    int j = m + 1;

    // Criando vetor auxiliar
    int *aux = malloc(sizeof(int) * (r - l + 1));

    // Índice do vetor auxiliar
    int k = 0;

    // Copiando valores de forma ordenada no novo vetor
    while(i <= m && j <= r)
        if(v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];


    // Terminando de fazer a cópia dos valores (caso não tenham acabado)
    while (i <= m)
        aux[k++] = v[i++];
    
    while (j <= r)
        aux[k++] = v[j++];

    // Reiniciando o índice
    k = 0;

    // Copiando os valores para o vetor principal
    for(i = l; i <= r; i++)
        v[i] = aux[k++];

    free(aux);
}
~~~

O algoritmo de merge sort tem complexidade assintótica constante de $O(n log n)$, tanto o pior, o melhor e o caso médio.

Não é um algoritmo in-place, vez que usa de um vetor auxiliar para fazer a união das partes ordenadas.

Não caracteriza um algoritmo adaptativo, pois o vetor estar ordenado não diminui as divisões e comparações do "merge".

É contudo um código estável, mantém as posições relativas.

É possível fazer alterações no código de forma a torna-lo mais eficiente. Uma possibilidade é usar um *insertion sort* em vetores pequenos (de +- 15 itens). Essa implementação melhora o tempo de execução do código em 10 a 15 %.

Outra possibilidade é testar se o vetor já está ordenado. Implementar isso diminui o tempo de execução para linear em arrays, já que estão em ordem. Adicionando um teste para pular a chamada de *"merge"* caso *v[meio]* for menor ou igual a *v[meio + 1]*. Não diminui as chamadas recursivas, mas o tempo de execução para qualquer subarray ordenado é linear.

Finalmente, não utilize um vetor auxiliar local na função merge. Declare o auxiliar em *"merge_sort"* e passe como argumento para merge. Implementar isso faz com que ocorra uma diminuição do overhead (sobrecarga) dessa criação a cada merge.

O algoritmo de merge sort representado acima usa a abordagem "*Top-Down*", contudo, não é a única possível, uma outra forma de aplicar um algoritmo de merge sort é usando a abordagem *"Bottom-Up*. Essa abordagem consiste em uma sequencia de passos pelo vetor inteiro, fazendo o merge dos vetores de tamanho igual. Começa 1 por 1 e vai dobrando em cada passo.
Mantém a mesma complexidade da abordagem top-down.

~~~C
void mergeBU_sort(int *v, int l, int r)
{
    int tam = (r - l) + 1;

    for (int sz = 1; sz < tam; sz *= 2)
        for(int lo = l; lo < tam - sz; lo += 2*sz)
        {
            int hi = lo + 2*sz - 1;
            if(hi > tam - 1)
                hi = tam - 1;

            merge(v, lo, lo + sz - 1, hi);
        }
}
~~~

### MERGE SORT X SHELL SORT

Os tempos de execução do merge sort e do shell sort são similares, diferindo em pequenos fatores constantes, porém, ainda não se comprovou que o shell sort é $O(n log n)$ para dados aleatórios. Portanto, o crescimento assintótico do shell sort nos casos médios pode ser alto.


## QUICK SORT

O algoritmo do Quick Sort é um dos algoritmos mais utilizados, isso se deve ao fato de ser um algoritmo simples e eficiente. É um algoritmo muito pesquisado, tornando-o bem embasado e bem comprovado. A implementação desse algoritmo se baseia no uso de divisão e conquista, particionando o vetor em subsetores, ordenando cada um independentemente.

Particionar é o processo crucial desse algoritmo, escolhemos um pivô e reorganizamos os elementos de acordo com esse elemento de referência. Esse elemento está em sua posição final, é responsável por marcar a divisão dos sub-vetores. Repetimos esse processo até que todos os elementos estiverem ordenados. Algumas condições devem ser satisfeitas, o elemento a[j] está na posição final dentro do vetor, Nenhum elemento anterior ao a[j] é maior que a[j] e nenhum elemento posterior ao a[j] é menor que o a[j].

~~~C
int particao(int *v, int l, int r)
{
    //Definimos o pivô como o elemento mais a esquerda
    int pivo = v[r];
    int j = l;

    for(int i = l; i < r; i++)
    {
        if(v[i] < pivo)
        {
            int t = v[j];
            v[j] = v[i];
            v[i] = t;
        }
        else if(v[j] < pivo)
            j = i;
    }

    int t = v[j];
    v[j] = v[r];
    v[r] = t;

    return j;
}

void quick_sort(int *v, int l, int r)
{
    if(l > r)
        return;
    
    int p = particao(v, l, r);

    quick_sort(v, l, p - 1);
    quick_sort(v, p + 1, r);
}

~~~

O algoritmo acima faz a seguinte função:

1. Quando chamada a função *quick_sort()*, são passados os índices do elemento mais a esquerda e mais a direita.

2. A primeira verificação é feita, para saber se o tamanho do vetor é válido (se o índice mais da direita é maior que o da direita).

3. É feita a chamada da função *particao*

    3.1. A função *particao* é responsável por achar um pivô adequado, ela faz isso definindo o elemento mais a direita do vetor como pivô e percorrendo o vetor com um loop for usando a variável ***i***, procurando um elemento maior que esse pivô. Salvamos na variável ***j*** o valor do índice mais a esquerda, uma vez que achamos um elemento com valor maior ou igual ao valor do pivô, mudamos o valor de ***j*** para o contador percorrendo o vetor ***i***. A função retorna o valor final de ***j***.

4. Com o valor retornado pela função *particao* salvo na variável p, fazemos a chamada recursiva da função *quick_sort()* para os elementos a direita e a esquerda do pivô.

A chamada recursiva de *quick_sort()*, como citado acima, é a parte mais importante da ordenação. Uma vez que decidimos um pivô, fazemos a ordenação apenas para os lados, uma vez que esse elemento já está na sua posição final.

A complexidade Assintótica no melhor e no caso médio é de  $O(n log n)$.

Apenas a parte recursiva pode ser considerada in-place.

Não é um código estável, não mantendo a ordem relativa.

Não e um algoritmo com adaptatividade, vez que ao invés da ordenação ajudar a melhorar o desempenho, pode cair nos piores casos.