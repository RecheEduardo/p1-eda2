// Arquivo radixSortE.c - Ordena��o Radix Sort
// Feito por Lucas Silva de Oliveira

#include "aux_p1.h"

/*######################################################*/
// Uma fun��o utilit�ria para obter o valor m�ximo em
// arr[]
unsigned int getMax(unsigned int *arr,unsigned int n) {
    unsigned int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
/*######################################################*/
// Uma fun��o para realizar o ordenamento por contagem
// de arr[] de acordo com o d�gito representado por exp
void countSort(unsigned int *arr, unsigned int n, unsigned int exp, unsigned int radix) {
    // Array de sa�da
    unsigned int *output = malloc(n * sizeof(unsigned int));
    if (output == NULL) {
        printf("Erro na aloca��o de mem�ria!\n");
    }
    // Inicializa o array de contagem com 0
    //unsigned int count[radix];
    unsigned int *count = calloc(radix, sizeof(unsigned int));
    if (count == NULL) {
        printf("Erro na aloca��o de mem�ria!\n");
    }

    //for (int i = 0; i < radix; i++)
        //count[i] = 0;

    // Armazena a contagem de ocorr�ncias em count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % radix]++;

    //printf("\nCounting Array: ");
    //printArray(count, radix, radix);

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

    // Imprime a lista para cada etapa de ordena��o
    //unsigned int dg;
    //dg = log(exp) / log(radix);
    //printf("D�gito %d^%d: ", radix, dg);
    //printArray(arr, n, radix);

    // Libera as mem�rias alocadas
    free(output);
    free(count);
}
/*######################################################*/
// A fun��o principal para ordenar arr[] de tamanho n
// usando o Radix Sort
void radixSort(unsigned int *arr, int n, int radix) {

    // Encontra o n�mero m�ximo para saber o n�mero de
    // d�gitos
    int m = getMax(arr, n); // OK

    // Faz a ordena��o por contagem para cada d�gito
    // exp � 10^i, onde i � a posi��o do d�gito atual
    for (int exp = 1; m / exp > 0; exp *= radix){
        countSort(arr, n, exp, radix);
    }
}
/*######################################################*/
// Uma fun��o utilit�ria para imprimir um array
/*void printArray(unsigned int *arr, unsigned int n, unsigned int radix) {
    for (int i = 0; i < n; i++){
        //Alterando a impress�o dependendo da base
        if(radix == 16)
            printf("%X ", arr[i]); // Hexadecimal
        else if(radix == 2)
            printBinary(arr[i]); // Bin�rio
        else if(radix == 8)
            printf("%o ", arr[i]); // Octal
        else
            printf("%d ", arr[i]); // Decimal
    }

    printf("\n");
}*/
/*######################################################*/
// Fun��o auxiliar para imprimir n�meros bin�rios
/*void printBinary(unsigned int num) {
    if (num == 0) {  // Caso for zero
        printf("0 ");
        return;
    }

    int zero = 1; // Vari�vel para controlar zeros � esquerda

    // Tamanho m�ximo de bits, ajustado para 32 bits
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        // Imprime o bit mais significativo primeiro
        int bit = (num >> i) & 1; // Obt�m o valor do bit
        if(bit == 1){
            zero = 0;
        }
        if(!zero){
            printf("%d", bit);
        }
    }
    printf(" "); // Espa�o entre os n�meros bin�rios
}*/
/*######################################################*/
// Fun��o para criar uma lista aleat�ria dentro da base
// especificada, assim como o n�mero de elementos e
// quantidade ded�gito
/*unsigned int *createList(unsigned int radix,unsigned int n,unsigned int digit){
    int maxValue;
    // Aloca��o de mem�ria para a lista
    unsigned int *arr = malloc(n * sizeof(unsigned int));
    if (arr == NULL) {
        printf("Erro na aloca��o de mem�ria!\n");
    }

    // Inicializa a semente do gerador de n�meros
    // aleat�rios com a fun��o time para usar o
    // hor�rio local como seed
    srand(time(NULL));

    // Gera um n�mero aleat�rio no intervalo 0 at� o n�mero
    // m�ximo da base num�rica
    maxValue = (int)pow(radix, digit);

    for(int i = 0; i < n; i++){
        arr[i] = rand() % maxValue;
    }
    return arr;
}*/
/*######################################################*/
