#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

// Fun��o para trocar dois elementos no array
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o de parti��o
int divisao(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolhe o �ltimo elemento como piv�
    int i = (low - 1); // �ndice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Se o elemento for menor que o piv�
            i++; // Move o �ndice do menor elemento
            troca(&arr[i], &arr[j]); // Troca os elementos
        }
    }
    troca(&arr[i + 1], &arr[high]); // Coloca o piv� na posi��o correta
    return (i + 1); // Retorna o �ndice do piv�
}

// Implementa��o recursiva do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = divisao(arr, low, high); // Encontra o �ndice do piv�

        // Chama o QuickSort recursivamente para as duas metades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fun��o para imprimir o array
/*void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}*/
