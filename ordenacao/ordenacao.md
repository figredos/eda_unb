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