<h1 align="center"> 🚀 Aula 08: Ordenação Avançada (Shell, Quick e Merge)</h1>

Resumo da aula + exercícios para treinar. Resolva **no papel** antes de abrir as respostas. Os três usam ideias da [Aula 07](Aula07_Ordenacao_Simples.md) (o Shell é um Insertion "turbinado") e de recursão (Quick e Merge).

📄 Slides: [Aula 08 - Shell, Quick e Merge Sort](<../pdf/Aula 08 - Métodos de Ordenação de Dados Avançados - Shell, Quick, Merge Sort.pdf>)

---

## 1. Shell Sort: o poder dos saltos

> É o **Insertion Sort com saltos (gap)**. Em vez de mover os elementos casa por casa, compara e troca elementos **distantes**. O gap começa em `n / 2` e vai caindo pela metade até chegar em **1**.

```cpp
void shellSort(int arr[], int n) {
    // Reduzindo o gap pela metade a cada iteração
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Fazendo um Insertion Sort para este gap
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;

            // Deslocando elementos ordenados no gap atual
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
```

**Gaps** (divisão inteira!):

| n | Gaps     |
|---|----------|
| 6 | 3, 1     |
| 7 | 3, 1     |
| 8 | 4, 2, 1  |
| 9 | 4, 2, 1  |

> ⚠️ `7 / 2 = 3` em C++ (divisão inteira), não 3,5.

### No papel: o truque das sublistas

Com gap **g**, o vetor vira **g sublistas** "intercaladas": índices `0, g, 2g, ...`, depois `1, 1+g, 1+2g, ...` e assim por diante.

1. Escreva cada sublista separada.
2. **Ordene cada sublista** (são pequenas, dá para fazer de cabeça).
3. Devolva os valores **nos mesmos índices** da sublista.

Exemplo do slide: `[9, 5, 2, 7, 3, 8]` (n = 6 → gap 3):

```
Índice   0  1  2  3  4  5
Valor    9  5  2  7  3  8
```

| Sublista | Índices | Valores | Ordenada |
|----------|---------|---------|----------|
| A        | 0, 3    | 9, 7    | **7, 9** (troca) |
| B        | 1, 4    | 5, 3    | **3, 5** (troca) |
| C        | 2, 5    | 2, 8    | 2, 8 (já ok)     |

Depois do gap 3: `[7, 3, 2, 9, 5, 8]`

**Gap 1** = Insertion Sort normal. O vetor já está "quase ordenado", então precisa de poucas trocas → `[2, 3, 5, 7, 8, 9]`.

**Complexidade:** depende da sequência de gaps. Com `n/2, n/4, ...` o pior caso ainda é O(n²), mas na prática é bem mais rápido que o Insertion puro. **Não é estável.**

---

## 2. Quick Sort: dividir para conquistar

> Escolhe um **pivô** (no slide, o **último** elemento do trecho) e **particiona**: tudo **menor** que o pivô vai para a esquerda, tudo **maior ou igual** para a direita, e o pivô cai na sua **posição final**. Depois chama recursivamente para cada lado.

