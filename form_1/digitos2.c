#include <stdio.h>
#include <stdlib.h>

long long int vetorToInt(int vetor[], int tamanho) {
    long long int numero = 0;
    for (int i = 0; i < tamanho; i++) {
        numero = numero * 10 + vetor[i];
    }
    return numero;
}

int main(){
    int digitos, num;

    scanf("%d", &digitos);

    int *vetor = (int *)malloc(digitos * sizeof(int));

    for (int i = 0; i < digitos; i++){
        scanf("%d", &num);
        vetor[i] = num;
    }

    for (int i = 1; i <= digitos; i++){
        int *vetorAux = (int *)malloc(i * sizeof(int));
        
        for (int j = 0; j < i; j++) {
            vetorAux[j] = vetor[j];
        }

        long long int intAnalisado = vetorToInt(vetorAux, i);

        printf("comeco -> %lld\n", intAnalisado);

        for (int k = i; k < digitos; k++){
            // printf("%d\n", vetor[k]);

            int *vetorAux2 = (int *)malloc((k) * sizeof(int));

            for (int l = 0; l < k; l++) {
                vetorAux2[l] = vetor[i + l];
            }

            long long int intAnalisado2 = vetorToInt(vetorAux2, k);
            printf("resto -> %d\n", intAnalisado2);
        }

        printf("\n");
        
    }

    return 0;
}
