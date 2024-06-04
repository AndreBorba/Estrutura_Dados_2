#include <stdio.h>

void construirIndicePrimario(int vetor[], int tamanho, int indicePrimario[], int indiceSecundario[]) {
  // Inicializa os índices primário e secundário
  for (int i = 0; i < tamanho; i++) {
    indicePrimario[i] = i;
    indiceSecundario[i] = vetor[i];
  }

  // Ordena o vetor de índices secundários junto com o vetor de índices primários
  for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 0; j < tamanho - i - 1; j++) {
      if (indiceSecundario[j] > indiceSecundario[j + 1]) {
        // Troca os elementos dos vetores
        int tempIndicePrimario = indicePrimario[j];
        int tempIndiceSecundario = indiceSecundario[j];

        indicePrimario[j] = indicePrimario[j + 1];
        indiceSecundario[j] = indiceSecundario[j + 1];

        indicePrimario[j + 1] = tempIndicePrimario;
        indiceSecundario[j + 1] = tempIndiceSecundario;
      }
    }
  }
}

int main() {
  // Exemplo de uso

  int vetor[] = {5, 2, 4, 1, 3};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);

  int indicePrimario[tamanho];
  int indiceSecundario[tamanho];

  construirIndicePrimario(vetor, tamanho, indicePrimario, indiceSecundario);

  // Imprime os índices primários
  printf("Índices primários: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", indicePrimario[i]);
  }

  printf("\n");

  // Imprime os índices secundários (valores originais do vetor)
  printf("Índices secundários: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", indiceSecundario[i]);
  }

  printf("\n");

  return 0;
}
