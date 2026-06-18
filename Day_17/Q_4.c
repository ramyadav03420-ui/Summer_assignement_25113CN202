#include <stdio.h>
#include <stdbool.h>

void findCommonElements(int arr1[], int size1, int arr2[], int size2) {
    printf("Common elements: ");
    bool foundAny = false;

    for (int i = 0; i < size1; i++) {
        
        bool isDuplicate = false;
        for (int k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate) {
            continue; 
        }

        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                foundAny = true;
                break; 
            }
        }
    }

    if (!foundAny) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int array1[] = {4, 9, 2, 4, 1, 7};
    int array2[] = {2, 7, 4, 4, 12, 1};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", array1[i]);
    printf("\n");

    printf("Array 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", array2[i]);
    printf("\n");

    findCommonElements(array1, size1, array2, size2);

    return 0;
}
