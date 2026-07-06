#ifndef TABULEIRO_H
#define TABULEIRO_H

#define VAZIO 0
#define MARCA_O 1
#define MARCA_X 4

#define LINHAS 3
#define COLUNAS 3

#define POS_VALIDA 1
#define POS_INVALIDA -1
#define POS_OCUPADA -2

void iniciarTabuleiro(int Tabuleiro[LINHAS][COLUNAS]);

void desenha(int Tabuleiro[LINHAS][COLUNAS]);

int temVencedor(int Tabuleiro[LINHAS][COLUNAS]);

void marcaJogada(int Tabuleiro[LINHAS][COLUNAS], int linha, int coluna, int valor);

int posicaoValida(int Tabuleiro[LINHAS][COLUNAS], int linha, int coluna);

int tabuleiroCheio(int Tabuleiro[LINHAS][COLUNAS]);

#endif