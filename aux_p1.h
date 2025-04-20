#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> // Biblioteca para ler as teclas direcionais do teclado sem a necessidade do ENTER
#include <time.h>
#include <math.h>

// ALGORITMOS DE ORDENACAO
#include "algoritmos.h"
// Falta: Bubble Sort, Insertion Sort, Selection Sort


// PROCEDIMENTO DE EXIBIR AS OP��ES DO PROGRAMA NA TELA
unsigned int menuPrincipal();

unsigned long int menuTamanho();

unsigned long int *listaCrescente(unsigned long int tamanho);

unsigned long int *listaDecrescente(unsigned long int tamanho);

unsigned long int *listaAleatoria(unsigned long int tamanho);

void imprimirVetor(unsigned long int *vetor,unsigned long int tamanho); // Rotina para teste

void resultadoTestes(double tempo_medio, double tempo_melhor, double tempo_pior, unsigned long int tamanho);

void insertionSortTeste(unsigned long int *lista, unsigned long int tamanho);

void selectionSortTeste(unsigned long int *lista, unsigned long int tamanho);

// nomeDoAlgoritmoTeste(unsigned long int *lista, unsigned long int tamanho);
