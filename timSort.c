/*
Semin�rio TimSort:
    TimSort � um algoritmo de ordena��o h�brido, que combina dois outros m�todos de ordena��o (MergeSort e InsertionSort) para organizar arrays
    de forma mais eficiente. Inicialmente criado para a linguagem Python, TimSort funciona dividindo um array em pequenas partes chamadas 'runs',
    ordenando cada uma delas com o InsertionSort. Ap�s essa etapa, as partes s�o mescladas utilizando o MergeSort, garantindo um melhor desempenho
    para listas parcialmente ordenadas. O resultado final � um array ordenado de forma crescente.

    O seu processo ocorre em duas grandes fases:
        Ordena��o das RUNS - Onde o array � divido entre pequenas listas menores, ou subArrays com tamanhos de cada RUN e ordenado individualmente usando InsertionSort.
        Mesclagem de RUNS - Os subArrays s�o combinados e ordenados proguessivamente, utilizando o m�todo MergeSort, at� que o array original se complete.

    Para seu funcionamento ideal, � necess�rio determinar o tamanho adequado das runs, o que depende da necessidade do problema.
    Esse m�todo � ideal para arrays parcialmente ordenados, sendo est�vel e adaptativo. Ele � eficiente e escal�vel, tornando-se uma solu��o
    vantajosa em rela��o a outros algoritmos de ordena��o, como o InsertionSort.
*/

// Import de bibliotecas necess�rias para execu��o efetiva do c�digo:
#include <stdio.h>
#include <stdlib.h>
#include "timSort.h"

#define RUN 32 // Defini��o do tamanho m�nimo do bloco para o InsertionSort.

int min(int a, int b){ // Fun��o para definir o m�nimo de dois n�meros
    if(a < b){ // Se a for menor que B, A � retornado.
        return a;
    } else { // Caso contr�rio, B � retornado.
        return b;
    }
}

/*
A fun��o insertSort() implementa o algoritmo que divide o array em pequenos subarrays, ou seja, listas menores que
ser�o ordenadas em ordem crescente (do menor para o maior). Para que cada subarray possa ser analisado e ordenado,
� criado um looping que percorre os elementos da esquerda para a direita. Durante esse processo, um elemento tempor�rio,
chamado de "chave", � utilizado para armazenar o valor do elemento atual do array. Ela � ent�o comparada
com os elementos anteriores e, caso seja menor que algum deles, ser� deslocada para sua posi��o ideal na lista, garantindo a ordem correta.
*/
void insertSort(int array[], int esq, int dir) { // Fun��o para inserir o m�todo InsertionSort
    /* A fun��o recebe como par�metros um array e os valores esq (esquerda) e dir (direita),
    que definem os limites da ordena��o dentro do array.*/
    for (int index = esq + 1; index <= dir; index++) { // Percorre os elementos do array dentro do intervalo especificado.
        // Se o elemento atual for menor que algum dos anteriores, ser� reposicionado corretamente.
        int chave = array[index]; // A chave armazena temporariamente o elemento atual do array.
        int x = index - 1; // x representa a posi��o do elemento anterior ao analisado.
        while (x >= esq && array[x] > chave) { // Compara a chave com os elementos anteriores e move os maiores para frente.
            array[x + 1] = array[x]; // Move o elemento maior para a posi��o seguinte.
            x--;
        }
        array[x + 1] = chave; // Insere a chave na posi��o correta dentro do subarray ordenado.
    }
}

/*
A fun��o mergeSort() implementa o algoritmo que mescla dois subarrays ordenados dentro de um array principal.
Ela recebe um array e tr�s �ndices: x (in�cio do primeiro subarray), y (fim do primeiro subarray e in�cio do segundo) e z (fim do segundo subarray).
Se copiasse os elementos para dois arrays auxiliares (esq e dir), depois os compara e mescla de volta ao array principal em ordem crescente.
*/
void mergeSort(int array[], int x, int y, int z) {
    /*Na linha abaixo, � definido o tamanho de cada SubArray, feito anteriormente no InsertionSort.*/
    int el1 = y - x + 1, el2 = z - y;
    int esq[el1], dir[el2]; // � definido tamb�m, os arrays auxiliares esquerda e direita que ser�o integrados para formar o array original.
    // Os elementos do array original s�o copiados para os arrays auxiliares, esq e dir.
    for (int i = 0; i < el1; i++) {
        esq[i] = array[x + i];
    }
    for (int i2 = 0; i2 < el2; i2++) {
        dir[i2] = array[y + 1 + i2];
    }
    int i = 0, i2 = 0, i3 = x; // Indic�es para auxiliar no percorrer de cada subArray.
    // Esta etapa combina os subArrays e ordena-os para formar o array original.
    while (i < el1 && i2 < el2) {
        if (esq[i] <= dir[i2]) {// Se o elemento da esquerda for menor ou igual ao da direita, adiciona ao array
            array[i3] = esq[i];
            i++;
        } else { // Caso contr�rio, adiciona o elemento da direita
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

void timSort(int array[], int n) { // Fun��o que executa o m�todo TimSort:
    for (int i = 0; i < n; i += RUN) { // Para cada array menor, didivido pelo mergeSort, ser� aplicado o insertSort (ordena-los de forma crescente)
        insertSort(array, i, min((i + RUN - 1), (n - 1)));
    }
    /*Ap�s a ordena��o de cada subArray, ser� aplicado novamente o mergeSort(), unindo cada pequena parte de array, antes quebrada
    para uma �nica forma, como foi enviada a fun��o.

    No loop a seguir, � definido cada ARM como o tamanho total de cada RUN e assim, as runs ordenadas s�o combinadas usando MergeSort.
    O tamanho do bloco (arm) come�a com o valor RUN e dobra a cada itera��o,
    at� que todo o array seja mesclado. */
    for (int arm = RUN; arm < n; arm = 2 * arm) { // Mescla os subarrays usando MergeSort
        for (int esq = 0; esq < n; esq += 2 * arm) { // Itera sobre as runs para mescl�-las
            int meio = esq + arm - 1; // Determina o meio do array atual
            int dir = min((esq + 2 * arm - 1), (n - 1)); // Determina o final do array atual
            if (meio < dir) { // Se existir uma run v�lida para mesclar, aplica MergeSort
                mergeSort(array, esq, meio, dir);
            }
        }
    }
}
