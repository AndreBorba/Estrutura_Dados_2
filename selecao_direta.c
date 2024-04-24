#include <stdio.h>
#include <stdlib.h>

typedef long elem;

typedef struct {
    elem *elementos;
    long tamanho;
} lista;

void selecao_direta(lista *l) {
    long i, j;

    for (i = 0; i < l->tamanho - 1; i++) {
        long minIndex = i;

        // Encontrar o índice do menor elemento a partir de i até o final
        for (j = i + 1; j < l->tamanho; j++) {
            if (l->elementos[j] < l->elementos[minIndex]) {
                minIndex = j;
            }
        }

        // Trocar o elemento mínimo com o elemento na posição i
        elem temp = l->elementos[i];
        l->elementos[i] = l->elementos[minIndex];
        l->elementos[minIndex] = temp;
    }
}
