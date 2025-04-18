// Arquivo radixSortE.c - Ordenação Radix Sort
// Feito por Lucas Silva de Oliveira

#include "aux_p1.h"

/*######################################################*/
// Uma função utilitária para obter o valor máximo em
// arr[]
unsigned int getMax(unsigned int *arr,unsigned int n) {
    unsigned int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
/*######################################################*/
// Uma função para realizar o ordenamento por contagem
// de arr[] de acordo com o dígito representado por exp
void countSort(unsigned int *arr, unsigned int n, unsigned int exp, unsigned int radix) {
    // Array de saída
    unsigned int *output = malloc(n * sizeof(unsigned int));
    if (output == NULL) {
        printf("Erro na alocação de memória!\n");
    }
    // Inicializa o array de contagem com 0
    //unsigned int count[radix];
    unsigned int *count = calloc(radix, sizeof(unsigned int));
    if (count == NULL) {
        printf("Erro na alocação de memória!\n");
    }

    //for (int i = 0; i < radix; i++)
        //count[i] = 0;

    // Armazena a contagem de ocorrências em count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % radix]++;

    //printf("\nCounting Array: ");
    //printArray(count, radix, radix);

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

    // Imprime a lista para cada etapa de ordenação
    //unsigned int dg;
    //dg = log(exp) / log(radix);
    //printf("Dígito %d^%d: ", radix, dg);
    //printArray(arr, n, radix);

    // Libera as memórias alocadas
    free(output);
    free(count);
}
/*######################################################*/
// A função principal para ordenar arr[] de tamanho n
// usando o Radix Sort
void radixSort(unsigned int *arr, int n, int radix) {

    // Encontra o número máximo para saber o número de
    // dígitos
    int m = getMax(arr, n); // OK

    // Faz a ordenação por contagem para cada dígito
    // exp é 10^i, onde i é a posição do dígito atual
    for (int exp = 1; m / exp > 0; exp *= radix){
        countSort(arr, n, exp, radix);
    }
}
/*######################################################*/
// Uma função utilitária para imprimir um array
/*void printArray(unsigned int *arr, unsigned int n, unsigned int radix) {
    for (int i = 0; i < n; i++){
        //Alterando a impressão dependendo da base
        if(radix == 16)
            printf("%X ", arr[i]); // Hexadecimal
        else if(radix == 2)
            printBinary(arr[i]); // Binário
        else if(radix == 8)
            printf("%o ", arr[i]); // Octal
        else
            printf("%d ", arr[i]); // Decimal
    }

    printf("\n");
}*/
/*######################################################*/
// Função auxiliar para imprimir números binários
/*void printBinary(unsigned int num) {
    if (num == 0) {  // Caso for zero
        printf("0 ");
        return;
    }

    int zero = 1; // Variável para controlar zeros à esquerda

    // Tamanho máximo de bits, ajustado para 32 bits
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        // Imprime o bit mais significativo primeiro
        int bit = (num >> i) & 1; // Obtém o valor do bit
        if(bit == 1){
            zero = 0;
        }
        if(!zero){
            printf("%d", bit);
        }
    }
    printf(" "); // Espaço entre os números binários
}*/
/*######################################################*/
// Função para criar uma lista aleatória dentro da base
// especificada, assim como o número de elementos e
// quantidade dedígito
/*unsigned int *createList(unsigned int radix,unsigned int n,unsigned int digit){
    int maxValue;
    // Alocação de memória para a lista
    unsigned int *arr = malloc(n * sizeof(unsigned int));
    if (arr == NULL) {
        printf("Erro na alocação de memória!\n");
    }

    // Inicializa a semente do gerador de números
    // aleatórios com a função time para usar o
    // horário local como seed
    srand(time(NULL));

    // Gera um número aleatório no intervalo 0 até o número
    // máximo da base numérica
    maxValue = (int)pow(radix, digit);

    for(int i = 0; i < n; i++){
        arr[i] = rand() % maxValue;
    }
    return arr;
}*/
/*######################################################*/
