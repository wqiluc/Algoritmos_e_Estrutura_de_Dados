<h1 align="center">🔎 Aula 06: Algoritmos de Busca (Sequencial, Binária e Hash)</h1>

<p align="center">
    <img src="https://img.shields.io/badge/-C%2B%2B-111827?style=for-the-badge&logo=cplusplus&logoColor=00599C" height="28"/>
    <img src="https://img.shields.io/badge/Tema-Busca%20%26%20Hash-6f42c1?style=for-the-badge" alt="Tema"/>
    <img src="https://img.shields.io/badge/Avalia%C3%A7%C3%A3o-AV2-orange?style=for-the-badge" alt="Avaliação"/>
    <img src="https://img.shields.io/badge/Exerc%C3%ADcios-11-brightgreen?style=for-the-badge" alt="Exercícios"/>
</p>

> 🔎 Resumo da **aula 06**: busca **sequencial**, busca **binária** e busca por **espalhamento (hash)**, com os dois tratamentos de colisão do slide (**sondagem linear** e **encadeamento**). No fim, 11 exercícios: 6 **no papel** e 5 de **código**. Resolva antes de abrir as respostas.

📄 **Slides:** [Aula 06 - Algoritmos de Busca](<../pdf/Aula 06 - Algoritmos de Busca - sequencial, binária e por espalhamento (Hash).pdf>)

<h2 align="center">🧭 Sumário</h2>

