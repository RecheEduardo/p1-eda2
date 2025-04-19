//BUCKET SORT
void bucketSort(int *vetor, int tamanho);


// INSERTION SORT
void insertionSort(int *array, int tamanho);


// COUNTING SORT
void countingSort(int inputArray[], int numElementos);


// HEAP SORT
void swap(int *a, int *b);

// Fun��o para criar um Max-Heap
void maxHeapify(int arr[], int n, int i);

// Fun��o para criar um Min-Heap
void minHeapify(int arr[], int n, int i);

// Fun��o HeapSort usando Max-Heap (ordem crescente)
void heapSortAscending(int arr[], int n);

// Fun��o HeapSort usando Min-Heap (ordem decrescente)
void heapSortDescending(int arr[], int n);


// MERGE SORT
void mergesort(int *v, int inicio, int fim);
void merge(int *v, int inicio, int meio, int fim);


// QUICK SORT
void troca(int *a, int *b);

int divisao(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);


// RADIX SORT
// Uma fun��o utilit�ria para obter o valor m�ximo em arr[]
unsigned int getMax(unsigned int *arr, unsigned int n);

// Uma fun��o para realizar o ordenamento por contagem
// de arr[] de acordo com o d�gito representado por exp
//void countSort(unsigned int arr[], int n, int exp, int radix);
void countSort(unsigned int *arr, unsigned int n,unsigned int exp,unsigned int radix);

void radixSort(unsigned int *arr, int n, int radix);


// SHELL SORT
void InsertionSort(int arr[], int tam);
//ordena��o de vetor de inteiros por Insertion Sort

void ShellSort(int arr[], int tam);
//ordena��o de vetor de inteiros por Shell Sort


// TIM SORT
int min(int a, int b); // Fun��o para definir o m�nimo de dois n�meros
void insertSort(int array[], int esq, int dir); // Fun��o para inserir o m�todo InsertionSort
void mergeSort(int array[], int x, int y, int z);
void timSort(int array[], int n); // Fun��o que executa o m�todo TimSort:

