#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct inst {
    int cod;
    char instrucao[15];
    struct inst *esquerda;
    struct inst *direita;
};

struct inst *criarInstrucao(int cod, char *instrucao) {
    struct inst *novaInstrucao = (struct inst *)malloc(sizeof(struct inst));

    novaInstrucao->cod = cod;
    strcpy(novaInstrucao->instrucao, instrucao);

    novaInstrucao->esquerda = NULL;
    novaInstrucao->direita = NULL;
    
    return novaInstrucao;
}

struct inst *inserir(struct inst *raiz, int cod, char *instrucao){
    if (raiz == NULL) return criarInstrucao(cod, instrucao);
    else if (cod < raiz->cod) raiz->esquerda = inserir(raiz->esquerda, cod, instrucao);
    else if (cod >= raiz->cod) raiz->direita = inserir(raiz->direita, cod, instrucao);

    return raiz;
}

struct inst *buscar(struct inst *raiz, int cod){
    if(raiz == NULL || cod == raiz->cod) return raiz;
    else if(cod >= raiz->cod) return buscar(raiz->direita, cod);
    else return buscar(raiz->esquerda, cod);
}

int main() {
    int numInstrucoes, cod, instInput;
    char instrucao[15];

    scanf("%d", &numInstrucoes);
    struct inst *raiz = NULL;

    for (int i = 0; i < numInstrucoes; i++) {
        scanf("%d %s", &cod, instrucao);
        raiz = inserir(raiz, cod, instrucao);
    }

    while (scanf("%d", &instInput) != EOF) {
        struct inst *encontrado = buscar(raiz, instInput);

        if (encontrado != NULL)
            printf("%s\n", encontrado->instrucao);
        else
            printf("undefined\n");
    }

    return 0;
}