```cpp
// O coração do algoritmo: posicionar o pivô
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolhemos o último como pivô
    int i = (low - 1);      // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);         // Retorna a posição final do pivô
}

// Função recursiva principal
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

### No papel: a tabela do i e do j

- `i` começa em `low - 1` (**fora** do vetor). Ele marca o **fim da região dos menores**.
- `j` varre de `low` até `high - 1`.
- Se `arr[j] < pivô` → `i++` e **troca** `arr[i] ↔ arr[j]`. Senão, nada.
- No fim → troca `arr[i + 1] ↔ pivô`. O pivô vai para a posição **i + 1**.

Exemplo do slide: `[8, 3, 1, 7, 0, 10, 2]`, pivô **2**.

| j   | arr[j] | arr[j] < 2? | i  | Ação                    | Vetor                        |
|-----|--------|-------------|----|-------------------------|------------------------------|
| -   | -      | -           | -1 | início                  | [8, 3, 1, 7, 0, 10, **2**]   |
| 0   | 8      | ❌          | -1 | nada                    | [8, 3, 1, 7, 0, 10, 2]       |
| 1   | 3      | ❌          | -1 | nada                    | [8, 3, 1, 7, 0, 10, 2]       |
| 2   | 1      | ✅          | 0  | troca arr[0] ↔ arr[2]   | [**1**, 3, **8**, 7, 0, 10, 2] |
| 3   | 7      | ❌          | 0  | nada                    | [1, 3, 8, 7, 0, 10, 2]       |
| 4   | 0      | ✅          | 1  | troca arr[1] ↔ arr[4]   | [1, **0**, 8, 7, **3**, 10, 2] |
| 5   | 10     | ❌          | 1  | nada                    | [1, 0, 8, 7, 3, 10, 2]       |
| fim |        |             |    | troca arr[2] ↔ arr[6]   | [1, 0, **2**, 7, 3, 10, 8]   |

Pivô **2** na posição **2** (definitiva). Esquerda `[1, 0]`, direita `[7, 3, 10, 8]`. Agora o `quickSort` chama ele mesmo para cada lado.

**Complexidade:**

- Médio: **O(n log n)**.
- Pior: **O(n²)**, quando o pivô é sempre o maior ou o menor do trecho (ex.: vetor **já ordenado** com pivô = último). Veja a Questão 9.
- **Não é estável.** É in-place (só usa a pilha da recursão).

---

## 3. Merge Sort: a conquista garantida

> **Divide** o vetor ao meio, repetidas vezes, até cada pedaço ter **1 elemento** (que já está ordenado por definição). Depois, na volta da recursão, **intercala (merge)** os pedaços em ordem.

```cpp
// Função auxiliar merge() junta dois subarrays ordenados
// (o slide omitiu a lógica, ela está na Questão 12)
void merge(int arr[], int left, int mid, int right);

// Função recursiva de divisão
void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return; // Condição de parada: sublista de 1 elemento

    int mid = left + (right - left) / 2;

    // Divide e ordena a primeira e a segunda metade
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Junta (Merge) as duas metades agora ordenadas
    merge(arr, left, mid, right);
}
```

> 💡 Com `mid = left + (right - left) / 2`, a metade da **esquerda** vai de `left` até `mid` (inclusive). Quando o tamanho é **ímpar**, a **esquerda fica com 1 a mais**.

### Exemplo do slide: `[38, 27, 43, 3, 9, 82]`

**Divisão** (nenhuma comparação, só corta):

```
              [38, 27, 43, 3, 9, 82]
               /                  \
       [38, 27, 43]           [3, 9, 82]
         /      \               /     \
     [38, 27]   [43]        [3, 9]    [82]
      /   \                  /   \
   [38]  [27]              [3]   [9]
```

> ⚠️ **O slide 12 tem um erro de desenho:** mostra `[38, 27, 43]` virando `[38, 27]` e `[27, 43]` (o 27 aparece duas vezes) e `[3, 9, 82]` virando `[3]` e `[9, 82]`. Pelo código, o certo é o desenho acima, que bate com o slide 13 (intercalação).

**Intercalação** (na volta da recursão):

```
   [38]  [27]              [3]   [9]
      \   /                  \   /
     [27, 38]   [43]        [3, 9]    [82]
         \      /               \     /
       [27, 38, 43]           [3, 9, 82]
               \                  /
              [3, 9, 27, 38, 43, 82]
