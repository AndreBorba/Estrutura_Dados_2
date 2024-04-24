# include <stdio.h>
# include <stdlib.h>

typedef int elem;

typedef struct{
    elem *elementos;
    long tamanho;
}lista;


void shell_sort(lista *l){
    long i, j, h, k = 0;
    elem aux;

    // gerando o vetor de passos
    long *passos = malloc(sizeof(long));
    passos[k] = 1;

    while(l->tamanho > passos[k]){
        k++;
        passos = realloc(passos, (k+1)*sizeof(long));
        passos[k] = 3*passos[k-1] + 1;
    }

    // fazendo a ordenação por inserção direta, respeitando os passos
    while(k>=0){        
        h = passos[k];    
        for(i=h; i <  l->tamanho; i++){
            aux = l->elementos[i];

            for(j = i-h; j>=0 && l->elementos[j] > aux; j-=h){
                l->elementos[j+h] = l->elementos[j];
            }
            l->elementos[j+h] = aux;
        }

        k--;
    }

    free(passos);
    
}
