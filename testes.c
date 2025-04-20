#include "algoritmos.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <sys/time.h>
#include "aux_p1.h"

// BUBBLE SORT
// a fazer............


// SELECTION SORT
void selectionSortTeste(unsigned long int *lista, unsigned long int tamanho){
    double tempo_medio = 0, tempo_melhor = 0, tempo_pior = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO M�DIO
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        selectionSort(lista, tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // MELHOR CASO
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    selectionSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_melhor = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");


    // PIOR CASO
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    selectionSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_pior = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_melhor, tempo_pior, tamanho);
}


// INSERTION SORT
void insertionSortTeste(unsigned long int *lista, unsigned long int tamanho) {
    double tempo_medio = 0, tempo_melhor = 0, tempo_pior = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO M�DIO
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        insertionSort(lista, tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // MELHOR CASO
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    insertionSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_melhor = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");


    // PIOR CASO
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    insertionSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_pior = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_melhor, tempo_pior, tamanho);
}


// COUNTING SORT
void countingSortTeste(unsigned long int *lista, unsigned long int tamanho) {
    double tempo_medio = 0, tempo_melhor = 0, tempo_pior = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO M�DIO
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        countingSort(lista, tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // MELHOR CASO
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    countingSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_melhor = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");


    // PIOR CASO
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    countingSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_pior = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_melhor, tempo_pior, tamanho);
}


// RADIX SORT
void radixSortTeste(unsigned long int *lista, unsigned long int tamanho) {
    double tempo_medio = 0, tempo_melhor = 0, tempo_pior = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO M�DIO
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        radixSort(lista, tamanho, 10);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // MELHOR CASO
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    radixSort(lista, tamanho, 10);
    gettimeofday(&tempo_fim, NULL);
    tempo_melhor = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");


    // PIOR CASO
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    radixSort(lista, tamanho, 10);
    gettimeofday(&tempo_fim, NULL);
    tempo_pior = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_melhor, tempo_pior, tamanho);
}


// BUCKET SORT


// SHELL SORT
void shellSortTeste(unsigned long int *lista, unsigned long int tamanho) {
        double tempo_medio = 0, tempo_melhor = 0, tempo_pior = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO M�DIO
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        shellSort(lista, tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // MELHOR CASO
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    shellSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_melhor = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");


    // PIOR CASO
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    shellSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_pior = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_melhor, tempo_pior, tamanho);
}

// MERGE SORT;
void mergeSortTeste(unsigned long int *lista, unsigned long int tamanho) {
        double tempo_medio = 0, tempo_melhor = 0, tempo_pior = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO M�DIO
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        mergeSort(lista, 0,tamanho - 1);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // MELHOR CASO
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    mergeSort(lista, 0,tamanho - 1);
    gettimeofday(&tempo_fim, NULL);
    tempo_melhor = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");


    // PIOR CASO
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    mergeSort(lista, 0,tamanho - 1);
    gettimeofday(&tempo_fim, NULL);
    tempo_pior = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_melhor, tempo_pior, tamanho);
}

// QUICK SORT


// HEAP SORT


// TIM SORT

