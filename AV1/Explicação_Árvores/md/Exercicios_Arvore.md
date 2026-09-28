<h1 align="center"> 🌴 Exercícios: Árvore Binária de Busca no Papel</h1>

Resolva **no papel** antes de abrir as respostas. Use o guia [Arvore_no_Papel.md](Arvore_no_Papel.md) se travar.

Em cada questão:

1. Monte a árvore inserindo os valores **na ordem dada**.
2. Escreva os percursos **pré-ordem**, **em ordem** e **pós-ordem**.
3. Aplique a **regra de impressão** pedida e diga quais valores aparecem e quais **não** aparecem.

Lembrete dos percursos:

| Percurso      | Ordem de visita           | Dica                         |
|---------------|---------------------------|------------------------------|
| **Pré-ordem** | nó → esquerda → direita   | começa pela raiz             |
| **Em ordem**  | esquerda → nó → direita   | sai em ordem crescente       |
| **Pós-ordem** | esquerda → direita → nó   | termina na raiz              |

---

## Questão 1

Insira, **nesta ordem**, numa árvore binária de busca vazia:

```
45, 25, 65, 15, 35, 55, 75, 10, 30, 40, 70
```

**a)** Desenhe a árvore final.

**b)** Escreva a sequência em **pré-ordem**, **em ordem** e **pós-ordem**.

**c)** Percorra a árvore em **pós-ordem**, mas anote **apenas os valores maiores que 30**. Qual a sequência anotada?

**d)** Percorra a árvore em **pré-ordem**, mas anote **apenas os nós que têm exatamente 1 filho**. Qual a sequência anotada?

<details>
<summary><b>👀 Resposta da Questão 1</b></summary>

### a) Árvore

| Valor | Caminho percorrido                            | Onde entra       |
|-------|-----------------------------------------------|------------------|
| 45    | árvore vazia                                  | **raiz**         |
| 25    | 25 < 45 → esq                                 | esquerda do 45   |
| 65    | 65 > 45 → dir                                 | direita do 45    |
| 15    | 15 < 45 → esq, 15 < 25 → esq                  | esquerda do 25   |
| 35    | 35 < 45 → esq, 35 > 25 → dir                  | direita do 25    |
| 55    | 55 > 45 → dir, 55 < 65 → esq                  | esquerda do 65   |
| 75    | 75 > 45 → dir, 75 > 65 → dir                  | direita do 65    |
| 10    | 10 < 45 → esq, 10 < 25 → esq, 10 < 15 → esq   | esquerda do 15   |
| 30    | 30 < 45 → esq, 30 > 25 → dir, 30 < 35 → esq   | esquerda do 35   |
| 40    | 40 < 45 → esq, 40 > 25 → dir, 40 > 35 → dir   | direita do 35    |
| 70    | 70 > 45 → dir, 70 > 65 → dir, 70 < 75 → esq   | esquerda do 75   |

```
                  45
               /      \
            25          65
           /  \        /  \
         15    35    55    75
        /     /  \         /
      10    30    40     70
```

### b) Percursos

**Em ordem** (esq → nó → dir):

```
[ [ [10] 15 ]  25  [ [30] 35 [40] ] ]   45   [ [55] 65 [ [70] 75 ] ]
```

`10 15 25 30 35 40 45 55 65 70 75` ✅ crescente, confere o desenho.

**Pré-ordem** (nó → esq → dir):

```
45   [ 25 [ 15 [10] ] [ 35 [30] [40] ] ]   [ 65 [55] [ 75 [70] ] ]
```

`45 25 15 10 35 30 40 65 55 75 70` (começa na raiz)

**Pós-ordem** (esq → dir → nó):

```
[ [ [10] 15 ] [ [30] [40] 35 ] 25 ]   [ [55] [ [70] 75 ] 65 ]   45
```

`10 15 30 40 35 25 55 70 75 65 45` (termina na raiz)

### c) Pós-ordem, só valores > 30

Todos os nós são percorridos; o filtro só decide quem é anotado.

Pegue a pós-ordem e risque quem é ≤ 30:

```
10  15  30  40  35  25  55  70  75  65  45
~~  ~~  ~~          ~~
```