```

### No papel: como intercalar duas listas ordenadas

Um "dedo" em cada lista. Compara os dois da frente, o **menor sai**. Quando uma lista acaba, **copia o resto** da outra.

Exemplo: `[27, 38, 43]` + `[3, 9, 82]`

| Rodada | Esquerda          | Direita         | Compara   | Sai | Resultado                  |
|--------|-------------------|-----------------|-----------|-----|----------------------------|
| 1      | **27**, 38, 43    | **3**, 9, 82    | 27 vs 3   | 3   | [3]                        |
| 2      | **27**, 38, 43    | **9**, 82       | 27 vs 9   | 9   | [3, 9]                     |
| 3      | **27**, 38, 43    | **82**          | 27 vs 82  | 27  | [3, 9, 27]                 |
| 4      | **38**, 43        | **82**          | 38 vs 82  | 38  | [3, 9, 27, 38]             |
| 5      | **43**            | **82**          | 43 vs 82  | 43  | [3, 9, 27, 38, 43]         |
| 6      | (vazia)           | 82              | sobra     | 82  | [3, 9, 27, 38, 43, 82]     |

**5 comparações.**

**Complexidade:** **O(n log n) em todos os casos** (melhor, médio e pior). **É estável.** Desvantagem: precisa de um **vetor auxiliar** do tamanho do trecho (não é in-place).

---

## 4. Comparativo geral (Aulas 07 e 08)

| Algoritmo     | Melhor       | Médio        | Pior         | Estável? | Memória extra       |
|---------------|--------------|--------------|--------------|----------|---------------------|
| **Bubble**    | O(n)*        | O(n²)        | O(n²)        | ✅       | nenhuma             |
| **Selection** | O(n²)        | O(n²)        | O(n²)        | ❌       | nenhuma             |
| **Insertion** | O(n)         | O(n²)        | O(n²)        | ✅       | nenhuma             |
| **Shell**     | O(n log n)   | depende dos gaps | O(n²) (gaps n/2) | ❌ | nenhuma           |
| **Quick**     | O(n log n)   | O(n log n)   | **O(n²)**    | ❌       | pilha da recursão   |
| **Merge**     | O(n log n)   | O(n log n)   | O(n log n)   | ✅       | **vetor auxiliar O(n)** |

\* só com a flag `trocou`.

---

<h1 align="center"> 🏋️ Exercícios</h1>

## Parte A: exercícios do slide

### Questão 1: Shell Sort com tabelas

Ordene `[14, 33, 27, 10, 35, 19, 42]` usando gaps de **3** e depois **1**. Apresente a tabela de estado após cada gap.

<details>
<summary><b>👀 Resposta da Questão 1</b></summary>

```
Índice   0   1   2   3   4   5   6
Valor    14  33  27  10  35  19  42
```

### Gap 3

| Sublista | Índices  | Valores      | Ordenada          |
|----------|----------|--------------|-------------------|
| A        | 0, 3, 6  | 14, 10, 42   | **10, 14, 42**    |
| B        | 1, 4     | 33, 35       | 33, 35 (já ok)    |
| C        | 2, 5     | 27, 19       | **19, 27**        |

Devolvendo nos índices:

```
Índice   0   1   2   3   4   5   6
Valor    10  33  19  14  35  27  42
```

### Gap 1 (Insertion Sort normal)

| i | key | Quem anda      | Vetor                             |
|---|-----|----------------|-----------------------------------|
| 1 | 33  | ninguém        | [10, 33, 19, 14, 35, 27, 42]      |
| 2 | 19  | 33             | [10, 19, 33, 14, 35, 27, 42]      |
| 3 | 14  | 33, 19         | [10, 14, 19, 33, 35, 27, 42]      |
| 4 | 35  | ninguém        | [10, 14, 19, 33, 35, 27, 42]      |
| 5 | 27  | 35, 33         | [10, 14, 19, 27, 33, 35, 42]      |
| 6 | 42  | ninguém        | [10, 14, 19, 27, 33, 35, 42]      |

**Resultado:** `[10, 14, 19, 27, 33, 35, 42]`

</details>

---

### Questão 2: Shell Sort com setas de troca

Aplique Shell Sort no vetor `[50, 12, 65, 30, 22, 9]`, indicando graficamente as setas de troca.

<details>
<summary><b>👀 Resposta da Questão 2</b></summary>

n = 6 → gaps **3, 1**.

### Gap 3

```
Índice   0    1    2    3    4    5
Valor    50   12   65   30   22   9
         └──────────────┘                 50 > 30 → troca
              └──────────────┘            12 < 22 → fica
                   └──────────────┘       65 > 9  → troca

