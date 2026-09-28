<h1 align="center"> 🪓 Exercício: Remover Nó da Árvore Binária de Busca</h1>

Resolva **no papel** antes de abrir as respostas. Use o guia [Arvore_no_Papel.md](Arvore_no_Papel.md) se travar.

Lembrete dos 3 casos de remoção:

| Caso                 | O que fazer                                                                |
|----------------------|----------------------------------------------------------------------------|
| **Folha**            | só apaga o nó (o pai passa a apontar para `NULL`)                          |
| **1 filho**          | o filho sobe e ocupa o lugar do nó removido                                |
| **2 filhos**         | copia o **sucessor em ordem** (menor da subárvore direita) e remove ele    |

### Como remover no papel

1. **Ache o nó** como numa busca: comece pela raiz, menor → esquerda, maior → direita. Anote o caminho.
2. **Conte os filhos** dele e descubra o caso.
3. Aplique o caso **no desenho**:
   - **Folha:** risque o nó e o traço que liga ele ao pai.
   - **1 filho:** risque o nó e ligue o pai direto no filho (o filho sobe **com tudo que estiver pendurado nele**).
   - **2 filhos:** ache o sucessor com o truque **"1 passo à direita, depois tudo à esquerda"**. Escreva o valor do sucessor **por cima** do nó removido e risque o sucessor lá embaixo (ele sempre é folha ou tem só filho à direita, então cai num dos casos fáceis).
4. **Redesenhe** a árvore limpa e faça o **teste de sanidade**: em ordem tem que sair crescente.

---

## Questão 1

Dada a estrutura:

```c
typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;
```

**a)** Implemente a função abaixo. Ela remove o nó com `valor` da BST e retorna a nova raiz:

```c
No* removerNo(No* raiz_arvore, int valor);
```

Trate os **3 casos** (folha, 1 filho e 2 filhos). Se o valor não existir, a árvore deve continuar igual. Não esqueça do `free()`.

**b)** Insira, **nesta ordem**, numa árvore binária de busca vazia:

```
50, 30, 70, 20, 40, 60, 80, 65
```

Desenhe a árvore e, em seguida, desenhe-a de novo **depois de cada remoção** (uma aplicada após a outra):

1. `remover(20)`
2. `remover(60)`
3. `remover(50)`: quem vira a nova raiz?

**c)** Depois das três remoções, escreva o percurso **em ordem**. Ele precisa sair crescente.

<details>
<summary><b>👀 Resposta da Questão 1</b></summary>

### a) Código

```c
No* menorValor(No* raiz_arvore) {
    while (raiz_arvore->esq != NULL) {
        raiz_arvore = raiz_arvore->esq;
    }
    return raiz_arvore;
}

No* removerNo(No* raiz_arvore, int valor) {
    if (raiz_arvore == NULL) {
        return NULL; // valor não existe na árvore
    }

    if (valor < raiz_arvore->valor) {
        raiz_arvore->esq = removerNo(raiz_arvore->esq, valor);
    } else if (valor > raiz_arvore->valor) {
        raiz_arvore->dir = removerNo(raiz_arvore->dir, valor);
    } else {
        // achou o nó

        // folha ou só filho à direita
        if (raiz_arvore->esq == NULL) {
            No* temp = raiz_arvore->dir;
            free(raiz_arvore);
            return temp;
        }
        // só filho à esquerda
        if (raiz_arvore->dir == NULL) {
            No* temp = raiz_arvore->esq;
            free(raiz_arvore);
            return temp;
        }
        // 2 filhos: copia o sucessor e remove ele da subárvore direita
        No* sucessor = menorValor(raiz_arvore->dir);
        raiz_arvore->valor = sucessor->valor;
        raiz_arvore->dir = removerNo(raiz_arvore->dir, sucessor->valor);
    }
    return raiz_arvore;
}
```

O caso **folha** cai no primeiro `if`: como `esq == NULL` e `dir == NULL`, o nó retorna `NULL` para o pai.

### b) No papel

#### Montando a árvore

| Valor | Caminho percorrido                          | Onde entra       |
|-------|---------------------------------------------|------------------|
| 50    | árvore vazia                                | **raiz**         |
| 30    | 30 < 50 → esq                               | esquerda do 50   |
| 70    | 70 > 50 → dir                               | direita do 50    |
| 20    | 20 < 50 → esq, 20 < 30 → esq                | esquerda do 30   |
| 40    | 40 < 50 → esq, 40 > 30 → dir                | direita do 30    |
| 60    | 60 > 50 → dir, 60 < 70 → esq                | esquerda do 70   |
| 80    | 80 > 50 → dir, 80 > 70 → dir                | direita do 70    |
| 65    | 65 > 50 → dir, 65 < 70 → esq, 65 > 60 → dir | direita do 60    |

```
            50
          /    \
        30      70
       /  \    /  \
     20   40  60   80
                \
                 65
```

---

