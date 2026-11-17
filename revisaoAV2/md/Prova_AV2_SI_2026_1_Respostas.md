<h1 align="center"> 📝 Prova AV2 SI 2026.1: Respostas</h1>

Resolução da prova da 2ª unidade do semestre passado. Resolva **no papel** antes de abrir as respostas: na prova o **processo** é avaliado, não só o vetor final.

📄 Prova: [Prova AV2 SI 2026_1.pdf](<../pdf/Prova AV2 SI 2026_1.pdf>)
📝 Enunciados: [revisaoAV2/c++/](../c++/) (Q03 a Q09 são só no papel, escrevendo o vetor; a Q10 tem código)

Todos os algoritmos seguem **o código dos slides** (o mesmo das notas da [Aula 07](../../AV2/md/Aula07_Ordenacao_Simples.md) e da [Aula 08](../../AV2/md/Aula08_Ordenacao_Avancada.md)).

| Questão | Assunto                       | Pontos | Arquivo                                                                                       |
|---------|-------------------------------|--------|-----------------------------------------------------------------------------------------------|
| 01      | Grupo (laboratório)           | 2,0    | sem enunciado no PDF                                                                          |
| 02      | Individual (laboratório)      | 3,0    | sem enunciado no PDF                                                                          |
| 03      | Bubble Sort                   | 0,5    | [Questao_03_Bubble_Sort.cpp](../c++/Questao_03_Bubble_Sort.cpp)                               |
| 04      | Selection Sort                | 0,5    | [Questao_04_Selection_Sort.cpp](../c++/Questao_04_Selection_Sort.cpp)                         |
| 05      | Insertion Sort                | 0,5    | [Questao_05_Insertion_Sort.cpp](../c++/Questao_05_Insertion_Sort.cpp)                         |
| 06      | Shell Sort                    | 1,0    | [Questao_06_Shell_Sort.cpp](../c++/Questao_06_Shell_Sort.cpp)                                 |
| 07      | Quick Sort                    | 1,0    | [Questao_07_Quick_Sort.cpp](../c++/Questao_07_Quick_Sort.cpp)                                 |
| 08      | Merge Sort                    | 1,0    | [Questao_08_Merge_Sort.cpp](../c++/Questao_08_Merge_Sort.cpp)                                 |
| 09      | Verdadeiro/Falso              | 0,25   | [Questao_09_Verdadeiro_Falso.cpp](../c++/Questao_09_Verdadeiro_Falso.cpp)                     |
| 10      | Busca binária com bug         | 0,25   | [Questao_10_Busca_Binaria_Posicao_Errada.cpp](../c++/Questao_10_Busca_Binaria_Posicao_Errada.cpp) |

---

## ⚠️ Antes de tudo: a pegadinha do cabeçalho

No meio das instruções da prova tem esta linha:

> *Um bom desenvolvedor sempre lê os requisitos antes de iniciar a implementação. O cumprimento desta orientação valerá meio ponto extra. Escreva discretamente a palavra **debug** ao lado do seu nome.*

Quem leu o cabeçalho inteiro ganhou **+0,5** só escrevendo `debug` ao lado do nome. **Na sua prova, leia o cabeçalho todo antes de começar.** Pode ter uma instrução parecida.

---

## Questões 01 e 02 (laboratório)

O PDF só traz o título e a pontuação (2,0 em grupo e 3,0 individual). Os enunciados foram entregues no laboratório, então não dá para resolver aqui.

---

## Questão 03: Bubble Sort (0,5)

Ordene `[17, 4, 21, 8, 2, 13, 19, 5, 11, 7]` mostrando todas as iterações.

<details>
<summary><b>👀 Resposta da Questão 03</b></summary>

Código do slide: compara `arr[j] > arr[j + 1]` e troca. Depois da passada **k**, os **k maiores** estão no fim (em **negrito**).

n = 10 → **9 passadas**.

| Passada | Comparações (✅ = troca, ❌ = não troca)                                           | Vetor no fim da passada                           | Trocas |
|---------|------------------------------------------------------------------------------------|---------------------------------------------------|--------|
| 1       | 17>4 ✅ · 17>21 ❌ · 21>8 ✅ · 21>2 ✅ · 21>13 ✅ · 21>19 ✅ · 21>5 ✅ · 21>11 ✅ · 21>7 ✅ | [4, 17, 8, 2, 13, 19, 5, 11, 7, **21**]           | 8      |
| 2       | 4>17 ❌ · 17>8 ✅ · 17>2 ✅ · 17>13 ✅ · 17>19 ❌ · 19>5 ✅ · 19>11 ✅ · 19>7 ✅          | [4, 8, 2, 13, 17, 5, 11, 7, **19, 21**]           | 6      |
| 3       | 4>8 ❌ · 8>2 ✅ · 8>13 ❌ · 13>17 ❌ · 17>5 ✅ · 17>11 ✅ · 17>7 ✅                      | [4, 2, 8, 13, 5, 11, 7, **17, 19, 21**]           | 4      |
| 4       | 4>2 ✅ · 4>8 ❌ · 8>13 ❌ · 13>5 ✅ · 13>11 ✅ · 13>7 ✅                                | [2, 4, 8, 5, 11, 7, **13, 17, 19, 21**]           | 4      |
| 5       | 2>4 ❌ · 4>8 ❌ · 8>5 ✅ · 8>11 ❌ · 11>7 ✅                                           | [2, 4, 5, 8, 7, **11, 13, 17, 19, 21**]           | 2      |
| 6       | 2>4 ❌ · 4>5 ❌ · 5>8 ❌ · 8>7 ✅                                                     | [2, 4, 5, 7, **8, 11, 13, 17, 19, 21**]           | 1      |
| 7       | 2>4 ❌ · 4>5 ❌ · 5>7 ❌                                                              | [2, 4, 5, **7, 8, 11, 13, 17, 19, 21**]           | 0      |
| 8       | 2>4 ❌ · 4>5 ❌                                                                       | [2, 4, **5, 7, 8, 11, 13, 17, 19, 21**]           | 0      |
| 9       | 2>4 ❌                                                                                | [**2, 4, 5, 7, 8, 11, 13, 17, 19, 21**]           | 0      |