Após     30   12   9    50   22   65
```

### Gap 1

| i | key | Quem anda | Vetor                         |
|---|-----|-----------|-------------------------------|
| 1 | 12  | 30        | [12, 30, 9, 50, 22, 65]       |
| 2 | 9   | 30, 12    | [9, 12, 30, 50, 22, 65]       |
| 3 | 50  | ninguém   | [9, 12, 30, 50, 22, 65]       |
| 4 | 22  | 50, 30    | [9, 12, 22, 30, 50, 65]       |
| 5 | 65  | ninguém   | [9, 12, 22, 30, 50, 65]       |

**Resultado:** `[9, 12, 22, 30, 50, 65]`

</details>

---

### Questão 3: Quick Sort, tabela do i e j

Ordene o vetor `[24, 9, 29, 14, 19, 27]` usando o último elemento (**27**) como pivô. Desenhe a tabela mostrando os ponteiros **i** e **j** até a primeira partição.

<details>
<summary><b>👀 Resposta da Questão 3</b></summary>

| j   | arr[j] | < 27? | i  | Ação                              | Vetor                          |
|-----|--------|-------|----|-----------------------------------|--------------------------------|
| -   | -      | -     | -1 | início                            | [24, 9, 29, 14, 19, **27**]    |
| 0   | 24     | ✅    | 0  | troca arr[0] ↔ arr[0] (ele mesmo) | [24, 9, 29, 14, 19, 27]        |
| 1   | 9      | ✅    | 1  | troca arr[1] ↔ arr[1] (ele mesmo) | [24, 9, 29, 14, 19, 27]        |
| 2   | 29     | ❌    | 1  | nada                              | [24, 9, 29, 14, 19, 27]        |
| 3   | 14     | ✅    | 2  | troca arr[2] ↔ arr[3]             | [24, 9, **14**, **29**, 19, 27] |
| 4   | 19     | ✅    | 3  | troca arr[3] ↔ arr[4]             | [24, 9, 14, **19**, **29**, 27] |
| fim |        |       |    | troca arr[4] ↔ arr[5]             | [24, 9, 14, 19, **27**, 29]    |

Pivô **27** na posição **4**. Esquerda `[24, 9, 14, 19]`, direita `[29]`.

**Continuando até o fim (bônus):**

- `[24, 9, 14, 19]`, pivô 19 → `[9, 14, 19, 24]`, pivô na posição 2.
- `[9, 14]`, pivô 14 → já fica no lugar.

**Resultado:** `[9, 14, 19, 24, 27, 29]`

</details>

---

### Questão 4: Posição do pivô com valor repetido

Encontre a posição correta do pivô **15** no array `[18, 12, 5, 20, 15, 8, 15]` e mostre as duas sublistas resultantes.

<details>
<summary><b>👀 Resposta da Questão 4</b></summary>

O pivô é o **último** (índice 6). Repare que existe **outro 15** no índice 4.

| j   | arr[j] | < 15?                   | i  | Ação                  | Vetor                              |
|-----|--------|-------------------------|----|-----------------------|------------------------------------|
| -   | -      | -                       | -1 | início                | [18, 12, 5, 20, 15, 8, **15**]     |
| 0   | 18     | ❌                      | -1 | nada                  | [18, 12, 5, 20, 15, 8, 15]         |
| 1   | 12     | ✅                      | 0  | troca arr[0] ↔ arr[1] | [**12**, **18**, 5, 20, 15, 8, 15] |
| 2   | 5      | ✅                      | 1  | troca arr[1] ↔ arr[2] | [12, **5**, **18**, 20, 15, 8, 15] |
| 3   | 20     | ❌                      | 1  | nada                  | [12, 5, 18, 20, 15, 8, 15]         |
| 4   | 15     | ❌ (15 < 15 é **falso**) | 1  | nada                  | [12, 5, 18, 20, 15, 8, 15]         |
| 5   | 8      | ✅                      | 2  | troca arr[2] ↔ arr[5] | [12, 5, **8**, 20, 15, **18**, 15] |
| fim |        |                         |    | troca arr[3] ↔ arr[6] | [12, 5, 8, **15**, 15, 18, 20]     |

Pivô **15** na posição **3**.

- Esquerda (menores que 15): `[12, 5, 8]`
- Direita (maiores **ou iguais** a 15): `[15, 18, 20]`

> ⚠️ **Pegadinha:** o outro 15 vai para a **direita**, porque a comparação é `<` estrita.

</details>

---

### Questão 5: Merge Sort, árvores de divisão e intercalação

Desenhe a árvore completa de divisão e a árvore de mescla (merge) para o array `[11, 4, 7, 2, 9, 5]`.

<details>
<summary><b>👀 Resposta da Questão 5</b></summary>

### Divisão

```
               [11, 4, 7, 2, 9, 5]
                /               \
         [11, 4, 7]          [2, 9, 5]
          /      \            /     \
      [11, 4]    [7]       [2, 9]    [5]
       /   \                /   \
    [11]   [4]            [2]   [9]