0. [Padrão dos códigos](#padrao)
1. [Busca Sequencial](#sequencial)
2. [Busca Binária](#binaria)
3. [Sequencial x Binária](#comparacao)
4. [Busca por Espalhamento (Hash)](#hash)
   - [4.1 Hash simples](#hash-simples)
   - [4.2 Sondagem linear](#sondagem)
   - [4.3 Encadeamento](#encadeamento)
   - [4.4 Qual tratamento usar?](#qual-usar)
5. [Resumo comparativo](#resumo)
6. [Exercícios](#exercicios)
   - [Parte A: no papel](#parte-a) (Questões 1 a 6)
   - [Parte B: código](#parte-b) (Questões 7 a 11)

---

<h2 align="center" id="padrao">📐 0. Padrão dos códigos: </h2>

Todos os códigos deste arquivo seguem o padrão da AV1 e consideram este cabeçalho:

```cpp
#include <iostream>
using namespace std;
```

A **lógica** é a mesma do slide. O que muda é só a escrita:

| No slide                                      | Aqui                                          | Por quê                                                                  |
|-----------------------------------------------|-----------------------------------------------|--------------------------------------------------------------------------|
| `int hash(int chave)`                         | `int funcaoHash(int chave)`                   | com `using namespace std;`, `hash` bate com `std::hash` e **não compila** |
| `std::cout` / `printf`                        | `cout << ... << endl`                         | o slide mistura C e C++                                                  |
| `(No*)malloc(sizeof(No))` / `free` / `NULL`   | `new No` / `delete` / `nullptr`               | mesmo padrão C++ da AV1                                                  |
| `struct No *prox`                             | `No* proximo`                                 | nome por extenso                                                         |
| `if` sem chaves, comentário solto depois do `}` | sempre `{ }` em linha própria, comentário na linha que ele explica | leitura                                       |

> ⚠️ **O erro do `hash`:** se você escrever `using namespace std;` e chamar uma função sua de `hash`, o compilador acusa `reference to 'hash' is ambiguous`. O slide não tem esse problema porque usa `std::cout` sem o `using`. Na prova, se você for usar o `using namespace std;`, **troque o nome** da função.

---

<h2 align="center" id="sequencial">🚶 1. Busca Sequencial</h2>

<p align="center">
    <img src="https://img.shields.io/badge/Complexidade-O%28n%29-f97316?style=flat-square" alt="O(n)"/>
    <img src="https://img.shields.io/badge/Precisa_ordenar%3F-N%C3%A3o-22c55e?style=flat-square" alt="Não precisa ordenar"/>
</p>

Olha **elemento por elemento**, do índice 0 até achar a chave.

- Funciona em vetor **desordenado**.
- Retorna o **índice** da chave ou **-1** se não achar.

```cpp
int buscaSequencial(int vetor[], int tamanho_vetor, int valor)
{
    int indice_vetor;
    for (indice_vetor; = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if (vetor[indice_vetor] == valor)
        {
            return indice_vetor; 
            // retorna índice se encontrado
        }
    }
    return -1; 
    // não encontrado
}
```

<details>
<summary><b>▶️ Testando: main do slide</b></summary>

```cpp
int main()
{
    int vetor[] = {4, 8, 15, 16, 23, 42};
    int valor = 15;
    int pos = buscaSequencial(vetor, 6, valor);

    if (pos != -1)
    {
        cout << "Valor " << valor << " encontrado na posição " << pos << endl;
    }

    else
    {
        cout << "Valor não encontrado." << endl;
    }

    return 0;
}
```

**Saída:**

```
Valor 15 encontrado na posição 2
```

</details>

| Caso       | Quando acontece                        | Acessos         |
|------------|----------------------------------------|-----------------|
| **Melhor** | chave na posição 0                     | 1               |
| **Pior**   | chave é a última **ou não existe**     | N               |
| **Médio**  | chave existe, todas com mesma chance   | **(N + 1) / 2** |

<h2 align="center" id="binaria">✂️ 2. Busca Binária: </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Complexidade-O%28log_n%29-22c55e?style=flat-square" alt="O(log n)"/>
    <img src="https://img.shields.io/badge/Precisa_ordenar%3F-Sim-ef4444?style=flat-square" alt="Precisa ordenar"/>
</p>

> ⚠️ **Só funciona em vetor ORDENADO.** Se o vetor estiver bagunçado, ela pode dizer "não encontrado" para um valor que existe (Questão 1c).

Passo a passo:

1. Olha o elemento do **meio**: `meio = (inicio + fim) / 2` (divisão inteira).
2. Se `vetor[meio] == valor` → achou.
3. Se `vetor[meio] < valor` → o valor só pode estar **à direita**: `inicio = meio + 1`.
4. Se `vetor[meio] > valor` → o valor só pode estar **à esquerda**: `fim = meio - 1`.
5. Repete enquanto `inicio <= fim`. Se `inicio` passar de `fim`, **não existe** → -1.

```cpp
int buscaBinaria(int vetor[], int tamanho, int valor)
{
    int inicio = 0; 
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == valor)
        {
            return meio; 
            // valor encontrado
        }

        else if (vetor[meio] < valor)
        {
            inicio = meio + 1; 
            // busca na metade superior (direita)
        }

        else
        {
            fim = meio - 1; 
            // busca na metade inferior (esquerda)
        }
    }

    return -1; // não encontrado
}
```

<details>
<summary><b>▶️ Testando: main do slide</b></summary>

```cpp
int main()
{
    int vetor[] = {3, 6, 9, 12, 15, 18, 21};
    int valor = 15;
    int pos = buscaBinaria(vetor, 7, valor);

    if (pos != -1)
    {
        cout << "Valor " << valor << " encontrado na posição " << pos << endl;
    }

    else
    {
        cout << "Valor não encontrado." << endl;
    }

    return 0;
}
```

**Saída:**

```
Valor 15 encontrado na posição 4
```

</details>

**✏️ No papel:** monte uma tabela com **inicio, fim, meio, vetor[meio]** e a **decisão**. Exemplo do slide: `{3, 6, 9, 12, 15, 18, 21}` buscando **15**.

```
Valor   3   6   9   12   15   18   21
Índice  0   1   2   3    4    5    6
```

| inicio | fim | meio | vetor[meio] | Decisão                    |
|--------|-----|------|-------------|----------------------------|
| 0      | 6   | 3    | 12          | 12 < 15 → `inicio = 4`     |
| 4      | 6   | 5    | 18          | 18 > 15 → `fim = 4`        |
| 4      | 4   | 4    | 15          | **achou!** retorna **4**   |

**3 acessos.** A cada passo o vetor cai **pela metade**.

- Pior caso: **⌊log₂ n⌋ + 1** acessos (ex.: n = 7 → 3 acessos; n = 10 → 4 acessos).

> 💡 O slide escreve a média como "(log n) - 1" e "log 10⁶ ≈ 1 ~ 19". O log ali é na **base 2**: log₂(10⁶) ≈ 20. Ou seja, num vetor de 1 milhão a binária faz **entre 1 e uns 20 acessos**.

<h2 align="center" id="comparacao">⚖️ 3. Sequencial x Binária: </h2>

Vetor com **1 milhão** de itens (10⁶):

| Busca          | Acessos em média               |
|----------------|--------------------------------|
| **Sequencial** | (10⁶ + 1) / 2 ≈ **500.000**    |
| **Binária**    | log₂ 10⁶ ≈ **20**              |

O preço da binária: o vetor **precisa estar ordenado**. Se os dados chegam bagunçados, só a sequencial serve.

<h2 align="center" id="hash">🗂️ 4. Busca por Espalhamento (Hash): </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Caso_ideal-O%281%29-16a34a?style=flat-square" alt="O(1)"/>
    <img src="https://img.shields.io/badge/Muitas_colis%C3%B5es-O%28n%29-ef4444?style=flat-square" alt="O(n)"/>
    <img src="https://img.shields.io/badge/Precisa_ordenar%3F-N%C3%A3o-22c55e?style=flat-square" alt="Não precisa ordenar"/>
</p>

A ideia: uma **função hash** transforma a chave direto num **índice** da tabela.

```cpp
int funcaoHash(int chave)
{
    return chave % TAM; // resto da divisão pelo tamanho da tabela
}
```

- **Inserir:** calcula `funcaoHash(chave)` e guarda naquele índice.
- **Buscar:** calcula o **mesmo** `funcaoHash(chave)` e olha só aquele índice → **O(1)** no caso ideal.

> ⚠️ **Colisão:** duas chaves diferentes caindo no mesmo índice. Com `TAM = 10`: 15, 25 e 35 → todas dão **5**.

> 💡 **Chave negativa:** em C++, `-3 % 10` dá **-3**, e `tabelaHash[-3]` acessa memória fora da tabela. Os códigos do slide só funcionam com chave **≥ 0** (Questão 11).

Duas formas de tratar colisão 💥:

| Forma                              | Tipo        | Onde guarda quem colidiu                   |
|------------------------------------|-------------|--------------------------------------------|
| **Sondagem linear** (espaço vago)  | **interno** | na próxima posição livre da própria tabela |
| **Lista encadeada** (encadeamento) | **externo** | numa lista pendurada em cada posição       |

<h2 align="center" id="hash-simples">🧱 4.1 Hash simples (sem tratar colisão): </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Colis%C3%A3o-Sobrescreve-ef4444?style=flat-square" alt="Sobrescreve"/>
</p>

É o primeiro código do slide. Se der colisão, o `inserir` **sobrescreve** o valor antigo.

```cpp
#define TAM 10

int tabelaHash[TAM]; // o main preenche tudo com -1 (vazio) antes de usar

void inserir(int chave)
{
    int indice = funcaoHash(chave);
    tabelaHash[indice] = chave; // se já tinha alguém aqui, sobrescreve!
}

int buscar(int chave)
{
    int indice = funcaoHash(chave);

    if (tabelaHash[indice] == chave)
    {
        return indice; 
        // encontrado
    }

    return -1; 
    // não encontrado
}
```

O `main` do slide é exatamente a [Questão 3](#q3).

<h2 align="center" id="sondagem">🔁 4.2 Sondagem linear (endereçamento aberto): </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Tratamento-Interno-0ea5e9?style=flat-square" alt="Interno"/>
    <img src="https://img.shields.io/badge/Fica_lenta-acima_de_70%25-f97316?style=flat-square" alt="Acima de 70%"/>
</p>

Se a posição estiver ocupada, tenta a **próxima**: `(indice + i) % TAM`, com i = 0, 1, 2, ... O `% TAM` faz **dar a volta** no fim da tabela (depois do 9 vem o 0).

A tabela usa duas marcas especiais:

| Marca              | Significado                         | Inserir pode usar? | Buscar...              |
|--------------------|-------------------------------------|--------------------|------------------------|
| `VAZIO` (-1)       | nunca teve nada aqui                | ✅                 | **para** aqui (-1)     |
| `REMOVIDO` (-2)    | tinha algo, mas foi removido        | ✅                 | **pula** e continua    |

> ⚠️ **Por que remover marca REMOVIDO e não VAZIO?** Porque a busca **para no primeiro VAZIO**. Se você apagar um elemento do meio de uma "corrente" de colisões colocando VAZIO, quem estava depois dele fica inalcançável (Questão 4d).

```cpp
#define TAM 10
#define VAZIO -1
#define REMOVIDO -2

int tabelaHash[TAM];

void inicializarTabela()
{
    for (int i = 0; i < TAM; i++)
    {
        tabelaHash[i] = VAZIO;
    }
}

int inserir(int chave)
{
    int indice = funcaoHash(chave);

    for (int i = 0; i < TAM; i++)
    {
        int tentativa = (indice + i) % TAM;

        if (tabelaHash[tentativa] == VAZIO || tabelaHash[tentativa] == REMOVIDO)
        {
            tabelaHash[tentativa] = chave;
            return tentativa; 
            // inserido com sucesso
        }
    }

    return -1; 
    // tabela cheia
}

int buscar(int chave)
{
    int indice = funcaoHash(chave);

    for (int i = 0; i < TAM; i++)
    {
        int tentativa = (indice + i) % TAM;

        if (tabelaHash[tentativa] == VAZIO)
        {
            return -1; 
            // posição vazia: a chave nunca foi inserida
        }

        if (tabelaHash[tentativa] == chave)
        {
            return tentativa; 
            // encontrado
        }
    }

    return -1; 
    // percorreu a tabela toda e não achou
}

int remover(int chave)
{
    int pos = buscar(chave);

    if (pos != -1)
    {
        tabelaHash[pos] = REMOVIDO; 
        // marca, não apaga
        return 1; 
        // removido com sucesso
    }

    return 0; 
    // não encontrado
}

void imprimirTabela()
{
    cout << "Tabela Hash:" << endl;

    for (int i = 0; i < TAM; i++)
    {
        cout << i << ": ";

        if (tabelaHash[i] == VAZIO)
        {
            cout << "VAZIO" << endl;
        }

        else if (tabelaHash[i] == REMOVIDO)
        {
            cout << "REMOVIDO" << endl;
        }

        else
        {
            cout << tabelaHash[i] << endl;
        }
    }
}
```

> 🐞 No `imprimirTabela` do slide está `std::cout << ": " << i;`, que imprime `: 0VAZIO`. O certo é `cout << i << ": ";`, como acima.

<details>
<summary><b>▶️ Testando: main do slide</b></summary>

```cpp
int main()
{
    inicializarTabela();

    inserir(15);
    inserir(25);
    inserir(35); // colide com o 15 e o 25
    inserir(7);  // colide com o 35
    inserir(17); // colide com o 35 e o 7

    imprimirTabela();

    int busca = 25;
    int pos = buscar(busca);

    if (pos != -1)
    {
        cout << endl << "Elemento " << busca << " encontrado na posição " << pos << endl;
    }

    else
    {
        cout << endl << "Elemento " << busca << " não encontrado" << endl;
    }

    remover(25);

    cout << endl << "Tabela após remover o valor 25:" << endl;
    imprimirTabela();

    return 0;
}
```

**Saída:**

```
Tabela Hash:
0: VAZIO
1: VAZIO
2: VAZIO
3: VAZIO
4: VAZIO
5: 15
6: 25
7: 35
8: 7
9: 17

Elemento 25 encontrado na posição 6

Tabela após remover o valor 25:
Tabela Hash:
0: VAZIO
1: VAZIO
2: VAZIO
3: VAZIO
4: VAZIO
5: 15
6: REMOVIDO
7: 35
8: 7
9: 17
```

</details>

**✏️ No papel:** exemplo do slide, inserir 15, 25, 35, 7, 17 (`TAM = 10`).

| Chave | funcaoHash = chave % 10 | Tentativas         | Posição final |
|-------|-------------------------|--------------------|---------------|
| 15    | 5                       | 5 ✅               | **5**         |
| 25    | 5                       | 5 ❌ → 6 ✅         | **6**         |
| 35    | 5                       | 5 ❌ → 6 ❌ → 7 ✅   | **7**         |
| 7     | 7                       | 7 ❌ → 8 ✅         | **8**         |
| 17    | 7                       | 7 ❌ → 8 ❌ → 9 ✅   | **9**         |

```
Índice   0  1  2  3  4  5   6   7   8  9
Valor    -  -  -  -  -  15  25  35  7  17
```

> 💡 O 7 nem colidiu com "outro 7": o 35 é que já tinha ocupado a posição 7. Isso é o **agrupamento (clustering)**: os elementos formam um "bloco" e todo mundo que cai perto dele precisa andar mais. O comentário do slide diz que o 17 colide "com 7", mas na verdade ele bate no 35 (posição 7) **e** no 7 (posição 8).

| ✅ Vantagens                                  | ❌ Desvantagens                                       |
|----------------------------------------------|------------------------------------------------------|
| não usa ponteiros (menos memória)            | agrupamento (clustering)                             |
| aproveita bem o espaço da tabela             | fica lenta acima de ~**70%** de ocupação             |
|                                              | remoção precisa de marcação (`REMOVIDO`)             |

---

<h2 align="center" id="encadeamento">🔗 4.3 Encadeamento (lista encadeada): </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Tratamento-Externo-0ea5e9?style=flat-square" alt="Externo"/>
    <img src="https://img.shields.io/badge/Remo%C3%A7%C3%A3o-F%C3%A1cil-22c55e?style=flat-square" alt="Remoção fácil"/>
</p>

Cada posição da tabela é o **início de uma lista**. Quem colide entra na lista daquela posição.

```cpp
#define TAM 10

typedef struct No
{
    int chave;
    No* proximo;
} No;

No* tabelaHash[TAM];

void inicializarTabela()
{
    for (int i = 0; i < TAM; i++)
    {
        tabelaHash[i] = nullptr;
    }
}

void inserir(int chave)
{
    int indice = funcaoHash(chave);

    No* novo = new No;
    novo->chave = chave;
    novo->proximo = tabelaHash[indice]; 
    // aponta para o antigo primeiro
    tabelaHash[indice] = novo;          
    // e vira o novo primeiro
}

No* buscar(int chave)
{
    int indice = funcaoHash(chave);
    No* atual = tabelaHash[indice];

    while (atual)
    {
        if (atual->chave == chave)
        {
            return atual; 
            // encontrado
        }
        atual = atual->proximo;
    }

    return nullptr; 
    // não encontrado
}

void imprimirTabela()
{
    for (int i = 0; i < TAM; i++)
    {
        cout << "[" << i << "]: ";

        No* atual = tabelaHash[i];

        while (atual)
        {
            cout << atual->chave << " -> ";
            atual = atual->proximo;
        }
        cout << "NULL" << endl;
    }
}
```

> ⚠️ A inserção é **no início** da lista: o **último inserido fica na frente**.

<details>
<summary><b>▶️ Testando: main do slide</b></summary>

```cpp
int main()
{
    inicializarTabela();

    inserir(12);
    inserir(22);
    inserir(32);
    inserir(42);
    inserir(15);

    imprimirTabela();

    int chave_busca = 22;
    No* resultado = buscar(chave_busca);

    if (resultado)
    {
        cout << endl << "Elemento " << resultado->chave << " encontrado na tabela hash." << endl;
    }

    else
    {
        cout << endl << "Elemento não encontrado na tabela hash." << endl;
    }

    return 0;
}
```

**Saída:**

```
[0]: NULL
[1]: NULL
[2]: 42 -> 32 -> 22 -> 12 -> NULL
[3]: NULL
[4]: NULL
[5]: 15 -> NULL
[6]: NULL
[7]: NULL
[8]: NULL
[9]: NULL

Elemento 22 encontrado na tabela hash.
```

</details>

**✏️ No papel:** exemplo do slide, inserir 12, 22, 32, 42, 15 (`TAM = 10`). 12, 22, 32 e 42 → todos dão **2**. O 15 → **5**.

```
[0]: NULL
[1]: NULL
[2]: 42 -> 32 -> 22 -> 12 -> NULL
[3]: NULL
[4]: NULL
[5]: 15 -> NULL
...
[9]: NULL
```

`buscar(22)`: vai direto na posição 2 e compara **42, 32, 22** → achou na 3ª comparação.

| ✅ Vantagens                                  | ❌ Desvantagens                                              |
|----------------------------------------------|-------------------------------------------------------------|
| nunca "enche"                                | gasta mais memória (ponteiros)                              |
| aguenta muitas colisões                      | com muitas colisões, a busca cai de O(1) para perto de **O(n)** |
| inserir e remover é simples                  |                                                             |

---

<h2 align="center" id="qual-usar">🤔 4.4 Qual tratamento usar? "Depende!": </h2>

| Cenário                                  | Encadeamento (listas) | Sondagem linear          |
|------------------------------------------|-----------------------|--------------------------|
| Tabela grande com fator de carga alto    | ✅ melhor             | ❌ ruim (clusterização)  |
| Pouca memória                            | ❌ usa mais           | ✅ usa menos             |
| Remoções frequentes                      | ✅ fácil              | ❌ precisa de marcação   |
| Simplicidade de implementação            | ❌ ponteiros          | ✅ mais simples          |
| Tempo de busca estável                   | ✅ mais previsível    | ❌ pode variar muito     |

> **Fator de carga** = elementos ÷ tamanho da tabela. 7 elementos numa tabela de 10 = 70%.

**Resumo do slide:**

- **Encadeamento**: melhor quando a tabela vai ser muito usada (muitas colisões ou muitos elementos) e memória não é problema. No mundo real costuma ser o **mais robusto**.
- **Sondagem linear**: melhor quando precisa **economizar memória**, o fator de carga é baixo/moderado (até ~70%) e a escala é pequena.

<h2 align="center" id="resumo">📊 5. Resumo comparativo das buscas: </h2>

| Algoritmo        | Complexidade | Precisa ordenar? | Vantagem             | Desvantagem                     |
|------------------|--------------|------------------|----------------------|---------------------------------|
| **Sequencial**   | O(n)         | Não              | simplicidade         | lenta com listas grandes        |
| **Binária**      | O(log n)     | **Sim**          | velocidade           | exige dados ordenados           |
| **Hash (ideal)** | O(1)         | Não              | velocidade altíssima | tratamento de colisões          |

---

<h2 align="center" id="exercicios">🏋️ 6. Exercícios: </h2>

Resolva **antes** de abrir as respostas.

| Questão         | Assunto                          | Parte     |
|-----------------|----------------------------------|-----------|
| [1](#q1)        | Busca sequencial                 | ✏️ Papel✅ |
| [2](#q2)        | Busca binária                    | ✏️ Papel✅ |
| [3](#q3)        | Hash simples                     | ✏️ Papel✅ |
| [4](#q4)        | Sondagem linear                  | ✏️ Papel✅ |
| [5](#q5)        | Encadeamento                     | ✏️ Papel✅ |
| [6](#q6)        | Qual busca usar?                 | ✏️ Papel  |
| [7](#q7)        | Última ocorrência                | 💻 Código |
| [8](#q8)        | Busca binária recursiva          | 💻 Código |
| [9](#q9)        | Busca em lista encadeada         | 💻 Código |
| [10](#q10)      | Remover do hash com encadeamento | 💻 Código |
| [11](#q11)      | Sondagem sem chave repetida      | 💻 Código |

<h2 align="center" id="parte-a">✏️ Parte A: no papel</h2>

Monte as tabelas do jeito das seções [2](#binaria) e [4.2](#sondagem): uma linha por passo, com a **decisão** escrita.

<h2 align="center" id="q1">✏️ Questão 1: Busca Sequencial: </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_A-No_papel-0ea5e9?style=flat-square" alt="Parte A"/>
    <img src="https://img.shields.io/badge/Assunto-Busca_sequencial-6f42c1?style=flat-square" alt="Assunto"/>
</p>

```
Valor   30  15  20  55  8   10
Índice  0   1   2   3   4   5
```

**a)** Quantas comparações a busca sequencial faz para achar o **55**? E o **10**? E o **99**?

**b)** Qual o número médio de acessos para chaves que estão no vetor?

**c)** Dá para usar busca binária nesse vetor? Rode a busca binária procurando o **8** e veja o que acontece.

<details>
<summary><b>👀 Resposta da Questão 1</b></summary>

**a)**

| Chave | Onde está    | Comparações                       | Retorno |
|-------|--------------|-----------------------------------|---------|
| 55    | índice 3     | **4** (30, 15, 20, 55)            | 3       |
| 10    | índice 5     | **6** (pior caso: era o último)   | 5       |
| 99    | não existe   | **6** (pior caso: olhou todos)    | -1      |

**b)** (N + 1) / 2 = (6 + 1) / 2 = **3,5 acessos**.

**c)** **Não**, o vetor não está ordenado. Veja o estrago:

| inicio | fim | meio | vetor[meio] | Decisão                  |
|--------|-----|------|-------------|--------------------------|
| 0      | 5   | 2    | 20          | 20 > 8 → `fim = 1`       |
| 0      | 1   | 0    | 30          | 30 > 8 → `fim = -1`      |
| 0      | -1  |      |             | inicio > fim → **-1**    |

Retornou **-1 (não encontrado)**, mas o 8 **está** no índice 4! A binária "jogou fora" a metade da direita achando que só tinha números maiores que 20 lá.

</details>

<h2 align="center" id="q2">✏️ Questão 2: Busca Binária: </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_A-No_papel-0ea5e9?style=flat-square" alt="Parte A"/>
    <img src="https://img.shields.io/badge/Assunto-Busca_bin%C3%A1ria-6f42c1?style=flat-square" alt="Assunto"/>
</p>

```
Valor   2   5   8   12  16  23  38  56  72  91
Índice  0   1   2   3   4   5   6   7   8   9
```

Faça a tabela (inicio, fim, meio, vetor[meio], decisão) para:

**a)** buscar **23**

**b)** buscar **91**

**c)** buscar **7**

**d)** Qual o número **máximo** de acessos para um vetor de 10 elementos?

<details>
<summary><b>👀 Resposta da Questão 2</b></summary>

**a)** buscar 23

| inicio | fim | meio | vetor[meio] | Decisão                  |
|--------|-----|------|-------------|--------------------------|
| 0      | 9   | 4    | 16          | 16 < 23 → `inicio = 5`   |
| 5      | 9   | 7    | 56          | 56 > 23 → `fim = 6`      |
| 5      | 6   | 5    | 23          | **achou! retorna 5**     |

3 acessos.

**b)** buscar 91

| inicio | fim | meio | vetor[meio] | Decisão                  |
|--------|-----|------|-------------|--------------------------|
| 0      | 9   | 4    | 16          | 16 < 91 → `inicio = 5`   |
| 5      | 9   | 7    | 56          | 56 < 91 → `inicio = 8`   |
| 8      | 9   | 8    | 72          | 72 < 91 → `inicio = 9`   |
| 9      | 9   | 9    | 91          | **achou! retorna 9**     |

4 acessos.

**c)** buscar 7

| inicio | fim | meio | vetor[meio] | Decisão                       |
|--------|-----|------|-------------|-------------------------------|
| 0      | 9   | 4    | 16          | 16 > 7 → `fim = 3`            |
| 0      | 3   | 1    | 5           | 5 < 7 → `inicio = 2`          |
| 2      | 3   | 2    | 8           | 8 > 7 → `fim = 1`             |
| 2      | 1   |      |             | inicio > fim → **retorna -1** |

3 acessos. O 7 "deveria" estar entre o 5 e o 8, e é exatamente ali que a busca termina.

**d)** ⌊log₂ 10⌋ + 1 = 3 + 1 = **4 acessos**. O item (b) é um pior caso.

</details>

<h2 align="center" id="q3">✏️ Questão 3: A pegadinha do hash simples: </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_A-No_papel-0ea5e9?style=flat-square" alt="Parte A"/>
    <img src="https://img.shields.io/badge/Assunto-Hash_simples-6f42c1?style=flat-square" alt="Assunto"/>
</p>

Usando o [hash simples](#hash-simples) do slide (sem tratamento de colisão, `TAM = 10`):

```cpp
int main()
{
    for (int i = 0; i < TAM; i++)
    {
        tabelaHash[i] = -1; // -1 = posição vazia
    }

    inserir(15);
    inserir(25);
    inserir(35);

    int valor = 25;
    int pos = buscar(valor);

    if (pos != -1)
    {
        cout << "Valor " << valor << " encontrado na posição hash " << pos << endl;
    }
    else
    {
        cout << "Valor não encontrado na tabela hash." << endl;
    }

    return 0;
}
```

**a)** Desenhe a tabela depois das 3 inserções.

**b)** O que é impresso?

<details>
<summary><b>👀 Resposta da Questão 3</b></summary>

**a)** 15 % 10 = 5, 25 % 10 = 5, 35 % 10 = 5. Todos vão para a **posição 5**, e cada um **sobrescreve** o anterior:

```
inserir(15) → tabelaHash[5] = 15
inserir(25) → tabelaHash[5] = 25   (o 15 sumiu)
inserir(35) → tabelaHash[5] = 35   (o 25 sumiu)

Índice   0   1   2   3   4   5   6   7   8   9
Valor   -1  -1  -1  -1  -1  35  -1  -1  -1  -1
```

**b)** `buscar(25)` olha `tabelaHash[5]`, que vale **35 ≠ 25** → retorna -1.

```
Valor não encontrado na tabela hash.
```

Mesmo o 25 tendo sido inserido. É por isso que **precisa** tratar colisão (sondagem linear ou encadeamento).

</details>

<h2 align="center" id="q4">✏️ Questão 4: Sondagem Linear: </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_A-No_papel-0ea5e9?style=flat-square" alt="Parte A"/>
    <img src="https://img.shields.io/badge/Assunto-Sondagem_linear-6f42c1?style=flat-square" alt="Assunto"/>
</p>

`TAM = 10`, `funcaoHash(k) = k % 10`, sondagem linear. Insira, **nesta ordem**:

```
23, 43, 13, 27, 37, 9, 19
```

**a)** Para cada chave, mostre as tentativas e a posição final. Desenhe a tabela.

**b)** Quantas tentativas para buscar o **13**? E o **29** (que não existe)?

**c)** Remova o **43**. Como fica a posição dele? Busque o **13** de novo: quantas tentativas? Por que ainda acha?

**d)** E se a remoção colocasse **VAZIO** em vez de **REMOVIDO**, o que aconteceria com `buscar(13)`?

**e)** Depois da remoção, insira o **33**. Onde ele entra?

**f)** Qual era o fator de carga antes da remoção?

<details>
<summary><b>👀 Resposta da Questão 4</b></summary>

**a)**

| Chave | funcaoHash | Tentativas                     | Posição final |
|-------|------------|--------------------------------|---------------|
| 23    | 3          | 3 ✅                           | **3**         |
| 43    | 3          | 3 ❌ → 4 ✅                     | **4**         |
| 13    | 3          | 3 ❌ → 4 ❌ → 5 ✅               | **5**         |
| 27    | 7          | 7 ✅                           | **7**         |
| 37    | 7          | 7 ❌ → 8 ✅                     | **8**         |
| 9     | 9          | 9 ✅                           | **9**         |
| 19    | 9          | 9 ❌ → (9+1) % 10 = **0** ✅    | **0**         |

O 19 **deu a volta** na tabela por causa do `% TAM`.

```
Índice   0   1  2  3   4   5   6  7   8   9
Valor    19  -  -  23  43  13  -  27  37  9
```

**b)**

- **13:** 3 (23) → 4 (43) → 5 (13 ✅) → **3 tentativas**.
- **29:** funcaoHash = 9 → 9 (9 ≠ 29) → 0 (19 ≠ 29) → 1 (**VAZIO**, para) → **3 tentativas**, retorna -1.

**c)** A posição 4 vira **REMOVIDO**:

