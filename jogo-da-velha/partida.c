#include <stdio.h>
#include "partida.h"
#include "jogador_teclado.h"
#include "tabuleiro.h"
#include "jogadorIA.h"

static int Tabuleiro[LINHAS][COLUNAS];
static int simboloJogador1;
static int simboloJogador2;

void configuraJogadores() {
    iniciarTabuleiro(Tabuleiro);

    printf("Jogador 1: ");
    simboloJogador1 = escolheSimbolo();

    simboloJogador2 = (simboloJogador1 == MARCA_X) ? MARCA_O : MARCA_X;
    printf("Jogador 2 ficou com %s.\n", (simboloJogador2 == MARCA_X) ? "X" : "O");
}

void inicia() {
    int vencedor = 0;
    int turno = simboloJogador1;

    while (vencedor == VAZIO && !tabuleiroCheio(Tabuleiro)) {
        desenha(Tabuleiro);
        
        if (turno == simboloJogador1) {
            joga(Tabuleiro, turno);
        } else {
            jogaIA(Tabuleiro, turno);
        }

        vencedor = temVencedor(Tabuleiro);
        turno = (turno == simboloJogador1) ? simboloJogador2 : simboloJogador1;
    }

    desenha(Tabuleiro);

    if (vencedor == simboloJogador1) {
        printf("Vencedor: Jogador 1\n");
    } else if (vencedor == simboloJogador2) {
        printf("Vencedor: Jogador 2 (IA)\n");
    } else {
        printf("Deu velha!\n"); 
    }
}