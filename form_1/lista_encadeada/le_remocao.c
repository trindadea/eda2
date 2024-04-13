#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        return 0;
    }
    celula *temp = p->prox;
    p->prox = temp->prox;
    int valor_removido = temp->dado;
    free(temp);
    return valor_removido;
}

void remove_elemento(celula *le, int x) {
    celula *atual = le->prox;
    celula *anterior = le;

    while (atual != NULL && atual->dado != x) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        anterior->prox = atual->prox;
        free(atual);
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *atual = le->prox;
    celula *anterior = le;

    while (atual != NULL) {
        if (atual->dado == x) {
            anterior->prox = atual->prox;
            celula *temp = atual;
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}