```

### Intercalação

```
    [11]   [4]            [2]   [9]
       \   /                \   /
      [4, 11]    [7]       [2, 9]    [5]
          \      /            \     /
         [4, 7, 11]          [2, 5, 9]
                \               /
               [2, 4, 5, 7, 9, 11]
```

</details>

---

### Questão 6: Intercalação passo a passo

Dadas as sublistas já ordenadas `[2, 8, 15]` e `[4, 5, 9]`, demonstre o processo de intercalação passo a passo, mostrando qual elemento é selecionado a cada rodada.

<details>
<summary><b>👀 Resposta da Questão 6</b></summary>

| Rodada | Esquerda        | Direita        | Compara   | Sai | Resultado               |
|--------|-----------------|----------------|-----------|-----|-------------------------|
| 1      | **2**, 8, 15    | **4**, 5, 9    | 2 vs 4    | 2   | [2]                     |
| 2      | **8**, 15       | **4**, 5, 9    | 8 vs 4    | 4   | [2, 4]                  |
| 3      | **8**, 15       | **5**, 9       | 8 vs 5    | 5   | [2, 4, 5]               |
| 4      | **8**, 15       | **9**          | 8 vs 9    | 8   | [2, 4, 5, 8]            |
| 5      | **15**          | **9**          | 15 vs 9   | 9   | [2, 4, 5, 8, 9]         |
| 6      | 15              | (vazia)        | sobra     | 15  | [2, 4, 5, 8, 9, 15]     |

**5 comparações.** É o máximo possível para juntar 3 + 3 elementos (n1 + n2 - 1).

</details>

---

## Parte B: extras no papel

### Questão 7: Shell Sort com 3 gaps

Ordene `[23, 29, 15, 19, 31, 7, 9, 5, 2]`. Quais são os gaps? Mostre o vetor após cada um.

<details>
<summary><b>👀 Resposta da Questão 7</b></summary>

n = 9 → gaps **4, 2, 1** (9/2 = 4, 4/2 = 2, 2/2 = 1).

```
Índice   0   1   2   3   4   5   6   7   8
Valor    23  29  15  19  31  7   9   5   2
```

### Gap 4

| Sublista | Índices  | Valores      | Ordenada       |
|----------|----------|--------------|----------------|
| A        | 0, 4, 8  | 23, 31, 2    | **2, 23, 31**  |
| B        | 1, 5     | 29, 7        | **7, 29**      |
| C        | 2, 6     | 15, 9        | **9, 15**      |
| D        | 3, 7     | 19, 5        | **5, 19**      |

Após gap 4: `[2, 7, 9, 5, 23, 29, 15, 19, 31]`

### Gap 2

| Sublista | Índices        | Valores              | Ordenada               |
|----------|----------------|----------------------|------------------------|
| Pares    | 0, 2, 4, 6, 8  | 2, 9, 23, 15, 31     | **2, 9, 15, 23, 31**   |
| Ímpares  | 1, 3, 5, 7     | 7, 5, 29, 19         | **5, 7, 19, 29**       |

Após gap 2: `[2, 5, 9, 7, 15, 19, 23, 29, 31]`

### Gap 1

Só o 7 precisa andar uma casa (troca com o 9): `[2, 5, 7, 9, 15, 19, 23, 29, 31]`

Repare como o gap 1 quase não teve trabalho: **1 deslocamento**. Essa é a mágica do Shell.

</details>

---

### Questão 8: Quick Sort completo

Ordene `[10, 80, 30, 90, 40, 50, 70]` até o fim. Para cada partição, diga o pivô, a posição final dele e as sublistas. Desenhe a árvore de recursão.

<details>
<summary><b>👀 Resposta da Questão 8</b></summary>

### Partição 1: `[10, 80, 30, 90, 40, 50, 70]`, pivô 70

| j   | arr[j] | < 70? | i  | Ação                  | Vetor                              |
|-----|--------|-------|----|-----------------------|------------------------------------|
| -   | -      | -     | -1 | início                | [10, 80, 30, 90, 40, 50, **70**]   |
| 0   | 10     | ✅    | 0  | arr[0] ↔ arr[0]       | [10, 80, 30, 90, 40, 50, 70]       |
| 1   | 80     | ❌    | 0  | nada                  |                                    |
| 2   | 30     | ✅    | 1  | arr[1] ↔ arr[2]       | [10, 30, 80, 90, 40, 50, 70]       |
| 3   | 90     | ❌    | 1  | nada                  |                                    |
| 4   | 40     | ✅    | 2  | arr[2] ↔ arr[4]       | [10, 30, 40, 90, 80, 50, 70]       |
| 5   | 50     | ✅    | 3  | arr[3] ↔ arr[5]       | [10, 30, 40, 50, 80, 90, 70]       |
| fim |        |       |    | arr[4] ↔ arr[6]       | [10, 30, 40, 50, **70**, 90, 80]   |

### Resumo de todas as partições

| # | Trecho              | Pivô | Posição final | Esquerda        | Direita    |
|---|---------------------|------|---------------|-----------------|------------|
| 1 | [10,80,30,90,40,50,70] | 70 | 4           | [10, 30, 40, 50] | [90, 80]  |
| 2 | [10, 30, 40, 50]    | 50   | 3             | [10, 30, 40]    | (vazia)    |
| 3 | [10, 30, 40]        | 40   | 2             | [10, 30]        | (vazia)    |
| 4 | [10, 30]            | 30   | 1             | [10]            | (vazia)    |
| 5 | [90, 80]            | 80   | 5             | (vazia)         | [90]       |

### Árvore de recursão

```
              [10, 80, 30, 90, 40, 50, 70]   pivô 70
                 /                     \
       [10, 30, 40, 50]  pivô 50      [90, 80]  pivô 80
          /                              \
    [10, 30, 40]  pivô 40               [90]
       /
  [10, 30]  pivô 30
     /
  [10]
