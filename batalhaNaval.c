#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5
#define TAMANHO_HABILIDADE 5

// Aplica uma habilidade em uma área do tabuleiro, modificando as posições de valor água (VALOR_AGUA) 
//para o valor da habilidade (VALOR_HABILIDADE),
// conforme a matriz de forma da habilidade (ex: cruz, cone, octaedro)
void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                        int origem_linha, int origem_coluna)
{
    int centro = TAMANHO_HABILIDADE / 2; // Define o centro da matriz da habilidade

    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (habilidade[i][j] == 1)
            { // Verifica se a célula faz parte da forma da habilidade
                int linha_tabuleiro = origem_linha - centro + i;
                int coluna_tabuleiro = origem_coluna - centro + j;

                // Garante que a posição calculada está dentro dos limites do tabuleiro
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO)
                {
                    // Se for água, aplica a habilidade (modifica para VALOR_HABILIDADE)
                    if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] == VALOR_AGUA)
                        tabuleiro[linha_tabuleiro][coluna_tabuleiro] = VALOR_HABILIDADE;
                }
            }
        }
    }
}

int main()
{
    // Declaração do tabuleiro e inicialização com água (0 = água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 1;

    int linha_diag_principal = 0;
    int coluna_diag_principal = 0;

    int linha_diag_secundaria = 0;
    int coluna_diag_secundaria = TAMANHO_TABULEIRO - 1;

    // Posiciona navio horizontal, se couber e não sobrepuser
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)
    {
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
        {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == VALOR_NAVIO)
            {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar)
        {
            for (int i = 0; i < TAMANHO_NAVIO; i++)
            {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = VALOR_NAVIO;
            }
        }
    }

    // Posiciona navio vertical, se couber e não sobrepuser
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)
    {
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
        {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == VALOR_NAVIO)
            {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar)
        {
            for (int i = 0; i < TAMANHO_NAVIO; i++)
            {
                tabuleiro[linha_vertical + i][coluna_vertical] = VALOR_NAVIO;
            }
        }
    }

    // Posiciona navio na diagonal principal (↘), se couber e não sobrepuser
    if (linha_diag_principal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        coluna_diag_principal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)
    {

        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
        {
            if (tabuleiro[linha_diag_principal + i][coluna_diag_principal + i] == VALOR_NAVIO)
            {
                pode_posicionar = 0;
                break;
            }
        }

        if (pode_posicionar)
        {
            for (int i = 0; i < TAMANHO_NAVIO; i++)
            {
                tabuleiro[linha_diag_principal + i][coluna_diag_principal + i] = VALOR_NAVIO;
            }
        }
    }

    // Posiciona navio na diagonal secundária (↙), se couber e não sobrepuser
    if (linha_diag_secundaria + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        coluna_diag_secundaria - (TAMANHO_NAVIO - 1) >= 0)
    {

        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++)
        {
            if (tabuleiro[linha_diag_secundaria + i][coluna_diag_secundaria - i] == VALOR_NAVIO)
            {
                pode_posicionar = 0;
                break;
            }
        }

        if (pode_posicionar)
        {
            for (int i = 0; i < TAMANHO_NAVIO; i++)
            {
                tabuleiro[linha_diag_secundaria + i][coluna_diag_secundaria - i] = VALOR_NAVIO;
            }
        }
    }

    // Imprime as letras das colunas (A a J)
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++)
    {
        printf("%c ", letra);
    }
    printf("\n");

    // Imprime o tabuleiro com a numeração das linhas (1 a 10)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("%2d ", i + 1); // Linha começa em 1
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
