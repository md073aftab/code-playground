#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 

typedef struct stack {
    float arr[MAX];
    int top;
} stack;

void push(stack *s, float n) {
    if (s->top >= MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->arr[++(s->top)] = n;
}

float pop(stack *s) {
    if (s->top == -1) {
        printf("Error! Stack Underflow!\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

int main() {
    stack stack;
    stack.top = -1;
    char exp[1000];

    printf("Enter your postfix expression: ");
    if (!fgets(exp, 1000, stdin)) {
        printf("Error reading input!\n");
        return 1;
    }
    exp[strcspn(exp, "\n")] = '\0';  
    

    float res;
    int i = 0;
    while (exp[i] != '\0') {
        if (isspace(exp[i])) {
            i++;  // Ignore spaces
        } else if (isdigit(exp[i])) {
            float n = 0.0;
            while (isdigit(exp[i])) {
                n = n * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, n);
        } else {
            if (stack.top < 1) {
                printf("Error! Invalid Expression!\n");
                return 1;
            }
            float p = pop(&stack);
            float q = pop(&stack);

            switch (exp[i]) {
                case '+': res = q + p; break;
                case '-': res = q - p; break;
                case '*': res = q * p; break;
                case '/':
                    if (p == 0) {
                        printf("Error! Division by zero!\n");
                        return 1;
                    }
                    res = q / p;
                    break;
                case '^': res = pow(q, p); break;
                default:
                    printf("Error! Invalid Operation: %c\n", exp[i]);
                    return 1;
            }
            push(&stack, res);
            i++;  // Move to the next character
        }
    }

    if (stack.top != 0) {
        printf("Error! Invalid Expression!\n");
        return 1;
    }

    res = pop(&stack);
    printf("Result: %.2f\n", res);
    return 0;
}