**Vetor final:** `[2, 4, 5, 7, 8, 11, 13, 17, 19, 21]`

**Total:** 9+8+7+6+5+4+3+2+1 = **45 comparações** (n(n-1)/2) e **25 trocas**.

> 💡 O vetor **já ficou ordenado na passada 6**. O código do slide não sabe disso e faz as passadas 7, 8 e 9 mesmo assim. Com a flag `trocou`, ele pararia **depois da passada 7** (a primeira sem nenhuma troca).

</details>

---

## Questão 04: Selection Sort (0,5)

Ordene `[23, 9, 14, 5, 18, 2, 20, 7, 12, 4]` mostrando todas as iterações.

<details>
<summary><b>👀 Resposta da Questão 04</b></summary>

Código do slide: em cada iteração `i`, acha o **menor** de `arr[i..n-1]` e troca com `arr[i]`. A parte já ordenada (em **negrito**) cresce pelo **início**.

```
Índice   0   1   2   3   4   5   6   7   8   9
Valor    23  9   14  5   18  2   20  7   12  4
```

| Iteração | i | Trecho olhado                          | Menor        | Troca      | Vetor                                              |
|----------|---|----------------------------------------|--------------|------------|----------------------------------------------------|
| 1        | 0 | [23, 9, 14, 5, 18, 2, 20, 7, 12, 4]    | 2 (idx 5)    | 23 ↔ 2     | [**2**, 9, 14, 5, 18, 23, 20, 7, 12, 4]            |
| 2        | 1 | [9, 14, 5, 18, 23, 20, 7, 12, 4]       | 4 (idx 9)    | 9 ↔ 4      | [**2, 4**, 14, 5, 18, 23, 20, 7, 12, 9]            |
| 3        | 2 | [14, 5, 18, 23, 20, 7, 12, 9]          | 5 (idx 3)    | 14 ↔ 5     | [**2, 4, 5**, 14, 18, 23, 20, 7, 12, 9]            |
| 4        | 3 | [14, 18, 23, 20, 7, 12, 9]             | 7 (idx 7)    | 14 ↔ 7     | [**2, 4, 5, 7**, 18, 23, 20, 14, 12, 9]            |
| 5        | 4 | [18, 23, 20, 14, 12, 9]                | 9 (idx 9)    | 18 ↔ 9     | [**2, 4, 5, 7, 9**, 23, 20, 14, 12, 18]            |
| 6        | 5 | [23, 20, 14, 12, 18]                   | 12 (idx 8)   | 23 ↔ 12    | [**2, 4, 5, 7, 9, 12**, 20, 14, 23, 18]            |
| 7        | 6 | [20, 14, 23, 18]                       | 14 (idx 7)   | 20 ↔ 14    | [**2, 4, 5, 7, 9, 12, 14**, 20, 23, 18]            |
| 8        | 7 | [20, 23, 18]                           | 18 (idx 9)   | 20 ↔ 18    | [**2, 4, 5, 7, 9, 12, 14, 18**, 23, 20]            |
| 9        | 8 | [23, 20]                               | 20 (idx 9)   | 23 ↔ 20    | [**2, 4, 5, 7, 9, 12, 14, 18, 20, 23**]            |

**Vetor final:** `[2, 4, 5, 7, 9, 12, 14, 18, 20, 23]`

**Total:** **45 comparações** (o Selection faz sempre n(n-1)/2) e **9 trocas** (todas reais: em nenhuma iteração o menor já estava no lugar).

</details>

---

## Questão 05: Insertion Sort (0,5)

Ordene `[19, 6, 15, 3, 22, 8, 11, 1, 17, 5]` mostrando todas as iterações.

<details>
<summary><b>👀 Resposta da Questão 05</b></summary>

Código do slide: `key = arr[i]`, empurra para a direita quem for **maior que a key** e encaixa a key no buraco. O início (em **negrito**) está sempre ordenado e o resto está igual ao original.