```

**Resultado:** `[10, 30, 40, 50, 70, 80, 90]`, com **5 partições**.

Repare que o lado esquerdo ficou "torto": `[10, 30, 40, 50]` já estava ordenado depois da 1ª partição, e cada pivô (o último) era o **maior** do trecho. É uma prévia do pior caso (próxima questão).

</details>

---

### Questão 9: O pior caso do Quick Sort

Ordene `[1, 2, 3, 4, 5]` (já ordenado) com o Quick Sort do slide.

**a)** Quantas partições acontecem? Qual o tamanho do trecho em cada uma?

**b)** Quantas comparações no total? Por que isso é O(n²)?

**c)** Como evitar?

<details>
<summary><b>👀 Resposta da Questão 9</b></summary>

### a)

| # | Trecho            | Pivô | Posição final | Esquerda        | Direita  |
|---|-------------------|------|---------------|-----------------|----------|
| 1 | [1, 2, 3, 4, 5]   | 5    | 4             | [1, 2, 3, 4]    | (vazia)  |
| 2 | [1, 2, 3, 4]      | 4    | 3             | [1, 2, 3]       | (vazia)  |
| 3 | [1, 2, 3]         | 3    | 2             | [1, 2]          | (vazia)  |
| 4 | [1, 2]            | 2    | 1             | [1]             | (vazia)  |

**4 partições**, e cada uma só tira **1 elemento** do problema (o pivô). O lado direito fica sempre vazio.

### b)

Comparações: 4 + 3 + 2 + 1 = **10** = n(n-1)/2 → **O(n²)**. A divisão "ao meio" que deixa o Quick rápido nunca acontece.

### c)

Escolher um pivô melhor: o **elemento do meio**, um elemento **aleatório**, ou a **mediana de três** (primeiro, meio e último).

</details>

---

### Questão 10: Merge Sort com tamanho ímpar

Faça a divisão e a intercalação de `[38, 27, 43, 3, 9, 82, 10]` (7 elementos). Quantas comparações no **último** merge?

<details>
<summary><b>👀 Resposta da Questão 10</b></summary>

left = 0, right = 6 → mid = 3. A esquerda fica com **4** e a direita com **3**.

### Divisão

```
                [38, 27, 43, 3, 9, 82, 10]
                 /                     \
        [38, 27, 43, 3]            [9, 82, 10]
          /          \               /     \
     [38, 27]     [43, 3]        [9, 82]   [10]
      /   \        /   \          /   \
   [38]  [27]   [43]   [3]      [9]  [82]
