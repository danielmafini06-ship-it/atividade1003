#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int vetor[], int tamanho) {
    int i, j, chave;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void super_sort(int vetor[], int tamanho) {
    if (tamanho < 10) {
        printf("Usando Insertion Sort (tamanho %d)\n", tamanho);
        insertion_sort(vetor, tamanho);
    } else {
        printf("Usando Quick Sort (tamanho %d)\n", tamanho);
        qsort(vetor, tamanho, sizeof(int), comparar);
    }
}
void imprimir(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
int main() {
    int v8[] = {9, 3, 1, 5, 8, 2, 4, 7};
    int v15[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    super_sort(v8, 8);
    imprimir(v8, 8);
    super_sort(v15, 15);
    imprimir(v15, 15);

    return 0;
}
