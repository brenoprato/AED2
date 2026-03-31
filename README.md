# 📚 AED2 — Algoritmos e Estruturas de Dados 2

> Repositório destinado à resolução dos exercícios propostos nas aulas de **Algoritmos e Estruturas de Dados 2 (AED2)** na **Universidade Federal de São Paulo (UNIFESP)** — 1º Semestre de 2026.

![Linguagem](https://img.shields.io/badge/linguagem-C-blue?style=flat-square&logo=c)
![Universidade](https://img.shields.io/badge/universidade-UNIFESP-green?style=flat-square)
![Status](https://img.shields.io/badge/status-em%20andamento-yellow?style=flat-square)

---

## 🗂️ Estrutura do Repositório

```
AED2/
└── AP01/
    ├── AP01_sort.md    # Enunciado da atividade
    └── res_AP01.c      # Solução em C
```

---

## 📝 Atividades

| Pasta | Título | Tema | Solução |
|-------|--------|------|---------|
| [AP01](./AP01) | Algoritmos de Ordenação de Ordem Quadrática | Lista duplamente encadeada com Regra de Proximidade | [res_AP01.c](./AP01/res_AP01.c) |

---

## 🧩 Descrição das Atividades

### AP01 — Lista Duplamente Encadeada Ordenada

Implementação de uma **lista duplamente encadeada** para organizar IDs de processos em ordem crescente.

A inserção segue a **Regra de Proximidade**, que otimiza a busca pela posição correta comparando a distância do novo elemento em relação à cabeça e ao final da lista. A cada inserção no meio da lista, contabiliza-se o **NEP** (Número de Elementos Percorridos).

**Entrada:** número de IDs `N` e os `N` inteiros a inserir.  
**Saída:** lista ordenada e o NEP total acumulado.

---

## ⚙️ Como Compilar e Executar

Todos os exercícios são escritos em **linguagem C**. Para compilar e executar qualquer solução:

```bash
# Compilar
gcc -o saida AP01/res_AP01.c

# Executar (digitar a entrada manualmente)
./saida

# Executar com arquivo de entrada
./saida < entrada.txt
```

---

## 🔗 Links Úteis

- 🏫 [Sistema Judge – UNIFESP](https://judge.unifesp.br/AEDII1S2026IN/)
- 🔍 [MOSS – Detector de Plágio (Stanford)](https://theory.stanford.edu/~aiken/moss/)

