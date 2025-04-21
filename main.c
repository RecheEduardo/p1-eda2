#include "aux_p1.h"
#include "testes.h"
int main()
{
    int *lista;
    int algoritmo;
    int tamanho;

    setlocale(LC_ALL, "");
    do{
        algoritmo = menuPrincipal();

        switch(algoritmo){
            case 1: // BUBBLE SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n======== Algoritmo selecionado: BUBBLE SORT ========");
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 2: // INSERTION SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n======= Algoritmo selecionado: INSERTION SORT =======");
                insertionSortTeste(lista, tamanho);
                break;

            case 3: // SELECTION SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n======= Algoritmo selecionado: SELECTION SORT =======");
                selectionSortTeste(lista, tamanho);
                break;

            case 4: // SHELL SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n========= Algoritmo selecionado: SHELL SORT =========");
                shellSortTeste(lista, tamanho);
                break;

            case 5: // MERGE SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n========= Algoritmo selecionado: MERGE SORT =========");
                mergeSortTeste(lista, tamanho);
                break;

            case 6: // QUICK SORT [06]
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n========= Algoritmo selecionado: QUICK SORT =========");
                quickSortTeste(lista, tamanho);
                break;

            case 7: // HEAP SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n========== Algoritmo selecionado: HEAP SORT =========");
                heapSortTeste(lista, tamanho);
                break;

            case 8: // BUCKET SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n========= Algoritmo selecionado: BUCKET SORT ========");
                // nomeDoAlgoritmoTeste(lista, tamanho);
                break;

            case 9: // RADIX SORT (LSD)
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n========= Algoritmo selecionado: RADIX SORT =========");
                radixSortTeste(lista, tamanho);
                break;

            case 10: // COUNTING SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n======== Algoritmo selecionado: COUNTING SORT =======");
                countingSortTeste(lista, tamanho);
                break;

            case 11: //TIM SORT
                tamanho = menuTamanho();
                if(!tamanho) break;
                system("cls");
                printf("\n#####################################################");
                printf("\n========== Algoritmo selecionado: TIM SORT ==========");
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
