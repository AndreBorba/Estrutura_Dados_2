#include <stdio.h>
#include <stdlib.h>

typedef long elem;

typedef struct {
    elem *elementos;
    long tamanho;
} lista;

void rearranjar_heap(lista *l, long i, long tam_heap){

    long fe, fd, mf;
    elem aux;
    
    // identifica filhos direita e esquerda
    if(2*i+1 < tam_heap){
        fe = 2*i+1;
    }
    else{
        fe = -1;
    }

    if(2*i+2 < tam_heap){
        fd = 2*i+2;
    }
    else{
        fd = -1;
    }

    // se i é folha, termina
    if(fe == -1){
        return; //nenhum filho, heap ok
    }

    // identifica maior filho
    if(fd == -1 || l->elementos[fe] > l->elementos[fd]){
        mf = fe;
    }
    else{
        mf = fd;
    }

    // verifica se elemento i é maior que filhos
    if(l->elementos[i] > l->elementos[mf]){
        return; // heap ok
    }

    // "escorregando" nó pai se ele tiver algum filho maior
    aux = l->elementos[i];
    l->elementos[i] = l->elementos[mf];
    l->elementos[mf] = aux;

    // chamada recursiva, começa rearranjando a partir de mf
    rearranjar_heap(l, mf, tam_heap);
}   

void construir_heap_max(lista *l){
    for(long i = l->tamanho/2 - 1; i>=0; i--){
        rearranjar_heap(l, i, l->tamanho);
    }
}

void heapsort(lista *l){
    long tam_heap;
    elem aux;

    construir_heap_max(l);

    tam_heap = l->tamanho;

    // trocando raiz por ultima folha;
    while(tam_heap > 1){
        aux = l->elementos[0];
        l->elementos[0] = l->elementos[tam_heap-1];
        l->elementos[tam_heap-1] = aux;

        tam_heap--;
        rearranjar_heap(l, 0, tam_heap);
    }       
}

