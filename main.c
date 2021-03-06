
/*
 * Programa: main.c
 * Autores: Alvaro de Carvalho, Nívea Martins e Rafaella Busch
 * Data: 23/11/2018
 * Descrição: Esse programa implementa um jogo de campo minado no terminal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funcoes_print.c"

#define PERDEU 0
#define GANHOU 1

/* MACROS PARA UTILIZAR AS CORES */
#define C_VERMELHO        "\033[0;31m"
#define C_VERMELHO_BOLD   "\033[1;31m"
#define C_AZUL            "\033[0;34m"
#define C_AZUL_BOLD       "\033[1;34m"
#define C_CIANO           "\033[0;36m"
#define C_CIANO_BOLD      "\033[1;36m"
#define C_LARANJA         "\033[0;33m"
#define C_LARANJA_BOLD    "\033[1;33m"
#define C_VERDE           "\033[0;32m"
#define C_VERDE_BOLD      "\033[1;32m"
#define C_BRANCO_BOLD     "\033[1;38m"
#define RESTAURA          "\033[0m"

/* VARIAVEIS GLOBAIS */
int aberto = 1, normal = 0; /* status do campo na matriz */

char fechado[6] = "▇▇", vazio[2] = " ", bomba[3] = "**", bandeira[2] = "P"; /* strings usadas para preencher a matriz */

char string_numeros[9][2] = {" ", "1", "2", "3", "4", "5", "6", "7", "8"}; /* strings usadas para preencher a matriz */

/*prototipo das funções*/
void jogo (int linhas, int colunas, int qtd_minas);
void preencheBombas (char **matriz, int *status_matriz, int linhas, int colunas, int qtd_minas);
void limpa_stream ();
void escreve_numero (char **matriz, int linhas, int colunas, int qtd_minas);
void abre_vazios (char **matriz_interna, char **matriz_usuario, int *status_matriz, int linhas, int colunas, int *qtd_aberto, int i, int j);

