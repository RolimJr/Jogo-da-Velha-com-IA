#include <stdio.h>
#include "jogador_teclado.h"
#include "tabuleiro.h"

int escolheSimbolo() {
    char simbolo[10];
    int valor;

    while(1) {
        printf("Escolha qual simbolo voce quer (X ou O): ");
        fgets(simbolo, sizeof(simbolo), stdin);

        if (simbolo[0] == 'X' || simbolo[0] == 'x') {
            valor = MARCA_X;
            break;
        } else if (simbolo[0] == 'O' || simbolo[0] == 'o') {
            valor = MARCA_O;
            break;
        } else {
            printf("Opcao Invalida! Digite X ou O\n");
        }
    }

    return valor;
}

void joga(int Tabuleiro[LINHAS][COLUNAS], int valor) {
    int linha, coluna;
    int jogadaValida = 0;

    while(jogadaValida == 0) {
        printf("Digite a linha e a coluna (ex: 1 1): ");

        if (scanf("%d %d", &linha, & coluna) != 2) {
            printf("Posicao Incorreta.\n");
            while (getchar() != '\n');
            continue;
        }

        int resultado = posicaoValida(Tabuleiro, linha, coluna);

        if (resultado == POS_INVALIDA) {
            printf("Posicao Invalida.\n");
            continue;
        } else if (resultado == POS_OCUPADA) {
            printf("Posicao ja ocupada.\n");
            continue;
        }

        jogadaValida = 1;

        marcaJogada(Tabuleiro, linha, coluna, valor);
    }
}