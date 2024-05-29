#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 131071 // Usando um número primo maior para melhor distribuição

typedef struct formigueiro {
    int id;
    char alimento[11];
    struct formigueiro *proximo;
} Formigueiro;

void insere(Formigueiro *formigueiros[], int id, char *alimento) {
    int hashind = id % TABLE_SIZE;
    Formigueiro *atual = formigueiros[hashind];

    while (atual != NULL) {
        if (atual->id == id && strcmp(atual->alimento, alimento) == 0) {
            printf("%d\n", id);
            return;
        }
        atual = atual->proximo;
    }

    Formigueiro *novo = malloc(sizeof(Formigueiro));
    novo->id = id;
    strncpy(novo->alimento, alimento, sizeof(novo->alimento) - 1);
    novo->alimento[sizeof(novo->alimento) - 1] = '\0';
    novo->proximo = formigueiros[hashind];
    formigueiros[hashind] = novo;
}

int main() {
    int id;
    char alimento[11];

    Formigueiro *formigueiros[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        formigueiros[i] = NULL;
    }

    while (scanf("%d %10s", &id, alimento) != EOF) {
        insere(formigueiros, id, alimento);
    }

    return 0;
}