```

### Intercalação

```
   [38]  [27]   [43]   [3]      [9]  [82]
      \   /        \   /          \   /
     [27, 38]     [3, 43]        [9, 82]   [10]
          \          /               \     /
        [3, 27, 38, 43]            [9, 10, 82]
                 \                     /
                [3, 9, 10, 27, 38, 43, 82]
```

### Último merge: `[3, 27, 38, 43]` + `[9, 10, 82]`

| Rodada | Compara   | Sai |
|--------|-----------|-----|
| 1      | 3 vs 9    | 3   |
| 2      | 27 vs 9   | 9   |
| 3      | 27 vs 10  | 10  |
| 4      | 27 vs 82  | 27  |
| 5      | 38 vs 82  | 38  |
| 6      | 43 vs 82  | 43  |
| -      | sobra     | 82  |

**6 comparações.**

</details>

---

### Questão 11: Qual algoritmo usar?

**a)** Vetor pequeno e **quase ordenado**.

**b)** Precisa garantir **O(n log n) mesmo no pior caso** e manter a ordem de quem empatou (ex.: pedidos por data, mantendo a ordem por cliente).

**c)** Pouca memória extra, dados aleatórios, quer o mais rápido **em média**.

**d)** Por que o Shell Sort é mais rápido que o Insertion Sort?

<details>
<summary><b>👀 Resposta da Questão 11</b></summary>

| Item   | Resposta |
|--------|----------|
| **a)** | **Insertion Sort**: perto do melhor caso, O(n). |
| **b)** | **Merge Sort**: O(n log n) em todos os casos e é **estável**. |
| **c)** | **Quick Sort**: O(n log n) em média e é in-place (não precisa de vetor auxiliar como o Merge). |
| **d)** | Com gaps grandes, um elemento que está muito longe do lugar certo "pula" várias casas de uma vez. Quando chega no gap 1, o vetor já está quase ordenado e o Insertion final tem pouquíssimo trabalho. |

</details>

---

## Parte C: código

Estilo da AV1: **faça todos os tratamentos necessários, não só o caminho feliz.** Os arquivos `.cpp` podem ir em [AV2/c++/](../c++/).

### Questão 12: Implemente o `merge()`

O slide **omitiu** a função `merge()` ("lógica de intercalação omitida por espaço"). Implemente:

```cpp
void merge(int arr[], int left, int mid, int right);
```

Ela recebe o trecho `arr[left..right]`, onde `arr[left..mid]` e `arr[mid+1..right]` já estão ordenados, e deixa o trecho inteiro ordenado.

<details>
<summary><b>👀 Resposta da Questão 12</b></summary>

Copia as duas metades para vetores auxiliares `L` e `R`, depois faz exatamente a tabela "dois dedos" do resumo.

```cpp
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) // <= mantém o merge estável
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arr[k] = L[i]; i++; k++; } // sobra da esquerda
    while (j < n2) { arr[k] = R[j]; j++; k++; } // sobra da direita

    delete[] L;
    delete[] R;
}
```

> 💡 O `<=` (e não `<`) é o que faz o Merge Sort ser **estável**: no empate, o da esquerda (que veio antes) sai primeiro.

</details>

---

### Questão 13: Quick Sort decrescente

Qual a menor mudança no código do slide para o Quick Sort ordenar em ordem **decrescente**? Teste com `[24, 9, 29, 14, 19, 27]` → `[29, 27, 24, 19, 14, 9]`.

<details>
<summary><b>👀 Resposta da Questão 13</b></summary>

Só a comparação dentro da `partition`: agora os **maiores** que o pivô vão para a esquerda.

```cpp
int partitionDecrescente(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot) // única mudança: > no lugar de <
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
```

O `quickSort` continua igual, só chamando `partitionDecrescente`.

</details>

---

### Questão 14: Intercalar duas listas encadeadas ordenadas

Juntando a AV1 (listas) com o Merge: dadas duas listas **já ordenadas**, devolva uma única lista ordenada **reaproveitando os nós** (sem criar nós novos).

```cpp
typedef struct No
{
    int valor;
    No* proximo_lista;
} No;

