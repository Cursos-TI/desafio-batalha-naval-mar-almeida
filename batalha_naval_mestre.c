#include <stdio.h>

#define LINHA 10
#define COLUNA 10

int main(){

    int navio1[3] = {3, 3, 3}; // horizontal
    int navio2[3] = {3, 3, 3}; // vertical
    int navio3[3] = {3, 3, 3}; // diagonal esquerda
    int navio4[3] = {3, 3, 3}; // diagonal direita

    char cabecalho[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // declarando cabecalho
    int tabuleiro[LINHA][COLUNA] = {0}; // declarando matriz 10 x 10 com valores '0'
    int cone[5][5] = {0}; // matriz 5x5 onde o cone é inserido
    int cruz[5][5] = {0}; // matriz 5x5 onde a cruz é inserida
    int octaedro[5][5] = {0}; // matriz 5x5 onde o octaedro é inserido
    int foundCone = 0; // foundCone = 1 identifica que algum navio colidiu com o Cone
    int foundCruz = 0; // foundCruz = 1 identifica que algum navio colidiu com a Cruz
    int foundOcta = 0; // foundOcta = 1 identifica que algum navio colidiu com o Octaedro

    // posicionamento dos navios no tabuleiro 10x10
    for (int i = 0; i < 3; i++) // posicionamento horizontal navio1 no tabuleiro
    {
        tabuleiro[7][i + 1] = navio1[i];
        //linha[7] = 8a linha. Coluna[i+1] = coluna[1] a coluna[3] (B a D).
    }

    for (int i = 0; i < 3; i++) // posicionamento vertical navio2 no tabuleiro
    {
        tabuleiro[i][8] = navio2[i];
        //linha[i] = linha[0] a linha[2] (1. até 3.) / Coluna[8] = 9a coluna (I).
    }

    for (int i = 0; i < 3; i++) // posicionamento diagonal principal (esquerda) navio3 no tabuleiro
    {
        tabuleiro[i + 2][i + 2] = navio3[i];
        //linha[2+i] = linha[2] até linha[4] / Coluna[i+2] = coluna[2] (C) até coluna[4] (E).
    }

    for (int i = 0; i < 3; i++) // posicionamento diagonal qualquer (direita) navio4 no tabuleiro
    {
        tabuleiro[i + 6][8 - i] = navio4[i];
        // linha[i+6] = linha[6] até linha[8] / Coluna[8-i] = coluna[8] (I) até coluna[6] (G).
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            //if ((j >= 3 - i) && (j <= 1 + i) && (i >= 1) && (i <= 3)) // funciona, cone centralizado.
            //if ((j >= 4 - i) && (j <= i)) // funciona, cone nao centralizado. 
            if ((j >= 2 - i) && (j <= 2 + i) && (i < 3)) // cone do desafio.
            {
                if (tabuleiro[i + 6][j] == 3) // procura pelo valor 3 (navios) dentro da condicional
                {
                   tabuleiro[i + 6][j] = 5; // atribui valor 5 se há intersecção (dano)
                   foundCone = 1; // pode usar outro if fora das condicionais para !foundCone
                } else {
                    cone[i][j] = 1; // cone formado de numeros '1'
                    tabuleiro[i + 6][j] = cone[i][j];
                }
            }
        }
        
    }
   
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((j == 2) || (i == 2)) // associa na condição coluna = 2 OU na linha = 2
            {
                if (tabuleiro[i + 4][j + 5] == 3) // procura pelo valor 3 (navios) dentro da condicional
                {
                    tabuleiro[i + 4][j + 5] = 5; // atribui valor 5 se há intersecção (dano)
                    foundCruz = 1; // pode usar outro if fora das condicionais para !foundCruz
                } else {
                    cruz[i][j] = 1; // cruz formada de numeros '1'
                    tabuleiro[i + 4][j + 5] = cruz[i][j];
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            /* if (((j == 2) || (i == 2)) || ((j == 1 && i == 1) || (j == 1 && i == 3) ||
            (j == 3 && i == 1) || (j == 3 && i == 3))) Também fuciona */
            if (((j >= 2 - i) && (j <= 2 + i)) && ((j >= i - 2) && (j <= 6 - i)))
            // ((Triangulo superior) && (Triangulo inferior))
            {
                if (tabuleiro[i][j + 1] == 3) // procura pelo valor 3 (navios) dentro da condicional
                {
                    tabuleiro[i][j + 1] = 5; // atribui valor 5 se há intersecção (dano)
                    foundOcta = 1; // pode usar outro if fora das condicionais para !foundOcta
                } else {
                    octaedro[i][j] = 1; // octaedro formado de numeros '1'
                    tabuleiro[i][j + 1] = octaedro[i][j];
                }
            }
        }
    }

    printf("*****BATALHA NAVAL MESTRE*****\n");
    printf("------------------------------\n");
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