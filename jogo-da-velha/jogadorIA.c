#include <stdio.h>
#include "jogadorIA.h"
#include "tabuleiro.h"

// Se tiver duas combinações, marca terceira pra ganhar
int regra1(int Tabuleiro[LINHAS][COLUNAS], int simbolo_escolhido, int somaGanhar) {
    for (int i = 0; i < LINHAS; i++) {
        if (Tabuleiro[i][0] + Tabuleiro[i][1] + Tabuleiro[i][2] == somaGanhar) {
            if (Tabuleiro[i][0] == VAZIO) { marcaJogada(Tabuleiro, i, 0, simbolo_escolhido); return 1; }
            if (Tabuleiro[i][1] == VAZIO) { marcaJogada(Tabuleiro, i, 1, simbolo_escolhido); return 1; }
            if (Tabuleiro[i][2] == VAZIO) { marcaJogada(Tabuleiro, i, 2, simbolo_escolhido); return 1; }
        }
    }
    for (int j = 0; j < COLUNAS; j++) {
        if (Tabuleiro[0][j] + Tabuleiro[1][j] + Tabuleiro[2][j] == somaGanhar) {
            if (Tabuleiro[0][j] == VAZIO) { marcaJogada(Tabuleiro, 0, j, simbolo_escolhido); return 1; }
            if (Tabuleiro[1][j] == VAZIO) { marcaJogada(Tabuleiro, 1, j, simbolo_escolhido); return 1; }
            if (Tabuleiro[2][j] == VAZIO) { marcaJogada(Tabuleiro, 2, j, simbolo_escolhido); return 1; }
        }
    }
    if (Tabuleiro[0][0] + Tabuleiro[1][1] + Tabuleiro[2][2] == somaGanhar) {
        if (Tabuleiro[0][0] == VAZIO) { marcaJogada(Tabuleiro, 0, 0, simbolo_escolhido); return 1; }
        if (Tabuleiro[1][1] == VAZIO) { marcaJogada(Tabuleiro, 1, 1, simbolo_escolhido); return 1; }
        if (Tabuleiro[2][2] == VAZIO) { marcaJogada(Tabuleiro, 2, 2, simbolo_escolhido); return 1; }
    }
    if (Tabuleiro[0][2] + Tabuleiro[1][1] + Tabuleiro[2][0] == somaGanhar) {
        if (Tabuleiro[0][2] == VAZIO) { marcaJogada(Tabuleiro, 0, 2, simbolo_escolhido); return 1; }
        if (Tabuleiro[1][1] == VAZIO) { marcaJogada(Tabuleiro, 1, 1, simbolo_escolhido); return 1; }
        if (Tabuleiro[2][0] == VAZIO) { marcaJogada(Tabuleiro, 2, 0, simbolo_escolhido); return 1; }
    }
    return 0; 
}

// Se tiver duas combinações, marca terceira pra bloquear
int regra2(int Tabuleiro[LINHAS][COLUNAS], int simbolo_escolhido, int somaBloquear) {
    for (int i = 0; i < LINHAS; i++) {
        if (Tabuleiro[i][0] + Tabuleiro[i][1] + Tabuleiro[i][2] == somaBloquear) {
            if (Tabuleiro[i][0] == VAZIO) { marcaJogada(Tabuleiro, i, 0, simbolo_escolhido); return 1; }
            if (Tabuleiro[i][1] == VAZIO) { marcaJogada(Tabuleiro, i, 1, simbolo_escolhido); return 1; }
            if (Tabuleiro[i][2] == VAZIO) { marcaJogada(Tabuleiro, i, 2, simbolo_escolhido); return 1; }
        }
    }
    for (int j = 0; j < COLUNAS; j++) {
        if (Tabuleiro[0][j] + Tabuleiro[1][j] + Tabuleiro[2][j] == somaBloquear) {
            if (Tabuleiro[0][j] == VAZIO) { marcaJogada(Tabuleiro, 0, j, simbolo_escolhido); return 1; }
            if (Tabuleiro[1][j] == VAZIO) { marcaJogada(Tabuleiro, 1, j, simbolo_escolhido); return 1; }
            if (Tabuleiro[2][j] == VAZIO) { marcaJogada(Tabuleiro, 2, j, simbolo_escolhido); return 1; }
        }
    }
    if (Tabuleiro[0][0] + Tabuleiro[1][1] + Tabuleiro[2][2] == somaBloquear) {
        if (Tabuleiro[0][0] == VAZIO) { marcaJogada(Tabuleiro, 0, 0, simbolo_escolhido); return 1; }
        if (Tabuleiro[1][1] == VAZIO) { marcaJogada(Tabuleiro, 1, 1, simbolo_escolhido); return 1; }
        if (Tabuleiro[2][2] == VAZIO) { marcaJogada(Tabuleiro, 2, 2, simbolo_escolhido); return 1; }
    }
    if (Tabuleiro[0][2] + Tabuleiro[1][1] + Tabuleiro[2][0] == somaBloquear) {
        if (Tabuleiro[0][2] == VAZIO) { marcaJogada(Tabuleiro, 0, 2, simbolo_escolhido); return 1; }
        if (Tabuleiro[1][1] == VAZIO) { marcaJogada(Tabuleiro, 1, 1, simbolo_escolhido); return 1; }
        if (Tabuleiro[2][0] == VAZIO) { marcaJogada(Tabuleiro, 2, 0, simbolo_escolhido); return 1; }
    }
    return 0; 
}

