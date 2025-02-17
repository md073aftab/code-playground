#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

int isFull(struct Node* top) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        return 1;
    } else {
        free(p); // Free the allocated memory
        return 0;
    }
}

struct Node* push(struct Node* top, int x) {
    if (isFull(top)) {
        printf("Stack Overflow\n");
    } else {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
    }
    return top;
}

int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1; // Indicating an error
    } else {
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main() {
    struct Node* top = NULL;
    int choice, data, position;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1: Push element\n");
        printf("2: Pop element\n");
        printf("3: Display stack\n");
        printf("0: Terminate\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                top = push(top, data);
                break;
            case 2:
                data = pop(&top);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                linkedListTraversal(top);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}