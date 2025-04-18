#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> // Biblioteca para ler as teclas direcionais do teclado sem a necessidade do ENTER
#include <time.h>
#include "aux_p1.h"

// ALGORITMOS DE ORDENA��O
#include "radixSort.h"
#include "quickSort.h"
#include "shellSort.h"
#include "bucketSort.h"
#include "countingSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "timSort.h"
// Falta: Bubble Sort, Insertion Sort, Selection Sort

int main()
{
    unsigned long int *lista;
    unsigned int algoritmo;
    unsigned long int tamanho;

    setlocale(LC_ALL, "");

    do{
        algoritmo = menuPrincipal();

        switch(algoritmo){
            case 1: // BUBBLE SORT
                system("cls");
                printf("Op��o Selecionada: BUBBLE SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 2: // INSERTION SORT
                system("cls");
                printf("Op��o Selecionada: INSERTION SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 3: // SELECTION SORT
                system("cls");
                printf("Op��o Selecionada: SELECTION SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 4: // SHELL SORT
                printf("Op��o Selecionada: SHELL SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 5: // MERGE SORT
                system("cls");
                printf("Op��o Selecionada: MERGE SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 6: // QUICK SORT [06]
                printf("Op��o Selecionada: QUICK SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 7: // HEAP SORT
                system("cls");
                printf("Op��o Selecionada: HEAP SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 8: // BUCKET SORT
                system("cls");
                printf("Op��o Selecionada: BUCKET SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 9: // RADIX SORT (LSD)
                system("cls");
                printf("Op��o Selecionada: RADIX SORT (LSD)");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 10: // COUNTING SORT
                system("cls");
                printf("Op��o Selecionada: COUNTING SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 11: //TIM SORT
                system("cls");
                printf("Op��o Selecionada: TIM SORT");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 12: // SAIR
                system("cls");
                printf("Encerrando programa.\n");
                system("PAUSE");
                return 0;
        }
    }while(1);
}
