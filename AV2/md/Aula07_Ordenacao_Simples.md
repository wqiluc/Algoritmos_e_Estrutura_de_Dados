<h1 align="center"> 🫧 Aula 07: Ordenação Simples (Bubble, Selection e Insertion)</h1>

Resumo da aula + exercícios para treinar. Resolva **no papel** antes de abrir as respostas.

📄 Slides: [Aula 07 - Bubble, Selection e Insertion Sort](<../pdf/Aula 07 - Métodos Internos de Ordenação de Dados - BubbleSort, SelectionSort e InsertionSort .pdf>)

---

## 0. Vocabulário rápido

| Termo         | Significado                                                                 |
|---------------|-----------------------------------------------------------------------------|
| **Iteração**  | uma volta do `for` de fora (`i`). É o que os slides desenham em cada tabela |
| **Troca**     | dois elementos trocam de lugar (`temp`)                                     |
| **Estável**   | elementos **iguais** continuam na mesma ordem relativa de antes             |
| **In-place**  | ordena no próprio vetor, sem vetor auxiliar                                 |

Os três da aula são **O(n²)** e **in-place**.

---

## 1. Bubble Sort

> **Compara vizinhos** (`j` e `j+1`) e troca se estiverem fora de ordem. A cada passada, o **MAIOR** "borbulha" até o **fim**.

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

### No papel: exemplo do slide `[5, 1, 4, 2, 8]`

**Passada 1** (i = 0, j vai de 0 a 3):

| j | Compara   | Troca? | Vetor             |
|---|-----------|--------|-------------------|
| 0 | 5 > 1     | ✅     | [1, 5, 4, 2, 8]   |
| 1 | 5 > 4     | ✅     | [1, 4, 5, 2, 8]   |
| 2 | 5 > 2     | ✅     | [1, 4, 2, 5, 8]   |
| 3 | 5 > 8     | ❌     | [1, 4, 2, **5, 8**] |

**Passada 2** (j vai de 0 a 2): 1 > 4 ❌, 4 > 2 ✅, 4 > 5 ❌ → `[1, 2, 4, 5, 8]`

**Passadas 3 e 4:** nenhuma troca, mas o código do slide **roda mesmo assim** (não sabe que já acabou).

> 💡 Depois da passada **k**, os **k últimos** já estão no lugar certo. Por isso o `j < n - i - 1`: não precisa comparar o que já "borbulhou".

> 💡 O slide diz "repetindo até não precisar mais de trocas", mas o código dele **não para sozinho**. Para parar, precisa de uma flag `trocou` (Questão 8).

---

## 2. Selection Sort

> **Acha o MENOR** do trecho que falta ordenar e **troca** com a primeira posição desse trecho.

```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
```

### No papel: exemplo do slide `[64, 25, 12, 22, 11]`

| Iteração | i | Trecho olhado          | Menor        | Troca          | Vetor                   |
|----------|---|------------------------|--------------|----------------|-------------------------|
| 1        | 0 | [64, 25, 12, 22, 11]   | 11 (idx 4)   | 64 ↔ 11        | [**11**, 25, 12, 22, 64] |
| 2        | 1 | [25, 12, 22, 64]       | 12 (idx 2)   | 25 ↔ 12        | [11, **12**, 25, 22, 64] |
| 3        | 2 | [25, 22, 64]           | 22 (idx 3)   | 25 ↔ 22        | [11, 12, **22**, 25, 64] |
| 4        | 3 | [25, 64]               | 25 (idx 3)   | nenhuma        | [11, 12, 22, **25**, 64] |

> 💡 Faz **no máximo n-1 trocas** (vantagem). Mas **sempre** percorre o trecho todo para achar o menor, mesmo se o vetor já estiver ordenado: é O(n²) **sempre**.

> ✏️ O código do slide executa a troca mesmo quando `min_idx == i` (troca o elemento com ele mesmo). Não estraga nada, só é uma troca "à toa".

---

## 3. Insertion Sort

> Igual a **arrumar cartas na mão**: pega o próximo elemento (`key`), empurra os **maiores** uma casa para a direita e **encaixa** a `key` no buraco.

```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];   // empurra para a direita
            j--;
        }
        arr[j + 1] = key;          // encaixa
    }
}
```

### No papel: exemplo do slide `[12, 11, 13, 5, 6]`

| Iteração | i | key | Quem anda para a direita | Vetor                    |
|----------|---|-----|--------------------------|--------------------------|
| 1        | 1 | 11  | 12                       | [**11, 12**, 13, 5, 6]   |
| 2        | 2 | 13  | ninguém (12 < 13)        | [**11, 12, 13**, 5, 6]   |
| 3        | 3 | 5   | 13, 12, 11               | [**5, 11, 12, 13**, 6]   |
| 4        | 4 | 6   | 13, 12, 11               | [**5, 6, 11, 12, 13**]   |

