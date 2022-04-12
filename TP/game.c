// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

#include <stdio.h>
#include <stdlib.h>
#include "save.h"
#include "matdin.h"

void game() {
    if (fileExists()) {
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
    Celula** tab;

    tab = iniciaTab();

    do {



    } while(!finished());
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

void startBot() {
    Celula** tab;

    tab = iniciaTab();

    do {

    } while(!finished());
}

void startMemoria() {
    Celula** tab;

    tab = iniciaTab();

    do {
        showTab(tab);
    } while(!finished());
}

Celula** iniciaTab() {
    Celula** aux = NULL;
    
    aux = malloc(sizeof(Celula) * 3);
    for (int k = 0; k < 3; k++) {
        aux[k] = malloc(sizeof(Celula) * 3);
    }
    
    for (int i = 0; i < 3; i++){ 
        for (int j = 0; j < 3; j++){
            aux[i][j].completed = 0;
            aux[i][j].player = 0;
            aux[i][j].tab = criaMat(3, 3);
        }
    }

    return aux;
}

void showTab(Celula** aux) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //TODO: Refazer esta parte para ficar bonitxinho
            mostraMat(aux[i][j].tab, 3, 3);
        }
        printf("\n");
    }
}

int finished() {
    
    
    return 0;
}