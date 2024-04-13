#include <stdio.h>
#include <stdbool.h>

int main() {
    int tamanho;
    long long int soma = 0;

    scanf("%d", &tamanho);
    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
        soma = soma + vetor[i];
    }

    bool zero = true;

    for(int i = 0; i < tamanho; i++){
        if(vetor[i] > soma/tamanho){
            printf("%d ", vetor[i]);
            zero = false;
        }
    }

    if (zero){
        printf("%d\n", 0);
    }

    return 0;
}