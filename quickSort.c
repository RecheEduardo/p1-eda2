#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

// Função para trocar dois elementos no array
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição
int divisao(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Se o elemento for menor que o pivô
            i++; // Move o índice do menor elemento
            troca(&arr[i], &arr[j]); // Troca os elementos
        }
    }
    troca(&arr[i + 1], &arr[high]); // Coloca o pivô na posição correta
    return (i + 1); // Retorna o índice do pivô
}

// Implementação recursiva do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = divisao(arr, low, high); // Encontra o índice do pivô

        // Chama o QuickSort recursivamente para as duas metades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array
/*void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}*/
