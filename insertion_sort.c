#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct{
    elem *elementos;
    long tamanho;
}lista;

void insertion_sort(lista *l){
    long i, j;
    elem aux;

    for(i=1; i < l->tamanho; i++){
        aux = l->elementos[i];

        for(j = i-1; j >= 0 && l->elementos[j] > aux; j--){
            l->elementos[j+1] = l->elementos[j];
        }
        
        l->elementos[j+1] = aux; // insere o elemento na posição correta
    }
}