int main(void) {
    int linhas, colunas, qtd_minas;
    int escolha_menu, tamanho_campo, escolha_recordes;
    char teste_entrada[10];

    /* RODA O MENU até que o usuário peça para sair */
    while (1) {
        system("@cls||clear"); /* limpa o terminal*/

        printTitulo();
        printMenu();

        printf("\n %sDigite o número da sua opção:%s ", C_BRANCO_BOLD, RESTAURA);

        while (1) {

            scanf("%s", teste_entrada);
            limpa_stream();

            if ((sscanf(teste_entrada, "%d", &escolha_menu)) == 1 && (escolha_menu == 1 || escolha_menu == 2 || escolha_menu == 3 || escolha_menu == 4 || escolha_menu == 5)) break;
            printf("\n Opção inválida. %sDigite novamente: %s", C_BRANCO_BOLD, RESTAURA);

        }


        /*OPCOES DE MENU*/
        switch (escolha_menu) {

            case 1: /*Escolha do tamanho do campo*/
                printf("\n %sSelecione o tamanho do campo:%s\n", C_BRANCO_BOLD, RESTAURA);
                printf(" 1- 8 x 8 (12 minas)\n");
                printf(" 2- 10 x 14 (24 minas)\n");
                printf(" 3- 16 x 20 (70 minas)\n");
                printf(" 4- Personalizado\n");
                printf("\n %sDigite o número da sua opção: %s", C_BRANCO_BOLD, RESTAURA);

                while (1) {
                    scanf("%s", teste_entrada);

                    limpa_stream();

                    if ((sscanf(teste_entrada, "%d", &tamanho_campo)) == 1 && (tamanho_campo == 1 || tamanho_campo == 2 || tamanho_campo == 3 || tamanho_campo == 4)) break;
                    printf("\n Opção inválida. %sPor favor, insira novamente:%s ", C_BRANCO_BOLD, RESTAURA);
                }

                switch (tamanho_campo) {

                    case 1: /*Campo pequeno*/
                        linhas = 8; colunas = 8; qtd_minas = 12;
                        break;

                    case 2: /*Campo medio*/
                        linhas = 10; colunas = 14; qtd_minas = 24;
                        break;

                    case 3: /*Campo grande*/
                        linhas = 16; colunas = 20; qtd_minas = 70;
                        break;

                    case 4: /*Campo Personalizado*/
                        printf("\n %sDigite a quantidade de linhas: %s", C_BRANCO_BOLD, RESTAURA);
                        while (1) {

                            scanf("%s", teste_entrada);

                            limpa_stream();

                            if ((sscanf(teste_entrada, "%d", &linhas)) == 1 && linhas > 1 && linhas < 50) break;
                            printf("\n Opção inválida. %sDigite um inteiro maior que 1 e menor que 50: %s", C_BRANCO_BOLD, RESTAURA);
                        }

                        printf("\n %sDigite a quantidade de colunas: %s", C_BRANCO_BOLD, RESTAURA);
                        while (1) {

                            scanf("%s", teste_entrada);

                            limpa_stream();

                            if ((sscanf(teste_entrada, "%d", &colunas)) == 1 && colunas > 1 && colunas < 50) break;
                            printf("\n Opção inválida. %sDigite um inteiro maior que 1 e menor que 50:%s ", C_BRANCO_BOLD, RESTAURA);
                        }

                        printf("\n %sDigite a quantidade de minas:%s ", C_BRANCO_BOLD, RESTAURA);
                        while (1) {

                            scanf("%s", teste_entrada);

                            limpa_stream();

                            if ((sscanf(teste_entrada, "%d", &qtd_minas)) == 1 && qtd_minas > 0 && qtd_minas < linhas * colunas ) break;
                            printf("\n Opção inválida. %sDigite um inteiro positivo menor que o total de campos:%s ", C_BRANCO_BOLD, RESTAURA);
                        }
                        break;

                } /* fim switch tamanho do campo */

                /* INICIA O JOGO */
                jogo(linhas, colunas, qtd_minas);

                break;

            case 2: /*RECORDE*/
                printf(" 1- Ver os recordes\n");
                printf(" 2- Apagar os recordes\n");
                printf("\n %sDigite o número da sua opção:%s ", C_BRANCO_BOLD, RESTAURA);

                while (1) {
                    scanf("%s", teste_entrada);

                    limpa_stream();

                    if ((sscanf(teste_entrada, "%d", &escolha_recordes)) == 1 && (escolha_recordes == 1 || escolha_recordes == 2)) break;
                    printf("\n Opção inválida. %sPor favor, insira novamente:%s ", C_BRANCO_BOLD, RESTAURA);
                }

                switch (escolha_recordes) {
                    case 1:
                        print_recorde();
                        break;
                    case 2:
                        apaga_recorde();
                        break;
                }

                break;

            case 3: /*Caso para apresentar as instruçoes do jogo ao usuario*/
                printInstrucoes();
                printf("\n Pressione qualquer tecla para voltar. ");
                limpa_stream();
                break;

            case 4: /*Caso para o jogador ver os creditos do jogo*/
                printf("\n %sCréditos:%s\n", C_AZUL_BOLD, RESTAURA);
                /*Exibe os autores para o usuário*/
                printf(" Alvaro de Carvalho DRE: 118183211\n");
                printf(" Nívea Martins DRE: 118149403\n");
                printf(" Rafaella Busch DRE: 118198999\n");
                printf("\n Pressione qualquer tecla para voltar. ");
                limpa_stream();
                break;

            case 5: /*Caso em que o jogador escolhe sair do jogo*/
                exit(1);
        }
    } /* Fim While Menu */

    return 0;
}/*FIM MAIN*/

