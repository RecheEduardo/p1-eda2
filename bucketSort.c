#include <stdio.h>
#include <stdlib.h>
#include "bucketSort.h"

#define NUM_BUCKETS 10  // Define o número de baldes
#define MAX_SIZE 10     // Define o tamanho do vetor de entrada

// Estrutura do balde
typedef struct {
    int *valor;  // Ponteiro para armazenar os valores do balde
    int tamanho;   // Quantidade de elementos armazenados no balde
} Balde;

// Função para organizar os itens do balde
void insertionSort(int *array, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = array[i];  // Chave = Elemento atual a ser ordenado
        int j = i - 1;

        // Move os elementos maiores que a Chave uma posição à frente
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave; // Insere o elemento na posição correta
    }
}

void bucketSort(int *vetor, int tamanho) {
    Balde balde[NUM_BUCKETS]; // Declara um array de baldes

    // Inicializa os baldes
    for (int i = 0; i < NUM_BUCKETS; i++) {
        balde[i].valor = (int *)malloc(MAX_SIZE * sizeof(int)); // Aloca memória para os valores
        balde[i].tamanho = 0; // Inicializa o tamanho do balde como zero
    }

    // Separa os elementos do vetor nos baldes apropriados
    for (int i = 0; i < tamanho; i++) {
        int indice = vetor[i] / NUM_BUCKETS; // Determina em qual balde o número pertence
        balde[indice].valor[balde[indice].tamanho++] = vetor[i]; // Adiciona o número ao balde
    }

    // Reconstruindo o vetor com os valores ordenados
    int index = 0; // Índice do vetor
    for (int i = 0; i < NUM_BUCKETS; i++) {
        insertionSort(balde[i].valor, balde[i].tamanho); // Ordena os elementos do balde
        for (int j = 0; j < balde[i].tamanho; j++) {
            vetor[index++] = balde[i].valor[j]; // Passa os elementos ordenados para o vetor original
        }
        free(balde[i].valor); // Libera a memória alocada para o valor do balde
    }
}

/*void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}*/
