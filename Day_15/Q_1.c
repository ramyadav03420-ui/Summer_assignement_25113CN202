#include <stdio.h>

void rev(int arr[], int n) {
  
    int l = 0, r = n - 1;
    while (l < r) {
      
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        
        l++;
        r--;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    rev(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}