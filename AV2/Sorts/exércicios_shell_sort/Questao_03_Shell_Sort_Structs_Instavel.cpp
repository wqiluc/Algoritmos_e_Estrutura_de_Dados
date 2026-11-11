// QUESTÃO 3 – Shell Sort: Vetor de Structs (e a instabilidade)
//
// Ordene a lista de alunos por nota em ordem DECRESCENTE usando Shell Sort
// (gaps n/2, ..., 1). A lista está na ordem de chegada (que também é a
// ordem alfabética).
//
// struct Aluno
// {
//     string nome;
//     int nota;
// };
//
// Índice  0     1      2      3      4      5      6     7
// Nome    Ana   Bruno  Carla  Diego  Elisa  Fabio  Gabi  Hugo
// Nota    7     9      7      6      9      8      7     6
//
// void shellSortAlunos(Aluno alunos[], int tamanho_vetor);
// → compara pelo campo nota (decrescente: a maior nota vai para a frente)
// → só desloca quando a nota de trás for MENOR (empate não desloca)
// → imprime a lista depois de cada gap no formato Nome(nota)
//
// Testes:
// Após gap 4 → Elisa(9) Bruno(9) Carla(7) Diego(6) Ana(7) Fabio(8) Gabi(7) Hugo(6)
// Após gap 2 → Elisa(9) Bruno(9) Carla(7) Fabio(8) Ana(7) Diego(6) Gabi(7) Hugo(6)
// Após gap 1 → Elisa(9) Bruno(9) Fabio(8) Carla(7) Ana(7) Gabi(7) Diego(6) Hugo(6)
//
// Perguntas:
// 1) Bruno chegou antes de Elisa, e os dois têm nota 9. Quem ficou na frente?
//    E entre Ana e Carla (nota 7)?
// 2) Um algoritmo é ESTÁVEL quando elementos com a mesma chave mantêm a ordem
//    original. O Shell Sort é estável? Em que gap a ordem foi "quebrada"?
// 3) Guarde esse resultado: na Questão 1 do Merge Sort você vai ordenar os
//    mesmos alunos e comparar.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_shell_sort/Questao_03_Shell_Sort_Structs_Instavel.cpp" -o "AV2/Sorts/exércicios_shell_sort/q3.out" && "./AV2/Sorts/exércicios_shell_sort/q3.out"
