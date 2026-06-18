#include <stdio.h>

int findMissingNumber(int arr[], int size) {
    int xor_all_elements = 0;
    int xor_sequence = 0;
    
    for (int i = 0; i < size; i++) {
        xor_all_elements ^= arr[i];
    }
    
    for (int i = 1; i <= size + 1; i++) {
        xor_sequence ^= i;
    }
    
    return xor_all_elements ^ xor_sequence;
}

int main() {
    int arr[] = {1, 2, 6, 3, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int missing_number = findMissingNumber(arr, size);
    
    printf("The missing number is: %d\n", missing_number);
    
    return 0;
}