> 💡 O começo do vetor (até `i`) está **sempre ordenado**, e o resto está **intocado** (igual ao original).

> 💡 Se o vetor já estiver ordenado, o `while` nunca entra: só **n-1 comparações** → O(n). Por isso o slide diz que ele é bom para vetores **quase ordenados**.

---

## 4. Comparativo

|                  | Bubble                            | Selection             | Insertion                       |
|------------------|-----------------------------------|-----------------------|---------------------------------|
| **Ideia**        | troca vizinhos                    | escolhe o menor       | encaixa na parte ordenada       |
| **Melhor caso**  | O(n²) no slide, O(n) com flag     | O(n²)                 | **O(n)** (já ordenado)          |
| **Médio / pior** | O(n²)                             | O(n²)                 | O(n²)                           |
| **Trocas**       | muitas                            | **poucas** (≤ n-1)    | deslocamentos                   |
| **Estável?**     | ✅ sim                            | ❌ não                | ✅ sim                          |
| **Vantagem**     | implementação simples             | poucas trocas         | ótimo em vetor pequeno/quase ordenado |

### ✏️ Dica de prova: reconhecer o algoritmo olhando os estados

| Algoritmo     | O que você vê depois de algumas iterações                                              |
|---------------|----------------------------------------------------------------------------------------|
| **Bubble**    | os **MAIORES** do vetor se acumulando no **FIM**                                       |
| **Selection** | os **MENORES** do vetor se acumulando no **INÍCIO**                                    |
| **Insertion** | o **início ordenado**, mas não necessariamente com os menores do vetor; o **fim igual ao original** |

---

<h1 align="center"> 🏋️ Exercícios</h1>

## Parte A: exercícios do slide

Mostre o vetor **depois de cada iteração** (e, no Bubble, cada comparação).

### Questão 1: Bubble Sort

**a)** `[9, 7, 3, 1]`

**b)** `[10, 5, 2, 8, 7]`

<details>
<summary><b>👀 Resposta da Questão 1</b></summary>

### a) `[9, 7, 3, 1]`

| Passada | Comparações e trocas                                 | Vetor no fim      |
|---------|------------------------------------------------------|-------------------|
| 1       | 9 > 7 ✅ · 9 > 3 ✅ · 9 > 1 ✅                         | [7, 3, 1, **9**]  |
| 2       | 7 > 3 ✅ · 7 > 1 ✅                                    | [3, 1, **7, 9**]  |
| 3       | 3 > 1 ✅                                              | [**1, 3, 7, 9**]  |

**6 comparações e 6 trocas.** Vetor invertido é o **pior caso**: toda comparação vira troca.

### b) `[10, 5, 2, 8, 7]`

| Passada | Comparações e trocas                                 | Vetor no fim          |
|---------|------------------------------------------------------|-----------------------|
| 1       | 10 > 5 ✅ · 10 > 2 ✅ · 10 > 8 ✅ · 10 > 7 ✅            | [5, 2, 8, 7, **10**]  |
| 2       | 5 > 2 ✅ · 5 > 8 ❌ · 8 > 7 ✅                          | [2, 5, 7, **8, 10**]  |
| 3       | 2 > 5 ❌ · 5 > 7 ❌                                     | [2, 5, **7, 8, 10**]  |
| 4       | 2 > 5 ❌                                               | [**2, 5, 7, 8, 10**]  |

**6 trocas.** Já estava ordenado depois da passada 2. Com a flag `trocou`, o algoritmo pararia na passada 3 (a primeira sem troca).

</details>

---

### Questão 2: Selection Sort

**a)** `[15, 10, 20, 5]`

**b)** `[4, 1, 3, 2]`

<details>
<summary><b>👀 Resposta da Questão 2</b></summary>

### a) `[15, 10, 20, 5]`

| Iteração | i | Trecho              | Menor       | Troca       | Vetor                |
|----------|---|---------------------|-------------|-------------|----------------------|
| 1        | 0 | [15, 10, 20, 5]     | 5 (idx 3)   | 15 ↔ 5      | [**5**, 10, 20, 15]  |
| 2        | 1 | [10, 20, 15]        | 10 (idx 1)  | nenhuma     | [5, **10**, 20, 15]  |
| 3        | 2 | [20, 15]            | 15 (idx 3)  | 20 ↔ 15     | [5, 10, **15**, 20]  |

