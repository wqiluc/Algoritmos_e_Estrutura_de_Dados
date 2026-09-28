# 🌳 Árvore Binária de Busca no Papel

Guia para a questão da avaliação: **montar a árvore à mão** a partir de uma sequência de valores e **descobrir quais valores são impressos** (e quais **não** são).

---

## 1. O que é um nó

Cada nó é uma "bolinha" com um valor dentro. Ele pode ser **pai** de até **dois filhos**:

- um filho à **esquerda** (sempre **menor** que ele)
- um filho à **direita** (sempre **maior** que ele)

Quando um nó não tem filho de um lado, aquele lado é um **galho vazio**. É nos galhos vazios que os valores novos entram.

---

## 2. Como montar no papel (a regra de ouro)

> **Menor vai para a ESQUERDA, maior vai para a DIREITA.**

Passo a passo para cada valor:

1. O **primeiro valor** da sequência vira a **raiz** (o pai de todos).
2. Para cada valor novo, comece **sempre pela raiz** e compare:
   - novo **menor** que o nó → desça para a **esquerda**
   - novo **maior** que o nó → desça para a **direita**
3. Repita a comparação a cada nó até encontrar um **galho vazio**. É ali que o valor entra, como **folha**.

> ⚠️ **Valor repetido:** leia o enunciado. Normalmente o repetido é **ignorado** (não entra na árvore). Alguns professores mandam colocar o igual à **direita**. Siga o que a questão disser.

### Exemplo completo

Inserir, **nesta ordem**: `50, 30, 70, 20, 40, 60, 80, 35, 65`

| Valor | Caminho percorrido                  | Onde entra               |
|-------|-------------------------------------|--------------------------|
| 50    | árvore vazia                        | **raiz**                 |
| 30    | 30 < 50 → esq                       | esquerda do 50           |
| 70    | 70 > 50 → dir                       | direita do 50            |
| 20    | 20 < 50 → esq, 20 < 30 → esq        | esquerda do 30           |
| 40    | 40 < 50 → esq, 40 > 30 → dir        | direita do 30            |
| 60    | 60 > 50 → dir, 60 < 70 → esq        | esquerda do 70           |
| 80    | 80 > 50 → dir, 80 > 70 → dir        | direita do 70            |
| 35    | 35 < 50 → esq, 35 > 30 → dir, 35 < 40 → esq | esquerda do 40   |
| 65    | 65 > 50 → dir, 65 < 70 → esq, 65 > 60 → dir | direita do 60    |

### Resultado final

```
Nível 1               50
                    /    \
Nível 2           30      70
                 /  \    /  \
Nível 3        20   40  60   80
                   /      \
Nível 4           35       65
```

#### Como desenhar no papel sem se perder

1. **Escreva a raiz no topo, centralizada.** Deixe bastante espaço dos dois lados, porque a árvore cresce para baixo e para os lados.
2. **Cada filho fica uma linha abaixo do pai**, ligado por um traço:
   - traço inclinado para a **esquerda** ( / ) = filho **menor**
   - traço inclinado para a **direita** ( \ ) = filho **maior**
3. **Cada valor novo começa lá em cima, no 50**, e vai descendo. Em cada nó, pergunte: *"sou menor ou maior que você?"*. Siga o traço até encontrar um lugar vazio e escreva o valor ali.
4. **Nunca mude um valor de lugar depois de escrito.** Os valores novos só se penduram embaixo dos que já existem.

Veja a árvore crescendo:

```
Após 50, 30, 70:        Após + 20, 40, 60, 80:        Após + 35, 65:

      50                        50                          50
     /  \                     /    \                      /    \
   30    70                 30      70                  30      70
                           /  \    /  \                /  \    /  \
                         20   40  60   80            20   40  60   80
                                                         /      \
                                                        35       65
```

> 🔎 **Por que o 35 fica embaixo do 40, e não do 20?** Ele desce assim: 35 é menor que 50 (esquerda), maior que 30 (direita), menor que 40 (esquerda). O 35 só é comparado com os nós **no caminho** dele. O 20 nunca entra na conta.
>
> O mesmo vale para o 65: maior que 50 (direita), menor que 70 (esquerda), maior que 60 (direita). Por isso ele fica **à direita do 60**, e não perto do 80.

#### Lendo o desenho

