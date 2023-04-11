#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // tamanho máximo da fila

typedef struct {
    int elementos[MAX];
    int inicio, fim;
} Fila;

int Fila_Vazia(Fila *f) {
    return f->inicio == f->fim;
}

int Fila_Cheia(Fila *f) {
    return f->fim == MAX;
}

void Insere(Fila *f, int x) {
    if (Fila_Cheia(f)) {
        printf("Erro: fila cheia.\n");
        exit(1);
    }
    f->elementos[f->fim++] = x;
}

int Remove(Fila *f) {
    if (Fila_Vazia(f)) {
        printf("Erro: fila vazia.\n");
        exit(1);
    }
    int x = f->elementos[f->inicio];
    f->inicio++;
    return x;
}

void Imprime(Fila *f) {
    if (Fila_Vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->elementos[i]);
    }
    printf("\n");
}

int main() {
    int x, y;
    Fila F1, F2;
    F1.inicio = F1.fim = F2.inicio = F2.fim = 0;
    
    // Leitura dos dados
    printf("Digite os dados: ");
    scanf("%d", &x);
    while (x != 0) {
        Insere(&F1, x);
        scanf("%d", &x);
    }
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    
    // Execução do algoritmo
    while (!Fila_Vazia(&F1)) {
        x = Remove(&F1);
        if (x < y) {
            Insere(&F2, x);
        }
    }
    
    // Impressão dos resultados
    printf("Fila F1: ");
    Imprime(&F1);
    printf("Fila F2: ");
    Imprime(&F2);
    printf("Final.\n");
    
    return 0;
}