void jogo(int linhas, int colunas, int qtd_minas){

    char **matriz_interna, **matriz_usuario;   /* DECLARA AS MATRIZES PARA INICIAR O JOGO */
    int *status_matriz;                        /* guarda se o campo já foi aberto ou está fechado */
    int i, j;                                  /* contadores do for */
    int status_jogo = 1;                       /* 1 - se ganhou, 0 - perdeu o jogo */
    int acao, x, y;                            /* ações do usuario e coordenadas digitadas */
    int qtd_aberto = qtd_minas;                /* guarda quantos campos estão abertos */
    char teste_entrada[10];                    /* usada pra testar a entrada de strings indesejadas */
    int escolha_fim;                           /* recebe a escolha do usuario ao terminar o jogo */
    time_t t_inicio;                           /* Variáveis de tempo */
    time_t t_fim;                              /* Variáveis de tempo */
    int tDecorrido;                            /* Variáveis de tempo */
    int t_min;                                 /* Variáveis de tempo */
    int t_sec;                                 /* Variáveis de tempo */


    matriz_interna = (char **) calloc( linhas * colunas, sizeof(char *));
    status_matriz = (int *) calloc( linhas * colunas, sizeof(int));
    matriz_usuario = (char **) calloc( linhas * colunas, sizeof(char *));

    if (!matriz_interna || !matriz_usuario || !status_matriz){
        printf("\n Erro de alocação. %sDigite algo para prosseguir.%s\n", C_BRANCO_BOLD, RESTAURA);
        limpa_stream();
        return;
    }

    /* preenche os primeiros valores da lista*/
    for (i=0; i < linhas; i++) {
        for (j=0; j < colunas; j++){
            *(status_matriz + i * colunas + j) = normal;
            *(matriz_interna + i * colunas + j) = vazio;
            *(matriz_usuario + i * colunas + j) = fechado;
        }
    }

    /* roda as funções para preencher as bombas e os numeros*/
    preencheBombas(matriz_interna, status_matriz, linhas, colunas, qtd_minas);
    escreve_numero(matriz_interna, linhas, colunas, qtd_minas);

    /* inicia a contagem do tempo */
    time(&t_inicio);

    /* começa a pedir as ações do usuário até que toda a matriz esteja aberta */
    while (qtd_aberto < linhas * colunas) {

        x = 0; y = 0;

        printMatriz(matriz_usuario, linhas, colunas, bandeira, bomba, fechado);

        /* recebe a acao que o usuário quer realizar durante o jogo */
        printf("\n%s AÇÕES:%s\n 1- Abrir Campo\n 2- Fixar Bandeira\n 3- Remover Bandeira\n 4- Voltar para o Menu\n", C_AZUL_BOLD, RESTAURA);
        printf("\n\n %sDigite a ação desejada:%s ", C_BRANCO_BOLD, RESTAURA);

        /* recebe a ação do usuario */
        while (1) {

            scanf("%s", teste_entrada);

            limpa_stream();

            if ((sscanf(teste_entrada, "%d", &acao)) == 1 && (acao == 1 || acao == 2 || acao == 3 || acao == 4)) break;
            printf("\n Valor inválido. %sDigite novamente: %s", C_BRANCO_BOLD, RESTAURA);
        }

        /* sai do jogo */
        if (acao == 4) {

            char resposta;

            printf("\n Tem certeza que quer sair? (S/N) ");
            while (1) {

                scanf("%c", &resposta);
                limpa_stream();

                if ( resposta == 'S' || resposta == 's' || resposta == 'N' || resposta == 'n') break;
                printf("\n Entrada inválida. %sDigite novamente:%s ", C_BRANCO_BOLD, RESTAURA);
            }

            if (resposta == 'S' || resposta == 's') {
                free(matriz_interna);
                free(matriz_usuario);
                free(status_matriz);
                return;
            } else continue;

        }

        printf("\n %sDigite \"0 0\" para cancelar.\n Digite as coordenadas do campo (x, y): %s", C_BRANCO_BOLD, RESTAURA);
        while (1) {

            scanf("%d %d", &x, &y);
            limpa_stream();

            if (x == 0 && y == 0) break;

            if (x >= 1 && x <= colunas && y >= 1 && y <= linhas) {
                if (*(status_matriz + (y-1) * colunas + x-1) == normal) break;
                else {
                    printf("\n %sO campo já está aberto. %sDigite outro: ", C_BRANCO_BOLD, RESTAURA);
                    continue;
                }
            }

            printf("\n Valor inválido. %sDigite novamente:%s ", C_BRANCO_BOLD, RESTAURA);
        }

        if (x == 0 && y == 0) continue;

        x--; y--; /*decrementa x e y para usar como indice da matriz*/

        /* entra aqui se o usuário quiser abrir um campo */
        if (acao == 1) {

            if (*(matriz_usuario + y * colunas + x) == bandeira) {
                char resposta_abre_bandeira;

                printf("\n %sHá uma bandeira fixada.%s Tem certeza que deseja abrir o campo? (S/N) ", C_BRANCO_BOLD, RESTAURA);

                while (1) {

                    scanf("%c", &resposta_abre_bandeira);
                    limpa_stream();

                    if ( resposta_abre_bandeira == 'S' || resposta_abre_bandeira == 's' || resposta_abre_bandeira == 'N' || resposta_abre_bandeira == 'n') break;
                    printf("\n Entrada inválida. %sDigite novamente: %s", C_BRANCO_BOLD, RESTAURA);
                }

                if (resposta_abre_bandeira == 'N' || resposta_abre_bandeira == 'n') continue;

            }

            /* caso o campo escolhido seja vazio, chama a função para abrir os adjacentes */
            if (!(strcmp(*(matriz_interna + y * colunas + x), " "))) abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, &qtd_aberto, y, x);

            /* QUANDO O USUARIO PERDE */
            else if (*(matriz_interna + y * colunas + x) == bomba) {
                status_jogo = PERDEU;
                break;
            }

            else {
                *(matriz_usuario + y * colunas + x) = *(matriz_interna + y * colunas + x);
                *(status_matriz + y * colunas + x) = aberto;
                qtd_aberto++;
            }

        } else if (acao == 2) {
            *(matriz_usuario + y * colunas + x) = bandeira;

        } else if (acao == 3) {
            if (*(matriz_usuario + y * colunas + x) == bandeira){
                *(matriz_usuario + y * colunas + x) = fechado;
            }
            else {
                printf("\n %sNão há bandeira aqui.%s\n Pressione qualquer tecla para prosseguir.", C_BRANCO_BOLD, RESTAURA);
                limpa_stream();
            }

        }


    } /*fim while ações*/

    /* calcula o tempo gasto no jogo em minutos e segundos */
    time(&t_fim);

    tDecorrido = (int) difftime(t_fim, t_inicio);

    t_sec = tDecorrido % 60;
    t_min = tDecorrido / 60;

    /* avalia o que o usuário deseja fazer após o fim do jogo */
    /* se ganhou */
    if(status_jogo == 1){
        char nome_usuario[40];

        /* fixa bandeiras onde tem bombas */
        for (i=0; i < linhas; i++) {
            for (j=0; j < colunas; j++) {
                if (*(matriz_interna + i * colunas + j) == bomba) *(matriz_usuario + i * colunas + j) = bandeira;
            }
        }

        printMatriz(matriz_usuario, linhas, colunas, bandeira, bomba, fechado);

        printf("\n Tempo gasto: %d min e %d seg\n", t_min, t_sec);

        printGanhou();

        /* recebe o nome do ganhador pra salvar nos recordes */
        printf(" %sDigite seu nome para gravar nos recordes: %s", C_BRANCO_BOLD, RESTAURA);
        scanf("%s", nome_usuario);
        limpa_stream();
        salva_recorde(nome_usuario, t_min, t_sec, qtd_minas, linhas, colunas);
    }

    /* se perdeu */
    if(status_jogo == 0){

        /* coloca todas as bombas visíveis para o usuário */
        for (i=0; i < linhas; i++) {
            for (j=0; j < colunas; j++) {
                if (*(matriz_interna + i * colunas + j) == bomba) *(matriz_usuario + i * colunas + j) = *(matriz_interna + i * colunas + j);
            }
        }

        printMatriz(matriz_usuario, linhas, colunas, bandeira, bomba, fechado);

        printf("\n Tempo gasto: %d min e %d seg\n", t_min, t_sec);

        printPerdeu();
    }

    free(matriz_interna);
    free(matriz_usuario);
    free(status_matriz);

    printf(" Deseja voltar para o menu?\n");
    /*Exibe as opções para o usuário*/
    printf(" 1. Sim\n");
    printf(" 2. Não, desejo sair do jogo.\n");

    while (1) {
        /*Pergunta ao usuário a opção escolhida */
        printf("\n %sDigite o número da sua opção:%s ", C_BRANCO_BOLD, RESTAURA);

        scanf("%s", teste_entrada);

        limpa_stream();

        if ((sscanf(teste_entrada, "%d", &escolha_fim)) == 1 && (escolha_fim == 1 || escolha_fim == 2)) break;
        printf(" \n Opção inválida.\n");
    }

    if (escolha_fim == 1) return; /*Encaminha o usuário para o menu*/

    else exit(1); /*Termina o programa*/

}

