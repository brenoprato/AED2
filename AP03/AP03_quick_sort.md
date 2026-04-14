# AED2 2026 (1S) - AP03 - ALGORITMO QUICKSORT

## Instruções

1. **E/S:** tanto a entrada quanto a saída de dados devem ser "secas", ou seja, sem frases explicativas. Siga o modelo fornecido e apenas complete as partes informadas (veja os exemplos fornecidos);
2. **Identificadores de variáveis:** escolha nomes apropriados;
3. **Documentação:** inclua cabeçalho, comentários e indentação no programa;
4. O código-fonte deve ser desenvolvido em **linguagem C**;
5. Não é permitido o uso da função `Sort(...)` da linguagem C ou o uso de estruturas do tipo `<list>` ou `<vector>`;
6. Tempo limite de solução no sistema Judge: **1 segundo**;
7. Submeta o programa no sistema Judge (link igual para ambas as turmas): https://judge.unifesp.br/AEDII1S2026IN/;
8. Plágios serão checados pela plataforma MOSS (https://theory.stanford.edu/~aiken/moss/). Caso detectados, não serão tolerados, sendo a submissão descartada.
9. Soluções que não sigam as diretrizes acima serão desconsideradas.

---

## Descrição

O sistema de gerenciamento de uma fila de transplantes de órgãos precisa organizar os pacientes de acordo com a gravidade do quadro clínico. A regra de prioridade é clara:

1. Pacientes com **maior nível de gravidade** devem ser atendidos primeiro (ordem decrescente).
2. Caso dois pacientes possuam o mesmo nível de gravidade, o paciente com o **menor ID** deve ser posicionado à frente (ordem crescente).

Devido a uma falha na integração entre os sistemas hospitalares regionais e a central de transplantes, alguns registros foram duplicados durante a migração de dados. O algoritmo deve ser capaz de lidar com essas redundâncias, garantindo que registros idênticos **não gerem processamento desnecessário** (movimentação de memória) durante a ordenação.

Para validar a precisão da implementação, o programa deve **contar o número exato de trocas (swaps)** de posição realizadas, em qualquer momento em que a troca seja efetivada. A função `swap` **não deve** incrementar o contador e nem realizar a troca de valores se:

- Os índices dos elementos a serem trocados forem iguais (`idxa == idxb`).
- O conteúdo dos elementos (**Gravidade** e **ID**) for idêntico.

---

## Restrições de Implementação (Obrigatório)

Para que o trabalho seja aceito, o algoritmo deve seguir rigorosamente as seguintes diretrizes técnicas:

1. **Adaptação do Algoritmo da disciplina:** O código-fonte deve ser uma adaptação direta do algoritmo QuickSort visto em sala de aula.

2. **Algoritmo In-Place:** A ordenação deve ser realizada *in-place* (no próprio local), para minimizar o uso de memória. É proibida a criação de vetores auxiliares ou cópias parciais do vetor original durante as etapas de partição. Toda a manipulação deve ser feita via trocas (`swaps`) de elementos dentro do único vetor alocado no início do programa.

3. **Passagem por Referência:** A função de partição deve trabalhar diretamente com os índices `p` (início) e `r` (fim) fornecidos, alterando o estado do vetor original de forma persistente.

4. **Alocação de Memória:** Embora o vetor principal deva ser alocado dinamicamente (`malloc`), a ordenação em si não deve alocar novos blocos de memória (arrays) a cada chamada recursiva.

---

## Entrada

- A primeira linha contém um inteiro **N** (`1 ≤ N ≤ 100.000`), representando o número de pacientes.
- Da linha **2** até a linha **N + 1**: cada uma contém dois números inteiros separados por um espaço, que representam:
  - **ID:** identificador do paciente.
  - **Gravidade:** valor que define a prioridade clínica de atendimento.

---

## Saída

- Lista de IDs ordenados (um por linha).
- Uma linha final no formato: `Swaps: X`, onde `X` representa exatamente a quantidade de vezes que a função `Swap` foi executada até o final, ou seja, trocando dois valores. Essa quantidade `X` **não deve** computar eventuais chamadas à função `Swap` onde, devido às restrições apontadas, não se faça nenhuma troca de dados.

---

## Exemplos de Caso de Teste

### Exemplo 1

**Entrada:**
```
4
100 7
100 7
100 7
200 10
```

**Saída:**
```
200
100
100
100
Swaps: 1
```

**Explicação:** No início, a mediana de três analisa as posições 0, 1 e 3, cujas gravidades são, respectivamente: 7, 7 e 10. A mediana é 7. O algoritmo tenta organizar, mas como os elementos com gravidade 7 são idênticos em ID e Gravidade, a trava de conteúdo bloqueia os swaps iniciais, forçando o pivô a ser levado para o fim do arranjo. O único swap contabilizado ocorre quando o elemento `(200, 10)` é movido para a frente por ter maior prioridade que o pivô. Assim, apenas 1 troca real de conteúdo diferente aconteceu.

---

### Exemplo 2

**Entrada:**
```
4
10 5
20 8
30 2
40 10
```

**Saída:**
```
40
20
10
30
Swaps: 8
```

**Explicação:** A mediana de três analisa inicialmente os pares `(10, 5)`, `(20, 8)` e `(40, 10)`. Para colocar a mediana no lugar esperado do pivô (final do arranjo), ocorrem trocas de valores distintos. Com 4 elementos distintos, o algoritmo realiza a varredura. Cada vez que encontra alguém com gravidade maior que o pivô, o `i` incrementa e o swap é chamado. Como os elementos são todos diferentes entre si, nenhuma trava de conteúdo é acionada. O valor 8 reflete a soma das trocas da mediana, o reposicionamento do pivô e as chamadas recursivas para as subpartes.

---

### Exemplo 3

**Entrada:**
```
4
50 10
10 10
30 10
20 5
```

**Saída:**
```
10
30
50
20
Swaps: 6
```

**Explicação:** todos os três primeiros têm gravidade 10, assim, a ordenação é feita puramente pelo ID (`10 < 30 < 50`). O valor de 6 swaps indica que o algoritmo precisou de 6 movimentações de pacientes com IDs diferentes para garantir que o `20` (Grav 5) ficasse no final e os IDs 10, 30, 50 ficassem em ordem crescente. Como os IDs são diferentes, a trava de conteúdo não bloqueia essas trocas.
