#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for priority queue
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Function to check if queue is empty
bool isEmpty(Node* front) {
    return front == NULL;
}

bool isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        return true; // Memory allocation failed
    }
    free(temp);
    return false;
}

// Function to insert an element based on priority
Node* enqueue(Node* front, int data, int priority) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        printf("Queue is full (Memory allocation failed)\n");
        return front;
    }
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    // Insert at the right position based on priority
    if (front == NULL || priority < front->priority) {
        temp->next = front;
        return temp;
    }

    Node* current = front;
    while (current->next != NULL && current->next->priority <= priority) {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
    
    return front;
}

// Function to remove the highest priority element
Node* dequeue(Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return NULL;
    }
    Node* temp = front;
    printf("Dequeued element: %d (Priority: %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
    return front;
}

// Function to return the highest-priority element
void peek(Node* front){
    if (isEmpty(front)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d (Priority: %d)\n", front->data, front->priority);
    }
}

// Main function to test the priority queue
int main() {
    Node* front = NULL;
    int choice, data, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &data, &priority);
                front = enqueue(front, data, priority);
                printf("Enqueued: %d (Priority: %d)\n", data, priority);
                break;

            case 2:
                front = dequeue(front);
                break;

            case 3:
                peek(front);
                break;

            case 4:
                if (isEmpty(front))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;

            case 5:
                if (isFull())
                    printf("Queue is full (Memory allocation failed).\n");
                else
                    printf("Queue is not full.\n");
                break;

            case 6:
                printf("Exiting program...\n");
                while (!isEmpty(front)) {
                    front = dequeue(front);
                }
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
