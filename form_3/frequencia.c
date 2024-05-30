#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 95

typedef struct ascii {
    int freq;
    int value;
} ASCII;

int compare(const void *a, const void *b) {
    ASCII *asciiA = (ASCII *)a;
    ASCII *asciiB = (ASCII *)b;
    if (asciiA->freq == asciiB->freq) {
        return (asciiA->value - asciiB->value); // Mantém a ordem pelo valor ASCII em caso de empate
    }
    return (asciiA->freq - asciiB->freq); // Ordena em ordem crescente de frequência
}

int main() {
    char string[1001];

    ASCII *tabela_hash = malloc(TABLE_SIZE * sizeof(ASCII));

    while (scanf("%s", string) != EOF)
    {
        for (int i = 0; i < TABLE_SIZE; i++){
            tabela_hash[i].freq = 0;
            tabela_hash[i].value = i + 32;
        }

        for (int i = 0; string[i] != '\0'; i++){
            int hashind = ((int)string[i]) - 32;
            tabela_hash[hashind].freq++;
            tabela_hash[hashind].value = ((int)string[i]);
        }

        qsort(tabela_hash, TABLE_SIZE, sizeof(ASCII), compare);

        for (int i = 0; i < TABLE_SIZE; i++){
            if(tabela_hash[i].freq != 0) printf("%d %d\n", tabela_hash[i].value, tabela_hash[i].freq);        
        }

        printf("\n");
    }

    free(tabela_hash);
    return 0;
}