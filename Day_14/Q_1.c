#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n, target, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Success! Element %d found at index %d (position %d).\n", target, result, result + 1);
    } else {
        printf("Element %d is not present in the array.\n", target);
    }

    return 0;
}