// Se o meio tiver vazio, marca lá
int regra3(int Tabuleiro[LINHAS][COLUNAS], int simbolo_escolhido) {
    if (Tabuleiro[1][1] == VAZIO) {
        marcaJogada(Tabuleiro, 1, 1, simbolo_escolhido);
        return 1;
    }
    return 0;
}

// Se um canto ou extremidade tiver marcada, marca a oposta
int regra4(int Tabuleiro[LINHAS][COLUNAS], int simbolo_escolhido, int jogada_humana) {
    if (Tabuleiro[0][0] == jogada_humana && Tabuleiro[2][2] == VAZIO) { marcaJogada(Tabuleiro, 2, 2, simbolo_escolhido); return 1; }
    if (Tabuleiro[0][2] == jogada_humana && Tabuleiro[2][0] == VAZIO) { marcaJogada(Tabuleiro, 2, 0, simbolo_escolhido); return 1; }
    if (Tabuleiro[2][2] == jogada_humana && Tabuleiro[0][0] == VAZIO) { marcaJogada(Tabuleiro, 0, 0, simbolo_escolhido); return 1; }
    if (Tabuleiro[2][0] == jogada_humana && Tabuleiro[0][2] == VAZIO) { marcaJogada(Tabuleiro, 0, 2, simbolo_escolhido); return 1; }
    return 0;
}

// Se o canto ou extremidade tiver vazio, marca lá
int regra5(int Tabuleiro[LINHAS][COLUNAS], int simbolo_escolhido) {
    if (Tabuleiro[0][0] == VAZIO) { marcaJogada(Tabuleiro, 0, 0, simbolo_escolhido); return 1; }
    if (Tabuleiro[0][2] == VAZIO) { marcaJogada(Tabuleiro, 0, 2, simbolo_escolhido); return 1; }
    if (Tabuleiro[2][0] == VAZIO) { marcaJogada(Tabuleiro, 2, 0, simbolo_escolhido); return 1; }
    if (Tabuleiro[2][2] == VAZIO) { marcaJogada(Tabuleiro, 2, 2, simbolo_escolhido); return 1; }
    return 0;
}

// Marca em qualquer uma vazia
int regra6(int Tabuleiro[LINHAS][COLUNAS], int simbolo_escolhido) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (Tabuleiro[i][j] == VAZIO) {
                marcaJogada(Tabuleiro, i, j, simbolo_escolhido);
                return 1;
            }
        }
    }
    return 0;
}

void jogaIA(int Tabuleiro[LINHAS][COLUNAS], int simbolo_escolhido) {
    printf("IA pensando...\n");

    int jogada_humana = (simbolo_escolhido == MARCA_X) ? MARCA_O : MARCA_X;

    int somaGanhar = simbolo_escolhido * 2;
    int somaBloquear = jogada_humana * 2;

    if (regra1(Tabuleiro, simbolo_escolhido, somaGanhar)) return;
    if (regra2(Tabuleiro, simbolo_escolhido, somaBloquear)) return;
    if (regra3(Tabuleiro, simbolo_escolhido)) return;
    if (regra4(Tabuleiro, simbolo_escolhido, jogada_humana)) return;
    if (regra5(Tabuleiro, simbolo_escolhido)) return;
    if (regra6(Tabuleiro, simbolo_escolhido)) return;
}