#### 1. `remover(20)`

| Passo              | No papel                                         |
|--------------------|--------------------------------------------------|
| Achar              | 20 < 50 → esq, 20 < 30 → esq, **achou o 20**     |
| Contar filhos      | esq vazio, dir vazio → **0 filhos**              |
| Caso               | **folha**                                        |
| O que fazer        | risca o 20 e o traço `/` que liga ele ao 30      |

```
Riscando:                        Limpo:

            50                              50
          /    \                          /    \
        30      70                      30      70
       ✗  \    /  \                       \    /  \
     ✗20✗ 40  60   80                     40  60   80
                \                               \
                 65                              65
```

Chamadas da função (o recuo mostra a profundidade):

```
removerNo(50, 20): 20 < 50 → 50->esq = removerNo(30, 20)
   removerNo(30, 20): 20 < 30 → 30->esq = removerNo(20, 20)
      removerNo(20, 20): ACHOU. esq == NULL → temp = dir = NULL
                         free(20), retorna NULL
   30->esq = NULL, retorna 30
50->esq = 30 (não mudou), retorna 50
```

---

#### 2. `remover(60)`

| Passo              | No papel                                         |
|--------------------|--------------------------------------------------|
| Achar              | 60 > 50 → dir, 60 < 70 → esq, **achou o 60**     |
| Contar filhos      | esq vazio, dir = 65 → **1 filho**                |
| Caso               | **1 filho**                                      |
| O que fazer        | risca o 60 e liga o 70 direto no 65              |

```
Riscando:                        Limpo:

            50                              50
          /    \                          /    \
        30      70                      30      70
          \    /  \                       \    /  \
          40 ✗60✗  80                     40  65   80
                \
                 65   ← sobe para o lugar do 60
```

> ⚠️ O 65 ficava à **direita** do 60, mas agora vira filho da **esquerda** do 70. Tudo bem: ele ocupa o **lugar** do 60, e o 60 era filho esquerdo do 70. Confere: 65 < 70 ✅.

```
removerNo(50, 60): 60 > 50 → 50->dir = removerNo(70, 60)
   removerNo(70, 60): 60 < 70 → 70->esq = removerNo(60, 60)
      removerNo(60, 60): ACHOU. esq == NULL → temp = dir = 65
                         free(60), retorna 65
   70->esq = 65, retorna 70
50->dir = 70, retorna 50
```

---

#### 3. `remover(50)`

| Passo              | No papel                                                   |
|--------------------|------------------------------------------------------------|
| Achar              | 50 é a própria raiz, **achou de primeira**                 |
| Contar filhos      | esq = 30, dir = 70 → **2 filhos**                          |
| Caso               | **2 filhos**                                               |
| Achar o sucessor   | 1 passo à direita (**70**), depois tudo à esquerda (**65**), esq do 65 vazio → **sucessor = 65** |
| O que fazer        | escreve 65 por cima do 50 e risca o 65 lá de baixo (lá ele é **folha**) |

```
Passo A: copia o 65 para a raiz        Passo B: risca o 65 de baixo (folha)

            65  ← era 50                          65
          /    \                                /    \
        30      70                            30      70
          \    /  \                             \       \
          40  65   80   ← agora tem 65 duas     40       80
              ↑          vezes; esse sai
```

```
removerNo(50, 50): ACHOU. esq e dir existem → 2 filhos
   sucessor = menorValor(70): 70 → esq 65 → esq NULL → para no 65
   50->valor = 65                         (a raiz agora mostra 65)
   raiz->dir = removerNo(70, 65)
      removerNo(70, 65): 65 < 70 → 70->esq = removerNo(65, 65)
         removerNo(65, 65): ACHOU. esq == NULL → temp = dir = NULL
                            free(65 de baixo), retorna NULL
      70->esq = NULL, retorna 70
   raiz->dir = 70, retorna raiz (valor 65)
```

> 💡 Repare que o `free` **nunca** acontece no nó da raiz. O nó da raiz continua o mesmo na memória, só trocou o **valor**. Quem é liberado é o nó do 65 lá de baixo.

**Árvore final:**

```
            65
          /    \
        30      70
          \       \
          40       80
```

**Nova raiz: 65**

> ✏️ **Dica de prova:** alguns professores usam o **antecessor** (maior da subárvore **esquerda**: 1 passo à esquerda, depois tudo à direita) em vez do sucessor. Aqui seria o **40**, e a raiz viraria 40. As duas respostas são árvores de busca válidas; siga o que a questão (ou o código dado) usar. Neste código é o **sucessor**, então a resposta é **65**.

### c) Em ordem

Método dos blocos (esq → nó → dir):

```
[ 30  [ 40 ] ]   65   [ 70  [ 80 ] ]
```

`30 40 65 70 80` ✅ crescente, confere o desenho. Sobraram 5 valores: começou com 8 e saíram 3 (20, 60 e 50).

</details>
