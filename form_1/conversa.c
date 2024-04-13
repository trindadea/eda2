#include <stdio.h>
#include <stdbool.h>

struct coord {
    int x, y;
};

void passot(int passo, struct coord *suspeitos){
    switch(passo) {
        case 1:
            suspeitos->y += 1;
            break;
        case 2:
            suspeitos->y -= 1;
            break;
        case 3:
            suspeitos->x += 1;
            break;
        case 4:
            suspeitos->x -= 1;
            break;
    }
}

int verifica(struct coord camposEscutados[], int tamanhoVetor, struct coord *suspeitos){
    for(int i = 0; i < tamanhoVetor; i++){
        if (suspeitos->x == camposEscutados[i].x && suspeitos->y == camposEscutados[i].y){
            // printf("Posicao %d X --> %d, Posicao %d Y --> %d\n", i, camposEscutados[i].x, i, camposEscutados[i].y);
            return 1;
        }
    }
    return 0;
}


int main() {
    int linhas, colunas, numPassos, passo, tamanhoVetor, minutosEscutados;
    int microX, microY;

    scanf("%d %d", &linhas, &colunas);
    scanf("%d %d", &microX, &microY);
    
    struct coord camposEscutados[] = {
        {microX, microY},
        {microX, microY+1},
        {microX, microY-1},
        {microX+1, microY},
        {microX-1, microY},
        {microX+1, microY+1},
        {microX+1, microY-1},
        {microX-1, microY+1},
        {microX-1, microY-1}};

    struct coord suspeitos = {0, 0};

    tamanhoVetor = sizeof(camposEscutados) / sizeof(camposEscutados[0]);
    minutosEscutados = 0;

    scanf("%d", &numPassos);

    for (int i = 0; i < numPassos; i++){
        scanf("%d", &passo);
        passot(passo, &suspeitos);
        minutosEscutados += verifica(camposEscutados, tamanhoVetor, &suspeitos);
    }

    printf("%d\n", minutosEscutados);
}
