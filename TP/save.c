// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#include "save.h"

#include <stdio.h>
#include <stdlib.h>

//Funcao de apoio
void printLista(Save *save){
    int count = 0;
    printf("Listar Lista Ligada:\n\n");
    while(save != NULL){
        printf("Jogada [%d], posicao [%d][%d]\n", save->jogada, save->lin, save->col);
        count += 1;
        save = save->nextPlay;
    }
    printf("Numero Total de listas: %d\n", count);
    printf("\n");
}

Save* insereFim(Save* save, Save s){
    Save* novo = NULL;
    Save* aux;
    novo = malloc(sizeof(Save));
    if(novo == NULL){
        printf("Erro");
        return NULL;
    }

    novo->jogada = s.jogada;
    novo->vencedor = s.vencedor;
    novo->col = s.col;
    novo->lin = s.lin;
    novo->nextPlay = NULL;

    if(save == NULL){
        save = novo;
    } else {
        aux = save;
        while(aux->nextPlay != NULL){
            aux = aux->nextPlay;
        }
        aux->nextPlay = novo;
    }
    return save;
}

Save* insereInicio(Save *save, Save s){
    Save* novo = NULL;
    novo = malloc(sizeof (Save));
    if(novo == NULL){
        printf("Erro");
        return NULL;
    }

    novo->jogada = s.jogada;
    novo->vencedor = s.vencedor;
    novo->col = s.col;
    novo->lin = s.lin;

    novo->nextPlay = save;
    save = novo;
    return save;
}

void imprimeJogoFile(char fileName[50], Save *save, int isPlayer){
    FILE *f;

    f = fopen(fileName, "wt");
    if(f == NULL){
        printf("Erro");
        return;
    }

    if(isPlayer == TRUE){
        fprintf(f, "Jogo contra Jogador\n");
    } else {
        fprintf(f, "Jogo contra BOT\n");
    }
    while(save != NULL){
        fprintf(f, "Jogada [%d] feita pelo jogador [%d] na posicao(lin,col) [%d],[%d]", save->jogada, jogador(save->jogada), save->lin, save->col);
        fprintf(f, "\n");
        save = save->nextPlay;
    }

    fclose(f);
}

void imprimeJogadasAnterior(Save *save){
    printf("\nDez Jogadas Anteriores:\n");
    for(int i = 0; i < 10 && save != NULL; i++){
        printf("Jogada [%d], na linha [%d] e coluna [%d]\n", save->jogada, save->lin, save->col);
        save = save->nextPlay;
    }
}

int existsBinaryFile(){
    FILE *f;

    f = fopen("save.bin", "rb");
    if(f == NULL){
        fclose(f);
        return 0;
    }
    fclose(f);
    return 1;
}

void escreveFicheiroBinario(Save *save, int isPlayer){
    Save aux;
    FILE* f;

    f = fopen("save.bin", "wb");
    if(f == NULL){
        printf("Erro na escrita do ficheiro");
        return;
    }

    fwrite(&isPlayer, sizeof(int), 1, f);
    while(save != NULL){
        aux.jogada = save->jogada;
        aux.vencedor = save->vencedor;
        aux.lin = save->lin;
        aux.col = save->col;

        fwrite(&aux, sizeof(Save), 1, f);
        save = save->nextPlay;
    }
    fclose(f);
}

Save* readBinaryFile(Save* save, int *isPlayer){
    Save aux;
    int aux1;
    FILE *f;

    f = fopen("save.bin", "rb");
    if(f == NULL){
        return 0;
    }

    fread(&aux1, sizeof (int), 1, f);
    *isPlayer = aux1;
    while(fread(&aux, sizeof (Save), 1, f) == 1){
        save = insereFim(save, aux);
    }
    fclose(f);
    return save;
}

void libertaListaLigada(Save *save){
    Save* aux;

    while(save != NULL){
        aux = save;
        save = save->nextPlay;
        free(aux);
    }
}

void carregaJogoJogador(Save* save) {
    Tabuleiro **tab = NULL;
    tab = carregaTabuleiro(tab, save);
    mostraTabuleiro(tab, NLIN, NCOL);

    Save s;
    s.jogada = save->jogada;
    int player;
    int option;
    char filename[50];

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
                    libertaListaLigada(save);
                    libertaTabuleiro(tab, NLIN);
                    return;
            }
        }
        while(!isFinished);
        mostraTabuleiro(tab, NLIN, NCOL);
        save = insereInicio(save, s);
        escreveFicheiroBinario(save, TRUE);
    }
    while(!finish(tab, &s));
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

void carregaJogoBot(Save* save){
    Tabuleiro **tab = NULL;
    tab = carregaTabuleiro(tab, save);
    mostraTabuleiro(tab, NLIN, NCOL);

    Save s;
    s.jogada = save->jogada;
    int player;
    int option;
    char filename[50];

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
                        libertaListaLigada(save);
                        libertaTabuleiro(tab, NLIN);
                        return;
                }
            }
            while(!isFinished);
        } else {
            printf("Jogada: BOT\n");
            jogadaBot(tab, &s);
        }
        mostraTabuleiro(tab, NLIN, NCOL);
        save = insereInicio(save, s);
        escreveFicheiroBinario(save, FALSE);
    }
    while(!finish(tab, &s));
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
    libertaListaLigada(save);;
}

Tabuleiro** carregaTabuleiro(Tabuleiro **tab, Save *save){
    tab = inicializaTabuleiro(NLIN, NCOL);
    while(save != NULL){
        if(jogador(save->jogada) == 1){
            tab[conversorLinColTab(save->lin-1)][conversorLinColTab(save->col-1)].tab[conversorLinCol(save->lin-1)][conversorLinCol(save->col-1)] = 'O';
        } else {
            tab[conversorLinColTab(save->lin-1)][conversorLinColTab(save->col-1)].tab[conversorLinCol(save->lin-1)][conversorLinCol(save->col-1)] = 'X';
        }
        save = save->nextPlay;
    }
    return tab;
}

void deleteBinaryFile(){
    if(remove("save.bin") != 0){
        printf("Erro ao deletar o ficheiro\n");
    }
}