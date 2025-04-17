#include <stdio.h>
#include <stdlib.h>
#include "shellSort.h"

// Insertion sort
void InsertionSort(int arr[], int tam){
    int i, j, atual;
    for(i = 0; i < tam; i++){
        atual = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > atual) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = atual;
    }
}


// Shell sort, uma variação do Insertion sort
void ShellSort(int arr[], int tam) {
    int intervalo, aux, i, j;
    for (intervalo = tam / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < tam; i++) {
            aux = arr[i];
            for (j = i; j >= intervalo && arr[j - intervalo] > aux; j -= intervalo) {
                arr[j] = arr[j - intervalo];
            }
            arr[j] = aux;
        }
    }
}
