// QUESTÃO 2 – Hash Duplo (Double Hashing)
//
// Na sondagem linear e na quadrática, chaves que caem na mesma posição seguem
// EXATAMENTE o mesmo caminho de tentativas (agrupamento secundário).
// No hash duplo, o tamanho do pulo depende da própria chave, usando uma
// segunda função hash:
//
//   h1(chave) = chave % 11
//   h2(chave) = 7 - (chave % 7)                → nunca dá 0 (fica entre 1 e 7)
//   posicao(chave, i) = (h1 + i * h2) % 11,    i = 0, 1, 2, ...
//
// Use TAM_TABELA 11. Insira 14, 25, 36, 47 e 9. Depois faça as buscas.
//
// ex: inserir 25 → h1 = 3, h2 = 7 - 4 = 3 → 3 (ocupada) → 3 + 3 = 6 (livre)
//
// int hash1(int chave);
// int hash2(int chave);
// bool inserir(int tabela[], int chave);                → imprime h1, h2 e cada posição tentada
// int buscar(int tabela[], int chave, int &tentativas); → posição da chave ou -1
//
// Testes:
// Inserir 14 → h1=3, h2=7 → 3 (livre)
// Inserir 25 → h1=3, h2=3 → 3 (ocupada) → 6 (livre)
// Inserir 36 → h1=3, h2=6 → 3 (ocupada) → 9 (livre)
// Inserir 47 → h1=3, h2=2 → 3 (ocupada) → 5 (livre)
// Inserir 9  → h1=9, h2=5 → 9 (ocupada) → 3 (ocupada) → 8 (livre)   (9 + 5 = 14 → 3; 9 + 10 = 19 → 8)
// Tabela → [3] 14 | [5] 47 | [6] 25 | [8] 9 | [9] 36 | resto: -
// Buscar 9  → 9 (36) → 3 (14) → 8 (9)              → achou na posição 8, 3 tentativas
// Buscar 47 → 3 (14) → 5 (47)                      → achou na posição 5, 2 tentativas
// Buscar 58 → h1=3, h2=5 → 3 (14) → 8 (9) → 2 (vazia) → não achou, 3 tentativas
//
// Pergunta: 14, 25, 36 e 47 colidiram TODOS na posição 3. Quantas tentativas
// cada um precisou? Compare com a Questão 1 (quadrática), em que todos seguiam
// o mesmo caminho 4 → 5 → 8 → 2 → 9.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_hash/Questao_02_Hash_Duplo.cpp" -o "AV2/Buscas/exércicios_hash/q2.out" && "./AV2/Buscas/exércicios_hash/q2.out"
