# Linguagem-C-lab09
Nono laboratório da disciplina Estrutura de Dados da Universidade Estadual de Campinas

[Heap de mínimo]

Em várias aplicações de uma fila de prioridades as operações essenciais são inserir uma chave, remover a chave mínima e reduzir o valor de uma chave.
Uma dessas aplicações é no algoritmo de Dijkstra, que encontra caminhos de custo mínimo em um grafo. O algoritmo usa uma fila de prioridades que armazena pares {índice-do-vértice, custo} e a cada passo remove da fila de prioridades um vértice com custo mínimo e reduz o custo de alguns nós adjacentes ao que saiu da fila de prioridades.

O heap é uma boa estrutura de dados para implementar uma fila de prioridades: as operações de inserção e remoção de mínimo levam tempo O(log n) cada e a estrutura usa pouca memória (n é o número de chaves no heap).

Para reduzir o valor de uma chave em tempo O(log n) é necessário aumentar o heap com um índice I. Uma possibilidade é usar um vetor como índice. Outra possibilidade é usar uma tabela de hashing, especialmente quando as chaves não formam um intervalo dos inteiros.

Todas as operações no heap (inserção, remoção de mínimo e redução de chave) devem atualizar I adequadamente sempre que H for atualizado. Usando um vetor como índice, as atualizações podem ser feitas sem modificar o custo assintótico das operações. Com uma tabela de hashing como índice, as atualizações podem ser feitas sem modificar o custo assintótico esperado das operações.

Neste trabalho deve-se implementar um heap de mínimo indexado com capacidade para n pares {chaves,custo}, inicialmente vazio. As chaves são números no intervalo [0,n) e os custos são inteiros. O heap deve ser minimo no custo. A representação do heap deve ser seqüencial e a indexação deve ser feita com um vetor.

[E/S]

A primeira linha da entrada contém o número n. O programa deve começar com um heap com capacidade para até n pares, inicialmente vazio. Em seguida o programa deve processar comandos para atualizar o heap indexado. Cada comando aparece em uma linha e são:

i chave custo

Inserir o par {chave,custo} no heap indexado. Se chave já existir, essa operação não deve fazer nada.

m

Remover o mínimo do heap indexado e imprimir os dados em uma linha. Se o heap já estiver vazio então o programa deve imprimir 'heap vazio'. Veja o exemplo abaixo.

d chave custo'

Diminuir o valor do custo de chave para custo'.

t

Terminar o programa. Antes de terminar, toda memória alocada dinamicamente deve ser liberada.
