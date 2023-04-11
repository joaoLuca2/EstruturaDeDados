#include <stdio.h>
#include <stdlib.h>

#define MAX 7 // tamanho máximo da pilha

typedef struct {
    int topo;
    int dados[MAX];
} Pilha;

void Pilha_Inicia(Pilha *p) {
    p->topo = -1;
}

int Pilha_Vazia(Pilha *p) {
    return p->topo == -1;
}

int Pilha_Cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void Empilha(Pilha *p, int x) {
    if (Pilha_Cheia(p)) {
        printf("Erro: pilha cheia\n");
        exit(1);
    }
    p->topo++;
    p->dados[p->topo] = x;
}

int Desempilha(Pilha *p) {
    int x;
    if (Pilha_Vazia(p)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    x = p->dados[p->topo];
    p->topo--;
    return x;
}

void Imprime(Pilha *p) {
    int i;
    for (i = p->topo; i >= 0; i--)
        printf("%d\n", p->dados[i]);
}

int main() {
    Pilha p;
    Pilha_Inicia(&p);
    Empilha(&p, 2);
    Empilha(&p, 6);
    Empilha(&p, 7);
    Empilha(&p, 9);
    Empilha(&p, 5);
    Empilha(&p, 2);
    Empilha(&p, 10);
    Empilha(&p, 4);
    Empilha(&p, 3);
    Empilha(&p, 9);
    Empilha(&p, 8);
    Empilha(&p, 7);
    Empilha(&p, 1);
    Imprime(&p);
    return 0;
}
 
