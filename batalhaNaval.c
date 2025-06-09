#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // Declaração do tabuleiro e inicialização com água (0 = água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 1;
    
     // Posiciona navio horizontal, se couber e não sobrepuser
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == VALOR_NAVIO) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = VALOR_NAVIO;
            }
        }
    }

     // Posiciona navio vertical, se couber e não sobrepuser
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode_posicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == VALOR_NAVIO) {
                pode_posicionar = 0;
                break;
            }
        }
        if (pode_posicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = VALOR_NAVIO;
            }
        }
    }

     // Imprime as letras das colunas (A a J)
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Imprime o tabuleiro com a numeração das linhas (1 a 10)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // Linha começa em 1
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
