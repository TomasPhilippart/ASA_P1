# ASA_P1

# Descrição do Problema
O Professor João Caracol tem um fascínio por dominós e passa tardes a fazer longas sequências de dominós. Depois chama os vizinhos para todos observarem os dominós a cairem em
sequência quando o professor deita alguns dos dominós abaixo.
Como passatempo decidiu desenvolver um algoritmo para conseguir determinar qual o número mínimo de dominós que tem de deitar abaixo com a mão, de forma a garantir que todos os
dominós caiem. Adicionalmente, ficou curioso em saber qual o número de peças pertencente à
maior sequência de dominós a cair, de cada vez que ele deita abaixo com a mão um dominó.

# Input
O ficheiro de entrada contém a informação sobre as sequências de dominós, e é definido da seguinte forma:
- Uma linha contendo dois inteiros: o número n de peças de dominó (n ≥ 2), e o número de dependências m a indicar (m ≥ 0);
- Uma lista em que cada linha i contém dois inteiros x e y indicando que se o dominó x cair, então o dominó y também cai.

Quaisquer inteiros numa linha estão separados por no máximo um espaço em branco, não contendo qualquer outro caractér, a não ser o fim de linha. Assuma que os grafos de input são um DAG (grafo dirigido acíclico).

# Output
O programa deverá escrever no output dois inteiros k e l separados por um espaço, onde k corresponde ao número mínimo de intervençoes necessárias para garantir que todos os dominós caem e l corresponde ao tamanho da maior sequência de dominós a cair.

# Exemplo
## Input
7 8

3 4

3 2

4 6

4 5

6 2

6 5

5 7

2 7
## Output
2 5

# Implementação
A implementação do projecto deverá ser feita preferencialmente usando as linguagens de programação C ou C++. Submissões nas linguagens Java/Python também serão aceites, embora fortemente desaconselhadas. Alunos que o escolham fazer devem estar cientes de que submissões em Java/Python podem não passar todos os testes mesmo implementando o algoritmo correcto. Mais se observa que soluções recursivas podem esgotar o limite da pilha quando executadas sobre os testes de maior tamanho, pelo que se recomenda a implementação de um algoritmo iterativo.

O tempo necessário para implementar este projeto é inferior a 15 horas.

Parâmetros de compilação:
C++: `g++ -std=c++11 -O3 -Wall file.cpp -lm`

# Submissão do Projecto
A submissão do projecto deverá incluir um relatório resumido e um ficheiro com o código fonte da solução. Informação sobre as linguagens de programação possíveis está disponível no website do sistema Mooshak. A linguagem de programação é identificada pela extensão do ficheiro. Por exemplo, um projecto escrito em c deverá ter a extensão .c. Após a compilação,
o programa resultante deverá ler do standard input e escrever para o standard output. Informação sobre as opções e restrições de compilação podem ser obtidas através do botão help
do sistema Mooshak. O comando de compilação não deverá produzir output, caso contrário será considerado um erro de compilação.

Relatório: deverá ser submetido através do sistema Fénix no formato PDF com não mais de 2 páginas, fonte de 12pt, e 3cm de margem. O relatório deverá incluir uma descrição da solução, a análise teórica e a avaliação experimental dos resultados. O relatório deverá incluir qualquer referência que tenha sido utilizada na realização do projecto. Relatórios que não sejam entregues em formato PDF terão nota 0. Atempadamente será divulgado um template do relatório. Código fonte: deve ser submetido através do sistema Mooshak e o relatório (em formato PDF) deverá ser submetido através do Fénix. O código fonte será avaliado automaticamente pelo sistema Mooshak (http://acp.tecnico.ulisboa.pt/~mooshak/). Os alunos são encorajados a submeter, tão cedo quanto possível, soluções preliminares para o sistema Mooshak e para o Fénix. Note que apenas a última submissão será considerada para efeitos de avaliação.
Todas as submissões anteriores serão ignoradas: tal inclui o código fonte e o relatório.

# Avaliação
O projecto deverá ser realizado em grupos de um ou dois alunos e será avaliado em duas fases. Na primeira fase, durante a submissão, cada implementação será executada num conjunto de testes, os quais representam 85% da nota final. Na segunda fase, o relatório será avaliado. A nota do relatório contribui com 15% da nota final.

# Avaliação Automática
A primeira fase do projecto é avaliada automaticamente com um conjunto de testes, os quais são executados num computador com o sistema operativo GNU/Linux. É essencial que o código fonte compile sem erros e respeite os standards de entrada e saída indicados anteriormente. Os projectos que não respeitem os formatos especificados serão penalizados e poderão ter nota 0, caso falhem todos os testes. Os testes não serão divulgados antes da submissão. No entanto, todos os testes serão disponibilizados após o deadline para submissão do projecto. Além de verificar a correcção do output produzido, o ambiente de avaliação restringe a mémoria e o tempo
de execução disponíveis. A maior parte dos testes executa o comando diff da forma seguinte: `diff output result`
O ficheiro result contém o output gerado pelo executável a partir do ficheiro input. O ficheiro output contém o output esperado. Um programa passa num teste e recebe o valor correspondente, quando o comando diff não reporta quaisquer diferenças (i.e., não produz qualquer output). O sistema reporta um valor entre 0 e 170. A nota obtida na classificação automática poderá sofrer eventuais cortes caso a análise do código demonstre recurso a soluções ajustadas a inputs concretos ou outputs aleatórios/constantes.

# Detecção de Cópias
A avaliação dos projectos inclui um procedimento para detecção de cópias. A submissão de um projecto implica um compromisso de que o trabalho foi realizado exclusivamente pelos alunos. A violação deste compromisso ou a tentativa de submeter código que não foi desenvolvido pelo grupo implica a reprovação na unidade curricular, para todos os alunos envolvidos (includindo os alunos que disponibilizaram o código). Qualquer tentativa de fraude, directa or indirecta, será comunicada ao Conselho Pedagógico do IST, ao coordenador de curso, e será penalizada de acordo com as regras aprovadas pela Universidade e publicadas em “Diário da República”.
4
