#include <stdio.h>
#include <stdlib.h>

struct hash_ind {
    int valor;
    struct hash_ind *prox;
};

void hashing(struct hash_ind *ind, int valor){
    if(ind->valor == 0){
        ind->valor = valor;

        ind->prox = malloc(sizeof(struct hash_ind));
        ind->prox->valor = 0;
        ind->prox->prox = NULL;
    }
    else hashing(ind->prox, valor);
}

void print_hash(struct hash_ind *ind){
    if(ind->valor == 0) printf("\\");
    else{
        printf("%d -> ", ind->valor);
        print_hash(ind->prox);
    }
}

int main() {
    int num_casos;
    scanf("%d", &num_casos);

    int tam_hash, tam, num;
    int ind;

    for(int i = 0; i < num_casos; i++){
        scanf("%d %d", &tam_hash, &tam);

        struct hash_ind *hash_table = malloc(tam_hash * sizeof(struct hash_ind));

        for (int i = 0; i < tam_hash; i++) {
            hash_table[i].valor = 0;
            hash_table[i].prox = NULL;
        }

        for(int j = 0; j < tam; j++){
            scanf("%d", &num);
            ind = num%tam_hash;
        
            hashing(&hash_table[ind], num);
        }

        for (int i = 0; i < tam_hash; i++) {
            printf("%d -> ", i);
            print_hash(&hash_table[i]);
            printf("\n");
        }
        printf("\n");
    }
}