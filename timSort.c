/*
Seminário TimSort:
    TimSort é um algoritmo de ordenação híbrido, que combina dois outros métodos de ordenação (MergeSort e InsertionSort) para organizar arrays
    de forma mais eficiente. Inicialmente criado para a linguagem Python, TimSort funciona dividindo um array em pequenas partes chamadas 'runs',
    ordenando cada uma delas com o InsertionSort. Após essa etapa, as partes são mescladas utilizando o MergeSort, garantindo um melhor desempenho
    para listas parcialmente ordenadas. O resultado final é um array ordenado de forma crescente.

    O seu processo ocorre em duas grandes fases:
        Ordenação das RUNS - Onde o array é divido entre pequenas listas menores, ou subArrays com tamanhos de cada RUN e ordenado individualmente usando InsertionSort.
        Mesclagem de RUNS - Os subArrays são combinados e ordenados proguessivamente, utilizando o método MergeSort, até que o array original se complete.

    Para seu funcionamento ideal, é necessário determinar o tamanho adequado das runs, o que depende da necessidade do problema.
    Esse método é ideal para arrays parcialmente ordenados, sendo estável e adaptativo. Ele é eficiente e escalável, tornando-se uma solução
    vantajosa em relação a outros algoritmos de ordenação, como o InsertionSort.
*/

// Import de bibliotecas necessárias para execução efetiva do código:
#include <stdio.h>
#include <stdlib.h>
#include "timSort.h"

#define RUN 32 // Definição do tamanho mínimo do bloco para o InsertionSort.

int min(int a, int b){ // Função para definir o mínimo de dois números
    if(a < b){ // Se a for menor que B, A é retornado.
        return a;
    } else { // Caso contrário, B é retornado.
        return b;
    }
}

/*
A função insertSort() implementa o algoritmo que divide o array em pequenos subarrays, ou seja, listas menores que
serão ordenadas em ordem crescente (do menor para o maior). Para que cada subarray possa ser analisado e ordenado,
é criado um looping que percorre os elementos da esquerda para a direita. Durante esse processo, um elemento temporário,
chamado de "chave", é utilizado para armazenar o valor do elemento atual do array. Ela é então comparada
com os elementos anteriores e, caso seja menor que algum deles, será deslocada para sua posição ideal na lista, garantindo a ordem correta.
*/
void insertSort(int array[], int esq, int dir) { // Função para inserir o método InsertionSort
    /* A função recebe como parâmetros um array e os valores esq (esquerda) e dir (direita),
    que definem os limites da ordenação dentro do array.*/
    for (int index = esq + 1; index <= dir; index++) { // Percorre os elementos do array dentro do intervalo especificado.
        // Se o elemento atual for menor que algum dos anteriores, será reposicionado corretamente.
        int chave = array[index]; // A chave armazena temporariamente o elemento atual do array.
        int x = index - 1; // x representa a posição do elemento anterior ao analisado.
        while (x >= esq && array[x] > chave) { // Compara a chave com os elementos anteriores e move os maiores para frente.
            array[x + 1] = array[x]; // Move o elemento maior para a posição seguinte.
            x--;
        }
        array[x + 1] = chave; // Insere a chave na posição correta dentro do subarray ordenado.
    }
}

/*
A função mergeSort() implementa o algoritmo que mescla dois subarrays ordenados dentro de um array principal.
Ela recebe um array e três índices: x (início do primeiro subarray), y (fim do primeiro subarray e início do segundo) e z (fim do segundo subarray).
Se copiasse os elementos para dois arrays auxiliares (esq e dir), depois os compara e mescla de volta ao array principal em ordem crescente.
*/
void mergeSort(int array[], int x, int y, int z) {
    /*Na linha abaixo, é definido o tamanho de cada SubArray, feito anteriormente no InsertionSort.*/
    int el1 = y - x + 1, el2 = z - y;
    int esq[el1], dir[el2]; // É definido também, os arrays auxiliares esquerda e direita que serão integrados para formar o array original.
    // Os elementos do array original são copiados para os arrays auxiliares, esq e dir.
    for (int i = 0; i < el1; i++) {
        esq[i] = array[x + i];
    }
    for (int i2 = 0; i2 < el2; i2++) {
        dir[i2] = array[y + 1 + i2];
    }
    int i = 0, i2 = 0, i3 = x; // Indicíes para auxiliar no percorrer de cada subArray.
    // Esta etapa combina os subArrays e ordena-os para formar o array original.
    while (i < el1 && i2 < el2) {
        if (esq[i] <= dir[i2]) {// Se o elemento da esquerda for menor ou igual ao da direita, adiciona ao array
            array[i3] = esq[i];
            i++;
        } else { // Caso contrário, adiciona o elemento da direita
            array[i3] = dir[i2];
            i2++;
        }
        i3++;
    }
     // Copia os elementos restantes de esq[] e da dir[].
    while (i < el1) {
        array[i3] = esq[i];
        i++;
        i3++;
    }
    while (i2 < el2) {
        array[i3] = dir[i2];
        i2++;
        i3++;
    }
}

void timSort(int array[], int n) { // Função que executa o método TimSort:
    for (int i = 0; i < n; i += RUN) { // Para cada array menor, didivido pelo mergeSort, será aplicado o insertSort (ordena-los de forma crescente)
        insertSort(array, i, min((i + RUN - 1), (n - 1)));
    }
    /*Após a ordenação de cada subArray, será aplicado novamente o mergeSort(), unindo cada pequena parte de array, antes quebrada
    para uma única forma, como foi enviada a função.

    No loop a seguir, é definido cada ARM como o tamanho total de cada RUN e assim, as runs ordenadas são combinadas usando MergeSort.
    O tamanho do bloco (arm) começa com o valor RUN e dobra a cada iteração,
    até que todo o array seja mesclado. */
    for (int arm = RUN; arm < n; arm = 2 * arm) { // Mescla os subarrays usando MergeSort
        for (int esq = 0; esq < n; esq += 2 * arm) { // Itera sobre as runs para mesclá-las
            int meio = esq + arm - 1; // Determina o meio do array atual
            int dir = min((esq + 2 * arm - 1), (n - 1)); // Determina o final do array atual
            if (meio < dir) { // Se existir uma run válida para mesclar, aplica MergeSort
                mergeSort(array, esq, meio, dir);
            }
        }
    }
}