### b) `[4, 1, 3, 2]`

| Iteração | i | Trecho          | Menor      | Troca     | Vetor             |
|----------|---|-----------------|------------|-----------|-------------------|
| 1        | 0 | [4, 1, 3, 2]    | 1 (idx 1)  | 4 ↔ 1     | [**1**, 4, 3, 2]  |
| 2        | 1 | [4, 3, 2]       | 2 (idx 3)  | 4 ↔ 2     | [1, **2**, 3, 4]  |
| 3        | 2 | [3, 4]          | 3 (idx 2)  | nenhuma   | [1, 2, **3**, 4]  |

Ficou ordenado na iteração 2, mas o Selection **não sabe disso** e faz a 3ª mesmo assim.

</details>

---

### Questão 3: Insertion Sort

**a)** `[6, 4, 3, 7, 1]`

**b)** `[8, 2, 9, 5]`

<details>
<summary><b>👀 Resposta da Questão 3</b></summary>

### a) `[6, 4, 3, 7, 1]`

| Iteração | key | Quem anda para a direita | Vetor                  |
|----------|-----|--------------------------|------------------------|
| 1        | 4   | 6                        | [**4, 6**, 3, 7, 1]    |
| 2        | 3   | 6, 4                     | [**3, 4, 6**, 7, 1]    |
| 3        | 7   | ninguém (6 < 7)          | [**3, 4, 6, 7**, 1]    |
| 4        | 1   | 7, 6, 4, 3               | [**1, 3, 4, 6, 7**]    |

### b) `[8, 2, 9, 5]`

| Iteração | key | Quem anda para a direita | Vetor              |
|----------|-----|--------------------------|--------------------|
| 1        | 2   | 8                        | [**2, 8**, 9, 5]   |
| 2        | 9   | ninguém (8 < 9)          | [**2, 8, 9**, 5]   |
| 3        | 5   | 9, 8                     | [**2, 5, 8, 9**]   |

</details>

---

## Parte B: extras no papel

### Questão 4: Mesmo vetor, três algoritmos

Ordene `[29, 10, 14, 37, 13]` com **Bubble**, **Selection** e **Insertion**. Mostre o vetor depois de cada iteração e conte as **trocas** (no Insertion, conte os **deslocamentos**).

<details>
<summary><b>👀 Resposta da Questão 4</b></summary>

### Bubble

| Passada | Vetor no fim                | Trocas |
|---------|-----------------------------|--------|
| 1       | [10, 14, 29, 13, **37**]    | 3      |
| 2       | [10, 14, 13, **29, 37**]    | 1      |
| 3       | [10, 13, **14, 29, 37**]    | 1      |
| 4       | [**10, 13, 14, 29, 37**]    | 0      |

**Total: 5 trocas.**

### Selection

| Iteração | Menor        | Vetor                       | Trocou? |
|----------|--------------|-----------------------------|---------|
| 1        | 10 (idx 1)   | [**10**, 29, 14, 37, 13]    | ✅      |
| 2        | 13 (idx 4)   | [10, **13**, 14, 37, 29]    | ✅      |
| 3        | 14 (idx 2)   | [10, 13, **14**, 37, 29]    | ❌ já no lugar |
| 4        | 29 (idx 4)   | [10, 13, 14, **29**, 37]    | ✅      |

**Total: 3 trocas.**

### Insertion

| Iteração | key | Quem anda       | Vetor                        | Deslocamentos |
|----------|-----|-----------------|------------------------------|---------------|
| 1        | 10  | 29              | [**10, 29**, 14, 37, 13]     | 1             |
| 2        | 14  | 29              | [**10, 14, 29**, 37, 13]     | 1             |
| 3        | 37  | ninguém         | [**10, 14, 29, 37**, 13]     | 0             |
| 4        | 13  | 37, 29, 14      | [**10, 13, 14, 29, 37**]     | 3             |

**Total: 5 deslocamentos.**

> 💡 Bubble (5 trocas) e Insertion (5 deslocamentos) deram o **mesmo número**. Não é coincidência: os dois contam quantos **pares estão fora de ordem** no vetor original (as "inversões"). O Selection fez menos (3), como o slide promete.

</details>

---

### Questão 5: Qual algoritmo cada um usou?

Três alunos ordenaram `[5, 3, 8, 1, 4]` e pararam **depois de 2 iterações**. Os vetores ficaram assim:

```
Aluno A: [3, 5, 8, 1, 4]
Aluno B: [1, 3, 8, 5, 4]
Aluno C: [3, 1, 4, 5, 8]
```

