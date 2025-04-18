#include "aux_p1.h"

void countingSort(int inputArray[], int numElementos) {
    // 1� Passo:
    // Encontrar o maior n�mero no array
    int maiorNumero = 0;
    for (int i = 0; i < numElementos; i++){
        if (inputArray[i] > maiorNumero){
            maiorNumero = inputArray[i];
        }
    }

    // 2� Passo:
    // Inicializar um array auxiliar, sendo que
    // o tamanho dele ser� igual ao MAIOR N�MERO
    // encontrado no array de input
    int* auxArray = (int*)calloc(maiorNumero + 1, sizeof(int));

    // 3� Passo:
    // Utilizaremos os �ndices do array auxiliar
    // para contabilizar a quantidade de apari��es
    // de cada n�mero no nosso array de input
    for (int i = 0; i < numElementos; i++){
        auxArray[inputArray[i]]++;
    }

    // 4� Passo:
    // Para cada index do array auxiliar
    // Calcularemos a soma acumulativa dos index anteriores
    // Ex: {0, 1, 4, 2, 0, 0, 1} -> {0, 1, 5, 7, 7, 7, 8}
    for (int i = 1; i <= maiorNumero; i++){
        auxArray[i] += auxArray[i - 1];
    }

    // 5� Passo:
    // Criamos o array de output, onde conter� os n�meros ordenados
    // Percorremos o array de input de tr�s para frente, garantindo
    // que elementos iguais mantenham a ordem original (estabilidade).
    // Cada n�mero � colocado na posi��o correta no array ordenado
    // e decrementamos o array auxiliar para os n�meros que j� foram processados
    int* arrayOrdenado = (int*)malloc(numElementos * sizeof(int));
    for (int i = numElementos - 1; i >= 0; i--){
        arrayOrdenado[auxArray[inputArray[i]] - 1] = inputArray[i];
        auxArray[inputArray[i]]--;
    }

    // 6� Passo:
    // Copiaremos os elementos do array ordenado para o array de input
    // Apenas faremos isso pois essa fun��o n�o retorna um novo array,
    // E sim ordena no pr�prio array que foi passado.
    for (int i = 0; i < numElementos; i++){
        inputArray[i] = arrayOrdenado[i];
    }

    // Liberando a mem�ria alocada
    free(auxArray);
    free(arrayOrdenado);
}
