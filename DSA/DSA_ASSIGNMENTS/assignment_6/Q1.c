#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct stack {
    char arr[MAX];
    int top;   
} stack;

void push(stack *s, char c) {
    s->top++;
    s->arr[s->top] = c;
}

char pop(stack *s) {
    if (s->top == -1) return '\0';
    return s->arr[s->top--];
}

char peek(stack *s) {
    return (s->top == -1) ? '\0' : s->arr[s->top];
}

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int right_associative(char c) {
    return c == '^';
}

void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPostfix(char *exp, char *res) {
    stack Stack;
    Stack.top = -1;
    int i = 0;

    for (int j = 0; j < strlen(exp); j++) {
        if (isalnum(exp[j])) {
            res[i++] = exp[j];
        } else if (exp[j] == '(') {
            push(&Stack, exp[j]);
        } else if (exp[j] == ')') {
            while (Stack.top != -1 && peek(&Stack) != '(') {
                res[i++] = pop(&Stack);
            }
            pop(&Stack);
        } else {
            while (Stack.top != -1 && (priority(peek(&Stack)) > priority(exp[j]) || 
                (priority(peek(&Stack)) == priority(exp[j]) && !right_associative(exp[j])))) {
                res[i++] = pop(&Stack);
            }
            push(&Stack, exp[j]);
        }
    }
    while (Stack.top != -1) {
        res[i++] = pop(&Stack);
    }
    res[i] = '\0';
}

void infixToPrefix(char *exp, char *res) {
    reverse(exp);
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
    infixToPostfix(exp, res);
    reverse(res);
}

int main() {
    char exp[MAX], res[MAX];
    int choice;

    do {
        printf("Enter infix expression: ");
        fgets(exp, MAX, stdin);
        exp[strcspn(exp, "\n")] = '\0';

        printf("Choose an option:\n1. Infix to Postfix\n2. Infix to Prefix\n3. Quit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                infixToPostfix(exp, res);
                printf("Postfix Expression: %s\n", res);
                break;
            case 2:
                infixToPrefix(exp, res);
                printf("Prefix Expression: %s\n", res);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}