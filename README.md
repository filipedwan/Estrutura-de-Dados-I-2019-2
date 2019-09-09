# Estrutura de Dados I (semestre 2019-2)

Neste repositório são disponibilizadas as notas de aula da disciplina de Estrutura de Dados I, ministrada no segundo semestre de 2019. As aulas tem como base a seguinte literatura:

* CELES, W; CERQUEIRA, R; RANGEL, J. Introdução a Estruturas de Dados, com técnicas de programação. Rio de Janeiro: Elsevier, 2004.
* CORMEN, THOMAS H., et al. "Algoritmos: teoria e prática." Editora Campus 2 (2002).
* ASCENCIO, A; ARAUJO, G. Estruturas de dados algoritmos, análise da complexibilidade e implementações em Java e C/C++. São Paulo: Pearson, 2010.


Além dos livros supracitados, são utilizados exercícios de fixação disponibilizados no [URI online judge](https://www.urionlinejudge.com.br/judge/login?redirect=%2Fen%2Flogin). Outros recursos utilizados de modo pontual para aulas específicas são citados nas próprias notas de aula.

**Importante**: segue abaixo um breve tutorial sobre compilar as estruturas de dados criadas em C.
Fonte: https://fig.if.usp.br/~esdobay/c/gcc.html

* Uma forma rápida com compilar e linkar os arquivos objetos e indicar o nome do arquivo de sáida é:
	gcc principal.c pilha.c -o principal -std=c11
* Observe que o parâmetro '-std=c11' é opcional. Ele especifica a versão que será utilizada da linguagem C.
* Para executar o arquivo de sáida use:
	./principal
* Outras opções
-Wall
ativa vários avisos que não são ativados normalmente. Pode dar alguns conselhos úteis.

* O gcc pode otimizar o seu programa de modo a aumentar seu desempenho e/ou diminuir o tamanho do código de máquina gerado. Por omissão, o gcc não realiza nenhuma otimização. Há três níveis de otimização: 1, 2 e 3. Quanto maior o nível, maior deve ser a melhora no desempenho; mas também deve ser maior o tempo de compilação.
* Para ativar a otimização, use as opções -O1, -O2 ou -O3 (a letra O, não o número zero), de acordo com o nível de otimização que você desejar. Também existe a opção -Os, que realiza as mesmas otimizações de -O2, excetuando as que costumam aumentar o tamanho do executável gerado.
* Para apenas compilar (e não montar) um arquivo, você deve usar o comando
gcc -c prog.c
* Note que não foi necessário especificar o nome do arquivo a ser gerado. O gcc criará o arquivo prog.o (a extensão .o significa objeto ou programa-objeto), um nome que você, geralmente, não deveria mudar. (Você pode, no entanto, mudá-lo, também com a opção -o.)
* Os vários programas-objeto devem ser montados para formar um executável. Isso é feito com o comando:
gcc -o monstrinho prog1.o prog2.o prog3.o ...
que gerará o executável monstrinho.
* Assim, se você tiver um programa com três arquivos-fonte e resolver alterar o segundo, você pode recompilar apenas o segundo e apenas repetir a etapa de montagem (desde que já tenha os programas-objeto dos outros dois arquivos):
gcc -c prog2.c
gcc -o meuprog prog1.o prog2.o prog3.o

Makefiles

* À medida que seus programas vão ficando mais complexos e com mais arquivos, fica mais trabalhoso cuidar da recompilação de arquivos individuais, principalmente quando há dependência entre os arquivos e várias opções adicionais de linha de comando.


Atenciosamente,
prof. Filipe Dwan Pereira.
