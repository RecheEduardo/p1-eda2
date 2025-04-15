#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

// PROCEDIMENTO DE EXIBIR AS OPCOES DO PROGRAMA NA TELA
void exibeMenu_temp(){
    char inputUser;
    int row = 0, col = 0;
    char selection[5][3];
    setlocale(LC_ALL, "");

    // Inicializacao da matriz
    for(int j = 0; j < 5; j++){
        for(int k = 0; k < 3; k++){
            selection[j][k] = ' ';
        }

    }
    selection[0][0] = '>';

    do{
        system("cls"); // Limpa a tela
        printf("\n\t SELECIONE O ALGORITIMO QUE DESEJA REALIZAR O TESTE \n\n");
        printf("\n%c BUBBLE SORT   \t%c INSERTION SORT \t%c SELECTION SORT", selection[0][0], selection[0][1], selection[0][2]);
        printf("\n%c SHELL SORT    \t%c MERGE SORT     \t%c QUICK SORT", selection[1][0], selection[1][1], selection[1][2]);
        printf("\n%c HEAP SORT     \t%c BUCKET SORT    \t%c RADIX SORT", selection[2][0], selection[2][1], selection[2][2]);
        printf("\n%c COUNTING SORT \t%c TIM SORT", selection[3][0], selection[3][1]);

        // Ao clicar com as setas, envia 2 códigos, sendo o primeiro -32, e o segundo o código real
        inputUser = getch(); // Captura o primeiro código
        if(inputUser == -32){
            inputUser = getch(); // Captura o código real
            switch (inputUser) {
                case 72: // Código para seta pra cima
                    selection[row][col] = ' ';
                    row--;
                    if(row < 0)
                        row = 4;
                    selection[row][col] = '>';
                    break;
                case 80: // Código para seta pra baixo
                    selection[row][col] = ' ';
                    row++;
                    if(row > 4)
                        row = 0;
                    selection[row][col] = '>';
                    break;
                case 75: // Código para seta pra esquerda
                    selection[row][col] = ' ';
                    col--;
                    if(col < 0)
                        col = 2;
                    selection[row][col] = '>';
                    break;
                case 77: // Código para seta pra direita
                    selection[row][col] = ' ';
                    col++;
                    if(col > 2)
                        col = 0;
                    selection[row][col] = '>';
                    break;
            }
        }
    }while(/*option != 4*/ 1);
    printf("\nVocê selecionou a última opcao! Encerrando...\n");
    system("PAUSE");
    return 0;
}

void exibeMenu(){
        printf("\t========================================\n\n");
        printf("\tOPCAO 1 -  BUBBLE SORT\n\n");
        printf("\tOPCAO 2 -  INSERTION SORT\n\n");
        printf("\tOPCAO 3 -  SELECTION SORT\n\n");
        printf("\tOPCAO 4 -  SHELL SORT\n\n");
        printf("\tOPCAO 5 -  MERGE SORT\n\n");
        printf("\tOPCAO 6 -  QUICK SORT\n\n");
        printf("\tOPCAO 7 -  HEAP SORT\n\n");
        printf("\tOPCAO 8 -  BUCKET SORT\n\n");
        printf("\tOPCAO 9 -  RADIX SORT\n\n");
        printf("\tOPCAO 10 - COUNTING SORT\n\n");
        printf("\tOPCAO 11 - TIM SORT\n\n");
        printf("\t========================================\n\n");
}