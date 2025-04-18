#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h> // Biblioteca para ler as teclas direcionais do teclado sem a necessidade do ENTER
#include <sys/time.h>

// MENU PRINCIPAL INTERATIVO
int menuPrincipal(){
    char inputUser;
    int row = 0, col = 0, algoritmo = 0;
    char selection[4][3];

    // Zera matriz de seleção
    for(int j = 0; j < 4; j++){
        for(int k = 0; k < 3; k++){
            selection[j][k] = ' ';
        }
    }
    selection[0][0] = '>';

    do{
        system("cls"); // Limpa a tela
        printf("\n===== ESCOLHA UM ALGORITMO PARA A BATERIA DE TESTES =====\n");
        printf("\n%c BUBBLE SORT   %c INSERTION SORT %c SELECTION SORT  ", selection[0][0], selection[0][1], selection[0][2]);
        printf("\n%c SHELL SORT    %c MERGE SORT     %c QUICK SORT      ", selection[1][0], selection[1][1], selection[1][2]);
        printf("\n%c HEAP SORT     %c BUCKET SORT    %c RADIX SORT (LSD)", selection[2][0], selection[2][1], selection[2][2]);
        printf("\n%c COUNTING SORT %c TIM SORT       %c SAIR            ", selection[3][0], selection[3][1], selection[3][2]);
        printf("\n\n#########################################################\n");


        // Ao clicar com as setas, envia 2 códigos, sendo o primeiro -32, e o segundo o código real
        inputUser = getch(); // Captura o primeiro código
        if(inputUser == -32){
            inputUser = getch(); // Captura o código real

            switch (inputUser) {
                case 72: // Código para seta pra cima
                    selection[row][col] = ' ';
                    row--;
                    if(row < 0)
                        row = 3;
                    selection[row][col] = '>';
                    break;

                case 80: // Código para seta pra baixo
                    selection[row][col] = ' ';
                    row++;
                    if(row > 3)
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

        else if(inputUser == 13){
            break;
        }

        /*else {
            printf("Comando Inválido!");
        }*/
    }while(1);
    algoritmo = (((row + 1) * 3) + (col + 1)) - 3;
    return algoritmo;
}

// SUBMENU PARA O TAMANHO DA LISTA
unsigned long int menuTamanho(){
    char inputUser;
    int row = 0;
    char selection[7];
    unsigned int tamanho;

    // Zera vetor de seleção
    for(int i = 0; i < 7; i++) selection[i] = ' ';
    selection[0] = '>';

    do{
        system("cls");
        printf("\n====== SELECIONE O TAMANHO DO VETOR DE TESTES ======\n");
        printf("\n%c 10.000      ELEMENTOS", selection[0]);
        printf("\n%c 50.000      ELEMENTOS", selection[1]);
        printf("\n%c 100.000     ELEMENTOS", selection[2]);
        printf("\n%c 200.000     ELEMENTOS", selection[3]);
        printf("\n%c 500.000     ELEMENTOS", selection[4]);
        printf("\n%c 1.000.000   ELEMENTOS", selection[5]);
        printf("\n\n%c VOLTAR AO MENU PRINCIPAL", selection[6]);
        printf("\n\n#####################################################\n");

        // Ao clicar com as setas, envia 2 códigos, sendo o primeiro -32, e o segundo o código real
        inputUser = getch(); // Captura o primeiro código
        if(inputUser == -32){
            inputUser = getch(); // Captura o código real

            switch (inputUser) {
                case 72: // Código para seta pra cima
                    selection[row] = ' ';
                    row--;
                    if(row < 0)
                        row = 6;
                    selection[row] = '>';
                    break;

                case 80: // Código para seta pra baixo
                    selection[row]= ' ';
                    row++;
                    if(row > 6)
                        row = 0;
                    selection[row] = '>';
                    break;
            }
        }

        else if(inputUser == 13){
            break;
        }
    }while(1);

    switch(row){
        case 0:
            tamanho = 10000;
            return tamanho;

        case 1:
            tamanho = 50000;
            return tamanho;

        case 2:
            tamanho = 100000;
            return tamanho;

        case 3:
            tamanho = 200000;
            return tamanho;

        case 4:
            tamanho = 500000;
            return tamanho;

        case 5:
            tamanho = 1000000;
            return tamanho;

        case 6:
            return 0;
    }

    return -1; // O retorno acontece pelo switch, porém coloquei um aqui para o compilador não ficar dando Warning
}

unsigned long int *listaCrescente(unsigned long int tamanho){
    unsigned long int *lista = malloc(tamanho * sizeof(unsigned int));

    if (lista == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    // Gera um número aleatório para cada item da lista
    for(unsigned long int i = 0; i < tamanho; i++){
        lista[i] = i;
    }
    return lista;
}

unsigned long int *listaDecrescente(unsigned long int tamanho){
    unsigned long int *lista = malloc(tamanho * sizeof(unsigned int));

    if (lista == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    // Gera um número aleatório para cada item da lista
    for(unsigned long int i = 0; i < tamanho; i++){
        lista[i] = tamanho - i;
    }
    return lista;
}

unsigned long int *listaAleatoria(unsigned long int tamanho){
    unsigned long int *lista;
    unsigned long int tmp, j;

    srand((unsigned) time(NULL));

    // Cria primeiro uma lista crescente
    lista = listaCrescente(tamanho);

    // E agora embaralha a lista
    for(unsigned long int i = 0; i < tamanho; i++){
        j = rand() % (i + 1);
        tmp = lista[j];
        lista[j] = lista[i];
        lista[i] = tmp;
    }

    return lista;
}

unsigned long double insertionSort(unsigned long int *lista, unsigned long int tamanho){
    int aux, x;
    struct timeval tempoInicial, tempoFinal;

    x = gettimeofday(&tempoInicial, NULL); // Armazena o tempo em que a execução da ordenação começou
    if(x == -1){
        printf("\n-- Falha na coleta do tempo inicial de execução, abortando... --");
        return -1;
    }

    for(int i=1; i<tamanho; i++){
        aux = lista[i];
        for(j=i; (j>0) && (aux < v[j-1]); j--) {
            v[j] = v[j-1];
        }
        v[j] = aux;
    }

    x = gettimeofday(&tempoFinal, NULL); // Armazena o tempo em que a execução da ordenação terminou
    if(x == -1){
        printf("\n-- Falha na coleta do tempo final de execução, abortando... --");
        return -1;
    }

    return (tempoFinal.tv_sec + tempoFinal.tv_usec/1000000.0) - (tempoInicial.tv_sec + tempoInicial.tv_usec/1000000.0);
}

void insertionSortTeste(unsigned long int *lista, unsigned long int tamanho) {

}
