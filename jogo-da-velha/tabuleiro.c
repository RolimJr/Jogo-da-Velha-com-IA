#include <stdio.h>
#include "tabuleiro.h"

void iniciarTabuleiro(int Tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            Tabuleiro[i][j] = VAZIO;
        }
    }
}

void desenha(int Tabuleiro[LINHAS][COLUNAS]) {
     printf("\033[2J\033[H");

         printf("    0   1   2 \n");
    printf("  -------------\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%d | ", i);
        for (int j = 0; j < COLUNAS; j++) {
            if (Tabuleiro[i][j] == MARCA_O) {
                printf("O");
            } else if (Tabuleiro[i][j] == MARCA_X) {
                printf("X");
            } else {
                printf(" ");
            }
            printf(" | ");
        }
        printf("\n  -------------\n");
    }
}
int temVencedor(int Tabuleiro[LINHAS][COLUNAS]) {
    int soma;

    for (int i = 0; i < LINHAS; i++) {
        soma = Tabuleiro[i][0] + Tabuleiro[i][1] + Tabuleiro[i][2];
        if (soma == 3) {
            return MARCA_O;
        }
        if (soma == 12) {
            return MARCA_X;
        }
    }

    for (int j = 0; j < COLUNAS; j++) {
        soma = Tabuleiro[0][j] + Tabuleiro[1][j] + Tabuleiro[2][j];
        if (soma == 3) {
            return MARCA_O;
        }
        if (soma == 12) {
            return MARCA_X;
        }
    }

    soma = Tabuleiro[0][0] + Tabuleiro[1][1] + Tabuleiro[2][2];
    if (soma == 3) {
        return MARCA_O;
    }
    if (soma == 12) {
        return MARCA_X;
    }

    soma = Tabuleiro[0][2] + Tabuleiro[1][1] + Tabuleiro[2][0];
    if (soma == 3) {
        return MARCA_O;
    }
    if (soma == 12) {
        return MARCA_X;
    }

    return 0;
}

void marcaJogada(int Tabuleiro[LINHAS][COLUNAS], int linha, int coluna, int valor) {
    Tabuleiro[linha][coluna] = valor;
}

int posicaoValida(int Tabuleiro[LINHAS][COLUNAS], int linha, int coluna) {
    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) {
        return POS_INVALIDA;
    }

    if (Tabuleiro[linha][coluna] != VAZIO) {
        return POS_OCUPADA;
    }

    return POS_VALIDA;
}

int tabuleiroCheio(int Tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (Tabuleiro[i][j] == VAZIO) {
                return 0;
            }
        }
    }
    return 1;
}