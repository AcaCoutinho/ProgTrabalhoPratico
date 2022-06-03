// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "matdin.h"
#include "game.h"


void game() {
    int option;
    do {
        option = menuPrincipal();
        switch (option) {
            case 1:
                startPlayer();
                break;
            case 2:
                startBot();
                break;
            case 3:
                regras();
                break;
            case 9:
                break;
        }
    }
    while(option != 9);
}

void startPlayer() {
    Tabuleiro **tab = NULL;
    Save save;
    save.jogada = 0;
    int player;

    printf("Criacao do Tabuleiro\n");
    tab = inicializaTabuleiro(NLIN, NCOL);
    if(tab == NULL)
        return;
    mostraTabuleiro(tab, NLIN, NCOL);

    do{
        player = jogador(save.jogada);
        printf("Jogada: %d\n", ++save.jogada);
        printf("Jogador %d\n", player);

        jogada(tab, player);
        mostraTabuleiro(tab, NLIN, NCOL);
    }
    while(!finish(tab, &save));
    mostraVencedor(save);
}

void startBot(){
    Tabuleiro **tab = NULL;
    Save save;
    save.jogada = 0;
    int player;

    initRandom();
    printf("Criacao do Tabuleiro\n");
    tab = inicializaTabuleiro(NLIN, NCOL);
    if(tab == NULL)
        return;
    mostraTabuleiro(tab, NLIN, NCOL);

    do{
        player = jogador(save.jogada);
        printf("Jogada: %d\n", ++save.jogada);
        if(player == 1) {
            printf("Jogador %d\n", player);
            jogada(tab, player);
        } else {
            printf("Jogada: BOT\n");
            jogadaBot(tab);
        }
        mostraTabuleiro(tab, NLIN, NCOL);
    }
    while(!finish(tab, &save));
    mostraVencedor(save);
}

int finish(Tabuleiro **tab, Save *save){
    int count = 0;

    for(int i = 0; i < NLIN; i++){
        for(int j = 0; j < NCOL; j++){
            count += verificaCompletoTab(tab[i][j]);
            if(tab[i][j].completed == 0)
                tab[i][j].completed = verificaTabuleiro(tab[i][j]);
        }
    }

    if(tab[0][0].completed == tab[1][1].completed && tab[1][1].completed == tab[2][2].completed
        && tab[0][0].completed != 0){
        if(tab[0][0].completed == 1){
            save->vencedor = 1;
        }
        else{
            save->vencedor = 2;
        }
        return TRUE;
    }

    for(int i = 0; i < NLIN; i++){
        if(tab[i][0].completed == tab[i][1].completed && tab[i][1].completed == tab[i][2].completed
            && tab[i][0].completed != 0){
            if(tab[i][0].completed == 1){
                save->vencedor = 1;
            }
            else{
                save->vencedor = 2;
            }
           return TRUE;
        }

        if(tab[0][i].completed == tab[1][i].completed && tab[1][i].completed == tab[2][i].completed
            && tab[0][i].completed != 0){
            if(tab[0][i].completed == 1){
                save->vencedor = 1;
            }
            else{
                save->vencedor = 2;
            }
            return TRUE;
        }
    }

    if(count == 0){
        save->vencedor = 3;
        return TRUE;
    }
    return FALSE;
}

int menuPrincipal() {
    int option;
    printf("Escolha uma das seguintes opcoes:\n");
    printf("1. Jogar contra outro Jogador\n");
    printf("2. Jogar contra Bot\n");
    printf("3. Regras\n");
    printf("9. SAIR\n");

    printf(">>> ");
    scanf("%d", &option);
    printf("\n");
    return option;
}

void regras(){

}

int jogador(int jogada){
    if(jogada % 2 == 0)
        return 1;
    else
        return 2;
}

void jogada(Tabuleiro** tab, int player) {
    int lin, col;
    int isFinished = FALSE;

    do {
        do {
            printf("Digita em que tabuleiro pretende colocar (lin,col):\n");
            printf(">>> ");
            scanf("%d,%d", &lin, &col);
        } while (lin < 0 || lin > NLIN * NCOL && col < 0 || col > NCOL * NLIN);

        if (tab[conversorLinColTab(lin-1)][conversorLinColTab(col-1)].tab[conversorLinCol(lin-1)][conversorLinCol(col-1)] == '_') {
            if (player == 1) {
                tab[conversorLinColTab(lin-1)][conversorLinColTab(col-1)].tab[conversorLinCol(lin-1)][conversorLinCol(col-1)] = 'O';
                isFinished = TRUE;
            }
            if (player == 2) {
                tab[conversorLinColTab(lin-1)][conversorLinColTab(col-1)].tab[conversorLinCol(lin-1)][conversorLinCol(col-1)] = 'X';
                isFinished = TRUE;
            }
        }
    }
    while (!isFinished);
    printf("\nJogada terminada\n");
}

void mostraVencedor(Save save){
    if(save.vencedor == 3){
        printf("\n\tO jogo terminou num empate...\n\n");
    } else {
           printf("\n\tO vencedor e o jogador %d!\n\n", save.vencedor);
    }
}