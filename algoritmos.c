#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "aux_p1.h"

// 01 - BUBBLE SORT
void bubbleSort(int *v, int n){
    int continua, aux, fim = n;
    do{
        continua = 0;
        // Durante toda a itera��o do la�o for, ser�o feitas
        // compara�oes com as posi��es vizinhas. Percorre
        // at� a pen�ltima posi��o.
        for(int i = 0; i < fim - 1; i++){
            if(v[i] > v[i + 1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                // Recebe "i" atual para continuar a busca
                continua = i;
            }
        }
        fim --;
    }while(continua != 0);
}


// 02 - INSERTION SORT
void insertionSort(int *lista, int tamanho){
    int aux, i, j;

    for(i = 1; i < tamanho; i++){
        aux = lista[i];
        for(j = i; (j > 0) && (aux < lista[j - 1]); j--) {
            lista[j] = lista[j - 1];
        }
        lista[j] = aux;
    }
}


// 03 - SELECTION SORT
void selectionSort(int *v,int n){
    int menor, troca;
    for(int i = 0; i < n - 1; i++){
        // Procura o menor elemento em rela��o a i
        menor = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        // Troca os valores da posi��o atual com a "menor"
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}


// 04 - COUNTING SORT
void countingSort(int *inputArray, int numElementos) {
    // Encontrar o maior n�mero no array
    int maiorNumero = 0;
    for (int i = 0; i < numElementos; i++){
        if (inputArray[i] > maiorNumero){
            maiorNumero = inputArray[i];
        }
    }

    // Inicializar um array auxiliar, sendo que o tamanho dele
    // ser� igual ao MAIOR N�MERO encontrado no array de input
    int* auxArray = (int*)calloc(maiorNumero + 1, sizeof(int));

    // Utilizaremos os �ndices do array auxiliar
    // para contabilizar a quantidade de apari��es
    // de cada n�mero no nosso array de input
    for (int i = 0; i < numElementos; i++){
        auxArray[inputArray[i]]++;
    }

    // Para cada index do array auxiliar
    // Calcularemos a soma acumulativa dos index anteriores
    // Ex: {0, 1, 4, 2, 0, 0, 1} -> {0, 1, 5, 7, 7, 7, 8}
    for (int i = 1; i <= maiorNumero; i++){
        auxArray[i] += auxArray[i - 1];
    }

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


// 05 - RADIX SORT
int getMax(int *arr,int n) {
    // obter o valor m�ximo em arr[]
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// fun��o para realizar o ordenamento por contagem de arr[] de acordo com o d�gito representado por exp
void countingSortRadix(int *arr, int n, int exp, int radix) {
    // Array de sa�da
    int *output = malloc(n * sizeof(int));
    if (output == NULL) {
        printf("Erro na aloca��o de mem�ria!\n");
    }
    // Inicializa o array de contagem com 0
    int *count = calloc(radix, sizeof(int));
    if (count == NULL) {
        printf("Erro na aloca��o de mem�ria!\n");
    }

    // Armazena a contagem de ocorr�ncias em count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % radix]++;

    // Modifica count[i] para que ele agora contenha a
    // posi��o real deste d�gito no array de sa�da
    for (int i = 1; i < radix; i++)
        count[i] += count[i - 1];

    // Constr�i o array de sa�da
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    // Copia o array de sa�da para arr[], para que arr[]
    // agora contenha os n�meros ordenados
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Libera as mem�rias alocadas
    free(output);
    free(count);
}

// A fun��o principal para ordenar arr[] de tamanho n usando o Radix Sort
void radixSort(int *arr, int n, int radix) {

    // Encontra o n�mero m�ximo para saber o n�mero de
    // d�gitos
    int m = getMax(arr, n); // OK

    // Faz a ordena��o por contagem para cada d�gito
    // exp � 10^i, onde i � a posi��o do d�gito atual
    for (int exp = 1; m / exp > 0; exp *= radix){
        countingSortRadix(arr, n, exp, radix);
    }
}


// 06 - BUCKET SORT
#define NUM_BUCKETS 10  // Define o n�mero de baldes
#define MAX_SIZE 10     // Define o tamanho do vetor de entrada

// Estrutura do balde
typedef struct {
    int *valor;  // Ponteiro para armazenar os valores do balde
    int tamanho;   // Quantidade de elementos armazenados no balde
} Balde;

// Fun��o para organizar os itens do balde
void insertionSortBucket(int *array, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = array[i];  // Chave = Elemento atual a ser ordenado
        int j = i - 1;

        // Move os elementos maiores que a Chave uma posi��o � frente
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave; // Insere o elemento na posi��o correta
    }
}

void bucketSort(int *vetor, int tamanho) {
    Balde balde[NUM_BUCKETS]; // Declara um array de baldes

    // Inicializa os baldes
    for (int i = 0; i < NUM_BUCKETS; i++) {
        balde[i].valor = (int *)malloc(MAX_SIZE * sizeof(int)); // Aloca mem�ria para os valores
        balde[i].tamanho = 0; // Inicializa o tamanho do balde como zero
    }

    // Separa os elementos do vetor nos baldes apropriados
    for (int i = 0; i < tamanho; i++) {
        int indice = vetor[i] / NUM_BUCKETS; // Determina em qual balde o n�mero pertence
        balde[indice].valor[balde[indice].tamanho++] = vetor[i]; // Adiciona o n�mero ao balde
    }

    // Reconstruindo o vetor com os valores ordenados
    int index = 0; // �ndice do vetor
    for (int i = 0; i < NUM_BUCKETS; i++) {
        insertionSortBucket(balde[i].valor, balde[i].tamanho); // Ordena os elementos do balde
        for (int j = 0; j < balde[i].tamanho; j++) {
            vetor[index++] = balde[i].valor[j]; // Passa os elementos ordenados para o vetor original
        }
        free(balde[i].valor); // Libera a mem�ria alocada para o valor do balde
    }
}


// 07 - SHELL SORT
void insertionSortShell(int *arr, int tam){ // Insertion sort para o Shell
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

void shellSort(int *arr, int tam) { // Shell sort, uma varia��o do Insertion sort
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


// 08 - MERGE SORT
void merge(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho,i ,j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1; //tamanho do novo vetor
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i = 0; i<tamanho; i++){/*continua at'e preencher todos os indices do novo vetor*/
            if(fim1 == 0 && fim2 == 0){/*veifica se algum dos subvetores chegou ao final*/
                //------ordenando-------
                if(v[p1] < v[p2]){
                    temp[i] = v[p1];
                    p1++;
                }else{
                    temp[i] = v[p2];
                    p2++;
                }
                //-----verificando se o vetor acabou------
                if(p1> meio) {fim1 = 1;}
                if(p2> fim) {fim2 = 1;}

            }else{
                if(fim1 == 1){/*foi o p1 que acabou? Copia o resto do p1 no vetor*/
                    temp[i] = v[p2];
                    p2++;
                }else{        /*foi o p2 que acabou? copia o resto do p1 no vetor*/
                    temp[i] = v[p1];
                    p1++;
                }
            }
        }
        //----copiando temp para o vetor passado como parametro;
        for(j = 0, k= inicio; j<tamanho; j++, k++){
            v[k] = temp[j];
        }
    }
    free(temp);//liberar o vetor temporario
}

void mergeSort(int *v, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}


// 09 - QUICK SORT
// Fun��o para trocar dois elementos de posi��o
void troca(int *a,int *b) { // Fun��o para trocar dois elementos no array
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o que realiza a parti��o do array e retorna o �ndice do piv�
int divisao(int arr[], int low,int high) {
    int pivot = arr[high];  // Escolhe o �ltimo elemento como piv�
    int i = (low - 1); // �ndice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Se o elemento for menor que o piv�
            i++; // Move o �ndice do menor elemento
            troca(&arr[i], &arr[j]); // Troca os elementos
        }
    }
    troca(&arr[i + 1], &arr[high]); // Coloca o piv� na posi��o correta
    return (i + 1); // Retorna o �ndice do piv�
}

// Implementa��o recursiva do QuickSort
void quickSort(int arr[],int low, int high) {
    if (low < high) {
        int pi = divisao(arr, low, high); // Encontra o �ndice do piv�

        // Chama o QuickSort recursivamente para as duas metades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// 10 - HEAP SORT
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o para criar um Max-Heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior como o n�
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Fun��o para criar um Min-Heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Fun��o HeapSort usando Max-Heap (ordem crescente)
void heapSortAscending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Fun��o HeapSort usando Min-Heap (ordem decrescente)
void heapSortDescending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}


// 11 - TIM SORT
#define RUN 32 // Defini��o do tamanho m�nimo do bloco para o InsertionSort.

int minT(int a, int b){ // Fun��o para definir o m�nimo de dois n�meros
    if(a < b){ // Se a for menor que B, A � retornado.
        return a;
    } else { // Caso contr�rio, B � retornado.
        return b;
    }
}

void insertionSortTim(int array[], int esq, int dir) { // Fun��o para inserir o m�todo InsertionSort
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

void mergeSortTim(int array[], int x, int y, int z) {
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
        insertionSortTim(array, i, minT((i + RUN - 1), (n - 1)));
    }
    /*Ap�s a ordena��o de cada subArray, ser� aplicado novamente o mergeSort(), unindo cada pequena parte de array, antes quebrada
    para uma �nica forma, como foi enviada a fun��o.

    No loop a seguir, � definido cada ARM como o tamanho total de cada RUN e assim, as runs ordenadas s�o combinadas usando MergeSort.
    O tamanho do bloco (arm) come�a com o valor RUN e dobra a cada itera��o,
    at� que todo o array seja mesclado. */
    for (int arm = RUN; arm < n; arm = 2 * arm) { // Mescla os subarrays usando MergeSort
        for (int esq = 0; esq < n; esq += 2 * arm) { // Itera sobre as runs para mescl�-las
            int meio = esq + arm - 1; // Determina o meio do array atual
            int dir = minT((esq + 2 * arm - 1), (n - 1)); // Determina o final do array atual
            if (meio < dir) { // Se existir uma run v�lida para mesclar, aplica MergeSort
                mergeSortTim(array, esq, meio, dir);
            }
        }
    }
}
