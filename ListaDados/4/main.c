#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
	int j;
	
    for (j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int rows = 5;
    int cols = 3;
    int matrix[5][3] = {
        {4, 5, 7},
        {1, 2, 57},
        {31, 65, 22},
        {12, 54, 34},
        {15, 23, 87}
    };

    int totalElements = rows * cols;
    int flatArray[totalElements];
	int i, j;
    int index = 0;
    
    for ( i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            flatArray[index++] = matrix[i][j];
        }
    }

    quickSort(flatArray, 0, totalElements - 1);

    index = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = flatArray[index++];
        }
    }

    printf("Matriz Ordenada:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

