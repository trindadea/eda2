#include <stdio.h>
#include <stdlib.h>

int vetorToInt(int vetor[], int tamanho) {
    int numero = 0;
    for (int i = 0; i < tamanho; i++) {
        numero = numero * 10 + vetor[i];
    }
    return numero;
}

int dividir(int vetor[], int tamanho, int **vetor_esquerdo, int *tamanho_esquerdo, int **vetor_direito, int *tamanho_direito) {
    if (tamanho % 2 == 0) *tamanho_esquerdo = (tamanho / 2) + 1;
    else *tamanho_esquerdo = (tamanho + 1) / 2;
    *tamanho_direito = tamanho - *tamanho_esquerdo;

    printf("%d   %d\n", *tamanho_esquerdo, *tamanho_direito);

    // *vetor_esquerdo = (int *)malloc(*tamanho_esquerdo * sizeof(int));
    // *vetor_direito = (int *)malloc(*tamanho_direito * sizeof(int));
    
    // for (int i = 0; i < *tamanho_esquerdo; i++) {
    //     (*vetor_esquerdo)[i] = vetor[i];
    // }
    // for (int i = 0; i < *tamanho_direito; i++) {
    //     (*vetor_direito)[i] = vetor[*tamanho_esquerdo + i];
    // }

    // int num1, num2;
    // num1 = vetorToInt(*vetor_esquerdo, *tamanho_esquerdo);
    // num2 = vetorToInt(*vetor_direito, *tamanho_direito);

    // printf("%d %d\n", num1, num2);

    // if (*tamanho_esquerdo == 1) return num1;
    // else if(num2 == num1 + 1) return num1;
    // else return dividir(*vetor_esquerdo, *tamanho_esquerdo, vetor_esquerdo, &tamanho_esquerdo, vetor_direito, tamanho_direito);
}

int main(){
    int digitos, num;
    scanf("%d", &digitos);

    int *vetor = (int *)malloc(digitos * sizeof(int));

    int *vetor_esquerdo, *vetor_direito;
    int tamanho_esquerdo, tamanho_direito;

    for (int i = 0; i < digitos; i++){
        scanf("%d", &num);
        vetor[i] = num;
    }

    int menor_num;
    menor_num = dividir(vetor, digitos, &vetor_esquerdo, &tamanho_esquerdo, &vetor_direito, &tamanho_direito);

    printf("%d\n", menor_num);

    return 0;
}