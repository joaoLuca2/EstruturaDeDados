#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

typedef struct {
    int topo;
    char dados[TAM_MAX];
} Pilha;

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha *p) {
    return p->topo == TAM_MAX - 1;
}

void empilhar(Pilha *p, char x) {
    if (pilha_cheia(p)) {
        printf("Erro: a pilha esta cheia\n");
        exit(1);
    }
    p->topo++;
    p->dados[p->topo] = x;
}

char desempilhar(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Erro: a pilha esta vazia\n");
        exit(1);
    }
    char x = p->dados[p->topo];
    p->topo--;
    return x;
}

void imprimir(Pilha *p) {
    printf("Pilha: ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%c ", p->dados[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializar_pilha(&p);
    empilhar(&p, 'J');
    empilhar(&p, 'G');
    empilhar(&p, 'S');
    empilhar(&p, 'R');
    empilhar(&p, 'D');
    empilhar(&p, 'K');
    empilhar(&p, 'B');
    empilhar(&p, 'H');
    empilhar(&p, 'F');
    empilhar(&p, 'G');
    empilhar(&p, 'L');
    empilhar(&p, 'P');
    empilhar(&p, 'W');
    imprimir(&p);
    return 0;
}

