#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for circular queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to check if queue is empty
bool isEmpty(Node* rear) {
    return rear == NULL;
}

// Function to check if queue is full (linked list implementation never really gets full)
bool isFull() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        return true; // Memory allocation failed
    }
    free(temp);
    return false;
}

// Function to insert an element in the circular queue
Node* enqueue(Node* rear, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        printf("Queue is full (Memory allocation failed)\n");
        return rear;
    }
    temp->data = data;
    temp->next = NULL;

    if (rear == NULL) { // If queue is empty
        temp->next = temp; // Circular link to itself
        return temp;
    }

    temp->next = rear->next; // New node points to front
    rear->next = temp; // Old rear points to new node
    return temp; // New node becomes rear
}

// Function to remove an element from the front of the queue
Node* dequeue(Node* rear) {
    if (isEmpty(rear)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return NULL;
    }

    Node* front = rear->next; // Front element
    printf("Dequeued element: %d\n", front->data);

    if (front == rear) { // If only one element in queue
        free(front);
        return NULL;
    }

    rear->next = front->next; // Rear links to new front
    free(front);
    return rear;
}

// Function to return the front element
void peek(Node* rear) {
    if (isEmpty(rear)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", rear->next->data);
    }
}

// Main function to test the circular queue
int main() {
    Node* rear = NULL;
    int choice, data;

    while (1) {
        printf("\nCircular Queue Operations:\n");
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
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                rear = enqueue(rear, data);
                printf("%d enqueued successfully.\n", data);
                break;

            case 2:
                rear = dequeue(rear);
                break;

            case 3:
                peek(rear);
                break;

            case 4:
                if (isEmpty(rear))
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
                while (!isEmpty(rear)) {
                    rear = dequeue(rear);
                }
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
