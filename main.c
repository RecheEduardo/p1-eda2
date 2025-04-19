#include "aux_p1.h"
#include "algoritmos.h"

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
                insertionSortTeste(lista, tamanho);
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
                shellSortTeste(lista, tamanho);
                break;

            case 5: // MERGE SORT
                system("cls");
                printf("Algoritmo selecionado: MERGE SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                mergeSortTeste(lista, tamanho);
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
                radixSortTeste(lista, tamanho);
                break;

            case 10: // COUNTING SORT
                system("cls");
                printf("Algoritmo selecionado: COUNTING SORT\n");
                tamanho = menuTamanho();
                if(!tamanho) break;
                countingSortTeste(lista, tamanho);
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
