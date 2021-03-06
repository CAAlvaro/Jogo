/*
 * Programa: funcoes_print.c
 * Autores: Alvaro de Carvalho, Nívea Martins e Rafaella Busch
 * Data: 23/11/2018
 * Descrição: Esse programa reune as funções secundárias.
*/

#include <stdio.h>
#include <stdlib.h>

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

/*Essa função é resposável por exibir o título.*/
void printTitulo(void){
    printf("\n");
    printf  ("%s / %s$$$$$$                                                   %s/ %s$$      %s/%s$$ %s/%s$$                           %s/%s$$ %s\n", C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, RESTAURA);

    printf ("%s/ %s$$ %s__ %s$$                                                  %s| %s$$$    %s/%s$$$ %s|__/                          |%s$$%s\n", C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, RESTAURA);

    printf("%s|%s $$%s  \\__/  /%s$$$$$$%s  /%s$$$$$$%s/%s$$$$%s   /%s$$$$$$%s   /%s$$$$$$%s       | %s$$$$%s  /%s$$$$%s/ %s$$%s/ %s$$$$$$$%s  / %s$$$$$$%s  / %s$$$$$$$%s / %s$$$$$$%s\n", C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, RESTAURA);

    printf("%s| %s$$       %s|____  %s$$%s| %s$$%s_  %s$$%s_  %s$$ %s/%s$$%s__  %s$$ %s/%s$$%s__  %s$$      %s| %s$$ %s$$%s/%s$$ $$%s| %s$$%s| %s$$%s__  %s$$ %s|____  %s$$%s/ %s$$%s__  %s$$%s/ %s$$%s__  %s$$%s\n", C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD,C_VERMELHO, C_CIANO_BOLD,C_VERMELHO, C_CIANO_BOLD,C_VERMELHO, C_CIANO_BOLD,C_VERMELHO, C_CIANO_BOLD,C_VERMELHO, C_CIANO_BOLD,C_VERMELHO, C_CIANO_BOLD,C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, RESTAURA);

    printf("%s| %s$$%s        /%s$$$$$$$%s| %s$$%s \\ %s$$%s \\ %s$$%s| %s$$%s  \\ %s$$%s| %s$$%s  \\ %s$$%s      | %s$$  $$$%s| %s$$%s| %s$$%s| %s$$%s  \\ %s$$%s  /%s$$$$$$$%s| %s$$%s  | %s$$%s| %s$$%s  \\ %s$$%s\n", C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO,  C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, RESTAURA);

    printf("%s| %s$$    $$ %s/%s$$%s__  %s$$%s| %s$$%s | %s$$%s | %s$$%s| %s$$%s  | %s$$%s| %s$$ %s | %s$$%s      | %s$$%s\\  %s$ %s| %s$$%s| %s$$%s| %s$$%s  | %s$$%s /%s$$%s__ %s $$%s| %s$$%s  |%s $$%s| %s$$%s  |%s $$%s\n", C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, RESTAURA);

    printf("%s|  %s$$$$$$%s/|  %s$$$$$$$%s| %s$$ %s| %s$$ %s| %s$$%s| %s$$$$$$$%s/|  %s$$$$$$%s/      | %s$$ %s\\/  | %s$$%s| %s$$%s| %s$$  %s| %s$$%s | %s$$$$$$$%s|  %s$$$$$$$%s|  %s$$$$$$%s/%s\n", C_VERMELHO, C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO,C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, RESTAURA);

    printf("%s \\______/  \\_______/|__/ |__/ |__/| %s$$%s____/  \\______/       |__/     |__/|__/|__/  |__/ \\_______/ \\_______/ \\______/%s\n", C_VERMELHO, C_CIANO_BOLD, C_VERMELHO, RESTAURA);

    printf("                                  %s| %s$$%s                                                                               \n", C_VERMELHO,  C_CIANO_BOLD, RESTAURA);

    printf("                                  %s| %s$$ %s                                                                              \n", C_VERMELHO, C_CIANO_BOLD, RESTAURA);

    printf("                                  %s|__/%s    \n", C_VERMELHO, RESTAURA);



}

