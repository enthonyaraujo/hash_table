# Trabalho segunda unidade - Laborátorio de Algoritmos e Estruturas 2

## Configuração utilizado do grupo: 40 - E1.1, H4, C2, A4

### E1.1: **Vetor estático; capacidade fixa**;

É um vetor de tamanho fixo **m** onde cada posição guarda um registro diretamente, as colisões são resolvidas procurando outra posição livre dentro do próprio vetor (sondagem linear), e como a capacidade nunca cresce, a tabela pode encher e isso precisa ser tratado.
### H4: Função: **Dobra**; Ideia: **Dividir a chave em partes e combiná-las.**

A função de **dobra** tem como ideia principal pegar a chave e dividir em tamanhos fixos, para o nosso caso de palavras, como vai funcionar: 

- Pegar a palavra e converter em numeros
- Dividir em partes com mesmo número de digitos (ou bytes)
- Combinar os bits usando uma XOR

Exemplo: Palavra "casa", ou seja, k = casa

Passo 1: letras em números (ASCII)

| c   | a   | s   | a   |
| --- | --- | --- | --- |
| 99  | 97  | 115 | 97  |

Passo 2: Dividir em partes iguais

- ca
- sa
  
$k_{1} = ca$ e $k_{2} = sa$

Passo 3: Cada letra vai virar um número:

$$
k_{1} = ca = 99*256 + 97 = 25441
$$

$$
k_{2} = sa = 115*256 + 97 = 29537
$$

*obs: 256 -> (0 a 255)*

Passo 4: fazer a soma
$$
k = k_{1} + k_{2} = 29537 + 25441 = 54978
$$

Passo 5: Temos que fazer isso caber na tabela:

$$
h(k) = k \ mod \ m
$$

O nosso valor da tabela foi definido como  $m = 20011$,

$$
(h(54978) = 54978 \ mod \ 20011)
$$

$$
h(54978) = 14956
$$

Ou seja, ela vai para posição 14956 da tabela.

## C2: Sondagem Linear:

A sondagem linear é o método utilizado para previnir colisões

$$
p_{i}(k) = (h(k) + i) \ mod \ m;
$$

Pegando o exemplo anterior, se quisermos colocar a palavra **"saca"**, notamos que ela vai dar a mesma soma de 14956, e ouve uma colisão. Vamos usar a sondagem linear para evitar isso.
Inicialmente $i=0$, quando há colisão ela vai incrementando, portanto o valor agora é $i=1$:

$$
p_{1}(14956) = (54978+1) \ mod \ 20011)
$$

$$
	p_{1}(14956) = 14957
$$

Como `14957`está vazia, ele vai para essa posição.
## A4: Índice de palavras; Chave: **Palavra normalizada**; Valor armazenado: **Frequência, ocorrências**

A aplicação A4 recebe um texto, conta **quantas vezes cada palavra aparece** e guarda o resultado na tabela hash. A palavra é a chave, e o valor guardado junto com ela é a frequência e as ocorrências.

### Chave: palavra normalizada

Antes de calcular o hash, a palavra passa por uma normalização, para que formas diferentes da mesma palavra virem a mesma chave. Definimos:

- **Caixa:** todas as palavras em minúsculas ("Casa", "CASA" e "casa" são a mesma chave);
- **Pontuação e acentos:** *(definir a escolha do grupo, por exemplo: remover pontuação e manter/remover acentos)*;
- **Separação de palavras:** *(definir o que separa palavras, por exemplo: espaço, quebra de linha, vírgula, hífen)*.

Sem isso, aparecem duplicações indevidas ("Casa" e "casa" como duas entradas) e buscas sem resultado.

### Valor armazenado

- **Frequência:** contador de quantas vezes a palavra apareceu no texto;
- **Ocorrências:** onde a palavra apareceu *(definir: posição no texto, linha ou arquivo)*.

Exemplo com o texto "A casa é a casa de todos":

| palavra | frequência | ocorrências (posição) |
| ------- | ---------- | --------------------- |
| a       | 2          | 1, 4                  |
| casa    | 2          | 2, 5                  |
| é       | 1          | 3                     |
| de      | 1          | 6                     |
| todos   | 1          | 7                     |

### Como as operações funcionam na A4

- **Inserir:** na primeira vez que a palavra aparece, cria a entrada com frequência 1 e a primeira ocorrência;
- **Atualizar:** se a palavra já existe, incrementa a frequência e acrescenta a nova ocorrência. Por isso, inserir uma palavra repetida é uma atualização e **não conta como colisão**;
- **Consultar:** dada uma palavra, devolve a frequência e as ocorrências;
- **Remover:** apaga a palavra do índice, marcando a posição como `REMOVIDO` para não quebrar a busca de palavras que colidiram;
- **Listar:** percorre a tabela e mostra todas as palavras com seus valores.

### Por que A4 combina com tabela hash

Um índice de palavras faz muita busca e atualização ("essa palavra já existe?"), e a tabela hash faz isso em tempo médio constante. Além disso, textos reais têm muitas palavras repetidas e poucas distintas, então o número de chaves `n` fica bem menor que o total de palavras lidas, o que mantém o fator de carga baixo.

## Compilar:

```bash
gcc -Wall -Wextra -std=c11 src/main.c src/tabela.c -o tabela_hash
``` 

