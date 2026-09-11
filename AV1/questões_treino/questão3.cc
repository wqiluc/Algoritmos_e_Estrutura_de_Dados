// QUESTÃO 3 (2.0 pontos)
// Um mercado organiza o estoque em uma Árvore Binária de Busca (ABB), na
// qual cada nó guarda o código de barras de um produto.
//
// a) Construa a ABB inserindo, nesta ordem, os códigos:
//    500, 300, 800, 200, 400, 700, 900
//
// b) Implemente `buscarProduto`, que informa (true/false) se um
//    determinado código existe no estoque.
//
// c) Implemente `listarEmOrdemCrescente` (percurso em-ordem), que imprime
//    os códigos do menor para o maior — útil para gerar um relatório de
//    inventário.
//
// d) O produto de código 300 saiu de linha. Implemente a remoção desse
//    nó da ABB, tratando os três casos possíveis (nó folha, nó com um
//    filho, nó com dois filhos).
