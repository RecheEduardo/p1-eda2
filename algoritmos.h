// BUBBLE SORT
void bubbleSort(int *v, int n);


// SELECTION SORT
void selectionSort(int *v, int n);


// INSERTION SORT
void insertionSort(int *lista, int tamanho);


// COUNTING SORT
void countingSort(int *inputArray, int numElementos);


// RADIX SORT
void radixSort(int *arr, int n, int radix);
void countingSortRadix(int *arr, int n, int exp, int radix);
int getMax(int *arr,int n);


// BUCKET SORT
void bucketSort(int *vetor, int tamanho);
void insertionSortBS(int *arr, int tamanho);


// SHELL SORT
void shellSort(int *arr, int tam);
void insertionSortShell(int *arr, int tam);


// MERGE SORT
void mergeSort(int *v, int inicio, int fim);
void mergeMS(int *v, int inicio, int meio, int fim);


// QUICK SORT
void troca(int *a, int *b);
int divisao(int *arr, int low, int high);
void quickSort(int *arr, int low, int high);


// HEAP SORT
void swapHS(int *a, int *b);
void maxHeapify(int *arr, int n, int i);
void minHeapify(int *arr, int n, int i);
void heapSortAscending(int *arr, int n);
void heapSortDescending(int *arr, int n);


// TIM SORT
void timSort(int *arr, int n);
int minT(int a, int b);
void insertionSortTim(int *arr, int esq, int dir);
void mergeSortTim(int *arr, int x, int y, int z);



