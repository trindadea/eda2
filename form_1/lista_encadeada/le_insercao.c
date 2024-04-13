#include <stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));

    nova_celula->dado = x;
    nova_celula->prox = le->prox;
    le->prox = nova_celula;
}

void insere_antes(celula *le, int x, int y) {
    celula *atual = le->prox;
    celula *anterior = le;

    while (atual != NULL && atual->dado != y) {
        anterior = atual;
        atual = atual->prox;
    }

    celula *nova_celula = (celula *)malloc(sizeof(celula));

    nova_celula->dado = x;
    nova_celula->prox = atual;

    anterior->prox = nova_celula;
}

