// BUBBLE SORT
void bubbleSort(unsigned long int *v, unsigned long int n);


// SELECTION SORT
void selectionSort(unsigned long int *v, unsigned long int n);


// INSERTION SORT
void insertionSort(unsigned long int *lista, unsigned long int tamanho);


// COUNTING SORT
void countingSort(int *inputArray, int numElementos);


// RADIX SORT
void radixSort(unsigned int *arr, int n, int radix);
void countingSortRadix(unsigned int *arr, unsigned int n, unsigned int exp, unsigned int radix);
unsigned int getMax(unsigned int *arr,unsigned int n);


// BUCKET SORT
void bucketSort(int *vetor, int tamanho);
void insertionSortBucket(int *array, int tamanho);


// SHELL SORT
void shellSort(int *arr, int tam);
void insertionSortShell(int *arr, int tam);


// MERGE SORT
void mergeSort(int *v, int inicio, int fim);
void merge(int *v, int inicio, int meio, int fim);


// QUICK SORT
void troca(unsigned long int *a, unsigned long int *b);
int divisao(unsigned long int arr[], int low, int high);
void quickSort(unsigned long int arr[], int low, int high);


// HEAP SORT
void swap(int *a, int *b);
void maxHeapify(int arr[], int n, int i);
void minHeapify(int arr[], int n, int i);
void heapSortAscending(int arr[], int n);
void heapSortDescending(int arr[], int n);


// TIM SORT
void timSort(int array[], int n);
int minT(int a, int b);
void insertionSortTim(int array[], int esq, int dir);
void mergeSortTim(int array[], int x, int y, int z);