**Sequência:** `40 35 55 70 75 65 45`

**Não anotados:** 10, 15, 25, 30. O 30 **não** entra porque a regra é "maior que 30", e não "maior ou igual".

### d) Pré-ordem, só nós com exatamente 1 filho

| Nó | Filhos     | Qtd | Anota? |
|----|------------|-----|--------|
| 45 | 25, 65     | 2   | ❌     |
| 25 | 15, 35     | 2   | ❌     |
| 15 | 10         | 1   | ✅     |
| 10 | nenhum     | 0   | ❌     |
| 35 | 30, 40     | 2   | ❌     |
| 30 | nenhum     | 0   | ❌     |
| 40 | nenhum     | 0   | ❌     |
| 65 | 55, 75     | 2   | ❌     |
| 55 | nenhum     | 0   | ❌     |
| 75 | 70         | 1   | ✅     |
| 70 | nenhum     | 0   | ❌     |

**Sequência:** `15 75` (na ordem da pré-ordem)

</details>

---

## Questão 2

Insira, **nesta ordem**, numa árvore binária de busca vazia. **Valores repetidos são ignorados.**

```
60, 40, 80, 20, 50, 70, 90, 50, 10, 45, 85, 95, 65
```

**a)** Desenhe a árvore final. Quantos nós ela tem?

**b)** Escreva a sequência em **pré-ordem**, **em ordem** e **pós-ordem**.

**c)** Faça um percurso **em ordem** a partir da raiz, seguindo estas regras em cada nó:

1. Só desça para a **esquerda** se o valor do nó for **maior que 50**.
2. Anote o nó se o valor for **múltiplo de 10**.
3. Sempre desça para a **direita**.

Qual a sequência anotada? Quais nós **nem chegam a ser visitados**?

<details>
<summary><b>👀 Resposta da Questão 2</b></summary>

### a) Árvore

| Valor | Caminho percorrido                            | Onde entra         |
|-------|-----------------------------------------------|--------------------|
| 60    | árvore vazia                                  | **raiz**           |
| 40    | 40 < 60 → esq                                 | esquerda do 60     |
| 80    | 80 > 60 → dir                                 | direita do 60      |
| 20    | 20 < 60 → esq, 20 < 40 → esq                  | esquerda do 40     |
| 50    | 50 < 60 → esq, 50 > 40 → dir                  | direita do 40      |
| 70    | 70 > 60 → dir, 70 < 80 → esq                  | esquerda do 80     |
| 90    | 90 > 60 → dir, 90 > 80 → dir                  | direita do 80      |
| 50    | 50 < 60 → esq, 50 > 40 → dir, **50 = 50**     | **repetido, ignorado** |
| 10    | 10 < 60 → esq, 10 < 40 → esq, 10 < 20 → esq   | esquerda do 20     |
| 45    | 45 < 60 → esq, 45 > 40 → dir, 45 < 50 → esq   | esquerda do 50     |
| 85    | 85 > 60 → dir, 85 > 80 → dir, 85 < 90 → esq   | esquerda do 90     |
| 95    | 95 > 60 → dir, 95 > 80 → dir, 95 > 90 → dir   | direita do 90      |
| 65    | 65 > 60 → dir, 65 < 80 → esq, 65 < 70 → esq   | esquerda do 70     |

```
                     60
                 /        \
              40            80
             /  \          /  \
           20    50      70    90
          /     /       /     /  \
        10    45      65    85    95
```

**12 nós** (13 valores na sequência, mas o segundo 50 não entra).

### b) Percursos

**Em ordem** (esq → nó → dir):

```
[ [ [10] 20 ] 40 [ [45] 50 ] ]   60   [ [ [65] 70 ] 80 [ [85] 90 [95] ] ]
```

`10 20 40 45 50 60 65 70 80 85 90 95` ✅ crescente, e 12 valores.

**Pré-ordem** (nó → esq → dir):

```
60   [ 40 [ 20 [10] ] [ 50 [45] ] ]   [ 80 [ 70 [65] ] [ 90 [85] [95] ] ]
```