```
Índice   0   1  2  3   4         5   6  7   8   9
Valor    19  -  -  23  REMOVIDO  13  -  27  37  9
```

`buscar(13)`: 3 (23) → 4 (REMOVIDO: **não é VAZIO**, então continua) → 5 (13 ✅). **3 tentativas**, achou.

**d)** `buscar(13)`: 3 (23) → 4 (**VAZIO** → para e retorna -1). **Erro!** O 13 está na posição 5, mas a busca nunca chega lá. É exatamente por isso que existe a marca REMOVIDO.

**e)** 33 % 10 = 3 → 3 ocupado (23) → 4 é **REMOVIDO** → `inserir` aceita REMOVIDO → o 33 entra na **posição 4**.

**f)** 7 elementos / 10 posições = **70%**, o limite citado no slide. A partir daí a sondagem linear começa a ficar lenta (repare quantas chaves já precisaram de mais de 1 tentativa).

</details>

<h2 align="center" id="q5">✏️ Questão 5: Encadeamento: </h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_A-No_papel-0ea5e9?style=flat-square" alt="Parte A"/>
    <img src="https://img.shields.io/badge/Assunto-Encadeamento-6f42c1?style=flat-square" alt="Assunto"/>
</p>

`TAM = 7`, `funcaoHash(k) = k % 7`, encadeamento com **inserção no início** (igual ao slide). Insira, nesta ordem:

