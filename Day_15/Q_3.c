#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rightRotate(int arr[], int n, int k) {
    k = k % n;
    
    if (k == 0) return;

    reverse(arr, 0, n - 1);
    
    reverse(arr, 0, k - 1);
    
    reverse(arr, k, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 

    printf("Original Array:\n");
    printArray(arr, n);

    rightRotate(arr, n, k);

    printf("Array after Right Rotation by %d positions:\n", k);
    printArray(arr, n);

    return 0;
}
