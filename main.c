#include <stdio.h>
#include <stdlib.h>
#include "aux_p1.h"

int main()
{
    int opcao;
    
    printf("\n\t--------- TESTE DE ALGORITIMOS ---------\n\n");
    do {

        exibeMenu();
        printf("\tEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                    system("cls");
                    printf("\n\t========================================\n\n");
            break;
            case 2:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 3:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 4:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 5:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 6:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 7:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 8:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 9:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 10:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 11:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            case 12:
                    system("cls");
                    printf("\n\t========================================\n\n");
                break;
            default:
                printf("\n\n\n\tOpcao Invalida!\n\n");
        }

    } while (opcao != 12);

    exibeMenu();
    return 0;
}
