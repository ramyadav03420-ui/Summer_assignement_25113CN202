#include <stdio.h>

int main() {
    int n, i, j, count;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    int visited[n]; 

    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }

    printf("\nElement Frequencies:\n");
    for(i = 0; i < n; i++) {
        if(visited[i] == 1) {
            continue;
        }

        count = 1; 
        
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }
        
        printf("%d occurs %d time(s)\n", arr[i], count);
    }

    return 0;
}
