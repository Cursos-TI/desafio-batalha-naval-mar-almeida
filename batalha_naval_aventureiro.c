#include <stdio.h>

int main(){

    int navio1[3] = {3, 3, 3}; // horizontal
    int navio2[3] = {3, 3, 3}; // vertical
    int navio3[3] = {3, 3, 3}; // diagonal esquerda
    int navio4[3] = {3, 3, 3}; // diagonal direita

    char cabecalho[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // declarando cabecalho
    int tabuleiro [10][10] = { // declarando matriz 10 x 10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for (int i = 0; i < 3; i++) // posicionamento horizontal navio1 no tabuleiro
    {
        tabuleiro[7][i + 1] = navio1[i];
        // linha[7] = 8a linha. Coluna[i+1] = coluna[1] a coluna[3] (B a D).
    }

    for (int i = 0; i < 3; i++) // posicionamento vertical navio2 no tabuleiro
    {
        tabuleiro[i + 1][7] = navio2[i];
        // linha[i+1] = linha[1] a linha[3] (2. até 4.) / Coluna[7] = 8a coluna (H).
    }

    for (int i = 0; i < 3; i++) // posicionamento diagonal principal navio3 no tabuleiro
    {
        tabuleiro[i + 2][i + 2] = navio3[i];
        // linha[2+i] = linha[2] até linha[4] / Coluna[i+2] = coluna[2] (C) até coluna[4] (E).
    }

    for (int i = 0; i < 3; i++) // posicionamento diagonal direita qualquer navio4 no tabuleiro
    {
        tabuleiro[i + 6][8 - i] = navio4[i];
        // linha[i+6] = linha[6] até linha[8] / Coluna[8-i] = coluna[8] (I) até coluna[6] (G).
    }

    printf("*****BATALHA NAVAL AVENTUREIRO*****\n");
    printf("-----------------------------------\n");
    printf("    "); // espaços para alinhar com o cabeçalho

    for (int i = 0; i < 10; i++) // loop para impressao do array do cabecalho
    {
        printf("%c ", cabecalho[i]);
    }
    printf("\n");
    
    for ( int i = 0; i < 10; i++) // loop externo. impressao tabuleiro
    {
        printf("%2d. ", i + 1); // imprime os numeros das linhas no canto esquerdo(1.,2.,3.,4.,..)
        // 2 no "%d reserva espaço de dois caracteres"
        for ( int j = 0; j < 10; j++) // loop interno para impressao dos elementos de cada linha
        // 'j' é executado 10x (j de 0 a 9) para cada ciclo de 'i'
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // pula para a linha seguinte apos o ciclo do loop interno
    } 

  
    return 0;
}