Qual algoritmo (Bubble, Selection ou Insertion) cada aluno usou? Justifique.

<details>
<summary><b>👀 Resposta da Questão 5</b></summary>

| Aluno | Algoritmo     | Pista                                                                                 |
|-------|---------------|---------------------------------------------------------------------------------------|
| **A** | **Insertion** | o começo `3, 5, 8` está ordenado, mas o `1, 4` do fim está **igual ao original**       |
| **B** | **Selection** | `1, 3` no começo são os **2 menores do vetor todo**                                   |
| **C** | **Bubble**    | `5, 8` no fim são os **2 maiores do vetor todo**                                      |

Conferindo:

- **Insertion:** it. 1 (key 3) → `[3, 5, 8, 1, 4]`; it. 2 (key 8, ninguém anda) → `[3, 5, 8, 1, 4]`
- **Selection:** it. 1 (menor 1) → `[1, 3, 8, 5, 4]`; it. 2 (menor 3, já no lugar) → `[1, 3, 8, 5, 4]`
- **Bubble:** passada 1 → `[3, 5, 1, 4, 8]`; passada 2 → `[3, 1, 4, 5, 8]`

</details>

---

### Questão 6: Melhor e pior caso

Usando os **códigos do slide**, preencha quantas **comparações** e **trocas** (deslocamentos no Insertion) cada algoritmo faz em:

**a)** `[1, 2, 3, 4, 5]` (já ordenado)

**b)** `[5, 4, 3, 2, 1]` (invertido)

**c)** Qual conclusão você tira?

<details>
<summary><b>👀 Resposta da Questão 6</b></summary>

### a) Já ordenado

|                    | Bubble | Selection | Insertion |
|--------------------|--------|-----------|-----------|
| **Comparações**    | 10     | 10        | **4**     |
| **Trocas/desloc.** | 0      | 0 reais*  | 0         |

\* o código do slide "troca" cada elemento com ele mesmo 4 vezes.

### b) Invertido

|                    | Bubble | Selection | Insertion |
|--------------------|--------|-----------|-----------|
| **Comparações**    | 10     | 10        | 10        |
| **Trocas/desloc.** | 10     | **2**     | 10        |

Selection no invertido: it. 1 troca 5 ↔ 1 → `[1, 4, 3, 2, 5]`; it. 2 troca 4 ↔ 2 → `[1, 2, 3, 4, 5]`. Pronto, as outras iterações não trocam.

### c)

- **Insertion** é o único que fica rápido (O(n)) num vetor já ordenado.
- **Selection** faz **sempre** as mesmas 10 comparações (n(n-1)/2), mas pouquíssimas trocas.
- **Bubble** do slide compara 10 vezes **mesmo já ordenado**. Com a flag `trocou`, cairia para 4.

</details>

---

### Questão 7: Estabilidade

Vetor com dois 3 diferentes (marcados para dar para seguir): `[3a, 3b, 1]`.

**a)** Ordene com **Selection Sort**. A ordem entre `3a` e `3b` se manteve?

**b)** Ordene com **Insertion Sort**. E agora?

**c)** Por que isso importa na prática?

<details>
<summary><b>👀 Resposta da Questão 7</b></summary>

### a) Selection

| Iteração | Menor      | Troca       | Vetor              |
|----------|------------|-------------|--------------------|
| 1        | 1 (idx 2)  | 3a ↔ 1      | [1, **3b, 3a**]    |
| 2        | 3b (idx 1) | nenhuma (3a < 3b é falso) | [1, 3b, 3a] |

O `3a` foi jogado lá para o fim pela troca da iteração 1. A ordem **inverteu** → Selection **não é estável**.

### b) Insertion

| Iteração | key | Quem anda              | Vetor             |
|----------|-----|------------------------|-------------------|
| 1        | 3b  | ninguém (3a > 3b é falso) | [3a, 3b, 1]    |
| 2        | 1   | 3b, 3a                 | [1, **3a, 3b**]   |

Ordem mantida → Insertion **é estável** (porque usa `>` estrito: igual não anda).

### c)

Exemplo: uma lista de alunos já em ordem **alfabética** que você quer ordenar por **nota**. Com um algoritmo estável, quem empatou na nota continua em ordem alfabética. Com o Selection, os empatados podem embaralhar.

</details>

---

## Parte C: código

Estilo da AV1: **faça todos os tratamentos necessários, não só o caminho feliz.** Os arquivos `.cpp` podem ir em [AV2/c++/](../c++/).

### Questão 8: Bubble Sort otimizado

Modifique o `bubbleSort` do slide para **parar** quando uma passada inteira não fizer nenhuma troca.

