#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;


        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;


        else
            right = mid - 1;
    }

   
    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    clock_t start_time = clock(); 

    int result = binarySearch(arr, 0, n - 1, target);

    clock_t end_time = clock(); 
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (result == -1)
        printf("Element %d is not present in the array.\n", target);
    else
        printf("Element %d is present at index %d.\n", target, result);

    printf("Time taken for the search: %f seconds\n", execution_time);

    return 0;
}
