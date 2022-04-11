#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void game() {
    if (fileExists()) {
        //TODO: Verificao de um Ficheiro Binario
        startMemoria();
    }

    int option = menuPrincipal();
    switch (option) {
    case 1:
        startPlayer();
        break;
    
    case 2:
        startBot();
        break;
    }
}

void startPlayer() {
    Tabuleiro** tab;

    
}

int menuPrincipal() {
    int option;
    printf("Escolha uma das seguintes opcoes:\n");
    printf("1. Jogar contra outro Jogador\n");
    printf("2. Jogar contra Bot\n");
         
    do{
        printf(">>> ");
        scanf("%d", &option);
    } while (option < 1 || option > 2);
    
    return option;
}