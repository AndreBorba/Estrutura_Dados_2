// André Vargas VIllalba Codorniz - 14558436
// Lucas Augusto Moreira Barros - 14590610

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort_0(int *arr, int size){  // função pura, sem nenhuma otimização
    int aux;
    for (int k = 1; k < size; k++) {
        for (int j = 0; j < size - 1; j++) { 
            if (arr[j] > arr[j+1]) {
                aux      = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

void bubble_sort_1(int *arr, int size){  // função com primeira melhoria implementada
    int aux;
    for (int k = 1; k < size; k++) {
        for (int j = 0; j < size - k; j++) { // aqui está a primeira otimização, o vetor sempre é percorrido uma "casa" a menos, pois a cada iteração temos certeza que o maior numero está o final, então ele não é comparado com os demais.
            if (arr[j] > arr[j+1]) {
                aux      = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

void bubble_sort_2(int *arr, int size){  // função com segunda melhoria implementada
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
        if (flag == 0) {  // flag=0 significa que não houve mudança nenhuma no vetor, logo, ele já está ordenado. Esta é a segunda otimização.
            break;
        }
    }
}

int main(void) {
    int size, num;
    
    FILE *fw = fopen("./result.csv", "w");  // será gerado o arquivo result.csv para melhor manipulação dos dados pois iremos plotar gráficos. Esse arquivo conterá os tempos médios de execução
    if (fw == NULL)
        printf("Error opening the file");

    for (int n = 1; n <= 20; n++) {
        double total_time_0 = 0.0;
        double total_time_1 = 0.0;
        double total_time_2 = 0.0;

        char filename[13];
        sprintf(filename, "./tests/%d.in", n);
        FILE *fp = fopen(filename, "r");  // abrindo os arquivos .in para ordenar os valores inteiros
        if (fp == NULL) {
            printf("Error: could not open file %s", filename);
            return 1;
        }

        for (int i = 0; i < 20; i++) {  // esse for garante que cada função de bubble sort será executada 20 vezes, assim podemos tomar uma média de tempo dessas 20 execuções, tornando a medição mais confiável 
            int x = 0;

            fscanf(fp, "%d", &size);  // lendo apenas a primeira linha para saber quantos números o arquivo tem
            int *arr0 = calloc(size, sizeof(int));  // alocando memória para gerar os vetores com os números inteiros
            int *arr1 = calloc(size, sizeof(int));
            int *arr2 = calloc(size, sizeof(int));
            while (fscanf(fp, "%d", &num) == 1) { // gerando os vetores a partir dos arquivos .in, cada vetor será ordenado a partir da utilização de um dos três diferentes bubble sort. Exemplo: int *arr0 será ordenado com bubble_sort_0
                arr0[x] = num;
                arr1[x] = num;
                arr2[x] = num;
                x++;
            }

            clock_t t = clock();  // passo para a medida temporal
            bubble_sort_0(arr0, size);  // aqui deve ser selecionada a variação da função a ser utilizada
            t = clock() - t;

            double time_taken_0 = ((double)t) / CLOCKS_PER_SEC;  // calcula o tempo levado para executar a função
            total_time_0 += time_taken_0;

            t = clock();
            bubble_sort_1(arr1, size);  // aqui deve ser selecionada a variação da função a ser utilizada
            t = clock() - t;

            double time_taken_1 = ((double)t) / CLOCKS_PER_SEC;  // calcula o tempo levado para executar a função
            total_time_1 += time_taken_1;

            t = clock();
            bubble_sort_2(arr2, size);  // aqui deve ser selecionada a variação da função a ser utilizada
            t = clock() - t;

            double time_taken_2 = ((double)t) / CLOCKS_PER_SEC;  // calcula o tempo levado para executar a função
            total_time_2 += time_taken_2;

            free(arr0);
            free(arr1);
            free(arr2);
        }
        fclose(fp);

        double avg_time_0 = total_time_0 / 20.0;  // calculando a média dos tempos de execução
        double avg_time_1 = total_time_1 / 20.0;
        double avg_time_2 = total_time_2 / 20.0;
        
        fprintf(fw, "%d, %lf, %lf, %lf \n", n, avg_time_0, avg_time_1, avg_time_2);  // escrevendo no arquivo csv
    }

    fclose(fw);

    return 0;
}