| Termo | Nesta árvore | Significado |
|---|---|---|
| **Raiz** | 50 | O primeiro valor inserido, no topo |
| **Folhas** | 20, 35, 65, 80 | Nós sem nenhum filho |
| **Nós internos** | 50, 30, 70, 40, 60 | Nós com pelo menos um filho |
| **Subárvore esquerda do 50** | 30, 20, 40, 35 | Todos **menores** que 50 |
| **Subárvore direita do 50** | 70, 60, 80, 65 | Todos **maiores** que 50 |
| **Altura** | 4 níveis | O caminho mais longo: 50 → 30 → 40 → 35 (ou 50 → 70 → 60 → 65) |

> ✅ **Teste de sanidade:** escolha qualquer nó. **Tudo** o que está pendurado à esquerda dele tem que ser menor, e **tudo** à direita tem que ser maior. Exemplo: à esquerda do 70 estão 60 e 65, os dois menores que 70. Se algum nó falhar nesse teste, o desenho está errado.

> 💡 **A ordem de inserção muda a árvore.** Os mesmos números em outra ordem geram outro desenho. Se inserir `10, 20, 30, 40` em ordem crescente, a árvore vira uma "lista" torta, toda para a direita.

---

## 3. Percursos: em que ordem os valores são impressos?

Todo percurso faz **as mesmas três coisas** em cada nó: visitar o lado esquerdo, visitar o lado direito e escrever o próprio valor. **O que muda é quando o valor é escrito.**

| Percurso | Regra (em cada nó) | Quando o nó é escrito |
|---|---|---|
| **Pré-ordem** | **Nó** → Esq → Dir | Assim que você **chega** nele |
| **Em ordem** | Esq → **Nó** → Dir | Depois de terminar o lado **esquerdo** |
| **Pós-ordem** | Esq → Dir → **Nó** | Depois de terminar os **dois lados** |

### Método dos blocos

O jeito mais seguro no papel é **agrupar por subárvores**. Todo nó divide a árvore em três partes: **ele mesmo**, o **bloco da esquerda** e o **bloco da direita**. O percurso só diz em que ordem escrever essas três partes, e a mesma regra se repete dentro de cada bloco.

**Em ordem (esquerda → nó → direita)**

```
[ bloco do 30 ]                 50   [ bloco do 70 ]
[ 20  30  [ 35  40 ] ]          50   [ [ 60  65 ]  70  80 ]
```

**Impressão:** `20 30 35 40 50 60 65 70 80`
Numa árvore de busca, esse percurso sai **sempre em ordem crescente**. Serve para conferir o desenho.

**Pré-ordem (nó → esquerda → direita)**

```
50   [ 30  [ 20 ]  [ 40  [ 35 ] ] ]   [ 70  [ 60  [ 65 ] ]  [ 80 ] ]
```

**Impressão:** `50 30 20 40 35 70 60 65 80`
Sempre **começa pela raiz**. É exatamente a ordem em que você "desce" pela árvore.

**Pós-ordem (esquerda → direita → nó)**

```
[ [ 20 ]  [ [ 35 ]  40 ]  30 ]   [ [ [ 65 ]  60 ]  [ 80 ]  70 ]   50
```

**Impressão:** `20 35 40 30 65 60 80 70 50`
Sempre **termina na raiz**, porque a raiz é o último nó a ter os dois lados resolvidos.

### ✏️ Truque do contorno

Passe o lápis **em volta da árvore**, começando pela esquerda da raiz e contornando tudo no sentido anti-horário (descendo pela esquerda e subindo pela direita). Imagine três pontinhos em cada nó:

```
        • 50 •        ← ponto à ESQUERDA do nó  = pré-ordem
           •          ← ponto EMBAIXO do nó     = em ordem
                      ← ponto à DIREITA do nó   = pós-ordem
```

Anote o valor **na hora em que o lápis passa pelo ponto certo**:
- Pré-ordem: quando passa pelo **lado esquerdo** do nó (primeira vez que o vê)
- Em ordem: quando passa **por baixo** do nó
- Pós-ordem: quando passa pelo **lado direito** do nó (última vez que o vê, já subindo)

### Resumo

| Percurso | Ordem de impressão | Primeiro | Último |
|---|---|---|---|
| Em ordem | `20 30 35 40 50 60 65 70 80` | menor valor (20) | maior valor (80) |
| Pré-ordem | `50 30 20 40 35 70 60 65 80` | raiz (50) | 80 |
| Pós-ordem | `20 35 40 30 65 60 80 70 50` | 20 | raiz (50) |

