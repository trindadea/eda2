#include <stdio.h>
#include <string.h>

struct entidade {
    char nome[10];
    struct entidade* ganha[2];
};

int main() {
    // Definição das entidades
    struct entidade entidades[] = {
        {"pedra", {&entidades[3], &entidades[2]}},
        {"papel", {&entidades[0], &entidades[4]}},
        {"tesoura", {&entidades[1], &entidades[3]}},
        {"lagarto", {&entidades[4], &entidades[1]}},
        {"Spock", {&entidades[2], &entidades[0]}}
    };

    // Entradas do usuário
    char entrada1[10], entrada2[10];
    scanf("%s %s", entrada1, entrada2);

    // Verificação de empate
    if (strcmp(entrada1, entrada2) == 0) {
        printf("De novo!\n");
        return 0;
    }

    // Verificação do resultado do jogo
    for (int i = 0; i < 5; i++) {
        if (strcmp(entidades[i].nome, entrada1) == 0) {
            if (strcmp(entidades[i].ganha[0]->nome, entrada2) == 0 || 
                strcmp(entidades[i].ganha[1]->nome, entrada2) == 0) {
                printf("Bazinga!\n");
            } else {
                printf("Raj trapaceou!\n");
            }
            break;
        }
    }

    return 0;
}