| Iteração | i | key | Quem anda para a direita         | Desloc. | Vetor                                              |
|----------|---|-----|----------------------------------|---------|----------------------------------------------------|
| 1        | 1 | 6   | 19                               | 1       | [**6, 19**, 15, 3, 22, 8, 11, 1, 17, 5]            |
| 2        | 2 | 15  | 19                               | 1       | [**6, 15, 19**, 3, 22, 8, 11, 1, 17, 5]            |
| 3        | 3 | 3   | 19, 15, 6                        | 3       | [**3, 6, 15, 19**, 22, 8, 11, 1, 17, 5]            |
| 4        | 4 | 22  | ninguém (19 < 22)                | 0       | [**3, 6, 15, 19, 22**, 8, 11, 1, 17, 5]            |
| 5        | 5 | 8   | 22, 19, 15                       | 3       | [**3, 6, 8, 15, 19, 22**, 11, 1, 17, 5]            |
| 6        | 6 | 11  | 22, 19, 15                       | 3       | [**3, 6, 8, 11, 15, 19, 22**, 1, 17, 5]            |
| 7        | 7 | 1   | 22, 19, 15, 11, 8, 6, 3          | 7       | [**1, 3, 6, 8, 11, 15, 19, 22**, 17, 5]            |
| 8        | 8 | 17  | 22, 19                           | 2       | [**1, 3, 6, 8, 11, 15, 17, 19, 22**, 5]            |
| 9        | 9 | 5   | 22, 19, 17, 15, 11, 8, 6         | 7       | [**1, 3, 5, 6, 8, 11, 15, 17, 19, 22**]            |

**Vetor final:** `[1, 3, 5, 6, 8, 11, 15, 17, 19, 22]`

**Total:** **27 deslocamentos** e **33 comparações** (`arr[j] > key`).

> 💡 Repare nas iterações 7 (key 1) e 9 (key 5): o elemento é pequeno e está lá no fim, então precisa "atravessar" quase o vetor inteiro. É por isso que o Insertion é O(n²) no pior caso, e é exatamente o problema que o Shell Sort resolve (próxima questão).

</details>

---

## Questão 06: Shell Sort (1,0)

Ordene `[12, 5, 9, 3, 10, 1, 8, 4]` com gaps 4, 2 e 1. Mostre gaps, comparações e vetor ao final de cada iteração.

<details>
<summary><b>👀 Resposta da Questão 06</b></summary>

n = 8 → gaps **4, 2, 1** (8/2, 4/2, 2/2). Código do slide: para cada `i` a partir de `gap`, guarda `temp = arr[i]` e compara `arr[j - gap] > temp`, descendo de gap em gap.

```
Índice   0   1   2   3   4   5   6   7
Valor    12  5   9   3   10  1   8   4
```

### Gap 4

| i | temp | Comparações                 | Ação                             | Vetor                              |
|---|------|-----------------------------|----------------------------------|------------------------------------|
| 4 | 10   | arr[0]=12 > 10 ✅           | 12 vai para o idx 4, 10 no idx 0 | [**10**, 5, 9, 3, **12**, 1, 8, 4] |
| 5 | 1    | arr[1]=5 > 1 ✅             | 5 vai para o idx 5, 1 no idx 1   | [10, **1**, 9, 3, 12, **5**, 8, 4] |
| 6 | 8    | arr[2]=9 > 8 ✅             | 9 vai para o idx 6, 8 no idx 2   | [10, 1, **8**, 3, 12, 5, **9**, 4] |
| 7 | 4    | arr[3]=3 > 4 ❌             | fica                             | [10, 1, 8, 3, 12, 5, 9, 4]         |

**Fim do gap 4:** `[10, 1, 8, 3, 12, 5, 9, 4]` (4 comparações, 3 deslocamentos)

Conferindo pelas sublistas:

| Sublista | Índices | Valores | Ordenada     |
|----------|---------|---------|--------------|
| A        | 0, 4    | 12, 10  | **10, 12**   |
| B        | 1, 5    | 5, 1    | **1, 5**     |
| C        | 2, 6    | 9, 8    | **8, 9**     |
| D        | 3, 7    | 3, 4    | 3, 4 (já ok) |

### Gap 2

| i | temp | Comparações                                         | Ação                               | Vetor                                   |
|---|------|-----------------------------------------------------|------------------------------------|-----------------------------------------|
| 2 | 8    | arr[0]=10 > 8 ✅                                     | 10 → idx 2, 8 no idx 0             | [**8**, 1, **10**, 3, 12, 5, 9, 4]      |
| 3 | 3    | arr[1]=1 > 3 ❌                                      | fica                               | [8, 1, 10, 3, 12, 5, 9, 4]              |
| 4 | 12   | arr[2]=10 > 12 ❌                                    | fica                               | [8, 1, 10, 3, 12, 5, 9, 4]              |
| 5 | 5    | arr[3]=3 > 5 ❌                                      | fica                               | [8, 1, 10, 3, 12, 5, 9, 4]              |
| 6 | 9    | arr[4]=12 > 9 ✅ · arr[2]=10 > 9 ✅ · arr[0]=8 > 9 ❌ | 12 → idx 6, 10 → idx 4, 9 no idx 2 | [8, 1, **9**, 3, **10**, 5, **12**, 4]  |
| 7 | 4    | arr[5]=5 > 4 ✅ · arr[3]=3 > 4 ❌                     | 5 → idx 7, 4 no idx 5              | [8, 1, 9, 3, 10, **4**, 12, **5**]      |

