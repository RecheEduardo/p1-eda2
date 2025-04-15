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
        printf("\tOPCAO 12 - SAIR\n\n");
        printf("\t========================================\n\n");
}

void selecionarTamanho(int opcaoTam){
        printf("\t========================================\n\n");
        printf("\t1 - 10.000    ELEMENTOS\n\n");
        printf("\t2 - 50.000    ELEMENTOS\n\n");
        printf("\t3 - 100.000   ELEMENTOS\n\n");
        printf("\t4 - 200.000   ELEMENTOS\n\n");
        printf("\t5 - 500.000   ELEMENTOS\n\n");
        printf("\t6 - 1.000.000 ELEMENTOS\n\n");
        printf("\t7 - VOLTAR AO MENU PRINCIPAL\n\n");
        printf("\t========================================\n\n");

        printf("\tEscolha uma opcao: ");
        scanf("%d", &opcaoTam);

        switch (opcaoTam) {
                case 1:     
                        printf("\n\tOpcao 1\n\n");
                        break;
                case 2:
                        printf("\n\tOpcao 2\n\n");
                        break;
                case 3:
                        printf("\n\tOpcao 3\n\n");
                        break;
                case 4:
                        printf("\n\tOpcao 4\n\n");
                        break;
                case 5:
                        printf("\n\tOpcao 5\n\n");
                        break;
                case 6:
                        printf("\n\tOpcao 6\n\n");
                        break;
                case 7:
                        printf("\n\tOpcao 7\n\n");
                        break;
        } while (opcaoTam != 12);
}
