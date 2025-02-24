#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

// Create an empty queue
node* createQ() {
    return NULL;
}

// Enqueue (Insert at rear)
node* enqueue(node* rear, int data1) {
    node* ptr = (node*)malloc(sizeof(node));
    if (!ptr) {
        printf("Memory allocation failed!\n");
        return rear;
    }
    ptr->data = data1;
    ptr->next = NULL;

    if (rear) {
        rear->next = ptr;  // Link new node to rear
    }
    return ptr;  // Return new rear
}

// Peek (View front element)
void peek(node* head) {
    if (!head) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", head->data);
    }
}

// Dequeue (Remove from front)
node* dequeue(node* head) {
    if (!head) {
        printf("Queue is empty! Cannot dequeue.\n");
        return NULL;
    }
    node* temp = head;
    printf("Dequeued element: %d\n", head->data);
    head = head->next;
    free(temp);
    return head;
}

// Check if queue is empty
bool isEmpty(node* head) {
    return head == NULL;
}

// Main function
int main() {
    node* head = NULL;
    node* rear = NULL;
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Enqueue
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (head == NULL) {  
                    head = (node*)malloc(sizeof(node));
                    if (!head) {
                        printf("Memory allocation failed!\n");
                        break;
                    }
                    head->data = value;
                    head->next = NULL;
                    rear = head;
                } else {
                    rear = enqueue(rear, value);
                }
                printf("%d enqueued successfully.\n", value);
                break;

            case 2:  // Dequeue
                head = dequeue(head);
                if (head == NULL) {
                    rear = NULL;  // Reset rear if queue is empty
                }
                break;

            case 3:  // Peek
                peek(head);
                break;

            case 4:  // Check if empty
                if (isEmpty(head)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 5:  // Exit
                printf("Exiting program...\n");
                while (head) {  // Free memory before exiting
                    head = dequeue(head);
                }
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
