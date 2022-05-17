#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "matdin.h"

void game() {
    int option;
    do {
        option = menuPrincipal();
        switch (option) {
            case 1:
                startPlayer();
                break;

            case 2:
                //startBot();
                break;
            case 4:

                break;
            case 9:
                break;
        }
    }
    while(option != 9);
}

void startPlayer() {
    Tabuleiro **tab = NULL;

    tab = inicializaTabuleiro(3, 3);
    mostraTabuleiro(tab, 3, 3);
    if(tab == NULL)
       return;

    do{

    }
    while(!finish(tab));
}

//TODO: Falta fazer o empate
int finish(Tabuleiro **tab){
    if(tab[0][0].completed == tab[1][1].completed == tab[2][2].completed
        && tab[0][0].completed != 0){
        return TRUE;
    }

    for(int i = 0; i < NLIN; i++){
        if(tab[i][0].completed == tab[i][1].completed == tab[i][2].completed
            && tab[i][0].completed != 0){
           return TRUE;
        }

        if(tab[0][i].completed == tab[1][i].completed == tab[2][i].completed
            && tab[0][i].completed != 0){
            return TRUE;
        }
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
    return option;
}