/*Função para definir a posição das bombas no jogo aleatoriamente*/
void preencheBombas (char **matriz, int *status_matriz, int linhas, int colunas, int qtd_minas) {
    int i;
    int pos_vertical;
    int pos_horizontal;

    srand(time(NULL));

    for (i=0; i < qtd_minas; i++) {
    /* sorteia as bombas e só aloca no campo se estiver vazio */
        do {
            pos_vertical = rand() % linhas;
            pos_horizontal = rand() % colunas;
        } while (*(matriz + pos_vertical * colunas + pos_horizontal)  == bomba);

        *(matriz + pos_vertical * colunas + pos_horizontal) = bomba;

    }

}

/* função para avaliar a quantidade de bombas ao redor do campo*/
void escreve_numero (char **matriz, int linhas, int colunas, int qtd_minas) {
    int contador = 0;
    int i, j;

    /*
    * A função atribui a todos os campos da matriz dada o número de bombas ao redor.
    * Ela começa procurando nos cantos, nas primeiras e ultimas linhas e colunas.
    * Isso pois deve-se ter cuidado com os campos adjacentes nesses casos.
    * Depois disso passa a percorrer todo o resto da matriz
    */

    /* matriz[0][0] */
    if (*matriz == vazio){
        if (*(matriz + 1) == bomba) contador++;
        if (*(matriz + colunas) == bomba) contador++;
        if (*(matriz + colunas + 1) == bomba) contador++;

        *matriz = string_numeros[contador];
    }
    contador = 0;

    /* matriz[0][-1] */
    if (*(matriz + colunas - 1) == vazio){
        if (*(matriz + colunas - 2) == bomba) contador++;
        if (*(matriz + 2 * colunas - 1) == bomba) contador++;
        if (*(matriz + 2 * colunas - 2) == bomba) contador++;

        *(matriz + colunas - 1) = string_numeros[contador];
    }
    contador = 0;

    /* matriz[-1][0] */
    if (*(matriz + (linhas - 1) * colunas) == vazio){
        if (*(matriz + (linhas - 2) * colunas) == bomba) contador++;
        if (*(matriz + (linhas - 2) * colunas + 1) == bomba) contador++;
        if (*(matriz + (linhas - 1) * colunas + 1) == bomba) contador++;

        *(matriz + (linhas - 1) * colunas) = string_numeros[contador];
    }
    contador = 0;

    /* matriz[-1][-1] */
    if (*(matriz + linhas * colunas - 1) == vazio){
        if (*(matriz + (linhas - 1) * colunas - 1) == bomba) contador++;
        if (*(matriz + (linhas - 1) * colunas - 2) == bomba) contador++;
        if (*(matriz + linhas * colunas - 2) == bomba) contador++;

        *(matriz + linhas * colunas - 1) = string_numeros[contador];
    }
    contador = 0;

    /* linha 0 */
    for (j = 1; j < colunas - 1; j++){
        if (*(matriz + j) == vazio){
            if (*(matriz + j - 1) == bomba) contador++;
            if (*(matriz + j + 1) == bomba) contador++;
            if (*(matriz + colunas + j) == bomba) contador++;
            if (*(matriz + colunas + j - 1) == bomba) contador++;
            if (*(matriz + colunas + j + 1) == bomba) contador++;

            *(matriz + j) = string_numeros[contador];
        }
        contador = 0;
    }

    /* linha -1 */
    for (j = 1; j < colunas - 1; j++){
        if (*(matriz + (linhas - 1) * colunas + j) == vazio){
            if (*(matriz + (linhas - 1) * colunas + j + 1) == bomba) contador++;
            if (*(matriz + (linhas - 1) * colunas + j - 1) == bomba) contador++;
            if (*(matriz + (linhas - 2) * colunas + j) == bomba) contador++;
            if (*(matriz + (linhas - 2) * colunas + j - 1) == bomba) contador++;
            if (*(matriz + (linhas - 2) * colunas + j + 1) == bomba) contador++;

            *(matriz + (linhas - 1) * colunas + j) = string_numeros[contador];
        }
        contador = 0;
    }

    /* coluna 0 */
    for (j = 2; j < linhas; j++){
        if (*(matriz + (linhas - j) * colunas) == vazio){
            if (*(matriz + (linhas - j) * colunas + 1) == bomba) contador++;
            if (*(matriz + (linhas - j - 1) * colunas) == bomba) contador++;
            if (*(matriz + (linhas - j - 1) * colunas + 1) == bomba) contador++;
            if (*(matriz + (linhas - j + 1) * colunas) == bomba) contador++;
            if (*(matriz + (linhas - j + 1) * colunas + 1) == bomba) contador++;

            *(matriz + (linhas - j) * colunas) = string_numeros[contador];
        }
        contador = 0;
    }

    /* coluna -1 */
    for (j = 2; j < linhas; j++){
        if (*(matriz + (linhas - j + 1) * colunas - 1) == vazio){
            if (*(matriz + (linhas - j + 1) * colunas - 2) == bomba) contador++;
            if (*(matriz + (linhas - j) * colunas - 1) == bomba) contador++;
            if (*(matriz + (linhas - j) * colunas - 2) == bomba) contador++;
            if (*(matriz + (linhas - j + 2) * colunas - 1) == bomba) contador++;
            if (*(matriz + (linhas - j + 2) * colunas - 2) == bomba) contador++;

            *(matriz + (linhas - j + 1) * colunas - 1) = string_numeros[contador];
        }
        contador = 0;
    }

    /* resto da matriz */
    for (i = 1; i < linhas - 1; i++){
        for (j = 1; j < colunas - 1; j++) {
            if (*(matriz + i * colunas + j) == vazio){
                if (*(matriz + i * colunas + j + 1) == bomba) contador++;
                if (*(matriz + i * colunas + j - 1) == bomba) contador++;
                if (*(matriz + (i - 1) * colunas + j) == bomba) contador++;
                if (*(matriz + (i - 1) * colunas + j + 1) == bomba) contador++;
                if (*(matriz + (i - 1) * colunas + j - 1) == bomba) contador++;
                if (*(matriz + (i + 1) * colunas + j) == bomba) contador++;
                if (*(matriz + (i + 1) * colunas + j + 1) == bomba) contador++;
                if (*(matriz + (i + 1) * colunas + j - 1) == bomba) contador++;

                *(matriz + i * colunas + j) = string_numeros[contador];
            }
            contador = 0;
        }
    }
}

