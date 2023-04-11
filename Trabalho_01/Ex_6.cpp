#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

typedef struct {
    char itens[MAX_SIZE];
    int inicio, fim, tamanho;
} Fila;

void inicializa_fila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila *f) {
    return f->tamanho == MAX_SIZE;
}

void insere(Fila *f, char x) {
    if (fila_cheia(f)) {
        printf("Erro: a fila esta cheia!\n");
        exit(EXIT_FAILURE);
    }
    f->fim = (f->fim + 1) % MAX_SIZE;
    f->itens[f->fim] = x;
    f->tamanho++;
}

char remove_item(Fila *f) {
    if (fila_vazia(f)) {
        printf("Erro: a fila esta vazia!\n");
        exit(EXIT_FAILURE);
    }
    char item = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_SIZE;
    f->tamanho--;
    return item;
}

void imprime_fila(Fila *f) {
    printf("Fila: ");
    if (fila_vazia(f)) {
        printf("vazia\n");
        return;
    }
    for (int i = f->inicio; i != f->fim + 1; i = (i + 1) % MAX_SIZE) {
        printf("%c ", f->itens[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializa_fila(&f);

    insere(&f, 'b');
    if (fila_cheia(&f)) {
        printf("Fila cheia!\n");
    }
    insere(&f, 's');
    insere(&f, 'a');
    insere(&f, 'c');
    remove_item(&f);
    remove_item(&f);
    insere(&f, 'h');
    insere(&f, 'd');
    insere(&f, 'f');
    remove_item(&f);
    insere(&f, 'n');
    insere(&f, 'b');
    if (fila_cheia(&f)) {
        printf("Fila cheia!\n");
    }
    remove_item(&f);
    insere(&f, 'm');
    remove_item(&f);
    remove_item(&f);
    remove_item(&f);
    imprime_fila(&f);
    if (fila_vazia(&f)) {
        printf("Fila vazia!\n");
    }

    return 0;
}

