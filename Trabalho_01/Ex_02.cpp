#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void criaPilha(Pilha *p) {
    p->topo = NULL;
}

int pilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

void empilha(Pilha *p, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilha(Pilha *p) {
    if(pilhaVazia(p)) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }
    No *removido = p->topo;
    int valor = removido->dado;
    p->topo = removido->prox;
    free(removido);
    return valor;
}

int impar(int valor) {
    return valor % 2 != 0;
}

int main() {
    Pilha s1, s2;
    criaPilha(&s1);
    criaPilha(&s2);

    printf("Preenchendo S1...\n");
    for(int i=12; i<=19; i++) {
        empilha(&s1, i);
    }

    printf("Passo dois...\n");
    while(!pilhaVazia(&s1)) {
        int x = desempilha(&s1);
        if(impar(x)) {
            empilha(&s2, x);
        }
    }

    printf("Pilha S1:\n");
    No *atual = s1.topo;
    while(atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->prox;
    }

    printf("Pilha S2:\n");
    atual = s2.topo;
    while(atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->prox;
    }

    return 0;
}