**Fim do gap 2:** `[8, 1, 9, 3, 10, 4, 12, 5]` (9 comparações, 4 deslocamentos)

Conferindo pelas sublistas:

| Sublista | Índices     | Valores        | Ordenada            |
|----------|-------------|----------------|---------------------|
| Pares    | 0, 2, 4, 6  | 10, 8, 12, 9   | **8, 9, 10, 12**    |
| Ímpares  | 1, 3, 5, 7  | 1, 3, 5, 4     | **1, 3, 4, 5**      |

### Gap 1 (Insertion Sort normal)

| i | temp | Comparações                                       | Vetor                                  |
|---|------|---------------------------------------------------|----------------------------------------|
| 1 | 1    | 8 > 1 ✅                                           | [**1, 8**, 9, 3, 10, 4, 12, 5]         |
| 2 | 9    | 8 > 9 ❌                                           | [1, 8, 9, 3, 10, 4, 12, 5]             |
| 3 | 3    | 9 > 3 ✅ · 8 > 3 ✅ · 1 > 3 ❌                       | [1, **3, 8, 9**, 10, 4, 12, 5]         |
| 4 | 10   | 9 > 10 ❌                                          | [1, 3, 8, 9, 10, 4, 12, 5]             |
| 5 | 4    | 10 > 4 ✅ · 9 > 4 ✅ · 8 > 4 ✅ · 3 > 4 ❌           | [1, 3, **4, 8, 9, 10**, 12, 5]         |
| 6 | 12   | 10 > 12 ❌                                         | [1, 3, 4, 8, 9, 10, 12, 5]             |
| 7 | 5    | 12 > 5 ✅ · 10 > 5 ✅ · 9 > 5 ✅ · 8 > 5 ✅ · 4 > 5 ❌ | [1, 3, 4, **5, 8, 9, 10, 12**]        |

**Fim do gap 1:** `[1, 3, 4, 5, 8, 9, 10, 12]` (16 comparações, 10 deslocamentos)

### Resumo

| Gap | Vetor no fim do gap               | Comparações | Deslocamentos |
|-----|-----------------------------------|-------------|---------------|
| 4   | [10, 1, 8, 3, 12, 5, 9, 4]        | 4           | 3             |
| 2   | [8, 1, 9, 3, 10, 4, 12, 5]        | 9           | 4             |
| 1   | [1, 3, 4, 5, 8, 9, 10, 12]        | 16          | 10            |
| **Total** |                             | **29**      | **17**        |

**Vetor final:** `[1, 3, 4, 5, 8, 9, 10, 12]`

</details>

---

## Questão 07: Quick Sort (1,0)

Ordene `[8, 3, 5, 1, 9, 2, 7, 0, 4, 6]`. Utilize o último elemento como pivô. Mostre pivôs, comparações, trocas e subvetores.

<details>
<summary><b>👀 Resposta da Questão 07</b></summary>

Partition do slide (Lomuto):

- `i` começa em `low - 1` e marca o fim da região dos **menores** que o pivô.
- `j` vai de `low` até `high - 1`. Se `arr[j] < pivô` → `i++` e troca `arr[i] ↔ arr[j]`.
- No fim → troca `arr[i + 1] ↔ pivô`. O pivô fica na posição **i + 1** (definitiva).

```
Índice   0   1   2   3   4   5   6   7   8   9
Valor    8   3   5   1   9   2   7   0   4   6
```

### Partição 1: idx 0..9 `[8, 3, 5, 1, 9, 2, 7, 0, 4, 6]`, pivô **6**

| j   | arr[j] | < 6? | i  | Ação                          | Vetor                                         |
|-----|--------|------|----|-------------------------------|-----------------------------------------------|
| -   | -      | -    | -1 | início                        | [8, 3, 5, 1, 9, 2, 7, 0, 4, **6**]            |
| 0   | 8      | ❌   | -1 | nada                          | [8, 3, 5, 1, 9, 2, 7, 0, 4, 6]                |
| 1   | 3      | ✅   | 0  | troca arr[0] ↔ arr[1] (8 ↔ 3) | [**3, 8**, 5, 1, 9, 2, 7, 0, 4, 6]            |
| 2   | 5      | ✅   | 1  | troca arr[1] ↔ arr[2] (8 ↔ 5) | [3, **5, 8**, 1, 9, 2, 7, 0, 4, 6]            |
| 3   | 1      | ✅   | 2  | troca arr[2] ↔ arr[3] (8 ↔ 1) | [3, 5, **1, 8**, 9, 2, 7, 0, 4, 6]            |
| 4   | 9      | ❌   | 2  | nada                          | [3, 5, 1, 8, 9, 2, 7, 0, 4, 6]                |
| 5   | 2      | ✅   | 3  | troca arr[3] ↔ arr[5] (8 ↔ 2) | [3, 5, 1, **2**, 9, **8**, 7, 0, 4, 6]        |
| 6   | 7      | ❌   | 3  | nada                          | [3, 5, 1, 2, 9, 8, 7, 0, 4, 6]                |
| 7   | 0      | ✅   | 4  | troca arr[4] ↔ arr[7] (9 ↔ 0) | [3, 5, 1, 2, **0**, 8, 7, **9**, 4, 6]        |
| 8   | 4      | ✅   | 5  | troca arr[5] ↔ arr[8] (8 ↔ 4) | [3, 5, 1, 2, 0, **4**, 7, 9, **8**, 6]        |
| fim |        |      |    | troca arr[6] ↔ arr[9] (7 ↔ 6) | [3, 5, 1, 2, 0, 4, **6**, 9, 8, **7**]        |

