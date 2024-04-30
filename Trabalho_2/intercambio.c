// André Vargas Villalba Codorniz - 14558436

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura de dados que define o aluno
typedef struct{
    float nota;
    int reprovacoes;
    char nome[100];
}aluno;

// seleção direta que ordena decrescentemente
void selecao_direta(aluno *alunos, int N) {
    long i, j;

    for (i = 0; i < N - 1; i++) {
        long maxIndex = i;

        for (j = i + 1; j < N; j++) {

            // levando em conta a ordem de prioridade para ordenação do vetor de alunos
            if (alunos[j].nota > alunos[maxIndex].nota) {
                maxIndex = j;
            } else if (alunos[j].nota == alunos[maxIndex].nota && alunos[j].reprovacoes < alunos[maxIndex].reprovacoes) {
                maxIndex = j;
            } else if (alunos[j].nota == alunos[maxIndex].nota && alunos[j].reprovacoes == alunos[maxIndex].reprovacoes && strcmp(alunos[j].nome, alunos[maxIndex].nome) < 0) {
                maxIndex = j;
            }
        }

        // Trocar o aluno com maior prioridade com o aluno na posição i
        aluno temp = alunos[i];
        alunos[i] = alunos[maxIndex];
        alunos[maxIndex] = temp;
    }
}


void merge_sort(aluno *alunos, int N) {
    if (N <= 1) {
        return;
    }

    int mid = N / 2;

    // chama recursivamente o merge_sort pra ordenar primeira e segunda parte do vetor
    merge_sort(alunos, mid);
    merge_sort(alunos + mid, N - mid); // (alunos + mid) acessa a casa "mid" do vetor de alunos

    // vetor temporario para trocas
    aluno *temp = malloc(N * sizeof(aluno));
    int i = 0, j = mid, k = 0;

    // junta as metades ordenadas em um vetor temporario
    while (i < mid && j < N){
        if (alunos[i].nota > alunos[j].nota){
            temp[k++] = alunos[i++];
        } 
        else if (alunos[i].nota == alunos[j].nota && alunos[i].reprovacoes < alunos[j].reprovacoes){
            temp[k++] = alunos[i++];
        } 
        else if (alunos[i].nota == alunos[j].nota && alunos[i].reprovacoes == alunos[j].reprovacoes && strcmp(alunos[i].nome, alunos[j].nome) < 0){
            temp[k++] = alunos[i++];
        }
        else{
            temp[k++] = alunos[j++];
        }

    }

    while (i < mid){
        temp[k++] = alunos[i++];
    }

    while (j < N) {
        temp[k++] = alunos[j++];
    }

    for (i = 0; i < N; i++) {
        alunos[i] = temp[i];
    }

    free(temp);
}

// função que contém a lógica de selecionar quais são os aprovados para o intercambio e printar eles
void print_aprovados(aluno *alunos, aluno *aprovados, int N, int M){
    int i, j=0;
    int tam_aprovados = 0;
    int index_aprovados;
    
    // criando vetor com alunos aptos a serem contemplados com a bolsa
    for(i=0; i<N; i++){
        if(alunos[i].reprovacoes <= 10){
            aprovados[j] = alunos[i];
            tam_aprovados++;
            j++;
        }
    }
        
            /* a partir desse momento, serão analisados 3 casos:
            1. Número de vagas menor que número de inscritos
            2. Número de vagas igual ao número de inscritos
            3. Número de vagas maior que o número de inscritos
            */

    if(M < N){
        if(tam_aprovados > M){ // mais candidatos aptos do que bolsas
            index_aprovados = M; // a principio, tem-se M candidatos aprovados
                
            for(i=index_aprovados; i<tam_aprovados; i++){
                            
                // abrindo mais uma vaga no edital(notas e reprovações iguais)
                if(aprovados[index_aprovados - 1].nota == aprovados[index_aprovados].nota){
                    if(aprovados[index_aprovados - 1].reprovacoes == aprovados[index_aprovados].reprovacoes){
                        index_aprovados++;
                    }
                }
                else{
                    break;
                }
            }
        }

        else{
            index_aprovados = tam_aprovados; // numero de aprovados é o tamanho de elementos do vetor "aprovados"
        }
    }

    else if(M == N){
        index_aprovados = tam_aprovados; // "tam_aprovados" candidatos aprovados
    }
                            
    else{ // aqui tem-se M > N (vagas>candidatos)
        index_aprovados = tam_aprovados; // todos candidatos aptos foram aprovados
    }


    // aqui será feito o print de tudo, aqui é gerada a saída esperada pelo exercicio
    i=0;
    printf("%d\n", index_aprovados);
    while(i<index_aprovados){
        printf("%s\n", aprovados[i].nome);
        i++;
    }
}

int main(){
    int i, j; // variaveis para iterações
    int T; // método de ordenação a ser usado
    int N, M; // N = nro alunos e M = nro bolsas
    float a; // armazena temporariamente as notas
    int b; // armazena temporariamente as reprovações
    char c[100]; // armazena temporariamente os nomes
    

    scanf("%d", &T);
    scanf("%d %d", &N, &M);

    aluno *alunos = calloc(N, sizeof(aluno)); // vetor com todos alunos
    aluno *aprovados = calloc(N, sizeof(aluno)); // vetor que conterá os alunos passíveis de serem aprovados
    
    for(i=0; i<N; i++){
        scanf("%f %d %s", &a, &b, c);
        alunos[i].nota = a;
        alunos[i].reprovacoes = b;
        strcpy(alunos[i].nome, c);
    }

    if(T == 1){
        selecao_direta(alunos, N); // agora alunos estao ordenados decrescentemente de acordo com nota, reprovações e ordem alfabética

        print_aprovados(alunos, aprovados, N, M);
    }

    if(T == 2){
        merge_sort(alunos, N); // agora alunos estao ordenados decrescentemente de acordo com nota, reprovações e ordem alfabética
        
        print_aprovados(alunos, aprovados, N, M);
    }

    free(alunos);
    free(aprovados);

    return 0;
}        