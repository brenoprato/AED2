# AED2 2026 (1S) - AP02 - ALGORITMOS DE ORDENAÇÃO POR DIVISÃO E CONQUISTA

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

Você foi contratado por uma corretora de valores para desenvolver uma ferramenta de análise de volatilidade histórica. O objetivo é identificar momentos de desvalorização acentuada em uma série temporal de preços de ativos. Um par de dias **(i, j)** é classificado como uma **"Queda Drástica"** se as seguintes condições forem atendidas:

1. O dia `i` ocorre antes do dia `j` (`i < j`).
2. O valor do ativo no dia `i` é estritamente maior que o dobro do valor no dia `j` (`V[i] > 2 × V[j]`).

Sua tarefa é calcular o número total de quedas drásticas em um período de **N dias** e, ao final, exibir também a série de preços totalmente ordenada.

---

## Restrições de Desempenho

O volume de dados pode chegar a **N = 10⁵** elementos. Por este motivo, sua solução deve obrigatoriamente possuir complexidade de tempo **O(n log n)**, utilizando a estratégia de **Divisão e Conquista** (baseada no algoritmo **Merge Sort**).

> **Atenção:** Soluções de força bruta com complexidade O(n²) (dois laços aninhados) excederão o limite de tempo de 0.5 segundos no sistema de correção.

---

## Entrada

- A primeira linha contém um inteiro **N** (`1 ≤ N ≤ 100.000`), representando o número de dias.
- A segunda linha contém **N** inteiros positivos representando os valores dos ativos em cada dia.

---

## Saída

- A primeira linha deve conter um único inteiro: o **total de quedas drásticas** encontradas.  
  > **Dica:** utilize tipos de dados de 64 bits para o contador, como `long long int` em C.
- A segunda linha deve conter os **N inteiros da entrada ordenados de forma crescente**, separados por um espaço em branco.

---

## Exemplos de Caso de Teste

### Exemplo 1

**Entrada:**
```
5
10 2 8 3 1
```

**Saída:**
```
6
1 2 3 8 10
```

**Explicação:** As quedas são `(10,2)`, `(10,3)`, `(10,1)`, `(8,3)`, `(8,1)` e `(3,1)`.

---

### Exemplo 2 (Vetor Crescente)

**Entrada:**
```
4
1 2 3 4
```

**Saída:**
```
0
1 2 3 4
```

---

### Exemplo 3

**Entrada:**
```
4
4 3 2 1
```

**Saída:**
```
2
1 2 3 4
```

**Explicação:** apenas os pares `(4,1)` e `(3,1)` satisfazem `V[i] > 2 × V[j]`. O par `(4,2)` não conta, pois `4` não é estritamente maior que `2 × 2`.