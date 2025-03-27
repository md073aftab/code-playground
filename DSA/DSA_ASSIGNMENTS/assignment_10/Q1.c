#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct details {
    char Name[100];  
    int Rollno;     
    char Dept[10];   
};

// Function to swap two student records
void swap(struct details *a, struct details *b) {
    struct details temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort function (Sorts by name, then by roll Number)
void BubbleSort(struct details *arr, int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].Name, arr[j + 1].Name) > 0) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            } else if (strcmp(arr[j].Name, arr[j + 1].Name) == 0 && arr[j].Rollno > arr[j + 1].Rollno) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}

// Binary Search function to find students by Name
void BinarySearch(struct details *arr, int n, char *name) {
    int left = 0, right = n - 1, found = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid].Name, name);

        if (cmp == 0) {  
            found = 1;
            printf("Found Records:\n");

            // Print students before mid with the same name
            int i = mid;
            while (i >= 0 && strcmp(arr[i].Name, name) == 0) {
                printf("Name: %s, Roll No: %d, Dept: %s\n", arr[i].Name, arr[i].Rollno, arr[i].Dept);
                i--;
            }

            // Print students after mid with the same name
            i = mid + 1;
            while (i < n && strcmp(arr[i].Name, name) == 0) {
                printf("Name: %s, Roll No: %d, Dept: %s\n", arr[i].Name, arr[i].Rollno, arr[i].Dept);
                i++;
            }
            break;
        }
        if (cmp < 0)  //  If Name is greater, search right half
            left = mid + 1;
        else  // Name is smaller, search left half
            right = mid - 1;
    }

    if (!found)
        printf("No record found for student: %s\n", name);
}

// Function to print all student records
void printStudents(struct details *arr, int n) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Dept: %s\n", arr[i].Name, arr[i].Rollno, arr[i].Dept);
    }
}

int main() {
    FILE *file;
    struct details Students[1000];  // Array to store student details
    int i = 0;
    char line[150];

    // Open file in read mode
    file = fopen("text.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read file and store data in struct array
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        sscanf(line, "%99[^,],%d,%9s", Students[i].Name, &Students[i].Rollno, Students[i].Dept);
        i++;
    }

    fclose(file);

    int choice = 0;
    while (choice != 3) {
        printf("\n1. Bubble Sort\n2. Binary Search\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        if (choice == 1) {
            BubbleSort(Students, i);
            printf("\nRecords sorted successfully!\n");
            printStudents(Students, i);
        }
        else if (choice == 2) {
            char searchName[100];
            printf("\nEnter Student Name to Search: ");
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

            BinarySearch(Students, i, searchName);
        }
    }
    printf("\nProgram exited successfully.\n");
    return 0;
}
