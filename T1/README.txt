Nicholas Barbosa - 95667

Os testes foram realizando em um notebook com Linux 19.10, processador i7

Os resultados abaixo foram uma média dos 5 testes feitos para cada tamanho da matriz.

É importante ressaltar que o computador faz operações em segundo plano, enquanto executamos o código, por isso é necessário fazer mais de um teste para a média dar um resultado mais claro.

10x10:
tempo para criar a matriz: tradicional é 2 vezes mais lento
tempo para inicializar a matriz: tradicional é 3 vezes mais lento
tempo para somar a matriz: tradicional é 3 vezes mais lento
tempo para dobrar o numero de linhas da matriz: tradicional é 2 vezes mais rapida
tempo para deletar a matriz: a tradicional é 3 vezes mais lenta

10x1000:
tempo para criar a matriz: tradicional é 2 vezes mais lento
tempo para inicializar a matriz: tradicional é 2 vezes mais lento
tempo para somar a matriz: tradicional é 2 vezes mais lento
tempo para dobrar o numero de linhas da matriz: tradicional é duas vezes mais rápido
tempo para deletar a matriz: a tradicional é 3 vezes mais lenta

10x10000:
tempo para criar a matriz: tradicional é 2 vezes mais lento
tempo para inicializar a matriz: desempenho semelhante
tempo para somar a matriz: desempenho semelhante
tempo para dobrar o numero de linhas da matriz: tradicional é 2 vezes mais rápido
tempo para deletar a matriz: a tradicional é 2 vezes mais lenta

100x10:
tempo para criar a matriz: tradicional é 2 vezes mais lento
tempo para inicializar a matriz: tradicional é 2 vezes mais lento
tempo para somar a matriz: tradicional é 4 vezes mais lento
tempo para dobrar o numero de linhas da matriz: tradicional é duas vezes mais rápido
tempo para deletar a matriz: a tradicional eh 3 vezes mais lenta

1000x10:
tempo para criar a matriz: tradicional é2 vezes mais lento
tempo para inicializar a matriz: tradicional é 2 vezes mais lento
tempo para somar a matriz: tradicional é 2 vezes mais lento
tempo para dobrar o numero de linhas da matriz: tradicional é duas vezes mais rápido
tempo para deletar a matriz: a tradicional eh 5 vezes mais lenta

10000x10:
tempo para criar a matriz: tradicional é 6 vezes mais lento
tempo para inicializar a matriz: tradicional é 2 vezes mais lento
tempo para somar a matriz: mostram desempenho similar	
tempo para dobrar o numero de linhas da matriz: tradicional é duas vezes mais rápido
tempo para deletar a matriz: a tradicional eh 20 vezes mais lenta

100x100
tempo para criar a matriz: tradicional é 2 vezes mais lento
tempo para inicializar a matriz: tradicional é 2 vezes mais lento
tempo para somar a matriz: tradicional eh 2 vezes mais lento
tempo para dobrar o numero de linhas da matriz: tradicional é 2 vezes mais rapida
tempo para deletar a matriz: a tradicional eh 3 vezes mais lenta

1000x1000
tempo para criar a matriz: tradicional é 3 vezes mais lento
tempo para inicializar a matriz: desempenho semelhante
tempo para somar a matriz: desempenho semelhante
tempo para dobrar o numero de linhas da matriz: tradicional é 20 vezes mais rapida
tempo para deletar a matriz: a tradicional é 3 vezes mais lenta

Conlusões:
Em geral, utilizar a matriz tradicional é mais custoso. Porém, em funções que a estrutura da matriz é modificada, como alterar o numero de linha, a forma tradicional é mais rápida, mas criar e deletar matriz na forma tradicional ainda é mais custoso, em relação à matriz na forma ragged, então se for usar apenas matrizes pequenas, o tipo ragged ainda se mostra mais vantajoso.
Matrizes no formato tradicional com muitas linhas mostram um desempenho ainda menor, principalmente se tiver poucos elementos por linha.

A complexidade para deletar a matriz no formato ragged é constante e no modo tradicional é O(R). A complexidade para criar matrizes no formato ragged e tradicional é O(R), mas é visível que, quanto maior for a matriz, a forma tradicional terá um desmepenho inferior à ragged. Isso acontece, pois a função que descreve o tempo para criar uma matriz tradicional é f(T) = 2R, por isso gasta mais tempo. Porém, sabemos que 2R pertence à O(R).

O desempenho para a somar os elementos da matriz no formato ragged é inferior em relação à tradicional, mesmo que a função get seja O(1) para ambos os formatos. Isso acontece, pois para retornar um elemento no formato ragged existe uma operação de soma a mais que no formato tradicional. Embora a diferença seja pequena, é visível a diferença no tempo, pois as matrizes testes foram matrizes grandes.

Fontes: Vídeo aulas sobre MyVec.