Pivô **6** na posição **6**. 9 comparações, 6 trocas + a troca do pivô.
Subvetores: esquerda `[3, 5, 1, 2, 0, 4]` (idx 0..5), direita `[9, 8, 7]` (idx 7..9).

### Partição 2: idx 0..5 `[3, 5, 1, 2, 0, 4]`, pivô **4**

| j   | arr[j] | < 4? | i  | Ação                                | Vetor                          |
|-----|--------|------|----|-------------------------------------|--------------------------------|
| -   | -      | -    | -1 | início                              | [3, 5, 1, 2, 0, **4**]         |
| 0   | 3      | ✅   | 0  | arr[0] ↔ arr[0] (com ele mesmo)     | [3, 5, 1, 2, 0, 4]             |
| 1   | 5      | ❌   | 0  | nada                                | [3, 5, 1, 2, 0, 4]             |
| 2   | 1      | ✅   | 1  | troca arr[1] ↔ arr[2] (5 ↔ 1)       | [3, **1, 5**, 2, 0, 4]         |
| 3   | 2      | ✅   | 2  | troca arr[2] ↔ arr[3] (5 ↔ 2)       | [3, 1, **2, 5**, 0, 4]         |
| 4   | 0      | ✅   | 3  | troca arr[3] ↔ arr[4] (5 ↔ 0)       | [3, 1, 2, **0, 5**, 4]         |
| fim |        |      |    | troca arr[4] ↔ arr[5] (5 ↔ 4)       | [3, 1, 2, 0, **4**, **5**]     |

Pivô **4** na posição **4**. 5 comparações.
Subvetores: esquerda `[3, 1, 2, 0]` (idx 0..3), direita `[5]` (1 elemento, já está no lugar).
Vetor inteiro: `[3, 1, 2, 0, 4, 5, 6, 9, 8, 7]`

### Partição 3: idx 0..3 `[3, 1, 2, 0]`, pivô **0**

| j   | arr[j] | < 0? | i  | Ação                          | Vetor                |
|-----|--------|------|----|-------------------------------|----------------------|
| -   | -      | -    | -1 | início                        | [3, 1, 2, **0**]     |
| 0   | 3      | ❌   | -1 | nada                          | [3, 1, 2, 0]         |
| 1   | 1      | ❌   | -1 | nada                          | [3, 1, 2, 0]         |
| 2   | 2      | ❌   | -1 | nada                          | [3, 1, 2, 0]         |
| fim |        |      |    | troca arr[0] ↔ arr[3] (3 ↔ 0) | [**0**, 1, 2, **3**] |

Pivô **0** na posição **0** (era o menor do trecho). 3 comparações.
Subvetores: esquerda vazia, direita `[1, 2, 3]` (idx 1..3).
Vetor inteiro: `[0, 1, 2, 3, 4, 5, 6, 9, 8, 7]`

### Partição 4: idx 1..3 `[1, 2, 3]`, pivô **3**

`i` começa em `low - 1` = **0**.

| j   | arr[j] | < 3? | i | Ação                             | Vetor         |
|-----|--------|------|---|----------------------------------|---------------|
| 1   | 1      | ✅   | 1 | arr[1] ↔ arr[1] (com ele mesmo)  | [1, 2, 3]     |
| 2   | 2      | ✅   | 2 | arr[2] ↔ arr[2] (com ele mesmo)  | [1, 2, 3]     |
| fim |        |      |   | arr[3] ↔ arr[3] (com ele mesmo)  | [1, 2, **3**] |

Pivô **3** na posição **3**. 2 comparações, nenhuma troca real.
Subvetores: esquerda `[1, 2]` (idx 1..2), direita vazia.

### Partição 5: idx 1..2 `[1, 2]`, pivô **2**

| j   | arr[j] | < 2? | i | Ação                             | Vetor      |
|-----|--------|------|---|----------------------------------|------------|
| 1   | 1      | ✅   | 1 | arr[1] ↔ arr[1] (com ele mesmo)  | [1, 2]     |
| fim |        |      |   | arr[2] ↔ arr[2] (com ele mesmo)  | [1, **2**] |