`60 40 20 10 50 45 80 70 65 90 85 95`

**Pós-ordem** (esq → dir → nó):

```
[ [ [10] 20 ] [ [45] 50 ] 40 ]   [ [ [65] 70 ] [ [85] [95] 90 ] 80 ]   60
```

`10 20 45 50 40 65 70 85 95 90 80 60`

### c) Em ordem com **poda** e **filtro**

- **Poda:** só desce para a esquerda se o nó for **> 50**.
- **Filtro:** só anota se o valor for **múltiplo de 10**.
- Sempre desce para a direita.

Simulação:

```
60: 60 > 50? SIM → desce esq
   40: 40 > 50? NÃO → não desce esq (20 e 10 PODADOS)
       40 é múltiplo de 10 → ANOTA 40
       desce dir
      50: 50 > 50? NÃO → não desce esq (45 PODADO)
          50 é múltiplo de 10 → ANOTA 50
          desce dir → vazio
   volta ao 60 → ANOTA 60
   desce dir
   80: SIM → desce esq
      70: SIM → desce esq
         65: SIM → esq vazio → 65 não é múltiplo de 10 → dir vazio
      volta ao 70 → ANOTA 70 → dir vazio
   volta ao 80 → ANOTA 80
   desce dir
      90: SIM → desce esq
         85: esq vazio → não anota → dir vazio
      volta ao 90 → ANOTA 90
      desce dir
         95: esq vazio → não anota → dir vazio
```

**Sequência:** `40 50 60 70 80 90`

| Valor      | Visitado? | Anotado? | Por quê                                        |
|------------|-----------|----------|------------------------------------------------|
| 60         | ✅        | ✅       | múltiplo de 10                                 |
| 40         | ✅        | ✅       | múltiplo de 10                                 |
| 20         | ❌        | ❌       | **podado**: 40 não desceu para a esquerda      |
| 10         | ❌        | ❌       | **podado** junto com o 20 (está embaixo dele)  |
| 50         | ✅        | ✅       | múltiplo de 10                                 |
| 45         | ❌        | ❌       | **podado**: 50 não é > 50, não desceu esq      |
| 80, 70, 90 | ✅        | ✅       | múltiplos de 10                                |
| 65, 85, 95 | ✅        | ❌       | visitados, mas falharam no filtro              |

> 🔎 **Pegadinha:** o 20 e o 10 são múltiplos de 10 e **mesmo assim não aparecem**. Eles passariam no filtro, mas a poda impediu o percurso de chegar até eles.

</details>

---

## Questão 3

Insira, **nesta ordem**, numa árvore binária de busca vazia:

```
50, 30, 80, 20, 40, 70, 90, 10, 35, 60, 75, 95, 33
```

**a)** Desenhe a árvore final.

**b)** Escreva a sequência em **pré-ordem**, **em ordem** e **pós-ordem**.

**c)** Percorra a árvore em **pós-ordem**, mas anote **apenas as folhas**. Qual a sequência anotada?

**d)** Percorra a árvore em **pré-ordem**, mas anote **apenas os valores ímpares**. Qual a sequência anotada?

**e)** Faça uma **busca** pelo valor **75** e depois pelo valor **36**, anotando cada nó por onde a busca passa. Quais são os caminhos? Algum dos dois é encontrado?

<details>
<summary><b>👀 Resposta da Questão 3</b></summary>

### a) Árvore

| Valor | Caminho percorrido                                        | Onde entra       |
|-------|-----------------------------------------------------------|------------------|
| 50    | árvore vazia                                              | **raiz**         |
| 30    | 30 < 50 → esq                                             | esquerda do 50   |
| 80    | 80 > 50 → dir                                             | direita do 50    |
| 20    | 20 < 50 → esq, 20 < 30 → esq                              | esquerda do 30   |
| 40    | 40 < 50 → esq, 40 > 30 → dir                              | direita do 30    |
| 70    | 70 > 50 → dir, 70 < 80 → esq                              | esquerda do 80   |
| 90    | 90 > 50 → dir, 90 > 80 → dir                              | direita do 80    |
| 10    | 10 < 50 → esq, 10 < 30 → esq, 10 < 20 → esq               | esquerda do 20   |
| 35    | 35 < 50 → esq, 35 > 30 → dir, 35 < 40 → esq               | esquerda do 40   |
| 60    | 60 > 50 → dir, 60 < 80 → esq, 60 < 70 → esq               | esquerda do 70   |
| 75    | 75 > 50 → dir, 75 < 80 → esq, 75 > 70 → dir               | direita do 70    |
| 95    | 95 > 50 → dir, 95 > 80 → dir, 95 > 90 → dir               | direita do 90    |
| 33    | 33 < 50 → esq, 33 > 30 → dir, 33 < 40 → esq, 33 < 35 → esq | esquerda do 35  |

