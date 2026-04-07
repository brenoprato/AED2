# AED2 2026 (1S) - AP02 - ALGORITMOS DE ORDENAÇÃO DE ORDEM QUADRÁTICA

## Instruções

1. **E/S:** tanto a entrada quanto a saída de dados devem ser "secas", ou seja, sem frases explicativas. Siga o modelo fornecido e apenas complete as partes informadas (veja os exemplos fornecidos);
2. **Identificadores de variáveis:** escolha nomes apropriados;
3. **Documentação:** inclua cabeçalho, comentários e indentação no programa;
4. O código-fonte deve ser desenvolvido em **linguagem C**;
5. Não é permitido o uso da função `Sort(...)` da linguagem C ou o uso de estruturas do tipo `<list>` ou `<vector>`;
6. Tempo limite de solução no sistema Judge: **1 minuto**;
7. Submeta o programa no sistema Judge (link igual para ambas as turmas): https://judge.unifesp.br/AEDII1S2026IN/;
8. Plágios serão checados pela plataforma MOSS (https://theory.stanford.edu/~aiken/moss/). Caso detectados, não serão tolerados, sendo a submissão descartada.
9. Soluções que não sigam as diretrizes acima serão desconsideradas.

---

## Descrição

O Centro de Computação da Unifesp precisa organizar IDs de processos em ordem crescente. Para isso, você deve implementar uma **lista duplamente encadeada**.

A inserção de novos elementos deve ser feita de forma que a lista permaneça sempre ordenada. A cada inserção, será necessário contar a quantidade de elementos percorridos na lista encadeada até se encontrar o local ideal de inserção. Essa contagem será denominada **NEP** (Número de Elementos Percorridos). Para otimizar a busca pela posição correta de inserção, você deve seguir a **Regra de Proximidade**:

1. **Lista vazia:** insere o primeiro nó (NEP = 0).
2. **Novo_ID <= cabeça->ID:** insere no início e o novo nó vira o nó inicial/cabeça (NEP = 0).
3. **Novo_ID >= final->ID:** insere no fim e o novo nó vira o elemento final (NEP = 0).
4. **Inserção no meio:** Calcule a distância absoluta entre o novo ID e as extremidades:
   - `D_cabeca = ID_novo - ID_cabeca`
   - `D_final = ID_novo - ID_final`
5. **Se D_cabeca <= D_final:** inicie a busca a partir do nó inicial (cabeça), usando o ponteiro para o próximo elemento. O NEP incrementa em 1 para cada vez que você avançar para o próximo nó, até encontrar o ponto correto de inserção.
6. **Se D_cabeca > D_final:** inicie a busca a partir do nó final. O NEP incrementa em 1 para cada vez que você retroceder para o nó anterior até encontrar o ponto correto de inserção.

---

## Entrada

Duas linhas:

- Um inteiro `N` (1 ≤ N ≤ 1000), representando a quantidade de IDs a serem inseridos.
- `N` inteiros distintos positivos (cada um entre 0 e 10³), representando cada ID a ser inserido, separados por um espaço em branco entre si.

## Saída

Duas linhas:

- A lista de IDs final (ordenada).
- O NEP total computado.

---

## Exemplos de Entrada e Saída

### input01

| Entrada  | Saída |
|----------|-------|
| 3        | 10 15 20 |
| 10 20 15 | 1    |

### input02

| Entrada  | Saída |
|----------|-------|
| 3        | 10 20 30 |
| 30 20 10 | 0    |

### input03

| Entrada   | Saída    |
|-----------|----------|
| 4         | 10 20 30 50 |
| 50 10 30 20 | 2     |