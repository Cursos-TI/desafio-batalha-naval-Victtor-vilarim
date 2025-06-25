#include <stdio.h>

#define linhas 10
#define colunas 10

int main()
{
    int tabuleiro[linhas][colunas] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int cone[4][4] = {
        {5, 5, 5, 5},
        {5, 5, 5, 0},
        {5, 5, 0, 0},
        {5, 0, 0, 0}};

    int cruz[7][7] = {
        {0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 0},
        {7, 0, 7, 7, 7, 0, 7},
        {0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 0}};

    int losango[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0}};

    int barcoV[3] = {3, 3, 3};   // vertical
    int barcoH[3] = {3, 3, 3};   // horizontal
    int barcoD_1[3] = {3, 3, 3}; // diagonal
    int barcoD_2[3] = {3, 3, 3};
    // coordenadas para os barcos
    int x_Fixo = 1;
    int y_Fixo = 4;

    int x_Var = 3;
    int y_Var = 1;

    int x_diag1 = 0;
    int y_diag1 = 3;

    int x_diag2 = 9;
    int y_diag2 = 2;

    // posicionamento dos barcos
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[x_Fixo][y_Var] = barcoH[i];
        y_Var++;

        tabuleiro[x_Var][y_Fixo] = barcoV[i];
        x_Var++;

        tabuleiro[x_diag1][y_diag1] = barcoD_1[i];
        x_diag1++;
        y_diag1++;

        tabuleiro[x_diag2][y_diag2] = barcoD_2[i];
        x_diag2--;
        y_diag2--;
    }

    // Uso das habilidades especiais

    // coordenadas para habilidades
    int habilidade_x = 4;
    int habilidade_y = 3;

    // Qual habilidade será usada

    int decisao;
    printf("Qual habilidade você deseja usar?\n");
    printf("1. Cone\n");
    printf("2. cruz\n");
    printf("3. losango\n");
    printf("Sua escolha: ");
    scanf("%d", &decisao);

    // cone
    if (decisao == 1)
    {
        for (int j = 0; j < 4; j++)
        {
            habilidade_y = 3;

            for (int k = 0; k < 4; k++)
            {
                tabuleiro[habilidade_x][habilidade_y] = cone[j][k];
                habilidade_y++;
            }
            habilidade_x++;
        }
    }

    // cruz
    if (decisao == 2)
    {
        habilidade_x = 2;
        for (int j = 0; j < 7; j++)
        {
            habilidade_y = 1;

            for (int k = 0; k < 7; k++)
            {
                tabuleiro[habilidade_x][habilidade_y] = cruz[j][k];
                habilidade_y++;
            }
            habilidade_x++;
        }
    }

    // losango
    if (decisao == 3)
    {
        for (int j = 0; j < 4; j++)
        {
            habilidade_y = 3;

            for (int k = 0; k < 4; k++)
            {
                tabuleiro[habilidade_x][habilidade_y] = losango[j][k];
                habilidade_y++;
            }
            habilidade_x++;
        }
    }

    if (decisao > 3 || decisao <= 0)
    {
        printf("Poder inválido\n\n");
    }

    char colunas_L[colunas] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linhas_N[linhas] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // interface
    // impressão da letra de cada coluna
    int ind_y = 0;
    printf("    ");
    do
    {
        printf("%c ", colunas_L[ind_y]);
        ind_y++;
    } while (ind_y < colunas);

    for (int x = 0, ind_x = 0; x < linhas; x++, ind_x++)
    {
        printf("\n");
        // verificação do ind_x e impressão do número de cada linha
        if (ind_x == 9)
        {
            printf("%d. ", linhas_N[ind_x]);
        }
        else
        {
            printf("%d.  ", linhas_N[ind_x]);
        }
        // impressão do tabuleiro, ocorre após a verificação de ind_x
        int y = 0;
        while (y < colunas)
        {
            printf("%d ", tabuleiro[x][y]);
            y++;
        }
    }
    printf("\n\n");

    return 0;
}