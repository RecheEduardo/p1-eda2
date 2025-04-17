// Arquivo radixSortE.h - Ordenação Radix Sort
// Feito por Lucas Silva de Oliveira

// Uma função utilitária para obter o valor máximo em
// arr[]
unsigned int getMax(unsigned int *arr, unsigned int n);

// Uma função para realizar o ordenamento por contagem
// de arr[] de acordo com o dígito representado por exp
//void countSort(unsigned int arr[], int n, int exp, int radix);
void countSort(unsigned int *arr, unsigned int n,unsigned int exp,unsigned int radix);

// A função principal para ordenar arr[] de tamanho n
// usando o Radix Sort
void radixSort(unsigned int *arr, int n, int radix);

// Uma função utilitária para imprimir um array
//void printArray(unsigned int *arr, unsigned int n, unsigned int radix);

// Função auxiliar para imprimir números binários
//void printBinary(unsigned int num);

// Função para criar uma lista
//unsigned int *createList(unsigned int radix, unsigned int n,unsigned int digit);