/*Essa função é resposável por exibir as intruções.*/
void printInstrucoes(void) {
    printf("\n %sINSTRUÇÕES%s\n", C_AZUL_BOLD, RESTAURA);
    /*Exibe o modo de uso para o usuário*/
    printf(" %s1.%s Escolha o tamanho do seu tabuleiro, indicando qual o número da opção desejada.\n", C_BRANCO_BOLD, RESTAURA);
    printf(" %s2.%s Em jogo, selecione 1 para abrir algum campo, 2 para usar alguma bandeira e 3 para retirar a bandeira. \n", C_BRANCO_BOLD, RESTAURA);
    printf(" %s3.%s Para passar a coordenada do campo, primeiro coloque o número da horizontal (x), depois o da vertical (y). Ex: \"4 2\"\n", C_BRANCO_BOLD, RESTAURA);
    printf(" %s4.%s Fixe bandeiras onde você acha que há bombas. \n", C_BRANCO_BOLD, RESTAURA);
    printf(" %s5.%s Os números representam a quantidade de bombas ao redor do campo.\n", C_BRANCO_BOLD, RESTAURA);
    printf(" %sBom jogo :)%s \n", C_CIANO_BOLD, RESTAURA);
}

/*Essa função é resposável por exibir o menu.*/
void printMenu(void) {
    printf("\n\n\n\n");
    printf("%s MENU %s\n", C_AZUL_BOLD, RESTAURA);
    /*Exibe as opções para o usuário*/
    printf(" 1. %sJogar%s\n", C_BRANCO_BOLD, RESTAURA);
    printf(" 2. %sRecordes%s\n", C_BRANCO_BOLD, RESTAURA);
    printf(" 3. %sInstruções%s\n", C_BRANCO_BOLD, RESTAURA);
    printf(" 4. %sCréditos%s\n", C_BRANCO_BOLD, RESTAURA);
    printf(" 5. %sSair do jogo%s\n", C_BRANCO_BOLD, RESTAURA);
}

/*Essa função aparece quando o jogador perde, ela pergunta se ele deseja fechar o jogo ou reiniciá-lo*/
void printPerdeu(void) {

    printf("\n\n VOCÊ PERDEU!!! :( \n\n");

    printf("        %s`\\`|'/.%s\n", C_LARANJA, RESTAURA);
    printf("         %s`\\ /.%s\n", C_LARANJA, RESTAURA);
    printf("%s ▄█████████████▄▄▄   █▄▄▄▄█%s\n", C_LARANJA, RESTAURA);
    printf("%s ████▌ ▄▌ ▄ ▐ ▐▌ ██▌ ▀▀██▀▀%s\n",C_LARANJA, RESTAURA);
    printf("%s ██▄█▌ ▄▌ ▄ ▐ ▐▌ ▀██▄▄▄██%s\n", C_LARANJA, RESTAURA);
    printf("%s ▄▄▄▄▄██████████████▀%s\n\n\n", C_LARANJA, RESTAURA);

}

