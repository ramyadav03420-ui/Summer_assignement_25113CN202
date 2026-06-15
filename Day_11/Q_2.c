#include <stdio.h>

int find_array_max(int arr[], int size) {
    int max_val = arr[0]; 

    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i]; 
        }
    }
    return max_val;
}

int main() {
    int numbers[] = {5, 22, 87, 12, 9, 63};
    
    int size = sizeof(numbers) / sizeof(numbers[0]); 
    
    int max_element = find_array_max(numbers, size);
    
    printf("The maximum element in the array is: %d\n", max_element);
    
    return 0;
}
