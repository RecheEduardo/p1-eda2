// BUBBLE SORT

// a fazer............


// INSERTION SORT
void insertionSortTeste(unsigned long int *lista, unsigned long int tamanho);

// SELECTION SORT

// a fazer............


// COUNTING SORT
void countingSort(int inputArray[], int numElementos);


// RADIX SORT
unsigned int getMax(unsigned int *arr, unsigned int n);
void countingSortRadix(unsigned int *arr, unsigned int n,unsigned int exp,unsigned int radix);
void radixSort(unsigned int *arr, int n, int radix);


// BUCKET SORT
void insertionSortBucket(int *array, int tamanho);
void bucketSort(int *vetor, int tamanho);


// SHELL SORT
void InsertionSortShell(int arr[], int tam);
void ShellSort(int arr[], int tam);


// MERGE SORT
void mergeSort(int *v, int inicio, int fim);
void merge(int *v, int inicio, int meio, int fim);


// QUICK SORT
void troca(int *a, int *b);
int divisao(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);


// HEAP SORT
void swap(int *a, int *b);
void maxHeapify(int arr[], int n, int i);
void minHeapify(int arr[], int n, int i);
void heapSortAscending(int arr[], int n);
void heapSortDescending(int arr[], int n);


// TIM SORT
int min(int a, int b);
void insertionSortTim(int array[], int esq, int dir);
void mergeSortTim(int array[], int x, int y, int z);
void timSort(int array[], int n);