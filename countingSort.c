#include "aux_p1.h"

void countingSort(int inputArray[], int numElementos) {
    // 1º Passo:
    // Encontrar o maior número no array
    int maiorNumero = 0;
    for (int i = 0; i < numElementos; i++){
        if (inputArray[i] > maiorNumero){
            maiorNumero = inputArray[i];
        }
    }

    // 2º Passo:
    // Inicializar um array auxiliar, sendo que
    // o tamanho dele será igual ao MAIOR NÚMERO
    // encontrado no array de input
    int* auxArray = (int*)calloc(maiorNumero + 1, sizeof(int));

    // 3º Passo:
    // Utilizaremos os índices do array auxiliar
    // para contabilizar a quantidade de aparições
    // de cada número no nosso array de input
    for (int i = 0; i < numElementos; i++){
        auxArray[inputArray[i]]++;
    }

    // 4º Passo:
    // Para cada index do array auxiliar
    // Calcularemos a soma acumulativa dos index anteriores
    // Ex: {0, 1, 4, 2, 0, 0, 1} -> {0, 1, 5, 7, 7, 7, 8}
    for (int i = 1; i <= maiorNumero; i++){
        auxArray[i] += auxArray[i - 1];
    }

    // 5º Passo:
    // Criamos o array de output, onde conterá os números ordenados
    // Percorremos o array de input de trás para frente, garantindo
    // que elementos iguais mantenham a ordem original (estabilidade).
    // Cada número é colocado na posição correta no array ordenado
    // e decrementamos o array auxiliar para os números que já foram processados
    int* arrayOrdenado = (int*)malloc(numElementos * sizeof(int));
    for (int i = numElementos - 1; i >= 0; i--){
        arrayOrdenado[auxArray[inputArray[i]] - 1] = inputArray[i];
        auxArray[inputArray[i]]--;
    }

    // 6º Passo:
    // Copiaremos os elementos do array ordenado para o array de input
    // Apenas faremos isso pois essa função não retorna um novo array,
    // E sim ordena no próprio array que foi passado.
    for (int i = 0; i < numElementos; i++){
        inputArray[i] = arrayOrdenado[i];
    }

    // Liberando a memória alocada
    free(auxArray);
    free(arrayOrdenado);
}
