#include <stdio.h>
#include <stdlib.h>

typedef long elem;

typedef struct {
    elem *elementos;
    long tamanho;
} lista;

long *merge(lista *l1, lista *l2){
    long i=0, j=0, k=0;
    long n1 = l1->tamanho;
    long n2 = l2->tamanho;

    lista *l3 = malloc(sizeof(lista));
    l3->elementos = malloc((n1 + n2)*sizeof(elem));
    l3->tamanho = n1 + n2;

    while(i < n1 && j < n2){
        if(l1->elementos[i] <= l2->elementos[j]){
            l3->elementos[k] = l1->elementos[i];
            k++;
            i++;
        }
        else{
            l3->elementos[k] = l2->elementos[j];
            k++;
            j++;
        }
    }
    
    while(i<n1){
        l3->elementos[k] = l1->elementos[i];
        k++;
        i++;
    }

    while(j<n2){
        l3->elementos[k] = l2->elementos[j];
        k++;
        j++;
    }

    return l3->elementos;
}

void merge_sort(lista *l){
    
    if(l->tamanho == 1){
        return;
    }

    lista *l1 = malloc(sizeof(lista));
    lista *l2 = malloc(sizeof(lista));

    l1->elementos = malloc(l->tamanho/2 * sizeof(elem));
    l1->tamanho = l->tamanho/2;

    l2->elementos = malloc((l->tamanho - l1->tamanho) * sizeof(elem));
    l2->tamanho = l->tamanho - l1->tamanho;

    for(long i=0; i < l1->tamanho; i++){
        l1->elementos[i] = l->elementos[i];
    }

    for(long i=0; i < l2->tamanho; i++){
        l2->elementos[i] = l->elementos[i+l1->tamanho];
    }

    merge_sort(l1);
    merge_sort(l2);

    l->elementos = merge(l1,l2);    

    free(l1->elementos);
    free(l1);
    free(l2->elementos);
    free(l2);

}

int main() {
    // Exemplo de uso
    lista *l = malloc(sizeof(lista));
    l->tamanho = 5;
    l->elementos = malloc(5 * sizeof(elem));
    l->elementos[0] = 5;
    l->elementos[1] = 3;
    l->elementos[2] = 8;
    l->elementos[3] = 1;
    l->elementos[4] = 2;

    merge_sort(l);

    printf("Lista ordenada:\n");
    for(int i = 0; i < l->tamanho; i++) {
        printf("%ld ", l->elementos[i]);
    }

    free(l->elementos);
    free(l);

    return 0;
}