```
15, 8, 22, 4, 11, 30, 7
```

**a)** Desenhe a tabela com as listas.

**b)** Quantas comparações para buscar o **15**? E o **18**?

**c)** Qual a pior situação possível para essa tabela?

<details>
<summary><b>👀 Resposta da Questão 5</b></summary>

**a)**

| Chave | chave % 7 |
|-------|-----------|
| 15    | 1         |
| 8     | 1         |
| 22    | 1         |
| 4     | 4         |
| 11    | 4         |
| 30    | 2         |
| 7     | 0         |

Lembrando que quem chega depois entra **na frente**:

```
[0]: 7 -> NULL
[1]: 22 -> 8 -> 15 -> NULL
[2]: 30 -> NULL
[3]: NULL
[4]: 11 -> 4 -> NULL
[5]: NULL
[6]: NULL
```

**b)**

- **15:** posição 1 → compara 22, 8, 15 → **3 comparações** (foi o primeiro a entrar, então ficou no fim da lista).
- **18:** 18 % 7 = 4 → compara 11, 4 → chega no NULL → **2 comparações**, não encontrado.

**c)** Todas as chaves caírem na **mesma posição** (ex.: 0, 7, 14, 21, 28...). A tabela vira uma lista encadeada comum e a busca vira **O(n)**.

