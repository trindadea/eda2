#include <stdio.h>
#include <stdlib.h>

struct elemento {
    float dado;
    int x, y;
};

void intercala(int N, int total, struct elemento *original) {
    if (N >= total) return;

    struct elemento *aux = malloc(2 * N * sizeof(struct elemento));
    int i = 0, j = N, k = 0;

    while (i < N && j < 2 * N) {
        if (original[i].dado >= original[j].dado) {
            aux[k] = original[i];
            i++;
        } else {
            aux[k] = original[j];
            j++;
        }
        k++;
    }

    while (i < N) {
        aux[k] = original[i];
        i++;
        k++;
    }
    while (j < 2 * N) {
        aux[k] = original[j];
        j++;
        k++;
    }

    // Copiar os elementos de volta para o vetor original
    for (int idx = 0; idx < 2 * N; idx++) {
        original[idx] = aux[idx];
        // printf("%f   ", aux[idx].dado);
    }

    free(aux);

    return intercala(2*N, total, original);
}

int main() {
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, M;
        scanf("%d %d", &M, &N);
    
        int total = N * M;
        struct elemento *elementos = malloc(total * sizeof(struct elemento));
        int count = 0;

        for (int j = 1; j <= M; j++) {
            for (int k = 1; k <= N; k++) {
                scanf("%f", &elementos[count].dado);
                elementos[count].x = k;
                elementos[count].y = j;
                count++;
            }
        }

        intercala(N, total, elementos);

        // Imprimir os valores de x e y para cada elemento
        for (int i = 0; i < total; i++) {
            // printf("%f\n", elementos[i].dado);
            printf("%d,%d ", elementos[i].y, elementos[i].x);
        }
        free(elementos);
        printf("\n");
    }

    return 0;
}