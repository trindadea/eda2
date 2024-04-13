#include <stdio.h>
#include <stdbool.h>

struct pCoord {
    int x, y;
    bool saiu;
};

void passo(int passo, struct pCoord *prof){
    switch(passo) {
        case 1:
            prof->y += 1;
            break;
        case 2:
            prof->y -= 1;
            break;
        case 3:
            prof->x += 1;
            break;
        case 4:
            prof->x -= 1;
            break;
    }
}

void verifica(int linhas, int colunas, int passo, struct pCoord *PA, struct pCoord *PB, bool *encontro){
    // printf("PAx = %d; PAy = %d\n", PA->x, PA->y);
    // printf("PBx = %d; PBy = %d\n", PB->x, PB->y);

    //Caso PA e PB se encontrem
    if(PA->x == PB->x && PA->y == PB->y) {
        *encontro = true;
        printf("Encontraram-se na posicao (%d,%d) no passo %d\n", PA->x, PA->y, passo);
        return;
    }

    if(PA->x == 0 || PA->x == linhas + 1 || PA->y == 0 || PA->y == colunas + 1 ) PA->saiu = true;
    else if(PB->x == 0 || PB->x == linhas + 1 || PB->y == 0 || PB->y == colunas + 1 ) PB->saiu = true;

    if (PA->saiu) {
        printf("PA saiu na posicao (%d,%d) no passo %d\n", PA->x, PA->y, passo);
        return;
    }
    else if (PB->saiu) {
        printf("PB saiu na posicao (%d,%d) no passo %d\n", PB->x, PB->y, passo);
        return;
    }
}

int main() {
    int linhas, colunas, passos, PApasso, PBpasso;
    bool encontro = false;
    bool nope = true;

    scanf("%d %d", &linhas, &colunas);
    
    struct pCoord PA = {1, 1, false};
    struct pCoord PB = {linhas, colunas, false};
    
    // printf("PAx = %d; PAy = %d\n", PA.x, PA.y);
    // printf("PBx = %d; PBy = %d\n", PB.x, PB.y);

    scanf("%d", &passos);

    for (int i = 0; i < passos; i++){
        scanf("%d %d", &PApasso, &PBpasso);
        passo(PApasso, &PA);
        passo(PBpasso, &PB);
        
        verifica(linhas, colunas, i+1, &PA, &PB, &encontro);

        if (encontro || PA.saiu || PB.saiu){
            nope = false;
            break;
        }
    }
    if (nope) printf("Nao se encontraram\n");

    return 0;
}
