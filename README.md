# Trabalho 1 AEDSII - Top K Elementos
Primeiro trabalho da disciplina AEDS II - Top K Elementos

<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/mpiress/midpy/issues">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</a> 
</div>

<p> </p>
<p> </p>

<h2>Introdução </h2>

<p>Listar a frequência de dados constantemente recorrentes em um banco de dados é uma prática fundamental para extrair informações valiosas e insights úteis. Ao analisar a frequência com que diferentes conjuntos de dados aparecem, é possível identificar padrões de comportamento, tendências emergentes e até mesmo anomalias que poderiam passar despercebidas em uma análise superficial. Esses padrões podem ser cruciais para entender a dinâmica de um sistema, seja ele um mercado, uma operação de negócios ou até mesmo um ambiente científico.</p>

<p>Além disso, a análise da frequência de dados recorrentes também desempenha um papel crucial na alocação de recursos. Ao identificar quais dados ou eventos têm maior incidência, as organizações podem direcionar seus recursos, como tempo, dinheiro e pessoal, de maneira mais eficiente. Isso evita gastos desnecessários em áreas que não trazem tanto impacto e concentra os recursos onde eles podem ter um efeito mais significativo.</p>

<p>Dito isso, o algoritmo que será implementado "Top K Elementos", tende a simplificar e clarear quais são os dados com maior recorrência em um arquivo de texto, no qual será listado 20 palavras junto com o número de recorrências no texto. </p>

<h2>Interpretação do Problema </h2>

<p>Para desenvolver o algoritmo, foram consideradas as seguintes decisões:</p>

``` Criação da Tabela de Dispersão (Hash): ```

- Tokenização das palavras da coleção de dados de entrada.
- Utilização de uma tabela de hash para contar a frequência de cada token.
- Eficiência na contagem de elementos em O(n) tempo.

``` Criação da Árvore de Prioridades (Heap) de Tamanho k: ```

- Inserção dos primeiros k elementos da tabela de hash em um heap de tamanho k.
- Criação de uma estrutura inicial de itens mais valiosos.

``` Comparação e Atualização: ```

<p>Para cada elemento restante na tabela de hash:</p>

- Comparação da contagem com o menor valor do heap (elemento de menor frequência).
- Se a contagem for maior do que o menor valor do heap, substituição do elemento no heap.
- Manutenção da lista dos k itens de maior valor atualizada.


``` Impressão dos Resultados: ```

- Ao final, a heap conterá os k elementos com maiores valores (frequências).

``` Valor k: ```

- Predefinido como 20 para criar uma hash com apenas 20 elementos.

``` Inicialização do Programa: ```

- Leitura das stopwords e adição em um unordered_set.
- Leitura do arquivo de entrada de forma binária para alocação na memória.

``` Tratamento de Caracteres Especiais: ```

- Uso da codificação UTF-8 para lidar com caracteres especiais.
- Aplicação da função tolower() para eliminar a sensibilidade a maiúsculas/minúsculas.

``` Principais Funções para Heap: ```

- make_heap: Montagem do heap com todos os k elementos.
- push_heap: Adição de novo elemento ao heap, mantendo propriedades.
- pop_heap: Remoção do topo do heap e reorganização.

``` Criação da Hash com unordered_map: ```

- Armazenamento eficiente de pares chave-valor.
- Acesso rápido aos valores baseados nas chaves.

``` Leitura e Construção das Palavras: ```

- Leitura de caractere por caractere para construir palavras.
- Identificação do final de palavra pelo "\n" ou sentenças terminadoras (".", "!", "?").

``` Tratamento de Caracteres não Incluídos nas Palavras: ```

- Exclusão de caracteres como ",", "(", ")", ";", "/", ":", "—", "", "'", entre outros.

``` Verificação de Stopwords:: ```

- Descarte das palavras que são stopwords.
- Inclusão na hash das palavras não stopwords, com frequência como valor associado.

<h2>Implementação </h2>



<h2>Arquivos </h2>

* ``` main.cpp ```: Arquivo e função principal do sistema que recebe tanto o arquivo Funcoes.hpp quanto o arquivo Aux.hpp para execução do programa;
* ``` Funcoes.hpp ```: Arquivo que cria as funções utilizadas;
* ``` Funcoes.cpp ```: Arquivo que implementa as funções criadas em Funcoes.hpp;
* ``` Aux.hpp ```: Arquivo que cria as funções utilizadas;
* ``` Aux.cpp ```: Arquivo que implementa as funções criadas em Funcoes.hpp;;
* ``` in1.data ```: Primeiro arquivo que contém texto para execução do programa;
* ``` in2.data ```: Segundo arquivo que contém texto para execução do programa;
* ``` stopwords.txt ```: Contém as stopwords que serão verificadas pelo algoritmo;
* ``` Makefile ```: Automatiza os processos de compilação do sistema.

<h2>Funções </h2>

* ``` void Welcome(); ```: Exibe a mensagem de entrada do programa; 
* ``` void CriandoLab(); ```: Cria tanto o labirinto quanto o arquivo que irá mostrar o caminho feito pelo garoto;
* ``` void DeletandoLab(); ```: Deleta tanto o labirinto quanto o arquivo que mostra o caminho feito pelo garoto;
* ``` void ObterPosInicial(); ```: Obtém a posição inicial inserida pelo usuário;


