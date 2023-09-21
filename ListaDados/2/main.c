#include <stdio.h>

void insertionSort(int vetor[], int tamanho) {
    int i, j, chave;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] < chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    int vetor[] = {17, 8, 13, 5, 6}, i;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); 

    insertionSort(vetor, tamanho);

    printf("vetor em ordem decrescente: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}

