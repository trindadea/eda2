#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int linha, colunas;
    char lugar[4];

    scanf("%d %d", &linha, &colunas);
    int lugares[linha][colunas];

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < colunas; j++) {
            lugares[i][j] = 0;
        }
    }

    while(scanf("%s", lugar) != EOF){
        char letra = lugar[0];
        char numero_str[3];
        numero_str[0] = lugar[1];
        numero_str[1] = lugar[2];
        numero_str[2] = '\0';

        int numeroCol = letra - 'A';
        int numeroLinha = atoi(numero_str) - 1;
    
        lugares[numeroCol][numeroLinha] = 1;
    }

    for(int i = 0; i <= colunas; i++){
        if(i > 0 && i < 10) printf("0%d ", i);
        else if(i >= 10) printf("%d ", i);
        else printf("  ");
    }
    printf("\n");

    char letra = 'A' + linha;

    for (int i = 0; i < linha; i++){
        printf("%c ", letra - (i + 1));
        for(int j = 0; j < colunas; j++){
            if(lugares[linha - (i+1)][j] == 1) printf("XX ");
            else printf("-- ");
        }
        printf("\n");
    }
}