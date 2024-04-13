#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *p1 = l1->prox; // Ponteiro para percorrer a lista l1
    celula *p2 = l2->prox; // Ponteiro para percorrer a lista l2
    celula *p3 = l3; // Ponteiro para a lista mesclada l3

    // Enquanto houver elementos em ambas as listas
    while (p1 != NULL && p2 != NULL) {
        // Verifica qual valor é menor e avança o ponteiro correspondente
        if (p1->dado <= p2->dado) {
            p3->prox = p1; // Adiciona o elemento da lista l1 em l3
            p1 = p1->prox; // Avança para o próximo elemento de l1
        } else {
            p3->prox = p2; // Adiciona o elemento da lista l2 em l3
            p2 = p2->prox; // Avança para o próximo elemento de l2
        }
        p3 = p3->prox; // Avança o ponteiro para o próximo nó de l3
    }

    // Se ainda houver elementos na lista l1
    while (p1 != NULL) {
        p3->prox = p1; // Adiciona o restante da lista l1 em l3
        p1 = p1->prox; // Avança para o próximo elemento de l1
        p3 = p3->prox; // Avança o ponteiro para o próximo nó de l3
    }

    // Se ainda houver elementos na lista l2
    while (p2 != NULL) {
        p3->prox = p2; // Adiciona o restante da lista l2 em l3
        p2 = p2->prox; // Avança para o próximo elemento de l2
        p3 = p3->prox; // Avança o ponteiro para o próximo nó de l3
    }

    p3->prox = NULL; // Define o próximo ponteiro de l3 como NULL para indicar o final da lista mesclada
}
