#include <stdio.h>
#include <stdlib.h>
#define MAX 7 // tamanho máximo da pilha

typedef struct pilha {
  char vetor[MAX];
  int topo;
} Pilha;

void inicializa(Pilha *p) {
  p->topo = -1;
}

int pilha_vazia(Pilha *p) {
  return p->topo == -1;
}

int pilha_cheia(Pilha *p) {
  return p->topo == MAX - 1;
}

void empilha(Pilha *p, char x) {
  if (!pilha_cheia(p)) {
    p->topo++;
    p->vetor[p->topo] = x;
  }
}

char desempilha(Pilha *p) {
  if (!pilha_vazia(p)) {
    char x = p->vetor[p->topo];
    p->topo--;
    return x;
  }
  return ' ';
}

void imprime(Pilha *p) {
  if (!pilha_vazia(p)) {
    int i;
    for (i = p->topo; i >= 0; i--) {
      printf("%c\n", p->vetor[i]);
    }
  }
}

int main() {
  Pilha p;
  inicializa(&p);

  empilha(&p, 'A');
  empilha(&p, 'B');
  empilha(&p, 'C');
  empilha(&p, 'D');
  empilha(&p, 'E');
  empilha(&p, 'F');
  empilha(&p, 'G');
  empilha(&p, 'H');
  empilha(&p, 'I');
  empilha(&p, 'J');
  empilha(&p, 'K');

  imprime(&p);

  return 0;
}

