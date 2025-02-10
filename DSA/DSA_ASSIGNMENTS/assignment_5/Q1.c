#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(struct node* head, struct node* last, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    if (head == NULL) {
        ptr->next = ptr; // First node points to itself
        return ptr;
    }
    ptr->next = head;
    last->next = ptr;
    return ptr;
}

void linked_List_Traversal(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* ptr = head;
    do {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct node* insert_at_first(struct node* head, struct node** last, int data) {
    struct node* ptr = createnode(head, *last, data);
    if (*last == NULL) {
        *last = ptr;
    } else {
        (*last)->next = ptr;
    }
    return ptr;
}

void Insert_At_Specific_Position(struct node* head, int position, int data) {
    if (head == NULL || position < 1) return;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

void Insert_at_last(struct node* head, struct node** last, int data) {
    struct node* tail = (struct node*)malloc(sizeof(struct node));
    tail->data = data;
    tail->next = head;
    if (*last == NULL) {
        head = tail;
        tail->next = head;
    } else {
        (*last)->next = tail;
    }
    *last = tail;
}

struct node* delete_at_first(struct node* head, struct node** last) {
    if (head == NULL) return NULL;
    if (head->next == head) { // Only one element
        free(head);
        *last = NULL;
        return NULL;
    }
    struct node* first = head->next;
    (*last)->next = first;
    free(head);
    return first;
}

void delete_At_Specific_Position(struct node* head, int position) {
    if (head == NULL || position < 1) return;
    struct node* temp = head;
    struct node* ptr;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);
}

struct node* delete_at_last(struct node* head, struct node** last) {
    if (head == NULL) return NULL;
    if (head->next == head) { // Only one element
        free(head);
        *last = NULL;
        return NULL;
    }
    struct node* ptr = head;
    while (ptr->next->next != head) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = head;
    *last = ptr;
    return head;
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;
    int choice, data, position;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_at_first(head, &tail, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                Insert_at_last(head, &tail, data);
                break;
            case 3:
                printf("Enter position and data: ");
                scanf("%d %d", &position, &data);
                Insert_At_Specific_Position(head, position, data);
                break;
            case 4:
                head = delete_at_first(head, &tail);
                break;
            case 5:
                head = delete_at_last(head, &tail);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                delete_At_Specific_Position(head, position);
                break;
            case 7:
                linked_List_Traversal(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
