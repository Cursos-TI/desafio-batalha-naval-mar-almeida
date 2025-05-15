#include <stdio.h>

int main(){

    int navio1[4] = {3, 3, 3, 3}; // horizontal
    int navio2[3] = {3, 3, 3}; // vertical
    char cabecalho[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro [10][10] = {
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

    for (int i = 0; i < 4; i++) // posicionamento horizontal navio1 no tabuleiro
    {
        tabuleiro[6][i + 1] = navio1[i];
        // linha[6] = 7a linha. Coluna[i+1] = coluna[1] (B) até coluna[4] (E).
    }

    for (int i = 0; i < 3; i++) // posicionamento vertical navio2 no tabuleiro
    {
        tabuleiro[i + 2][7] = navio2[i];
        // linha[i+2] = 3a linha [2] até 5a linha [4]. Coluna[7] = 8a coluna (H).
    }

    printf("*****BATALHA NAVAL NOVATO*****\n");
    printf("------------------------------\n");
    printf("    ");

    for (int i = 0; i < 10; i++)
    {
        printf("%c ", cabecalho[i]);
    }
    printf("\n");
    
    for ( int i = 0; i < 10; i++)
    {
        printf("%2d. ", i + 1);
        for ( int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    } 

  
    return 0;
}