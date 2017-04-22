# Projeto Bouncing oriented Ball

Este projeto tem por finalidade implementar conhecimentos adquiridos nas aulas de Técnicas de Programação 1 por meio da simulação da queda de uma bola dentro de uma caixa 2D.

## Requisitos

É necessário ter instalado na máquina um compilador de C++.
O sistema operacional pode ser o Linux, Windows ou MacOS.
Instalação do compilador:
- [Windows.](https://cs.calvin.edu/courses/cs/112/resources/installingEclipse/cygwin/)
- [Mac.](https://www.mkyong.com/mac/how-to-install-gcc-compiler-on-mac-os-x/)
- [Linux.](https://askubuntu.com/questions/348654/how-to-install-g-compiler)

## Instalação/Compilação

Baixe todo o diretório do projeto, abra o terminal ou equivalente da sua máquina, acesse o diretório no qual o projeto foi baixado usando

```
cd /SeuDiretório/SuaPasta/tecnicadeprogramacao1
```
Depois deve-se compilar os códigos test-ball.cpp, ball.cpp e ball.h

```
g++ test-ball.cpp ball.cpp ball.h
```
E aí executar o arquivo a.out

```
./a.out
```

## Descrição dos arquivos

- ball.h - classe abstrata contendo as funções a serem implementadas em ball.cpp
- ball.cpp - classe ball contendo a implementação de ball
- simulation.h - interface para a ball
- test-ball.cpp - arquivo para teste da classe ball
- ball.txt - saída do arquivo test-ball.cpp
- plotBall - gráfico gerado pelo MATLAB a partir do ball.txt

### Resultado MATLAB

O MATLAB é usado para análise visual de dados. A partir da saída do test-ball.cpp foi possível plottar o seguinte gráfico.

![plotBall](plotBall.png)

### Diagrama de Classes

![Diagrama](DiagramaDeClasses.png)

### Saída

```
0.01 -0.00877778
0.02 -0.0284444
0.03 -0.059
0.04 -0.100444
0.05 -0.152778
0.06 -0.216
0.07 -0.290111
0.08 -0.375111
0.09 -0.471
0.1 -0.577778
0.11 -0.695444
0.12 -0.824
0.13 -0.824
0.14 -0.695444
0.15 -0.577778
0.16 -0.471
0.17 -0.375111
0.18 -0.290111
0.19 -0.216
0.2 -0.152778
0.21 -0.100444
0.22 -0.059
0.23 -0.0284444
0.24 -0.00877778
0.25 -8.1532e-17
0.26 -0.00211111
0.27 -0.0151111
0.28 -0.039
0.29 -0.0737778
0.3 -0.119444
0.31 -0.176
0.32 -0.243444
0.33 -0.321778
0.34 -0.411
0.35 -0.511111
0.36 -0.622111
0.37 -0.744
0.38 -0.876778
0.39 -0.876778
0.4 -0.744
0.41 -0.622111
0.42 -0.511111
0.43 -0.411
0.44 -0.321778
0.45 -0.243444
0.46 -0.176
0.47 -0.119444
0.48 -0.0737778
0.49 -0.039
0.5 -0.0151111
0.51 -0.00211111
0.52 -4.90059e-16
0.53 -0.00877778
0.54 -0.0284444
0.55 -0.059
0.56 -0.100444
0.57 -0.152778
0.58 -0.216
0.59 -0.290111
0.6 -0.375111
0.61 -0.471
0.62 -0.577778
0.63 -0.695444
0.64 -0.824
0.65 -0.824
0.66 -0.695444
0.67 -0.577778
0.68 -0.471
0.69 -0.375111
0.7 -0.290111
0.71 -0.216
0.72 -0.152778
0.73 -0.100444
0.74 -0.059
0.75 -0.0284444
0.76 -0.00877778
0.77 -7.47666e-16
0.78 -0.00211111
0.79 -0.0151111
0.8 -0.039
0.81 -0.0737778
0.82 -0.119444
0.83 -0.176
0.84 -0.243444
0.85 -0.321778
0.86 -0.411
0.87 -0.511111
0.88 -0.622111
0.89 -0.744
0.89 -0.876778
0.88 -0.876778
0.87 -0.744
0.86 -0.622111
0.85 -0.511111
0.84 -0.411
0.83 -0.321778
0.82 -0.243444
0.81 -0.176
0.8 -0.119444
0.79 -0.0737778
```


