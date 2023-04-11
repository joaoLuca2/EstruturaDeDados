#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Definição da estrutura da pilha encadeada
typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

// Funções da pilha encadeada
Stack *createStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Erro: Pilha vazia.\n");
        exit(1);
    }
    int value = stack->top->value;
    Node *node = stack->top;
    stack->top = node->next;
    free(node);
    return value;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void printStack(Stack *stack) {
    Node *node = stack->top;
    printf("Pilha: ");
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

// Funções da calculadora infix
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int evaluate(Stack *stack, char *expression) {
    int i, j, len, num1, num2, result;
    char c, op, num[MAX];
    len = strlen(expression);
    for (i = 0; i < len; i++) {
        c = expression[i];
        if (isdigit(c)) {
            j = 0;
            while (isdigit(c)) {
                num[j++] = c;
                c = expression[++i];
            }
            num[j] = '\0';
            push(stack, atoi(num));
            i--;
        }
        else if (c == '(') {
            push(stack, c);
        }
        else if (c == ')') {
            while (stack->top != NULL && stack->top->value != '(') {
                num2 = pop(stack);
                op = pop(stack);
                num1 = pop(stack);
                if (op == '+') result = num1 + num2;
                else if (op == '-') result = num1 - num2;
                else if (op == '*') result = num1 * num2;
                else if (op == '/') result = num1 / num2;
                push(stack, result);
            }
            pop(stack); // remove o '(' da pilha
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (stack->top != NULL && stack->top->value != '(' && precedence(c) <= precedence(stack->top->value)) {
                num2 = pop(stack);
                op = pop(stack);
                num1 = pop(stack);
                if (op == '+') result = num1 + num2;
                else if (op == '-') result = num1 - num2;
                else if (op == '*') result = num1 *