</details>

<h2 align="center" id="q6">✏️ Questão 6: Qual busca usar?</h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_A-No_papel-0ea5e9?style=flat-square" alt="Parte A"/>
    <img src="https://img.shields.io/badge/Assunto-Escolha_da_busca-6f42c1?style=flat-square" alt="Assunto"/>
</p>

Para cada cenário, diga se usaria **sequencial**, **binária**, **hash com sondagem linear** ou **hash com encadeamento**, e por quê.

**a)** Vetor pequeno (20 itens), desordenado, que vai ser consultado uma única vez.

**b)** Lista telefônica com 1 milhão de nomes já em ordem alfabética.

**c)** Sistema embarcado com pouquíssima memória e poucos elementos (tabela até uns 50% cheia).

**d)** Cadastro com muitas inserções e remoções que pode crescer bastante.

<details>
<summary><b>👀 Resposta da Questão 6</b></summary>

| Cenário | Escolha             | Por quê                                                                                                   |
|---------|---------------------|-----------------------------------------------------------------------------------------------------------|
| **a)**  | **Sequencial**      | A binária exigiria deixar o vetor em ordem antes, e isso dá mais trabalho do que olhar 20 itens uma vez.  |
| **b)**  | **Binária**         | Já está ordenado: no máximo ~20 acessos contra ~500.000 da sequencial.                                    |
| **c)**  | **Sondagem linear** | Não usa ponteiros (menos memória) e, com fator de carga baixo, quase não sofre com agrupamento.            |
| **d)**  | **Encadeamento**    | Nunca "enche", remover é só religar um ponteiro, e o tempo de busca é mais estável.                       |

