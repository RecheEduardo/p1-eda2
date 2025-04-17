#ifndef QUICK_H_INCLUDED
#define QUICK_H_INCLUDED

/********************************\
 *   Troca os valores dos dois
 *   elementos que forem passados
 *   como parametro
 *
 * @param a Ponteiro para o primeiro elemento.
 * @param b Ponteiro para o segundo elemento.
 *
 ********************************/
void troca(int *a, int *b);

/********************************\
 * Divide o Array utilizando um pivo
 *
 * Organizando de modo que os elementos
 * menores fiquem a esquerda do pivo e
 * os maiores fiquem a direita dele.
 *
 * @param arr - Array para ser dividido
 * @param low - Indice inicial do array
 * @param high - Indice final do array
 *
 * @return Indice final do pivo apos a divisao
 *******************************/

int divisao(int arr[], int low, int high);

/**********************************
 * Ordena um array de inteiros de forma crescente
 * usando o algoritmo QuickSort.
 *
 * @param arr Array que vai ser ordenado.
 * @param low Indice inicial do array.
 * @param high Indice final do array.
 *********************************/
void quickSort(int arr[], int low, int high);

/*********************
* Pequena funcao
* para teste e exemplo
* do QuickSort.
*
* Mostra os elementos do array
**********************/
//void printArray(int arr[], int size);

#endif // QUICK_H_INCLUDED
