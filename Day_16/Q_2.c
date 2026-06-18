#include <stdio.h>

int main() {
    int arr[] = {4, 2, 7, 4, 7, 5, 7, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int max_element = arr[0];
    int max_count = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }

    printf("Element with maximum frequency: %d\n", max_element);
    printf("Frequency: %d times\n", max_count);

    return 0;
}
