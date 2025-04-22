#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> // Biblioteca para ler as teclas direcionais do teclado sem a necessidade do ENTER
#include <time.h>
#include <math.h>

// ALGORITMOS DE ORDENACAO
#include "algoritmos.h"
// Falta: Bubble Sort, Insertion Sort, Selection Sort


// PROCEDIMENTO DE EXIBIR AS OPÇÕES DO PROGRAMA NA TELA
int menuPrincipal();

int menuTamanho();

int *listaCrescente(int tamanho);

int *listaDecrescente(int tamanho);

int *listaAleatoria(int tamanho);

void imprimirVetor(int *vetor,int tamanho); // Rotina para teste

void resultadoTestes(double tempo_medio, double tempo_LC, double tempo_LD, int tamanho);