<details>
<summary><b>👀 Resposta da Questão 8</b></summary>

```cpp
void bubbleSortOtimizado(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool trocou = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = true;
            }
        }

        if (!trocou)
        {
            break; // passada inteira sem troca: já está ordenado
        }
    }
}
```

Agora o melhor caso (vetor já ordenado) é **uma passada só**: O(n).

</details>

---

### Questão 9: Ordenar struct por nota

```cpp
typedef struct Aluno
{
    char nome[50];
    float nota;
} Aluno;

void ordenarPorNota(Aluno alunos[], int n);
```

Ordene por nota **decrescente** usando **Insertion Sort**. Quem empatar deve continuar na ordem em que estava.

Exemplo: `Ana 7.5, Bia 9.0, Caio 7.5, Davi 10.0` → `Davi 10.0, Bia 9.0, Ana 7.5, Caio 7.5`.

<details>
<summary><b>👀 Resposta da Questão 9</b></summary>

Mesma lógica do slide, mas a `key` é um `Aluno` inteiro e a comparação usa `.nota`. O `<` (em vez de `>`) deixa decrescente, e por ser **estrito** mantém os empates na ordem original (estável).

```cpp
void ordenarPorNota(Aluno alunos[], int n)
{
    if (!alunos || n <= 1)
    {
        return;
    }

    for (int i = 1; i < n; i++)
    {
        Aluno chave = alunos[i];
        int j = i - 1;

        while (j >= 0 && alunos[j].nota < chave.nota) // < para decrescente
        {
            alunos[j + 1] = alunos[j];
            j--;
        }
        alunos[j + 1] = chave;
    }
}
```

</details>

---

### Questão 10: Bubble Sort em lista encadeada

Usando a struct da AV1:

```cpp
typedef struct No
{
    int valor;
    No* proximo_lista;
} No;

void bubbleSortLista(No* inicio_lista);
```

Ordene a lista **trocando os valores** dos nós (não precisa mexer nos ponteiros). Trate lista vazia e lista com 1 elemento.

<details>
<summary><b>👀 Resposta da Questão 10</b></summary>

Na lista não dá para fazer `j < n - i - 1` com índice, então guardamos um ponteiro `fim_ordenado`: tudo dali em diante já "borbulhou".

```cpp
void bubbleSortLista(No* inicio_lista)
{
    if (!inicio_lista || !inicio_lista->proximo_lista)
    {
        return; // lista vazia ou com 1 elemento já está ordenada
    }

    bool trocou = true;
    No* fim_ordenado = nullptr; // a partir daqui já está no lugar certo

    while (trocou)
    {
        trocou = false;
        No* atual = inicio_lista;

        while (atual->proximo_lista != fim_ordenado)
        {
            if (atual->valor > atual->proximo_lista->valor)
            {
                int temp = atual->valor;
                atual->valor = atual->proximo_lista->valor;
                atual->proximo_lista->valor = temp;
                trocou = true;
            }
            atual = atual->proximo_lista;
        }
        fim_ordenado = atual; // o maior "borbulhou" até aqui
    }
}
```

Teste: `4 -> 1 -> 3 -> 2 -> 5` vira `1 -> 2 -> 3 -> 4 -> 5`.

</details>

---

### Questão 11: Selection Sort contando trocas

```cpp
int selectionSortContandoTrocas(int arr[], int n);
```

Ordena e retorna quantas trocas **reais** foram feitas (não troque um elemento com ele mesmo).

Teste: `[5, 4, 3, 2, 1]` → **2**. `[1, 2, 3]` → **0**.

<details>
<summary><b>👀 Resposta da Questão 11</b></summary>

```cpp
int selectionSortContandoTrocas(int arr[], int n)
{
    int trocas = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            trocas++;
        }
    }

    return trocas;
}
```

</details>

---

### Questão 12: Ordem decrescente (rápida)

Qual **única mudança** em cada código do slide faz ele ordenar em ordem **decrescente**?

<details>
<summary><b>👀 Resposta da Questão 12</b></summary>

| Algoritmo     | Antes                        | Depois                       | O que muda                        |
|---------------|------------------------------|------------------------------|-----------------------------------|
| **Bubble**    | `arr[j] > arr[j + 1]`        | `arr[j] < arr[j + 1]`        | o **menor** borbulha para o fim   |
| **Selection** | `arr[j] < arr[min_idx]`      | `arr[j] > arr[min_idx]`      | procura o **maior** (vira `max_idx`) |
| **Insertion** | `arr[j] > key`               | `arr[j] < key`               | empurra os **menores** para a direita |

</details>