```
                    50
               /          \
            30              80
           /  \           /    \
         20    40       70      90
        /     /        /  \       \
      10    35       60    75      95
           /
         33
```

### b) Percursos

**Em ordem** (esq → nó → dir):

```
[ [ [10] 20 ] 30 [ [ [33] 35 ] 40 ] ]   50   [ [ [60] 70 [75] ] 80 [ 90 [95] ] ]
```

`10 20 30 33 35 40 50 60 70 75 80 90 95` ✅ crescente, confere o desenho.

**Pré-ordem** (nó → esq → dir):

```
50   [ 30 [ 20 [10] ] [ 40 [ 35 [33] ] ] ]   [ 80 [ 70 [60] [75] ] [ 90 [95] ] ]
```

`50 30 20 10 40 35 33 80 70 60 75 90 95` (começa na raiz)

**Pós-ordem** (esq → dir → nó):

```
[ [ [10] 20 ] [ [ [33] 35 ] 40 ] 30 ]   [ [ [60] [75] 70 ] [ [95] 90 ] 80 ]   50
```

`10 20 33 35 40 30 60 75 70 95 90 80 50` (termina na raiz)

### c) Pós-ordem, só folhas

Folha = nó **sem nenhum filho**.

| Nó | Filhos     | Folha? |
|----|------------|--------|
| 10 | nenhum     | ✅     |
| 20 | 10         | ❌     |
| 33 | nenhum     | ✅     |
| 35 | 33         | ❌     |
| 40 | 35         | ❌     |
| 30 | 20, 40     | ❌     |
| 60 | nenhum     | ✅     |
| 75 | nenhum     | ✅     |
| 70 | 60, 75     | ❌     |
| 95 | nenhum     | ✅     |
| 90 | 95         | ❌     |
| 80 | 70, 90     | ❌     |
| 50 | 30, 80     | ❌     |

**Sequência:** `10 33 60 75 95`

> 🔎 As folhas saem na mesma ordem em pré, em ordem e pós-ordem (sempre da esquerda para a direita no desenho). O que muda é só a posição dos nós internos.

### d) Pré-ordem, só ímpares

Pegue a pré-ordem e risque quem é par:

```
50  30  20  10  40  35  33  80  70  60  75  90  95
~~  ~~  ~~  ~~  ~~          ~~  ~~  ~~      ~~
```

**Sequência:** `35 33 75 95`

### e) Busca (imprime só o caminho)

A busca **não percorre a árvore inteira**: em cada nó ela escolhe **um** lado só.

**Busca pelo 75:**

```
50: 75 > 50 → dir
80: 75 < 80 → esq
70: 75 > 70 → dir
75: 75 = 75 → ENCONTRADO
```

**Caminho:** `50 80 70 75` ✅ encontrado

**Busca pelo 36:**

```
50: 36 < 50 → esq
30: 36 > 30 → dir
40: 36 < 40 → esq
35: 36 > 35 → dir → vazio → NÃO ENCONTRADO
```

**Caminho:** `50 30 40 35` ❌ não encontrado

> 🔎 **Pegadinha:** mesmo sem achar o 36, a busca imprime os nós por onde passou. Ela para quando tenta descer para um filho que não existe (a direita do 35).

</details>

---

## Questão 4

Insira, **nesta ordem**, numa árvore binária de busca vazia. **Valores repetidos são ignorados.**

```
40, 20, 60, 10, 30, 50, 70, 5, 15, 25, 35, 55, 65, 80, 30, 45
```

