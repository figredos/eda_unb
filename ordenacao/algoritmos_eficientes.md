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
