#include "algoritmos.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <sys/time.h>
#include "aux_p1.h"

// BUBBLE SORT
void bubbleSortTeste(int *lista, int tamanho) {
    double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        bubbleSort(lista, tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    bubbleSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    bubbleSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// INSERTION SORT
void insertionSortTeste(int *lista, int tamanho) {
    double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
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

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    insertionSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    insertionSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// SELECTION SORT
void selectionSortTeste(int *lista, int tamanho){
    double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        selectionSort(lista, tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        /*pprintf("\nTempo Lista Aleatória %d / 10 = %fs\n", i + 1, tempo_LA);
        system("PAUSE");*/
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;
    /*printf("\nTempo Lista Aleatória (Média) = %f\n", tempo_medio);
    system("PAUSE");*/

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    selectionSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    /*printf("\nTempo Lista Crescente = %f\n", tempo_LC);
    system("PAUSE");*/
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    selectionSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    /*printf("\nTempo Lista Decrescente = %f\n", tempo_LD);
    system("PAUSE");*/

    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// COUNTING SORT
void countingSortTeste(int *lista, int tamanho) {
    double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
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

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    countingSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    countingSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// RADIX SORT
void radixSortTeste(int *lista, int tamanho) {
    double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
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

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    radixSort(lista, tamanho, 10);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    radixSort(lista, tamanho, 10);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// BUCKET SORT
void bucketSortTeste(int *lista, int tamanho) {
    double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        bucketSort(lista, tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    bucketSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    bucketSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// SHELL SORT
void shellSortTeste(int *lista, int tamanho) {
        double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
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

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    shellSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    shellSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// MERGE SORT;
void mergeSortTeste(int *lista, int tamanho) {
        double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
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

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    mergeSort(lista, 0,tamanho - 1);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    mergeSort(lista, 0,tamanho - 1);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// QUICK SORT
void quickSortTeste(int *lista, int tamanho){
    double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0; //tempo_LA = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        quickSort(lista, 0, tamanho - 1);
        gettimeofday(&tempo_fim, NULL);
        //tempo_LA = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        //    (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        //tempo_medio += tempo_LA;
        free(lista);
        printf("====");
    }
    //printf("]\n");
    tempo_medio = tempo_medio / 10;
    //printf("\nTempo Lista Aleatória (Média) = %fs\n", tempo_medio);
    //system("PAUSE");

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    quickSort(lista, 0, tamanho - 1);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    //printf("\nTempo Lista Crescente = %fs\n", tempo_LC);
    //system("PAUSE");
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    quickSort(lista, 0, tamanho - 1);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    //printf("\nTempo Lista Decrescente = %fs\n", tempo_LD);
    //system("PAUSE");

    free(lista);
    //printf("===]\n");
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}
// HEAP SORT
void heapSortTeste(int *lista, int tamanho) {
        double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        heapSortAscending(lista,tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    heapSortAscending(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    heapSortAscending(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}


// TIM SORT
void timSortTeste(int *lista, int tamanho) {
        double tempo_medio = 0, tempo_LC = 0, tempo_LD = 0;
    struct timeval tempo_inicio, tempo_fim;

    // CASO MÉDIO: LISTAS ALEATÓRIA
    printf("\n\n   [");
    for(int i = 0; i < 10; i++){
        lista = listaAleatoria(tamanho);
        gettimeofday(&tempo_inicio, NULL);
        timSort(lista,tamanho);
        gettimeofday(&tempo_fim, NULL);
        tempo_medio = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
            (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0) + tempo_medio;
        free(lista);
        printf("====");
    }
    tempo_medio = tempo_medio / 10;

    // CASO: LISTA CRESCENTE
    lista = listaCrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    timSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LC = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===");

    // CASO: LISTA DECRESCENTE
    lista = listaDecrescente(tamanho);
    gettimeofday(&tempo_inicio, NULL);
    timSort(lista, tamanho);
    gettimeofday(&tempo_fim, NULL);
    tempo_LD = (tempo_fim.tv_sec + tempo_fim.tv_usec/1000000.0) -
        (tempo_inicio.tv_sec + tempo_inicio.tv_usec/1000000.0);
    free(lista);
    printf("===]\n");

    resultadoTestes(tempo_medio, tempo_LC, tempo_LD, tamanho);
}

// FLUXO DOS TESTES
//  void nomeDoAlgoritmoTeste(int *lista, int tamanho){
//      1 - Teste com a lista aleatória (MÉDIA) (Testar 10 vezes)
//        { a - Cria a lista aleatória
//          b - Inicia o temporizador
//          c - Inicia a ordenação do vetor
//          d - Registra o tempo da ordenação e libera a lista com o Free } x10
//      2 - Feito os 10 testes da lista aleatória, tirar a média dos resultados e registra em uma variavel
//
//      3 - Agora faz o teste com a lista crescente (MELHOR CASO)
//          a - Cria a lista crescente
//          b - Inicia o temporizador
//          c - Inicia a ordenação do vetor
//          d - Registra o tempo da ordenação e libera a lista com o Free
//
//      4 - Agora faz o teste com a lista decrescente (PIOR CASO)
//          a - Cria a lista crescente
//          b - Inicia o temporizador
//          c - Inicia a ordenação do vetor
//          d - Registra o tempo da ordenação e libera a lista com o Free
//
//      5 - Chama uma rotina para imprimir o resultado dos 3 testes (Média, pior e melhor caso)
//  }