**a)** Desenhe a árvore final. Quantos nós ela tem?

**b)** Escreva a sequência em **pré-ordem**, **em ordem** e **pós-ordem**.

**c)** Faça um percurso em **pré-ordem** a partir da raiz, seguindo estas regras em cada nó:

1. Anote o nó se o valor for **par**.
2. Só desça para a **esquerda** se o valor do nó for **maior ou igual a 20**.
3. Só desça para a **direita** se o valor do nó for **menor que 60**.

Qual a sequência anotada? Quais nós **nem chegam a ser visitados**?

**d)** Repita o item **c)** com as **mesmas regras**, mas agora em **pós-ordem**. O que muda na resposta?

<details>
<summary><b>👀 Resposta da Questão 4</b></summary>

### a) Árvore

| Valor | Caminho percorrido                            | Onde entra             |
|-------|-----------------------------------------------|------------------------|
| 40    | árvore vazia                                  | **raiz**               |
| 20    | 20 < 40 → esq                                 | esquerda do 40         |
| 60    | 60 > 40 → dir                                 | direita do 40          |
| 10    | 10 < 40 → esq, 10 < 20 → esq                  | esquerda do 20         |
| 30    | 30 < 40 → esq, 30 > 20 → dir                  | direita do 20          |
| 50    | 50 > 40 → dir, 50 < 60 → esq                  | esquerda do 60         |
| 70    | 70 > 40 → dir, 70 > 60 → dir                  | direita do 60          |
| 5     | 5 < 40 → esq, 5 < 20 → esq, 5 < 10 → esq      | esquerda do 10         |
| 15    | 15 < 40 → esq, 15 < 20 → esq, 15 > 10 → dir   | direita do 10          |
| 25    | 25 < 40 → esq, 25 > 20 → dir, 25 < 30 → esq   | esquerda do 30         |
| 35    | 35 < 40 → esq, 35 > 20 → dir, 35 > 30 → dir   | direita do 30          |
| 55    | 55 > 40 → dir, 55 < 60 → esq, 55 > 50 → dir   | direita do 50          |
| 65    | 65 > 40 → dir, 65 > 60 → dir, 65 < 70 → esq   | esquerda do 70         |
| 80    | 80 > 40 → dir, 80 > 60 → dir, 80 > 70 → dir   | direita do 70          |
| 30    | 30 < 40 → esq, 30 > 20 → dir, **30 = 30**     | **repetido, ignorado** |
| 45    | 45 > 40 → dir, 45 < 60 → esq, 45 < 50 → esq   | esquerda do 50         |

```
                          40
                 /                  \
             20                        60
          /      \                 /        \
        10        30             50          70
       /  \      /  \           /  \        /  \
      5    15  25    35       45    55    65    80
```

**15 nós** (16 valores na sequência, mas o segundo 30 não entra). A árvore ficou **completa**: todo nó interno tem 2 filhos e todas as folhas estão no mesmo nível.

### b) Percursos

**Em ordem** (esq → nó → dir):

```
[ [ [5] 10 [15] ] 20 [ [25] 30 [35] ] ]   40   [ [ [45] 50 [55] ] 60 [ [65] 70 [80] ] ]
```

`5 10 15 20 25 30 35 40 45 50 55 60 65 70 80` ✅ crescente, e 15 valores.

**Pré-ordem** (nó → esq → dir):

```
40   [ 20 [ 10 [5] [15] ] [ 30 [25] [35] ] ]   [ 60 [ 50 [45] [55] ] [ 70 [65] [80] ] ]
```

`40 20 10 5 15 30 25 35 60 50 45 55 70 65 80`

**Pós-ordem** (esq → dir → nó):

```
[ [ [5] [15] 10 ] [ [25] [35] 30 ] 20 ]   [ [ [45] [55] 50 ] [ [65] [80] 70 ] 60 ]   40
```

`5 15 10 25 35 30 20 45 55 50 65 80 70 60 40`

### c) Pré-ordem com **poda dos dois lados** e **filtro**