/* função para abrir os espaços vazios que são vizinhos*/
void abre_vazios (char **matriz_interna, char **matriz_usuario, int *status_matriz, int linhas, int colunas, int *qtd_aberto, int i, int j) {

    /*
    * A função é iniciada com um campo e faz uma busca em todos os arredores até se deparar com numeros, bombas ou campos já abertos.
    * Há várias condições pois é necessário avaliar o local que o campo se encontra para verificar os arredores dele.
    */

    if (*(status_matriz + i * colunas + j) == aberto) return;

    /* condição de parada: o elemento dado ser um numero */
    else if (*(matriz_interna + i * colunas + j) != bomba && (strcmp(*(matriz_interna + i * colunas + j), " ")) && *(status_matriz + i * colunas + j) == normal) {
        *(matriz_usuario + i * colunas + j) = *(matriz_interna + i * colunas + j);
        *(status_matriz + i * colunas + j) = aberto;
        (*qtd_aberto)++;
        return;
    }

    /* a partir daqui chama a função recursivamente para abrir os campos */
    else if(!(strcmp(*(matriz_interna + i * colunas + j), " "))) {
        *(matriz_usuario + i * colunas + j) = *(matriz_interna + i * colunas + j);
        *(status_matriz + i * colunas + j) = aberto;
        (*qtd_aberto)++;

        /* matriz[0][0] */
        if (i == 0 && j == 0) {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j + 1);
        }

        /* matriz[-1][0] */
        else if (i == (linhas - 1) && j == 0) {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1 , j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1, j + 1);
        }

        /* matriz[0][-1] */
        else if (i == 0 && j == (colunas - 1)) {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1 , j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j - 1);
        }

        /* matriz[-1][-1] */
        else if (i == (linhas - 1) && j == (colunas - 1)) {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1 , j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1, j - 1);
        }

        /* linha 0 */
        else if (i == 0) {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j - 1);
        }

        /* linha -1 */
        else if (i == (linhas - 1)) {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1 , j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1, j + 1);
        }

        /* coluna -1 */
        else if (j == (colunas - 1)) {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1 , j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1 , j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1, j - 1);
        }

        /* coluna 0 */
        else if (j == 0) {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1 , j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j + 1);
        }

        else {
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1 , j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1, j - 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i - 1, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j + 1);
            abre_vazios(matriz_interna, matriz_usuario, status_matriz, linhas, colunas, qtd_aberto, i + 1, j - 1);
        }

    }

}
