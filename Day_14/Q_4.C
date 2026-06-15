#include <stdio.h>
#include <stdbool.h>

bool checkDuplicates(int *arr, int n) {
  	
    for(int i = 0; i < n - 1; i++) {
      
        for(int j = i + 1; j < n; j++) {
          
            if(arr[i] == arr[j])
                return true;
        }
    }

    return false;
}

int main () {
    int arr[] = {4, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
	printf(checkDuplicates(arr, n) ? "true" : "false");

    return 0;
}