// André Vargas VIllalba Codorniz - 14558436
// Lucas Augusto Moreira Barros - 14590610

#include <stdio.h>
#include <stdlib.h>

void bubble_sort (int *arr, int size) {
    int aux, flag;
    for (int k = 1; k < size; k++) {
        flag = 0;
        for (int j = 0; j < size - k; j++) {
            
            if (arr[j] > arr[j+1]) {
                aux      = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = aux;
                flag = 1;
            }
        }

        if(flag == 0){  // flag=0 significa que não houve mudança nenhuma no vetor, logo, ele já está ordenado.
            break;
        }
    }
}

void main(void){

    int size, num;

    int x = 0;

    scanf("%d", &size);  // lendo apenas a primeira linha para saber quantos números o arquivo tem
    int *arr = calloc(size, sizeof(int));

    for(int i=0; i<size; i++ ) {
        scanf("%d", &num);
        arr[i] = num;
    }

    bubble_sort(arr, size);

    for(int i=0; i<size; i++ ) {
        printf("%d ", arr[i]);
        arr[i] = num;
    }

    free(arr);

    
}
