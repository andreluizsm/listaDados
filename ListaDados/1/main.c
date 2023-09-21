#include <stdio.h>

void bubbleSort(int vet[], int tamanho) {
    int i, j, aux;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

int main() {
    int i, j, aux;

    int vet[5][3] = {{4, 5, 7}, {1, 2, 57}, {31, 65, 22}, {12, 54, 34}, {15, 23, 87}};

    int linhas = 5;
    int colunas = 3;
    int totalElements = linhas * colunas;

    int vetor[totalElements];
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            vetor[i * colunas + j] = vet[i][j];
        }
    }

    bubbleSort(vetor, totalElements);

    int index = 0;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            vet[i][j] = vetor[index++];
        }
    }

    printf("Matriz Ordenada:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", vet[i][j]);
        }
        printf("\n");
    }

    return 0;
}