- **Filtro:** só anota se for **par**.
- **Poda esquerda:** só desce esq se o nó for **≥ 20**.
- **Poda direita:** só desce dir se o nó for **< 60**.

Na pré-ordem o nó é anotado **antes** de descer.

```
40: par → ANOTA 40
    40 ≥ 20? SIM → desce esq
   20: par → ANOTA 20
       20 ≥ 20? SIM → desce esq
      10: par → ANOTA 10
          10 ≥ 20? NÃO → não desce esq (5 PODADO)
          10 < 60? SIM → desce dir
         15: ímpar → não anota
             15 ≥ 20? NÃO → não desce esq (vazio mesmo)
             15 < 60? SIM → dir vazio
       20 < 60? SIM → desce dir
      30: par → ANOTA 30
          30 ≥ 20? SIM → desce esq
         25: ímpar → não anota → esq vazio → dir vazio
          30 < 60? SIM → desce dir
         35: ímpar → não anota → esq vazio → dir vazio
    40 < 60? SIM → desce dir
   60: par → ANOTA 60
       60 ≥ 20? SIM → desce esq
      50: par → ANOTA 50
          50 ≥ 20? SIM → desce esq
         45: ímpar → não anota → esq vazio → dir vazio
          50 < 60? SIM → desce dir
         55: ímpar → não anota → esq vazio → dir vazio
       60 < 60? NÃO → não desce dir (70, 65, 80 PODADOS)
```

**Sequência:** `40 20 10 30 60 50`

| Valor              | Visitado? | Anotado? | Por quê                                              |
|--------------------|-----------|----------|------------------------------------------------------|
| 40, 20, 10, 30     | ✅        | ✅       | pares                                                |
| 60, 50             | ✅        | ✅       | pares                                                |
| 15, 25, 35, 45, 55 | ✅        | ❌       | visitados, mas são ímpares                           |
| 5                  | ❌        | ❌       | **podado**: 10 não é ≥ 20, não desceu esq            |
| 70                 | ❌        | ❌       | **podado**: 60 não é < 60, não desceu dir            |
| 65, 80             | ❌        | ❌       | **podados** junto com o 70 (estão embaixo dele)      |

**11 visitados**, 4 nunca visitados (5, 70, 65, 80).

> 🔎 **Pegadinha 1:** 70 e 80 são pares e **mesmo assim não aparecem**: a poda impediu o percurso de chegar até eles.
>
> 🔎 **Pegadinha 2:** o 60 **é anotado** (ele próprio foi visitado); o que a regra 3 bloqueia é só a descida para a **direita** dele. E como é "menor que 60", e não "menor ou igual", o 60 não desce.

### d) Mesmas regras, em pós-ordem

As regras de poda e filtro são as mesmas, então **os mesmos nós** são visitados e **os mesmos nós** são anotados. Só muda o **momento** da anotação: na pós-ordem o nó é anotado **depois** de terminar os dois lados.

```
40: desce esq
   20: desce esq
      10: esq PODADA → desce dir
         15: não anota
      volta → ANOTA 10
   20: desce dir
      30: desce esq → 25 (não anota) → desce dir → 35 (não anota)
      volta → ANOTA 30
   volta → ANOTA 20
40: desce dir
   60: desce esq
      50: desce esq → 45 (não anota) → desce dir → 55 (não anota)
      volta → ANOTA 50
   60: dir PODADA
   volta → ANOTA 60
volta → ANOTA 40
```

**Sequência:** `10 30 20 50 60 40`

| Item | Sequência              |
|------|------------------------|
| c) pré-ordem | `40 20 10 30 60 50` |
| d) pós-ordem | `10 30 20 50 60 40` |

> 🔎 **Mesmo conjunto** de valores `{10, 20, 30, 40, 50, 60}`, **ordem diferente**. Dica: filtre a pós-ordem completa do item **b)** removendo os podados (5, 70, 65, 80) e os ímpares, e confira: ~~5~~ ~~15~~ **10** ~~25~~ ~~35~~ **30** **20** ~~45~~ ~~55~~ **50** ~~65~~ ~~80~~ ~~70~~ **60** **40** → `10 30 20 50 60 40` ✅

</details>
