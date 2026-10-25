// QUESTÃO 4 – Busca Sequencial em Vetor de Struct (💻 código + ✏️ papel)
//
// struct Aluno
// {
//     int matricula;
//     string nome;
//     float nota;
// };
//
// Aluno turma[] = {
//     {1023, "Ana",   8.5},
//     {1007, "Bruno", 6.0},
//     {1051, "Carla", 9.2},
//     {1012, "Diego", 7.4},
//     {1038, "Eva",   5.8}
// };
//
// a) Implemente a busca por matrícula, retornando um PONTEIRO para o aluno
//    encontrado (ou nullptr se não existir):
//
//    Aluno* buscarPorMatricula(Aluno turma[], int tamanho, int matricula);
//
// b) Implemente a busca por nome, retornando o ÍNDICE (ou -1):
//
//    int buscarPorNome(Aluno turma[], int tamanho, string nome);
//
// c) No main, leia uma matrícula e mostre nome e nota do aluno, ou
//    "Aluno não encontrado". Depois, faça o mesmo lendo um nome.
//
// Testes:
// buscarPorMatricula(turma, 5, 1051) → Carla, 9.2
// buscarPorMatricula(turma, 5, 1007) → Bruno, 6.0
// buscarPorMatricula(turma, 5, 9999) → nullptr
// buscarPorNome(turma, 5, "Diego")   → 3
// buscarPorNome(turma, 5, "Zeca")    → -1
//
// d) Dá para usar busca binária por matrícula nesse vetor? O que precisaria mudar?
//
// ✏️ Sua resposta:
// d)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_04_Sequencial_Struct.cpp -o AV2/exércicios_buscas/q4.out && ./AV2/exércicios_buscas/q4.out
