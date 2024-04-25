#include <stdio.h>
#include <stdlib.h>

struct Dados {
    int inteiro;
    char nome[100];
};

int mediana(int *elementos, int inicio, int final) {
    int meio = (inicio + final) / 2;
    int a = elementos[inicio];
    int b = elementos[meio];
    int c = elementos[final];
    
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        int temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }
    
    if (elementos[meio] == a)
        return inicio;
    else if (elementos[meio] == b)
        return meio;
    else
        return final;
}

int pivotacao(int inicio, int final, int *elementos) {
    int mediana_index = mediana(elementos, inicio, final);
    int temp = elementos[final];
    elementos[final] = elementos[mediana_index];
    elementos[mediana_index] = temp;
    
    int pivo = elementos[final];
    int i = inicio - 1;

    for (int j = inicio; j < final; j++) {
        if (elementos[j] < pivo) {
            i++;
            temp = elementos[j];
            elementos[j] = elementos[i];
            elementos[i] = temp;
        }
    }

    temp = pivo;
    elementos[final] = elementos[i + 1];
    elementos[i + 1] = temp;
    
    return i + 1;
}

void quicksort(int inicio, int final, struct Dados *dados) {
    if (inicio < final) {
        int pivo = pivotacao(inicio, final, dados);
        quicksort(inicio, pivo - 1, dados);
        quicksort(pivo + 1, final, dados);
    }
}

int main(){
    int num;

    scanf("%d", &num);
    struct Dados *dados = malloc(num * sizeof(struct Dados));

    for (int i = 0; i < num;  i++){
        scanf("%d %s", &dados[i].inteiro, dados[i].nome);
    }

    // quicksort(0, num-1, dados);

    for (int i = 0; i < num;  i++){
        printf("%d %s\n", dados[i].inteiro, dados[i].nome);
    }

    return 0;
}