</details>

---

<h2 align="center" id="parte-b">💻 Parte B: código</h2>

Estilo da AV1: **faça todos os tratamentos necessários, não só o caminho feliz.** Cada questão traz a **assinatura**, o que **tratar** e uma tabela de **teste** com o retorno esperado. Use o [padrão dos códigos](#padrao).

---

<h2 align="center" id="q7">💻 Questão 7: Última ocorrência</h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_B-C%C3%B3digo-f97316?style=flat-square" alt="Parte B"/>
    <img src="https://img.shields.io/badge/Assunto-Busca_sequencial-6f42c1?style=flat-square" alt="Assunto"/>
</p>

```cpp
int buscaUltimaOcorrencia(int vetor[], int tamanho, int valor);
```

Retorna o índice da **última** vez que `valor` aparece, ou `-1`.

**Trate:** vetor nulo · `tamanho <= 0` · valor que não existe.

**Teste** com `int vetor[] = {4, 8, 15, 8, 23};`

| Chamada                                   | Retorno |
|-------------------------------------------|---------|
| `buscaUltimaOcorrencia(vetor, 5, 8)`      | `3`     |
| `buscaUltimaOcorrencia(vetor, 5, 4)`      | `0`     |
| `buscaUltimaOcorrencia(vetor, 5, 99)`     | `-1`    |
| `buscaUltimaOcorrencia(nullptr, 5, 8)`    | `-1`    |
| `buscaUltimaOcorrencia(vetor, 0, 8)`      | `-1`    |

<details>
<summary><b>👀 Resposta da Questão 7</b></summary>

Basta percorrer **de trás para frente**: a primeira que achar é a última.

```cpp
int buscaUltimaOcorrencia(int vetor[], int tamanho, int valor)
{
    if (!vetor || tamanho <= 0)
    {
        return -1; // vetor inválido
    }

    for (int i = tamanho - 1; i >= 0; i--)
    {
        if (vetor[i] == valor)
        {
            return i; // a primeira de trás para frente é a última
        }
    }

    return -1; // não encontrado
}
```

</details>

---

<h2 align="center" id="q8">💻 Questão 8: Busca binária recursiva</h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_B-C%C3%B3digo-f97316?style=flat-square" alt="Parte B"/>
    <img src="https://img.shields.io/badge/Assunto-Busca_bin%C3%A1ria_%2B_recurs%C3%A3o-6f42c1?style=flat-square" alt="Assunto"/>
</p>

```cpp
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor);
```

Mesma lógica da [busca binária](#binaria), mas sem `while`: cada chamada cuida de um trecho `[inicio, fim]`. Chamada inicial: `buscaBinariaRecursiva(vetor, 0, tamanho - 1, valor)`. Qual é o **caso base**?

**Trate:** vetor nulo · trecho vazio (`inicio > fim`).

**Teste** com `int vetor[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};` (o mesmo da Questão 2)

| Chamada                                    | Retorno |
|--------------------------------------------|---------|
| `buscaBinariaRecursiva(vetor, 0, 9, 23)`   | `5`     |
| `buscaBinariaRecursiva(vetor, 0, 9, 2)`    | `0`     |
| `buscaBinariaRecursiva(vetor, 0, 9, 91)`   | `9`     |
| `buscaBinariaRecursiva(vetor, 0, 9, 7)`    | `-1`    |
| `buscaBinariaRecursiva(nullptr, 0, 9, 23)` | `-1`    |

<details>
<summary><b>👀 Resposta da Questão 8</b></summary>

Dois casos base: **trecho vazio** (`inicio > fim`, não achou) e **achou no meio**.

```cpp
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor)
{
    if (!vetor || inicio > fim)
    {
        return -1; // caso base 1: vetor inválido ou trecho vazio
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == valor)
    {
        return meio; // caso base 2: achou no meio
    }

    if (vetor[meio] < valor)
    {
        return buscaBinariaRecursiva(vetor, meio + 1, fim, valor); // metade da direita
    }

    return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor); // metade da esquerda
}
```

Pilha de chamadas buscando **23** (compare com a tabela da Questão 2a):

```
buscaBinariaRecursiva(vetor, 0, 9, 23)   meio = 4 → 16 < 23 → direita
└── buscaBinariaRecursiva(vetor, 5, 9, 23)   meio = 7 → 56 > 23 → esquerda
    └── buscaBinariaRecursiva(vetor, 5, 6, 23)   meio = 5 → 23 == 23 → retorna 5
```

O 5 "sobe" pelas chamadas sem mudar, porque cada uma faz `return` direto do resultado da outra.

</details>

---

<h2 align="center" id="q9">💻 Questão 9: Busca sequencial em lista encadeada</h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_B-C%C3%B3digo-f97316?style=flat-square" alt="Parte B"/>
    <img src="https://img.shields.io/badge/Assunto-Lista_encadeada-6f42c1?style=flat-square" alt="Assunto"/>
</p>

Usando a struct da AV1:

```cpp
typedef struct No
{
    int valor;
    No* proximo_lista;
} No;

No* buscarNaLista(No* inicio_lista, int valor);
```

Retorna o **nó** que contém `valor`, ou `nullptr`.

**Trate:** lista vazia (`inicio_lista == nullptr`) · valor que não existe.

**Teste** com a lista `5 -> 8 -> 12 -> NULL`:

| Chamada                        | Retorno                  |
|--------------------------------|--------------------------|
| `buscarNaLista(inicio, 8)`     | o nó com `valor == 8`    |
| `buscarNaLista(inicio, 99)`    | `nullptr`                |
| `buscarNaLista(nullptr, 8)`    | `nullptr`                |

**Pergunta extra:** dá para fazer busca **binária** numa lista encadeada ordenada?

<details>
<summary><b>👀 Resposta da Questão 9</b></summary>

```cpp
No* buscarNaLista(No* inicio_lista, int valor)
{
    No* atual = inicio_lista;

    while (atual)
    {
        if (atual->valor == valor)
        {
            return atual; // encontrado
        }
        atual = atual->proximo_lista;
    }

    return nullptr; // não encontrado (ou lista vazia)
}
```

A lista vazia já é tratada: com `inicio_lista == nullptr`, o `while` nem entra e retorna `nullptr`.

**Pergunta extra:** não de forma eficiente. Lista **não tem acesso direto** ao meio (`vetor[meio]`); para chegar no meio você precisa andar nó por nó, e aí perde toda a vantagem do O(log n).

</details>

---

<h2 align="center" id="q10">💻 Questão 10: Remover do hash com encadeamento</h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_B-C%C3%B3digo-f97316?style=flat-square" alt="Parte B"/>
    <img src="https://img.shields.io/badge/Assunto-Encadeamento-6f42c1?style=flat-square" alt="Assunto"/>
</p>

O slide **não tem** remoção para a versão com [encadeamento](#encadeamento). Implemente:

```cpp
int remover(int chave); // 1 se removeu, 0 se não achou
```

**Trate:** posição vazia · nó é o **primeiro** da lista · nó no **meio/fim** · chave que não existe. Não esqueça do `delete`.

**Teste:** insira 12, 22, 32, 42 (`[2]: 42 -> 32 -> 22 -> 12 -> NULL`) e remova, nesta ordem:

| Chamada        | Situação                                    | Retorno | Lista na posição 2 depois      |
|----------------|---------------------------------------------|---------|--------------------------------|
| `remover(22)`  | nó do meio                                  | `1`     | `42 -> 32 -> 12 -> NULL`       |
| `remover(42)`  | primeiro da lista                           | `1`     | `32 -> 12 -> NULL`             |
| `remover(12)`  | último da lista                             | `1`     | `32 -> NULL`                   |
| `remover(99)`  | posição 9 está vazia                        | `0`     | `32 -> NULL`                   |
| `remover(52)`  | posição 2 tem lista, mas o 52 não está nela | `0`     | `32 -> NULL`                   |

<details>
<summary><b>👀 Resposta da Questão 10</b></summary>

Mesmo esquema de remoção em lista da AV1: anda com `atual` e `anterior`.

```cpp
int remover(int chave)
{
    int indice = funcaoHash(chave);
    No* atual = tabelaHash[indice];
    No* anterior = nullptr;

    while (atual && atual->chave != chave)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!atual)
    {
        return 0; // não achou (posição vazia ou chave fora da lista)
    }

    if (!anterior)
    {
        tabelaHash[indice] = atual->proximo; // era o primeiro da lista
    }
    else
    {
        anterior->proximo = atual->proximo; // pula o nó removido
    }

    delete atual;
    return 1; // removido com sucesso
}
```

Repare que aqui **não precisa** de marca REMOVIDO: a lista é religada e o nó some de verdade. Essa é a vantagem do encadeamento na tabela do slide ("remoções frequentes: fácil").

</details>

---

<h2 align="center" id="q11">💻 Questão 11: Sondagem linear sem chave repetida</h2>

<p align="center">
    <img src="https://img.shields.io/badge/Parte_B-C%C3%B3digo-f97316?style=flat-square" alt="Parte B"/>
    <img src="https://img.shields.io/badge/Assunto-Sondagem_linear-6f42c1?style=flat-square" alt="Assunto"/>
</p>

O `inserir` da [sondagem linear](#sondagem) aceita a **mesma chave duas vezes** (inserir 15 duas vezes → posições 5 e 6). Crie uma versão que **não insere repetida**:

```cpp
int inserirSemRepetir(int chave); // posição onde inseriu, ou -1
```

**Trate:** chave repetida · chave negativa · tabela cheia.

**Dica:** por que chave negativa é problema aqui? (São dois motivos.)

**Teste** a partir da tabela vazia, nesta ordem:

| Chamada                                  | Retorno | Por quê                                    |
|------------------------------------------|---------|--------------------------------------------|
| `inserirSemRepetir(15)`                  | `5`     | 15 % 10 = 5, posição livre                 |
| `inserirSemRepetir(15)`                  | `-1`    | já existe                                  |
| `inserirSemRepetir(25)`                  | `6`     | colide no 5, vai para o 6                  |
| `inserirSemRepetir(-5)`                  | `-1`    | chave negativa                             |
| `remover(15)` e `inserirSemRepetir(15)`  | `5`     | o 5 virou REMOVIDO, então pode ser reusado |

<details>
<summary><b>👀 Resposta da Questão 11</b></summary>

Usa o próprio `buscar` antes e, se não existir, reaproveita o `inserir` do slide.

```cpp
int inserirSemRepetir(int chave)
{
    if (chave < 0)
    {
        return -1; // chave negativa não é aceita
    }

    if (buscar(chave) != -1)
    {
        return -1; // já existe: não insere de novo
    }

    return inserir(chave); // -1 se a tabela estiver cheia
}
```

Os dois motivos para recusar chave negativa:

1. **-1 e -2 já significam VAZIO e REMOVIDO.** Inserir o -1 faria a posição parecer vazia.
2. **`%` com número negativo dá resultado negativo** em C++ (`-5 % 10 = -5`), e `tabelaHash[-5]` acessa fora da tabela.

</details>