#include <stdio.h>
#include <stdlib.h>

// Merge function that counts inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right) {// Merge Sort function that recursively counts inversions
    int mid, inv_count = 0;
    if (left < right) {
        mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int countInversions(int arr[], int n) {// Function to count inversions
    int *temp = (int *)malloc(n * sizeof(int));
    int inv_count = mergeSort(arr, temp, 0, n - 1);
    free(temp);
    return inv_count;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d distinct integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = countInversions(arr, n);
    printf("Number of inversions: %d\n", result);

    return 0;
}