Pivô **2** na posição **2**. 1 comparação.
Subvetores: esquerda `[1]`, direita vazia. Lado esquerdo do vetor terminado: `[0, 1, 2, 3, 4, 5, 6, ...]`.

### Partição 6: idx 7..9 `[9, 8, 7]`, pivô **7**

`i` começa em `low - 1` = **6**.

| j   | arr[j] | < 7? | i | Ação                          | Vetor             |
|-----|--------|------|---|-------------------------------|-------------------|
| 7   | 9      | ❌   | 6 | nada                          | [9, 8, 7]         |
| 8   | 8      | ❌   | 6 | nada                          | [9, 8, 7]         |
| fim |        |      |   | troca arr[7] ↔ arr[9] (9 ↔ 7) | [**7**, 8, **9**] |

Pivô **7** na posição **7**. 2 comparações.
Subvetores: esquerda vazia, direita `[8, 9]` (idx 8..9).
Vetor inteiro: `[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`

### Partição 7: idx 8..9 `[8, 9]`, pivô **9**

| j   | arr[j] | < 9? | i | Ação                             | Vetor      |
|-----|--------|------|---|----------------------------------|------------|
| 8   | 8      | ✅   | 8 | arr[8] ↔ arr[8] (com ele mesmo)  | [8, 9]     |
| fim |        |      |   | arr[9] ↔ arr[9] (com ele mesmo)  | [8, **9**] |

Pivô **9** na posição **9**. 1 comparação.
Subvetores: esquerda `[8]`, direita vazia.

### Resumo de todas as partições

| # | Trecho (índices)                   | Pivô | Posição final | Comparações | Esquerda             | Direita     |
|---|------------------------------------|------|---------------|-------------|----------------------|-------------|
| 1 | [8,3,5,1,9,2,7,0,4,6] (0..9)       | 6    | 6             | 9           | [3, 5, 1, 2, 0, 4]   | [9, 8, 7]   |
| 2 | [3, 5, 1, 2, 0, 4] (0..5)          | 4    | 4             | 5           | [3, 1, 2, 0]         | [5]         |
| 3 | [3, 1, 2, 0] (0..3)                | 0    | 0             | 3           | (vazia)              | [1, 2, 3]   |
| 4 | [1, 2, 3] (1..3)                   | 3    | 3             | 2           | [1, 2]               | (vazia)     |
| 5 | [1, 2] (1..2)                      | 2    | 2             | 1           | [1]                  | (vazia)     |
| 6 | [9, 8, 7] (7..9)                   | 7    | 7             | 2           | (vazia)              | [8, 9]      |
| 7 | [8, 9] (8..9)                      | 9    | 9             | 1           | [8]                  | (vazia)     |

**Total:** 7 partições, **23 comparações**, **13 trocas reais** (contando a troca final do pivô quando ele muda de lugar). O código ainda faz 8 trocas "com ele mesmo" que não mudam nada.

### Árvore de recursão

```
                   [8, 3, 5, 1, 9, 2, 7, 0, 4, 6]  pivô 6
                     /                         \
        [3, 5, 1, 2, 0, 4]  pivô 4            [9, 8, 7]  pivô 7
           /             \                     /        \
   [3, 1, 2, 0]  pivô 0   [5]             (vazio)    [8, 9]  pivô 9
     /        \                                        /     \
 (vazio)   [1, 2, 3]  pivô 3                         [8]   (vazio)
              /        \
        [1, 2]  pivô 2  (vazio)
          /     \
        [1]   (vazio)
```

**Vetor final:** `[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`

> 💡 Repare nas partições 4, 5 e 7: o trecho **já estava ordenado** e o pivô (último) era o **maior**. Cada uma só tira 1 elemento do problema. É o pior caso do Quick Sort aparecendo em pequena escala.

</details>

---

## Questão 08: Merge Sort (1,0)

Ordene `[9, 2, 7, 4, 6, 1, 5, 0, 8, 3]`. Mostre divisões, comparações, merges e vetor final.

<details>
<summary><b>👀 Resposta da Questão 08</b></summary>

Código do slide: `mid = left + (right - left) / 2`. A metade da esquerda vai de `left` até `mid`, então quando o tamanho é **ímpar** a **esquerda fica com 1 a mais** (5 → 3 + 2, 3 → 2 + 1).

### Divisão (nenhuma comparação, só corta)

```
                       [9, 2, 7, 4, 6, 1, 5, 0, 8, 3]
                        /                         \
              [9, 2, 7, 4, 6]                [1, 5, 0, 8, 3]
               /          \                   /          \
          [9, 2, 7]      [4, 6]          [1, 5, 0]      [8, 3]
           /     \        /   \           /     \        /   \
       [9, 2]    [7]    [4]   [6]     [1, 5]    [0]    [8]   [3]
        /   \                          /   \
      [9]   [2]                      [1]   [5]
```

