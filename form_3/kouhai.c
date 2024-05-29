#include <stdio.h>

int main() {
    int num_casos;
    scanf("%d", &num_casos);

    int id, num_itens, num_itens_tot;

    num_itens_tot = 0;

    for(int i = 0; i < num_casos; i++){
        scanf("%d %d", &id, &num_itens);
        num_itens_tot += num_itens;
    }

    printf("%d\n", num_itens_tot);
}