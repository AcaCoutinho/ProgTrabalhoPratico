// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#include <stdio.h>
#include "utils.h"
#include "matdin.h"
#include "game.h"


void game() {
    if(existsBinaryFile()){
        int option;
        int isPlayer;

        printf("\nEscolha uma das seguintes opcoes:\n");
        printf("1. Pretende carregar o jogo guardado\n");
        printf("2. Nao pretende carregar o jogo guardado\n");
        do{
            printf(">>>");
            scanf("%d", &option);
        }
        while(option < 1 || option > 2);
        if(option == 1){
            Save *save = NULL;
            save = readBinaryFile(save, &isPlayer);
            if(isPlayer){
                carregaJogoJogador(save);
            } else {
                carregaJogoBot(save);
            }
        }
        if(option == 2){
            deleteBinaryFile();
        }
    }

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
            case 9:
                break;
        }
    }
    while(option != 9);
}

void startPlayer() {
    Tabuleiro **tab = NULL;
    Save* save = NULL;

    Save s;
    s.jogada = 0;
    int player;
    int option;
    int finished;
    char filename[50];

    printf("Criacao do Tabuleiro\n");
    tab = inicializaTabuleiro(NLIN, NCOL);
    if(tab == NULL)
        return;
    mostraTabuleiro(tab, NLIN, NCOL);

    do{
        printf("Jogada: %d\n", ++s.jogada);
        player = jogador(s.jogada);
        printf("Jogador %d\n", player);

        int isFinished = FALSE;
        do {
            int option = menuJogadas();
            switch (option) {
                case 1:
                    jogada(tab, player, &s);
                    isFinished = TRUE;
                    break;
                case 2:
                    imprimeJogadasAnterior(save);
                    break;
                case 3:
                    libertaTabuleiro(tab, NLIN);
                    libertaListaLigada(save);
                    return;
            }
        }
        while(!isFinished);
        finished = finish(tab, &s);
        mostraTabuleiro(tab, NLIN, NCOL);
        save = insereInicio(save, s);
        escreveFicheiroBinario(save, TRUE);
    }
    while(!finished);
    mostraVencedor(s);
    deleteBinaryFile();
    option = menuFicheiros();
    if(option == 1){
        fflush(stdin);
        printf("Digita o nome do ficheiro:\n");
        scanf("%s", filename);
        imprimeJogoFile(filename, save, FALSE);
    }
    libertaTabuleiro(tab, NLIN);
    libertaListaLigada(save);
}

void startBot(){
    Tabuleiro **tab = NULL;
    Save* save = NULL;

    Save s;
    s.jogada = 0;
    int player;
    int option;
    char filename[50];
    int finished;

    initRandom();
    printf("Criacao do Tabuleiro\n");
    tab = inicializaTabuleiro(NLIN, NCOL);
    if(tab == NULL)
        return;
    mostraTabuleiro(tab, NLIN, NCOL);

    do{
        printf("Jogada: %d\n", ++s.jogada);
        player = jogador(s.jogada);
        if(player == 1) {
            printf("Jogador %d\n", player);
            int isFinished = FALSE;
            do {
                int option = menuJogadas();
                switch (option) {
                    case 1:
                        jogada(tab, player, &s);
                        isFinished = TRUE;
                        break;
                    case 2:
                        imprimeJogadasAnterior(save);
                        break;
                    case 3:
                        libertaTabuleiro(tab, NLIN);
                        libertaListaLigada(save);
                        return;
                }
            }
            while(!isFinished);
        } else {
            printf("Jogada: BOT\n");
            jogadaBot(tab, &s);
        }
        finished = finish(tab, &s);
        mostraTabuleiro(tab, NLIN, NCOL);
        save = insereInicio(save, s);
        escreveFicheiroBinario(save, FALSE);
    }
    while(!finished);
    mostraVencedor(s);
    deleteBinaryFile();
    option = menuFicheiros();
    if(option == 1){
        fflush(stdin);
        printf("Digita o nome do ficheiro:\n");
        scanf("%s", filename);
        imprimeJogoFile(filename, save, FALSE);
    }
    libertaTabuleiro(tab, NLIN);
    libertaListaLigada(save);
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

    for(int i = 0; i < NLIN; i++){
        for(int j = 0; j < NCOL; j++){
            if (tab[i][j].completed == 1) {
                completaTabuleiro(tab[i][j].tab, 1);
            }
            if (tab[i][j].completed == 2){
                completaTabuleiro(tab[i][j].tab, 2);
            }
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
    printf("\n\n\n");
    printf("Escolha uma das seguintes opcoes:\n");
    printf("1. Jogar contra outro Jogador\n");
    printf("2. Jogar contra Bot\n");
    printf("9. SAIR\n");

    printf(">>> ");
    scanf("%d", &option);
    printf("\n");
    return option;
}

int jogador(int jogada){
    if(jogada % 2 == 0)
        return 2;
    else
        return 1;
}

void jogada(Tabuleiro** tab, int player, Save *save) {
    int isFinished = FALSE;
    int lin, col;

    do {
        do {
            printf("Digita em que tabuleiro pretende colocar (lin,col):\n");
            printf(">>> ");
            scanf("%d,%d", &lin, &col);
        } while (lin < 0 || lin > NLIN * NCOL && col < 0 || col > NCOL * NLIN);

        save->lin = lin;
        save->col = col;

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

int menuJogadas(){
    int option;

    printf("Escolha uma das seguintes opcoes:\n");
    printf("1. Jogar Jogada:\n");
    printf("2. Visualizar 10 Jogadas Anteriores:\n");
    printf("3. Sair e Gravar Jogo:\n");
    do{
        printf(">>> ");
        scanf("%d", &option);
    }
    while(option < 1 || option > 3);
    printf("\n");

    return option;
}

int menuFicheiros(){
    int option;

    printf("Pretende guardar o jogo num ficheiro:\n");
    printf("1. SIM:\n");
    printf("2. NAO:\n");

    do{
        printf(">>> ");
        scanf("%d", &option);
    }
    while(option < 1 || option > 2);
    printf("\n");
    return option;
}