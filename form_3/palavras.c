#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 131071

typedef struct palavra {
    char string[17];
    int votos;
    struct palavra *proxima;
} Palavra;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}

Palavra* encontra_palavra(Palavra *atual, char *palavra) {
    while (atual != NULL) {
        if (strcmp(atual->string, palavra) == 0) {
            return atual;
        }
        atual = atual->proxima;
    }
    return NULL;
}

void computar_comando(Palavra *tabela[], int comando, char *palavra) {
    unsigned long int hashind = hash(palavra);
    Palavra *atual = tabela[hashind];

    Palavra *encontrada = encontra_palavra(atual, palavra);

    if (encontrada != NULL) {
        switch (comando) {
        case 1:
            encontrada->votos++;
            return;
        case 2:
            printf("%d\n", encontrada->votos);
            return;
        case 3:
            encontrada->votos = 0;
            return;
        }
    } else {
        if (comando == 1) {
            Palavra *nova = malloc(sizeof(Palavra));
            strncpy(nova->string, palavra, sizeof(nova->string) - 1);
            nova->string[sizeof(nova->string) - 1] = '\0';
            nova->votos = 1;
            nova->proxima = tabela[hashind];
            tabela[hashind] = nova;
        } else if (comando == 2) {
            printf("0\n");
        }
    }
}

int main() {
    int comando;
    char palavra[17];

    Palavra *tabela_hash[TABLE_SIZE] = { NULL };

    while (scanf("%d %16s", &comando, palavra) != EOF) {
        computar_comando(tabela_hash, comando, palavra);
    }

    return 0;
}
