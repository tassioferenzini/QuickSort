/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tassio
 *
 * Created on 1 de Abril de 2017, 14:14
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[10], inicio, fim;

int Particao(int *a, int inicio, int fim) {
int pivo = a[fim], i, j = inicio, valor;
    for(i=inicio; i<fim; i++) {
        if(a[i] < pivo) {
            valor = a[i];
            a[i] = a[j];
            a[j] = valor;
            j++;
        }
    }
    if(pivo <= a[j]) {
        a[fim] = a[j];
        a[j] = pivo;
    }
    return j;
}

void quickSort(int *a, int inicio, int fim) {
    int meio;
    if (inicio >= fim) return;
    meio = Particao(a, inicio, fim);
    quickSort(a, inicio, meio-1);
    quickSort(a, meio + 1, fim);

}

int main(int argc, char** argv) {

    srand(time(NULL));
    for (int t = 1; t <= 10; t++) {
        a[t] = rand() % 10;
    }
    inicio = 1;
    fim = 10;

    printf("Entrada = ");
    for (int t = 1; t <= 10; t++) {
        printf("%d ", a[t]);
    }

    printf("\nOdenação = ");
    quickSort(a, inicio, fim);
    for (int t = 1; t <= 10; t++) {
        printf("%d ", a[t]);
    }

    return (EXIT_SUCCESS);
}


