// QUESTÃO 1 – Merge Sort: Vetor de Structs (e a estabilidade)
//
// Ordene os MESMOS alunos da Questão 3 do Shell Sort por nota em ordem
// DECRESCENTE, agora com Merge Sort recursivo.
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
// void intercalar(Aluno alunos[], int esquerda, int meio, int direita);
// void mergeSort(Aluno alunos[], int esquerda, int direita);
// → no intercalar, em caso de EMPATE, pegue o aluno da metade da ESQUERDA
//   (é isso que garante a estabilidade: use >= na comparação das notas)
// → imprima a lista ordenada no formato Nome(nota)
//
// Testes:
// Merge Sort → Bruno(9) Elisa(9) Fabio(8) Ana(7) Carla(7) Gabi(7) Diego(6) Hugo(6)
// Shell Sort → Elisa(9) Bruno(9) Fabio(8) Carla(7) Ana(7) Gabi(7) Diego(6) Hugo(6)  (Questão 3 do Shell)
//
// Perguntas:
// 1) Por que aqui Bruno ficou na frente de Elisa, e Ana na frente de Carla?
// 2) Troque o >= por > no intercalar. O resultado continua estável? Por quê?
// 3) Quando a estabilidade importa? (Pense: a lista estava em ordem alfabética
//    e você ordenou por nota. Como ficaram os empatados em cada algoritmo?)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_merge_sort/Questao_01_Merge_Sort_Structs_Estavel.cpp" -o "AV2/Sorts/exércicios_merge_sort/q1.out" && "./AV2/Sorts/exércicios_merge_sort/q1.out"

