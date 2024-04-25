#include <stdio.h>
#include <stdlib.h>

int *merge(int *vetorEsq, int *vetorDir, int *vetor, int tamanhoEsq, int tamanhoDir){
    int e = 0, d = 0, i = 0;

    while(e < tamanhoEsq && d < tamanhoDir){
        if(vetorEsq[e] < vetorDir[d]){
            vetor[i] = vetorEsq[e];
            e++;
        }
        else{
            vetor[i] = vetorDir[d];
            d++;
        }
        i++;
    }

    if(e < tamanhoEsq){
        while (i < tamanhoEsq + tamanhoDir){
            vetor[i] = vetorEsq[e];
            i++;
            e++;
        }
    }
    else if (d < tamanhoDir){
        while (i < tamanhoEsq + tamanhoDir){
            vetor[i] = vetorDir[d];
            i++;
            d++;
        }
    }

    return vetor;
}

int *mergesort(int *vetor, int tamanho) {
    if (tamanho <= 1) return vetor; // Caso base

    int tamanhoEsq = tamanho / 2;
    int tamanhoDir = tamanho - tamanhoEsq;

    int *vetorEsq = (int *)malloc(tamanhoEsq * sizeof(int));
    int *vetorDir = (int *)malloc(tamanhoDir * sizeof(int));

    // Copiando os elementos para os novos vetores
    for (int i = 0; i < tamanhoEsq; i++) {
        vetorEsq[i] = vetor[i];
    }

    for (int i = 0; i < tamanhoDir; i++) {
        vetorDir[i] = vetor[tamanhoEsq + i];
    }

    mergesort(vetorEsq, tamanhoEsq);
    mergesort(vetorDir, tamanhoDir);

    merge(vetorEsq, vetorDir, vetor, tamanhoEsq, tamanhoDir);

    free(vetorEsq);
    free(vetorDir);

    return vetor;
}

int main(){
    int vetor[] = {8, 2, 5, 3, 4, 7, 6, 1, 0};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    mergesort(vetor, tamanho);

    for (int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
}