No* intercalarListas(No* L1, No* L2);
```

Trate `L1` e/ou `L2` vazias. Exemplo: `2 -> 8 -> 15` e `4 -> 5 -> 9` → `2 -> 4 -> 5 -> 8 -> 9 -> 15`.

<details>
<summary><b>👀 Resposta da Questão 14</b></summary>

### Versão iterativa

```cpp
No* intercalarListas(No* L1, No* L2)
{
    if (!L1) return L2;
    if (!L2) return L1;

    No* inicio_lista;

    if (L1->valor <= L2->valor)
    {
        inicio_lista = L1;
        L1 = L1->proximo_lista;
    }
    else
    {
        inicio_lista = L2;
        L2 = L2->proximo_lista;
    }

    No* ultimo = inicio_lista;

    while (L1 && L2)
    {
        if (L1->valor <= L2->valor)
        {
            ultimo->proximo_lista = L1;
            L1 = L1->proximo_lista;
        }
        else
        {
            ultimo->proximo_lista = L2;
            L2 = L2->proximo_lista;
        }
        ultimo = ultimo->proximo_lista;
    }

    ultimo->proximo_lista = L1 ? L1 : L2; // sobra de uma das listas
    return inicio_lista;
}
```

### Versão recursiva

```cpp
No* intercalarListasRecursiva(No* L1, No* L2)
{
    if (!L1) return L2;
    if (!L2) return L1;

    if (L1->valor <= L2->valor)
    {
        L1->proximo_lista = intercalarListasRecursiva(L1->proximo_lista, L2);
        return L1;
    }

    L2->proximo_lista = intercalarListasRecursiva(L1, L2->proximo_lista);
    return L2;
}
```

Repare que é a mesma ideia do `concatenarListas` da AV1, só que em vez de ligar o fim de uma no começo da outra, você vai escolhendo **o menor da frente** a cada passo.

</details>

---

### Questão 15: Shell Sort que mostra cada gap

Modifique o `shellSort` para **imprimir o vetor depois de cada gap**. Use para **conferir** suas respostas das Questões 1, 2 e 7.

Saída esperada para `[14, 33, 27, 10, 35, 19, 42]`:

```
Apos gap 3: 10 33 19 14 35 27 42
Apos gap 1: 10 14 19 27 33 35 42
```

<details>
<summary><b>👀 Resposta da Questão 15</b></summary>

```cpp
void imprimirVetor(int arr[], int n)
{
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

void shellSortMostrando(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }

        std::cout << "Apos gap " << gap << ": ";
        imprimirVetor(arr, n);
    }
}
```

O mesmo truque serve para os outros: imprima o vetor no fim de cada `i` do Bubble/Selection/Insertion, ou depois de cada `partition` no Quick, e compare com o seu papel.

</details>

---

### Questão 16 (desafio): k-ésimo menor com `partition`

Sem ordenar o vetor inteiro, ache o **k-ésimo menor** elemento (k começa em 0) usando a `partition` do Quick Sort.

```cpp
int kEsimoMenor(int arr[], int low, int high, int k);
```

Exemplo: `[7, 10, 4, 3, 20, 15]`, k = 2 → **7** (ordenado seria `3, 4, 7, 10, 15, 20`).

**Dica:** depois da `partition`, o pivô está na **posição final**. Se essa posição for k, achou. Se não, precisa olhar **só um** dos lados.

<details>
<summary><b>👀 Resposta da Questão 16</b></summary>

```cpp
int kEsimoMenor(int arr[], int low, int high, int k)
{
    int pi = partition(arr, low, high);

    if (pi == k) return arr[pi];
    if (k < pi) return kEsimoMenor(arr, low, pi - 1, k);
    return kEsimoMenor(arr, pi + 1, high, k);
}
```

Chamada: `kEsimoMenor(arr, 0, n - 1, k)`, com `0 <= k < n`. Diferente do Quick Sort, só desce por **um lado** da recursão, então em média é O(n).

</details>
