//Given a singly linked list of n nodes, detect if it contains a loop or not.

#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to detect a loop
int detectLoop(struct Node* head) {
    struct Node* slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       
        fast = fast->next->next; 

        if (slow == fast) {      
            return 1;
        }
    }
    return 0; // No loop
}

// Function to create a loop in the list (for testing)
void createLoop(struct Node* head, int position) {
    if (head == NULL) return;

    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position)
            loopNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopNode; // Creating the loop
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data, choice, position;

    // Input linked list size
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input linked list elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    // Ask if the user wants to create a loop
    printf("Do you want to create a loop? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter position to create loop (1 to %d): ", n);
        scanf("%d", &position);
        createLoop(head, position);
    }

    // Detect loop
    if (detectLoop(head))
        printf("Loop detected in the linked list! \n");
    else
        printf("No loop detected in the linked list! \n");

    return 0;
}