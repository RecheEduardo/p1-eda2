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
        // Durante toda a iteração do laço for, serão feitas
        // comparaçoes com as posições vizinhas. Percorre
        // até a penúltima posição.
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
        // Procura o menor elemento em relação a i
        menor = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        // Troca os valores da posição atual com a "menor"
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}


// 04 - COUNTING SORT
void countingSort(int *inputArray, int numElementos) {
    // Encontrar o maior número no array
    int maiorNumero = 0;
    for (int i = 0; i < numElementos; i++){
        if (inputArray[i] > maiorNumero){
            maiorNumero = inputArray[i];
        }
    }

    // Inicializar um array auxiliar, sendo que o tamanho dele
    // será igual ao MAIOR NÚMERO encontrado no array de input
    int* auxArray = (int*)calloc(maiorNumero + 1, sizeof(int));

    // Utilizaremos os índices do array auxiliar
    // para contabilizar a quantidade de aparições
    // de cada número no nosso array de input
    for (int i = 0; i < numElementos; i++){
        auxArray[inputArray[i]]++;
    }

    // Para cada index do array auxiliar
    // Calcularemos a soma acumulativa dos index anteriores
    // Ex: {0, 1, 4, 2, 0, 0, 1} -> {0, 1, 5, 7, 7, 7, 8}
    for (int i = 1; i <= maiorNumero; i++){
        auxArray[i] += auxArray[i - 1];
    }

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


// 05 - RADIX SORT
int getMax(int *arr,int n) {
    // obter o valor máximo em arr[]
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// função para realizar o ordenamento por contagem de arr[] de acordo com o dígito representado por exp
void countingSortRadix(int *arr, int n, int exp, int radix) {
    // Array de saída
    int *output = malloc(n * sizeof(int));
    if (output == NULL) {
        printf("Erro na alocação de memória!\n");
    }
    // Inicializa o array de contagem com 0
    int *count = calloc(radix, sizeof(int));
    if (count == NULL) {
        printf("Erro na alocação de memória!\n");
    }

    // Armazena a contagem de ocorrências em count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % radix]++;

    // Modifica count[i] para que ele agora contenha a
    // posição real deste dígito no array de saída
    for (int i = 1; i < radix; i++)
        count[i] += count[i - 1];

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    // Copia o array de saída para arr[], para que arr[]
    // agora contenha os números ordenados
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Libera as memórias alocadas
    free(output);
    free(count);
}

// A função principal para ordenar arr[] de tamanho n usando o Radix Sort
void radixSort(int *arr, int n, int radix) {

    // Encontra o número máximo para saber o número de
    // dígitos
    int m = getMax(arr, n); // OK

    // Faz a ordenação por contagem para cada dígito
    // exp é 10^i, onde i é a posição do dígito atual
    for (int exp = 1; m / exp > 0; exp *= radix){
        countingSortRadix(arr, n, exp, radix);
    }
}


// 06 - BUCKET SORT
#define NUM_BUCKETS 10  // Define o número de baldes
#define MAX_SIZE 10     // Define o tamanho do vetor de entrada

// Estrutura do balde
typedef struct {
    int *valor;  // Ponteiro para armazenar os valores do balde
    int tamanho;   // Quantidade de elementos armazenados no balde
} Balde;

// Função para organizar os itens do balde
void insertionSortBucket(int *array, int tamanho) {
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
        insertionSortBucket(balde[i].valor, balde[i].tamanho); // Ordena os elementos do balde
        for (int j = 0; j < balde[i].tamanho; j++) {
            vetor[index++] = balde[i].valor[j]; // Passa os elementos ordenados para o vetor original
        }
        free(balde[i].valor); // Libera a memória alocada para o valor do balde
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

void shellSort(int *arr, int tam) { // Shell sort, uma variação do Insertion sort
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
// Função para trocar dois elementos de posição
void troca(int *a,int *b) { // Função para trocar dois elementos no array
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que realiza a partição do array e retorna o índice do pivô
int divisao(int arr[], int low,int high) {
    int pivot = arr[high];  // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Se o elemento for menor que o pivô
            i++; // Move o índice do menor elemento
            troca(&arr[i], &arr[j]); // Troca os elementos
        }
    }
    troca(&arr[i + 1], &arr[high]); // Coloca o pivô na posição correta
    return (i + 1); // Retorna o índice do pivô
}

// Implementação recursiva do QuickSort
void quickSort(int arr[],int low, int high) {
    if (low < high) {
        int pi = divisao(arr, low, high); // Encontra o índice do pivô

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

// Função para criar um Max-Heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior como o nó
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

// Função para criar um Min-Heap
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

// Função HeapSort usando Max-Heap (ordem crescente)
void heapSortAscending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Função HeapSort usando Min-Heap (ordem decrescente)
void heapSortDescending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}


// 11 - TIM SORT
#define RUN 32 // Definição do tamanho mínimo do bloco para o InsertionSort.

int minT(int a, int b){ // Função para definir o mínimo de dois números
    if(a < b){ // Se a for menor que B, A é retornado.
        return a;
    } else { // Caso contrário, B é retornado.
        return b;
    }
}

void insertionSortTim(int array[], int esq, int dir) { // Função para inserir o método InsertionSort
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

void mergeSortTim(int array[], int x, int y, int z) {
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
        insertionSortTim(array, i, minT((i + RUN - 1), (n - 1)));
    }
    /*Após a ordenação de cada subArray, será aplicado novamente o mergeSort(), unindo cada pequena parte de array, antes quebrada
    para uma única forma, como foi enviada a função.

    No loop a seguir, é definido cada ARM como o tamanho total de cada RUN e assim, as runs ordenadas são combinadas usando MergeSort.
    O tamanho do bloco (arm) começa com o valor RUN e dobra a cada iteração,
    até que todo o array seja mesclado. */
    for (int arm = RUN; arm < n; arm = 2 * arm) { // Mescla os subarrays usando MergeSort
        for (int esq = 0; esq < n; esq += 2 * arm) { // Itera sobre as runs para mesclá-las
            int meio = esq + arm - 1; // Determina o meio do array atual
            int dir = minT((esq + 2 * arm - 1), (n - 1)); // Determina o final do array atual
            if (meio < dir) { // Se existir uma run válida para mesclar, aplica MergeSort
                mergeSortTim(array, esq, meio, dir);
            }
        }
    }
}
