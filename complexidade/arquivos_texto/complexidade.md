# Complexidade

## Eficácia x Eficiência

Um código eficaz, é aquele que simplesmente realiza uma tarefa, independente da qualidade da forma com a qual conseguiu esse resultado.

Um código eficiente é aquele que realiza a tarefa de uma forma adequada e com qualidade.

## Análise de algoritmos

Quando tentamos analisar a qualidade de um algoritmo, alguns problemas surgem. Primeiramente, qual fator usamos para atestar a qualidade de um algoritmo. Tomemos como esse fator a eficiência do algoritmo. Feito isso, chegamos a outro problema, como medimos ou calculamos essa eficiência? Pelo tempo que leva à execução do algoritmo? Mais uma vez chegamos a um impasse, vez que, o tempo é dependente de fatores como linguagem na qual o algoritmo está sendo implementado, assim como no hardware e na quantidade de processos em execução. Portanto precisamos de uma medida independente da máquina.

Chegamos então à conclusão de que uma forma de fazer essa medida é contar a quantidade de instruções a serem executadas. Fazemos isso, tornando nossa atenção apenas para as instruções mais relevantes, observando a tendência do comportamento a medida que a entrada cresce. Fazendo o cálculo aproximado do custo das operações, assim definindo a ***complexidade dos algoritmos***.

### Complexidade de um algoritmo particular

Busca-se o custo de um algoritmo para resolver um problema específico. Podemos observar quantas repetições cada trecho executa e quanta memória é gasta.

### Complexidade de uma classe de algoritmos

Busca-se o custo de um algoritmo para resolver um problema particular, analisa-se uma família de algoritmos que resolvem um problema específico.

Um exemplo disso seria contar qual o menor número de comparações para ordenar ***n*** números.

## Função do custo

Contamos as operações mais relevantes considerando as instâncias do problema.

### Tamanho das instâncias do problema ***n***

Diferentes problemas geram diferentes tamanhos, por exemplo, problemas de ordenação em vetores dependem do tamanho do vetor, enquanto problemas de pesquisa em memória dependem to tamanho de registros, assim por diante.

## Tipos de complexidade

### Complexidade linear f(n) = n

Um pequeno trabalho é realizado sobre cada elemento da entrada. Possui n entradas e n saídas. Utilizada, por exemplo, em vetores.

Anel ou laço, tempo dos comandos internos com avaliação da condição multiplicado pelo número de iterações.

### Complexidade quadrática f(n) = $n^2$

Caracterizam-se pelo processamento dos dados em pares, muitas vezes com vários aninhamentos. Se ***n*** dobra, o tepo quadruplica. São algoritmos úteis para problemas pequenos.

Um grande exemplo é o uso de dois loops for para processar algum dado. E algoritmos bubblesort.

### Complexidade cúbica f(n) = $n^3$

Eficientes apenas para pequenos problemas, assim como a complexidade quadrática, o crescimento do tempo gasto por algoritmo é exponencial. Similar ao exemplo anterior, o uso de 3 loops for gera um código com complexidade cúbica.

Outro exemplo de complexidade cúbica, é para calcular a distância entre nós de grafos, sendo todos para todos.

### Complexidade exponencial f(n) = $2^n$

Resultantes de problemas resolvidos por força bruta, onde são verificadas todas as possibilidades.

Para entender a magnitude da complexidade de algoritmos exponenciais, quando o número de dados é 20, o tempo é cerca de 1.000.000.

### Complexidade fatorial f(n) = $n!$

Também usado em problemas resolvidos por força bruta, onde todas as possibilidades são verificadas. Esse tipo de algoritmo é ainda mais lento que problemas exponenciais.

### Complexidade logarítmica f(n) = $\log(n)$

É a função inversa da exponencial. É um pouco mais lenta a medida que ***n*** cresce. Tempo típico de algoritmos que dividem o problema em problemas menores. Não importa a base do log, pois a grandeza do resultado não tem alterações significativas.

Algoritmos de busca binária usam essa complexidade.

### Complexidade "*linearítmica*" f(n) = $n\log(n)$

Caracterizam-se por resolver um problema quebrando em problemas menores, resolvendo cada um deles independentemente, e depois juntando as soluções, localmente resolvidas, gerando uma nova solução. Algoritmos de divisão e conquista geralmente tem essa complexidade, como por exemplo mergesort.

### Complexidade constante f(n) = 1

Essa complexidade é caracterizada pela independência do número de dados. Possuem instruções executadas um número fixo de vezes.

## Notação O (Big O)

Para representar a relação assintótica, surgiram diversas notações, sendo "***O***" a mais utilizada. A relação assintótica entre duas funções distintas $f(n)$ e $g(n)$ é dada primeiramente através da comparação da linha de crescimento de cada uma das funções. Isso é feito para poder chegar à conclusão $f(n) = O(g(n))$, em outras palavras, $f(n)$ cresce tão rapidamente quanto $g(n)$. $g(n)$ é o limite superior para a taxa de cresimento de $f(n)$, assim, diz-se que $g(n)$ domina assintóticamente $f(n)$.

Dois algoritmos tem a mesma complexidade independente do tempo de execução de cada um. Ou seja, caso um algoritmo $f(n)$ seja igual a $3g(n)$, demorando 3 vezes mais, eles tem a mesma complexidade devido à forma com a qual sua curva cresce.