> ✏️ **Dica de prova:** depois de escrever a sequência, **conte os valores**. Tem que ter exatamente 9, um de cada nó, sem repetir e sem faltar. Nesses três percursos **todo mundo é impresso**. O que muda é só a **ordem**.

---

## 4. Quem é impresso e quem NÃO é

Aqui está a pegadinha da prova. Existem **dois motivos** para um valor não aparecer:

1. **Filtro:** o nó é **visitado**, mas só é impresso se passar numa condição (ex.: "só pares").
2. **Poda:** a função **nem desce** por um galho. A subárvore inteira é ignorada e nada dela é impresso, **mesmo que atendesse à condição**.

### Método para resolver no papel

1. Desenhe a árvore (seção 2).
2. Descubra a **ordem** do percurso: pré, em ordem ou pós.
3. Descubra a **condição para imprimir** (filtro).
4. Descubra a **condição para descer** em cada lado (poda).
5. Simule nó a nó, começando pela raiz, e **risque no desenho** os galhos podados.

### Exemplo A: filtro (só pares, em ordem)

Todos os nós são visitados, mas 35 e 65 (ímpares) **não aparecem**.

**Saída:** `20 30 40 50 60 70 80`

### Exemplo B: só as folhas

Só é escrito o nó que **não tem nenhum filho**.

**Saída:** `20 35 65 80` (folhas lidas da esquerda para a direita)

### Exemplo C: busca, que imprime só o caminho

A busca escreve cada nó por onde passa e escolhe **um único lado** para descer. O outro lado inteiro fica de fora.

Buscando o **65**:

| Nó atual | Imprime | Decisão                 |
|----------|---------|-------------------------|
| 50       | 50      | 65 > 50 → direita       |
| 70       | 70      | 65 < 70 → esquerda      |
| 60       | 60      | 65 > 60 → direita       |
| 65       | 65      | igual → achou, para     |

**Saída:** `50 70 60 65`. A subárvore do 30 (20, 40, 35) e o 80 **nunca são visitados**.

Buscando o **45** (que não existe): 50 → esquerda → 30 → direita → 40 → direita → galho vazio.
**Saída:** `50 30 40` e depois "não achou".

### Exemplo D: poda + filtro (o mais difícil)

Regras, com **x = 45**, em ordem:
- Em cada nó, **só desce para a esquerda se o nó for maior que 45**.
- **Só imprime o nó se ele for maior que 45.**
- **Sempre desce para a direita.**

Simulação (o recuo mostra quão fundo você está na árvore):

```
50: 50 > 45? SIM → desce esq
   30: 30 > 45? NÃO → não desce esq (20 PODADO), não imprime
       desce dir
      40: 40 > 45? NÃO → não desce esq (35 PODADO), não imprime
          desce dir → vazio
   volta ao 50 → IMPRIME 50
   desce dir
   70: 70 > 45? SIM → desce esq
      60: 60 > 45? SIM → esq vazio → IMPRIME 60
          desce dir
         65: SIM → esq vazio → IMPRIME 65 → dir vazio
   volta ao 70 → IMPRIME 70
   desce dir
      80: SIM → esq vazio → IMPRIME 80 → dir vazio
```

**Saída:** `50 60 65 70 80`

| Valor | Visitado? | Impresso? | Por quê                                  |
|-------|-----------|-----------|------------------------------------------|
| 50    | ✅        | ✅        | 50 > 45                                  |
| 30    | ✅        | ❌        | 30 ≤ 45 (falhou no filtro)               |
| 20    | ❌        | ❌        | **podado**: 30 não desceu para a esquerda |
| 40    | ✅        | ❌        | 40 ≤ 45                                  |
| 35    | ❌        | ❌        | **podado**: 40 não desceu para a esquerda |
| 60, 65, 70, 80 | ✅ | ✅     | todos > 45                               |

---

## 5. Checklist para a prova ✅

- [ ] Primeiro valor = raiz. Cada novo valor **começa a comparação pela raiz**.
- [ ] Menor → esquerda, maior → direita. Desce até achar um galho vazio.
- [ ] Conferiu o que a questão manda fazer com **valor repetido**?
- [ ] Identificou o percurso: **pré** (nó primeiro), **em ordem** (nó no meio) ou **pós** (nó por último)?
- [ ] Tem condição para imprimir? → **filtro** (visita, mas não imprime).
- [ ] Tem condição para descer? → **poda** (nem visita o galho).
- [ ] Conferiu: em ordem = crescente, pré começa na raiz, pós termina na raiz.
- [ ] Na dúvida, simule com o **recuo** como no Exemplo D.