/*Essa função aparece quando o jogador ganha, grava o recorde e pergunta se o jogador deseja jogar novamente.*/
void printGanhou(void) {

    printf("\n %sPARABÉNS!!!%s VOCÊ GANHOU!!! :)%s\n\n", C_VERDE_BOLD, C_CIANO_BOLD, RESTAURA);

    printf("      +%s.\\`\\`|'\\|%s+%s/.|.%s+\n", C_LARANJA_BOLD, RESTAURA, C_LARANJA_BOLD, RESTAURA);
    printf("      %s\\%s+%s`\\ /. `\\%s+%s/. /. %s\n", C_LARANJA_BOLD, RESTAURA, C_LARANJA_BOLD, RESTAURA, C_LARANJA_BOLD, RESTAURA);
    printf("       %s██████████████%s\n", C_LARANJA_BOLD, RESTAURA);
    printf("     %s▄▄██%s█%s███████████▄▄%s\n", C_LARANJA_BOLD, RESTAURA, C_LARANJA_BOLD, RESTAURA);
    printf("     %s█ ██%s██%s██████████ █%s\n", C_LARANJA_BOLD, RESTAURA, C_LARANJA_BOLD, RESTAURA);
    printf("     %s█▄██████████████▄█%s\n", C_LARANJA_BOLD, RESTAURA);
    printf("         %s██████████%s\n", C_LARANJA_BOLD, RESTAURA);
    printf("          %s████████%s\n", C_LARANJA_BOLD, RESTAURA);
    printf("            %s████%s\n", C_LARANJA_BOLD, RESTAURA);
    printf("            %s████%s\n", C_LARANJA_BOLD, RESTAURA);
    printf("            %s████%s\n", C_LARANJA_BOLD, RESTAURA);
    printf("        %s▄██████████▄%s\n\n", C_LARANJA_BOLD, RESTAURA);


}

/*Essa função é responsável por exibir a matriz*/
void printMatriz(char **matriz, int linhas, int colunas, char *bandeira, char *bomba, char *fechado) {
    int j;
    int i;

    system("@cls||clear"); /*limpa o terminal*/

    printTitulo();

    printf("\n%3c ", ' ');

    for (j=0; j < colunas; j++) printf("\t%s%2d%s", C_CIANO_BOLD, j + 1, RESTAURA); /* printa os numeros das colunas */

    for (i=0; i < linhas; i++) {

        printf("\n\n%s%3d%s", C_CIANO_BOLD, i + 1, RESTAURA); /* printa os números das linhas */

        /* printa os elementos da matriz */
        for (j=0; j < colunas; j++) {
            if (*(matriz + i * colunas + j) == bandeira) printf("\t%s%s%s", C_AZUL_BOLD, *(matriz + i * colunas + j), RESTAURA);
            else if (*(matriz + i * colunas + j) == bomba) printf("\t%s%s%s", C_VERMELHO_BOLD, *(matriz + i * colunas + j), RESTAURA);
            else if (*(matriz + i * colunas + j) != fechado) printf("\t%s%s%s", C_VERDE_BOLD, *(matriz + i * colunas + j), RESTAURA);
            else printf("\t%s", *(matriz + i * colunas + j));
        }

    }

    printf("\n\n");
}

void salva_recorde(char *nome, int tempo_min, int tempo_sec, int qtd_minas, int linhas, int colunas) {
    FILE *recorde;

    recorde = fopen("recordes.txt", "a");

    if (!recorde) {
        printf("\n Não foi possível abrir o arquivo.\n");
        return;
    }

    fprintf(recorde, "%s: %d min e %d seg no campo %d x %d com %d mina(s).\n\n", nome, tempo_min, tempo_sec, linhas, colunas, qtd_minas);

    fclose(recorde);

}

/* codigo para remover caracteres desnecessários e evitar problemas com a scanf*/
void limpa_stream(){
    while (getchar() != '\n');
}

void print_recorde() {
    FILE *recorde;
    char linha[60];

    recorde = fopen("recordes.txt", "r");

    if (!recorde) {
        printf(" O arquivo não existe. Ganhe alguma partida para entrar para a lista.\n");
        printf("\n\n Pressione qualquer tecla para voltar. ");
        limpa_stream();
        return;
    }

    printf("\n");

    while (!feof(recorde)) {
        fgets(linha, 60, recorde);

        printf(" %s", linha);

    }

    printf("\n\n Pressione qualquer tecla para voltar. ");
    limpa_stream();

    fclose(recorde);

}

void apaga_recorde() {
    FILE *recorde;

    recorde = fopen("recordes.txt", "w");

    if (!recorde) {
        printf(" Erro ao criar o arquivo.\n");
        printf("\n\n Pressione qualquer tecla para voltar. ");
        limpa_stream();
        return;
    }

    fclose(recorde);
}
