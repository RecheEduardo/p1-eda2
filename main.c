#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> // Biblioteca para ler as teclas direcionais do teclado sem a necessidade do ENTER
#include <time.h>
#include "aux_p1.h"

// ALGORITMOS DE ORDENAï¿½ï¿½O
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
    /*TESTE ########################*/
    unsigned long int *lc, *ld, *la;
    unsigned long int tm = 15;

    lc = listaCrescente(tm);
    printf("\n\nLista Crescente:");
    imprimirVetor(lc, tm);

    ld = listaDecrescente(tm);
    printf("\n\nLista Crescente:");
    imprimirVetor(ld, tm);

    la = listaAleatoria(tm);
    printf("\n\nLista Aleatória:");
    imprimirVetor(la, tm);
    printf("\n\n");
    system("PAUSE");
    /*##########################*/
    do{
        algoritmo = menuPrincipal();

        switch(algoritmo){
            case 1: // BUBBLE SORT
                system("cls");
                printf("Algoritmo selecionado: BUBBLE SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 2: // INSERTION SORT
                system("cls");
                printf("Algoritmo selecionado: INSERTION SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 3: // SELECTION SORT
                system("cls");
                printf("Algoritmo selecionado: SELECTION SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 4: // SHELL SORT
                printf("Algoritmo selecionado: SHELL SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 5: // MERGE SORT
                system("cls");
                printf("Algoritmo selecionado: MERGE SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 6: // QUICK SORT [06]
                printf("Algoritmo selecionado: QUICK SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 7: // HEAP SORT
                system("cls");
                printf("Algoritmo selecionado: HEAP SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 8: // BUCKET SORT
                system("cls");
                printf("Algoritmo selecionado: BUCKET SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 9: // RADIX SORT (LSD)
                system("cls");
                printf("Algoritmo selecionado: RADIX SORT (LSD)\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 10: // COUNTING SORT
                system("cls");
                printf("Algoritmo selecionado: COUNTING SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 11: //TIM SORT
                system("cls");
                printf("Algoritmo selecionado: TIM SORT\n");
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
