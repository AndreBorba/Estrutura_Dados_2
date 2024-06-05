// André Vargas Villalba Codorniz
// Número USP: 14558436

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palavra{
    char palavra[40];
    int contagem;
}palavra;

int hash(char *palavra, int S){
    int v = 0;
    int i;
    int tam = strlen(palavra);
    int ascii;
    for(i = 0; i < tam; i++){
        ascii = (int) palavra[i];
        v += v*3 + ascii;
        v = v % S;
    }

    return v;
}

/* A função a seguir é para recalcular o índice de uma palavra na tabela
caso tenha havido conflito e a palavra que já existia no bucket era diferente da palavra atual
(Usando sondagem quadrática)*/

int rehash(int v, int S, int count, int c1, int c2){
    return (v + c1*count + c2*count*count) % S;
}

// Função para inserir uma palavra na tabela hash
void inserir(palavra *tabelaHash, int S, char *palavra, int c1, int c2){
    int indiceInicial = hash(palavra, S); // Esse índice inicial é armazenado pois caso haja conflito, pois a função rehash sempre utiliza o índice de onde ocorreu o primeiro conflito
    int indice = indiceInicial;
    int i = 0;

    /* Se o código entrar no loop while --> EXISTE conflito e palavras são DIFERENTES!
    Ao sair do while é GARANTIDO uma das duas opções a seguir:
    1) bucket está vazio ("casa" do vetor[índice] está vazia). Logo, a palavra é adicionada nesse bucket
    OU
    2) bucket NÃO está vazio e a palavra do bucket é igual à palavra a ser inserida. Logo, a contagem
    da palavra neste bucket é aumentada.*/
    while(tabelaHash[indice].contagem != 0 && strcmp(tabelaHash[indice].palavra, palavra) != 0){
        i++;
        indice = rehash(indiceInicial, S, i, c1, c2);
    }

    if(tabelaHash[indice].contagem == 0){
        strcpy(tabelaHash[indice].palavra,palavra);
        tabelaHash[indice].contagem = 1;
    }
    else{
        tabelaHash[indice].contagem++;
    }
}



int main(){
    int S, c1, c2, T;

    scanf("%d %d %d", &S, &c1, &c2);
    getchar();

    // Inicializando a tabela hash
    palavra *tabelaHash = (palavra *) calloc(S, sizeof(palavra));

char linha[256];
    while (fgets(linha, sizeof(linha), stdin)) {
        // Verifica se a linha está vazia
        if (strcmp(linha, "\n") == 0) {
            break;
        }
        char *token = strtok(linha, " \n");
        while (token != NULL) {
            inserir(tabelaHash, S, token, c1, c2);
            token = strtok(NULL, " \n");
        }
    }

    scanf("%d", &T);

    switch (T)
    {
    case 0:
        return 0;
    
    case 1:
        char linha_1[256];
        while (fgets(linha, sizeof(linha_1), stdin)) {
            // Verifica se a linha está vazia
            if (strcmp(linha_1, "\n") == 0) {
                break;
            }
            char *token = strtok(linha_1, " \n");
            while (token != NULL) {
                inserir(tabelaHash, S, token, c1, c2);
                token = strtok(NULL, " \n");
            }
        }
        break;
    
    case 2:
        
    
    default:
        break;
    }


    // Impressão da tabela hash para verificação
    for (int i = 0; i < S; i++) {
        if (tabelaHash[i].contagem > 0) {
            printf("Posição %d: %s -> %d\n", i, tabelaHash[i].palavra, tabelaHash[i].contagem);
        }
    }

    free(tabelaHash);
    return 0;
}