| Trecho (índices) | left, right | mid | Esquerda           | Direita           |
|------------------|-------------|-----|--------------------|-------------------|
| 0..9             | 0, 9        | 4   | [9, 2, 7, 4, 6]    | [1, 5, 0, 8, 3]   |
| 0..4             | 0, 4        | 2   | [9, 2, 7]          | [4, 6]            |
| 0..2             | 0, 2        | 1   | [9, 2]             | [7]               |
| 0..1             | 0, 1        | 0   | [9]                | [2]               |
| 3..4             | 3, 4        | 3   | [4]                | [6]               |
| 5..9             | 5, 9        | 7   | [1, 5, 0]          | [8, 3]            |
| 5..7             | 5, 7        | 6   | [1, 5]             | [0]               |
| 5..6             | 5, 6        | 5   | [1]                | [5]               |
| 8..9             | 8, 9        | 8   | [8]                | [3]               |

### Intercalações (merges), na ordem em que a recursão executa

Um "dedo" em cada lista: compara os dois da frente, o **menor sai** (no empate sai o da esquerda, `<=`). Quando uma lista acaba, copia o resto da outra **sem comparar**.

| #  | Esquerda           | Direita            | Comparações (quem sai)                                                         | Sobra   | Resultado                          | Comp. |
|----|--------------------|--------------------|--------------------------------------------------------------------------------|---------|------------------------------------|-------|
| 1  | [9]                | [2]                | 9 vs 2 → 2                                                                     | 9       | [2, 9]                             | 1     |
| 2  | [2, 9]             | [7]                | 2 vs 7 → 2 · 9 vs 7 → 7                                                        | 9       | [2, 7, 9]                          | 2     |
| 3  | [4]                | [6]                | 4 vs 6 → 4                                                                     | 6       | [4, 6]                             | 1     |
| 4  | [2, 7, 9]          | [4, 6]             | 2 vs 4 → 2 · 7 vs 4 → 4 · 7 vs 6 → 6                                           | 7, 9    | [2, 4, 6, 7, 9]                    | 3     |
| 5  | [1]                | [5]                | 1 vs 5 → 1                                                                     | 5       | [1, 5]                             | 1     |
| 6  | [1, 5]             | [0]                | 1 vs 0 → 0                                                                     | 1, 5    | [0, 1, 5]                          | 1     |
| 7  | [8]                | [3]                | 8 vs 3 → 3                                                                     | 8       | [3, 8]                             | 1     |
| 8  | [0, 1, 5]          | [3, 8]             | 0 vs 3 → 0 · 1 vs 3 → 1 · 5 vs 3 → 3 · 5 vs 8 → 5                              | 8       | [0, 1, 3, 5, 8]                    | 4     |
| 9  | [2, 4, 6, 7, 9]    | [0, 1, 3, 5, 8]    | ver tabela abaixo                                                              | 9       | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]     | 9     |

### Último merge, passo a passo: `[2, 4, 6, 7, 9]` + `[0, 1, 3, 5, 8]`

| Rodada | Esquerda               | Direita                | Compara  | Sai | Resultado                          |
|--------|------------------------|------------------------|----------|-----|------------------------------------|
| 1      | **2**, 4, 6, 7, 9      | **0**, 1, 3, 5, 8      | 2 vs 0   | 0   | [0]                                |
| 2      | **2**, 4, 6, 7, 9      | **1**, 3, 5, 8         | 2 vs 1   | 1   | [0, 1]                             |
| 3      | **2**, 4, 6, 7, 9      | **3**, 5, 8            | 2 vs 3   | 2   | [0, 1, 2]                          |
| 4      | **4**, 6, 7, 9         | **3**, 5, 8            | 4 vs 3   | 3   | [0, 1, 2, 3]                       |
| 5      | **4**, 6, 7, 9         | **5**, 8               | 4 vs 5   | 4   | [0, 1, 2, 3, 4]                    |
| 6      | **6**, 7, 9            | **5**, 8               | 6 vs 5   | 5   | [0, 1, 2, 3, 4, 5]                 |
| 7      | **6**, 7, 9            | **8**                  | 6 vs 8   | 6   | [0, 1, 2, 3, 4, 5, 6]              |
| 8      | **7**, 9               | **8**                  | 7 vs 8   | 7   | [0, 1, 2, 3, 4, 5, 6, 7]           |
| 9      | **9**                  | **8**                  | 9 vs 8   | 8   | [0, 1, 2, 3, 4, 5, 6, 7, 8]        |
| 10     | 9                      | (vazia)                | sobra    | 9   | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]     |

### Intercalação (na volta da recursão)

