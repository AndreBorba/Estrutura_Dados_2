#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct{
    elem *elementos;
    long tamanho;
}lista;

void quick_sort_recursivo(lista *l, long ini, long fim){
    long i, j;
    elem aux;

    i = ini;
    for(j=ini; j<fim; j++){
        if(l->elementos[j] < l->elementos[fim]){
            aux = l->elementos[j];
            l->elementos[j] = l->elementos[i];
            l->elementos[i] = aux;
            i++;
        }
    }
    aux = l->elementos[fim];
    l->elementos[fim] = l->elementos[i];
    l->elementos[i] = aux;
    
    if(i-1 > ini){
    quick_sort_recursivo(l, ini, i-1);
    }

    if(fim > i+1){
    quick_sort_recursivo(l, i+1, fim);
    }
}

void ordena_quick_sort(lista *l){
    quick_sort_recursivo(l, 0, l->tamanho-1);
    return; 
}

int main(){

    lista *l = calloc(1, sizeof(lista));
    l->elementos = calloc(10, sizeof(int));
    l->tamanho = 0;

    for(int i=0; i<10; i++){
        l->elementos[i] = 20 - i;
        l->tamanho++;
    }

    ordena_quick_sort(l);

    for(int i=0; i<10; i++){
        printf("%d\n", l->elementos[i]);
    }

    free(l);

    return 0;
}