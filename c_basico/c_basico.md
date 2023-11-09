# C BÁSICO

## VARIÁVEIS

Cada variável possui um endereço na memória. Endereços são bytes menos significativos. Diferentes tipos de variáveis, ocupam espaços diferentes:

int: números inteiros; -2.147.483.648 <-> 2.147.483.648; 32 bits (4 bytes); %d;

short int: números inteiros curtos; -32,768 <-> 32,767; 4 bits (2 bytes); %hd;

unsigned short int: números inteiros positivos e curtos; 0 <-> 65.535; %hu;

unsigned int: números inteiros positivos; 0 <-> 4.294.967.295; 16 bits (4 bytes); %u;

long int: números inteiros longos; -2,147,483,648 to 2,147,483,647; 16 bits (4 bytes); %ld;

long unsigned int: números inteiros longos e positivos; 0 <-> 4.294.967.295; 16 bits (4 bytes); %lu;

long long int: números inteiros muito longos; -(2^63) <-> (2^63) - 1; 64 bits (8 bytes); %lld;

long long unsigned int: números inteiros postivos muito longos: 0 <-> 18,446,744,073,709,551,615; 64 bits (8 bytes); %llu;

float: números de ponto flutuante (decimais); 1.2E-38 <-> 3.4E+38; 16 bits (4 bytes); %f;

double: números de ponto flutuante longos; 3.4E-4932 <-> 1.1E+4932;  64 bits (8 bytes); %lf

long double: números de ponto flutuante muito longos; 3.4E-4932 <-> 1.1E+4932;  256 bits (816 bytes); %Lf;

char: caracter; -128 <-> 127; 8 bits (1 byte); %c;

unsigned char: caracter; 0 <-> 255; 8 bits (1 byte); %c;

## int main(void)

Quando uma função de qualquer tipo tem em sua chamada inicial, nos parênteses, "void" significa que aquela função não recebe argumentos.

## %nd

Quando usamos um número n antes do tipo de dado na formatação de uma impressão, isso está indicando quantos espaços a mais do que o necessário devem ser impressos. Ou seja, caso estejamos imprimindo o número '1234', quando usarmos a formatação '%2d', o número será impresso normalmente, contudo, caso o número tivesse menos que 2 espaços, seriam impressos 2 espaços normalmente. O número n reserva uma quantidade de espaços para serem impressos.Caso essse número seja de ponto flutuante, tudo após o '.' indica quantas casas o número deve ser arredondado.

## \#define

É definido como um pré-processador que é utilizado para definir 'macros'.

## MACROS

São pequenos pedaços de código que podem ser executados com um simples comando, podendo ser utilizados para automatizar tarefas, simplificar processos complexos, e aumentar produtividade. Contudo, macros podem gerar riscos de segurança, possuem funcionalidade limitada, problemas de compatibilidade, requerem manutenção. Esses riscos se aumentam quando se é criada uma dependência desses elementos.

## TYPEDEF

É uma forma de poupar tempo na definição de uma variável. Ao usarmos o keyword "typedef", seguido pelo tipo do dado desejado e um nome desejado, criamos um "apelido" para aquele tipo de dado. Com isso, o tempo gasto para definir dados pode diminuir.

## MEMÓRIA

Memória é um conjunto de componentes eletrônicos capazes de conservar estados. Por convenção, 1 é alta tensão e 0 baixa tensão. Computadores são a combinação de sistemas binários (dados) associados a álgebra booleana (lógica) e circuitos de comutação de estados, onde o componente de armazenamento de dados é chamado de memória.

### BITS

Nada mais são do que dados binários, podendo assumir apenas valores de 0 ou 1. Seu nome vem da abreviação do termo "binary digit". É o menor tamanho de dado em um sistema computacional e tem sua sigla como 'b', minúsculo

### BYTES

São conjuntos de 8 bits de dados. Como bits tem 2^1 possibilidades de valores (0 ou 1, 2 valores), e bytes possuem 8 bits, possibilita a essas unidades conterem 2^8 combinações de valores, sendo assim, são as unidades de valores responsáveis por representar caractéres únicos, como letras e números. Contém valores númericos apenas, mas com uso da tabela ASCII, é possível traduzir valores númericos em letras. São representados pela sigla "B" maíusculo.

Bytes binários: são aqueles que contém uma potência de 2 como possibilidades de valores, assim, um kilobyte tem 1024 bytes. É definido pelo IEC 80000-13:2008.

Bytes decimais: são aqueles que contém uma potência de 10 como possibilidadesde valores, assim, um kilobyte tem 1000 bytes. É definido pelo SI.

Ambos os tipos de bytes possuem 8 bits, sendo sua principal diferença na potência que é usada para definir seus múltiplos.

### ENDEREÇO FÍSICO X ENDEREÇO VIRTUAL

Endereço Virtual (Lógico): é gerado pela CPU durante a execução de um programa. É usado como referência para acessar o local da memória física pela CPU. O termo Espaço de Endereço Lógico é usado para o conjunto de todos os endereços lógicos gerados pela perspectiva de um programa. O dispositivo de hardware denominado Memory-Management Unit é usado para mapear o endereço lógico para seu endereço físico correspondente.

Endereço Físico: identifica uma localização física dos dados necessários em uma memória. O usuário nunca lida diretamente com o endereço físico, mas pode acessá-lo por meio de seu endereço lógico correspondente. O programa do usuário gera o endereço lógico e pensa que o programa está rodando neste endereço lógico, mas o programa precisa de memória física para sua execução, portanto, o endereço virtual deve ser mapeado para o endereço físico pela MMU antes de serem usados. O termo Espaço de endereço físico é usado para todos os endereços físicos correspondentes aos endereços lógicos em um espaço de endereço lógico.