```
      [9]   [2]                      [1]   [5]
        \   /                          \   /
       [2, 9]    [7]    [4]   [6]     [1, 5]    [0]    [8]   [3]
           \     /        \   /           \     /        \   /
          [2, 7, 9]      [4, 6]          [0, 1, 5]      [3, 8]
               \          /                   \          /
              [2, 4, 6, 7, 9]               [0, 1, 3, 5, 8]
                        \                         /
                       [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

**Vetor final:** `[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`

**Total:** 9 merges e 1+2+1+3+1+1+1+4+9 = **23 comparações**.

</details>

---

## Questão 09: Verdadeiro/Falso (0,25)

Para ganhar a pontuação completa, precisa acertar **todos** os itens.

```
(   ) Shell Sort é melhoria do Insertion Sort.
(   ) Quick Sort utiliza pivôs.
(   ) Busca Binária funciona em vetores desordenados.
(   ) Hash pode ter colisões.
(   ) Merge Sort utiliza Dividir para Conquistar.
```

<details>
<summary><b>👀 Resposta da Questão 09</b></summary>

| Resposta | Afirmação                                         | Por quê                                                                                                     |
|----------|---------------------------------------------------|-------------------------------------------------------------------------------------------------------------|
| **(V)**  | Shell Sort é melhoria do Insertion Sort.          | É o Insertion com saltos (gap). O último gap é 1, que é um Insertion normal num vetor já quase ordenado.      |
| **(V)**  | Quick Sort utiliza pivôs.                         | Cada partição escolhe um pivô (no slide, o último) e o coloca na posição final.                            |
| **(F)**  | Busca Binária funciona em vetores desordenados.   | Ela descarta metade do vetor supondo que tudo à esquerda do meio é menor. Só funciona em vetor **ordenado**. |
| **(V)**  | Hash pode ter colisões.                           | Chaves diferentes podem cair no mesmo índice. Trata-se com encadeamento ou sondagem (linear, quadrática, hash duplo). |
| **(V)**  | Merge Sort utiliza Dividir para Conquistar.       | Divide ao meio até sobrar 1 elemento e conquista intercalando na volta da recursão.                          |

**Gabarito:** V, V, F, V, V

</details>

---

## Questão 10: Busca binária com posição errada (0,25)

Um sistema financeiro utiliza busca binária para localizar contas. Em alguns casos, o sistema informa que encontrou a conta, mas retorna uma posição incorreta.

```cpp
int buscaBinaria(int v[], int n, int valor)
{
    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if(v[meio] == valor)
            return inicio;

        if(valor < v[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }

    return -1;
}
```

**a)** Explique o problema.
**b)** Reescreva a função corretamente.

<details>
<summary><b>👀 Resposta da Questão 10</b></summary>

### a) O problema

Quando a conta é encontrada (`v[meio] == valor`), a função retorna **`inicio`** em vez de **`meio`**.

- Quem foi comparado e é igual ao valor procurado é o `v[meio]`, então a posição da conta é **`meio`**.
- `inicio` é só o **limite esquerdo** do trecho que ainda está sendo procurado. Ele não tem relação com onde a conta está.
- O resto da função está certo (o `while`, o `fim = meio - 1`, o `inicio = meio + 1` e o `return -1`). Por isso ela **detecta** corretamente que a conta existe, mas **devolve a posição errada**.
- Ela só acerta **por coincidência**, quando `inicio == meio` (trecho de 1 ou 2 elementos). Isso explica o "em alguns casos".

**Exemplo** com as contas `{1012, 1025, 1033, 1047, 1058, 1061, 1079, 1084, 1090, 1102}` (índices 0 a 9), buscando **1084**:

| Passo | inicio | fim | meio | v[meio] | Decisão                          |
|-------|--------|-----|------|---------|----------------------------------|
| 1     | 0      | 9   | 4    | 1058    | 1084 > 1058 → inicio = 5         |
| 2     | 5      | 9   | 7    | 1084    | **achou!** → retorna `inicio` = **5** |

Retorna **5**, mas a conta 1084 está na posição **7**. A posição 5 é a conta **1061**: o sistema mostraria os dados de **outra conta**.

Testando todas as contas:

| Conta | Posição correta | Versão com bug | Acertou? |
|-------|-----------------|----------------|----------|
| 1012  | 0               | 0              | ✅       |
| 1025  | 1               | 0              | ❌       |
| 1033  | 2               | 2              | ✅       |
| 1047  | 3               | 3              | ✅       |
| 1058  | 4               | 0              | ❌ (achou no 1º meio, com inicio ainda 0) |
| 1061  | 5               | 5              | ✅       |
| 1079  | 6               | 6              | ✅       |
| 1084  | 7               | 5              | ❌       |
| 1090  | 8               | 8              | ✅       |
| 1102  | 9               | 9              | ✅       |

### b) Função corrigida

```cpp
int buscaBinaria(int v[], int n, int valor)
{
    if (v == NULL || n <= 0)
    {
        return -1; // vetor inválido ou vazio
    }

    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2; // mesmo valor que (inicio + fim) / 2, sem risco de overflow

        if (v[meio] == valor)
        {
            return meio; // CORREÇÃO: a conta está em meio, não em inicio
        }

        if (valor < v[meio])
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }

    return -1;
}
```

A correção **obrigatória** é só trocar `return inicio;` por `return meio;`. O resto é tratamento extra (estilo AV1: "não só o caminho feliz"):

- `inicio + (fim - inicio) / 2` evita estouro de `int` quando `inicio + fim` passa de 2.147.483.647 (vetores enormes).
- Validar `v == NULL` e `n <= 0`.
- Lembrete (Questão 09): só funciona se o vetor de contas estiver **ordenado**.

</details>
