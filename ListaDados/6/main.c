#include <stdio.h>

int buscaSequencial(int matriz[][3], int linhas, int colunas, int valor, int *linha, int *col) {
    int i,j;
    
	for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                *linha = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int linhas = 5;
    int colunas = 3;
    int matriz[5][3] = {
        {4, 5, 7},
        {1, 2, 57},
        {31, 65, 22},
        {12, 54, 34},
        {15, 23, 87}
    };

    int valorProcurado;
    printf("Digite o valor a ser procurado na matriz: ");
    scanf("%d", &valorProcurado);

    int linhaEncontrada, colunaEncontrada;
    int encontrado = buscaSequencial(matriz, linhas, colunas, valorProcurado, &linhaEncontrada, &colunaEncontrada);

    if (encontrado) {
        printf("Valor encontrado na posicao (%d, %d)\n", linhaEncontrada, colunaEncontrada);
    } else {
        printf("Valor nao encontrado na matriz.\n");
    }

    return 0;
}

