// Arquivo radixSortE.h - Ordena��o Radix Sort
// Feito por Lucas Silva de Oliveira

// Uma fun��o utilit�ria para obter o valor m�ximo em
// arr[]
unsigned int getMax(unsigned int *arr, unsigned int n);

// Uma fun��o para realizar o ordenamento por contagem
// de arr[] de acordo com o d�gito representado por exp
//void countSort(unsigned int arr[], int n, int exp, int radix);
void countSort(unsigned int *arr, unsigned int n,unsigned int exp,unsigned int radix);

// A fun��o principal para ordenar arr[] de tamanho n
// usando o Radix Sort
void radixSort(unsigned int *arr, int n, int radix);

// Uma fun��o utilit�ria para imprimir um array
//void printArray(unsigned int *arr, unsigned int n, unsigned int radix);

// Fun��o auxiliar para imprimir n�meros bin�rios
//void printBinary(unsigned int num);

// Fun��o para criar uma lista
//unsigned int *createList(unsigned int radix, unsigned int n,unsigned int digit);
