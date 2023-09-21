#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);
	int j;
	
    for (j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);

        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}


void intercalar(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int esquerda_temp[n1], direita_temp[n2];

    for (i = 0; i < n1; i++) {
        esquerda_temp[i] = arr[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        direita_temp[j] = arr[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (esquerda_temp[i] <= direita_temp[j]) {
            arr[k] = esquerda_temp[i];
            i++;
        } else {
            arr[k] = direita_temp[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = esquerda_temp[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = direita_temp[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergesort(arr, esquerda, meio);
        mergesort(arr, meio + 1, direita);

        intercalar(arr, esquerda, meio, direita);
    }
}

int main() {
    int arr1[] = {3, 6, 8, 10, 1, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    mergesort(arr1, 0, n1 - 1);

    int arr2[] = {12, 4, 5, 6, 7, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    mergesort(arr2, 0, n2 - 1);

    printf("Array 1 ordenado: ");
    int i;
	for ( i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Array 2 ordenado: ");

    for (i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}


