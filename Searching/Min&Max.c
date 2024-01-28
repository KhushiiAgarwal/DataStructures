// WAP to simulate an application of Divide and Conquer methodology to search minimum and maximum number 
// simultaneously from a pool of random numbers entered by the user using recursive function.
#include <stdio.h>
#include <limits.h>

void find_min_max(int arr[], int low, int high, int *min, int *max) {
    int mid, min1, max1, min2, max2;

    // base case: when the array contains only one element
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // base case: when the array contains two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    // recursive case: divide the array into two halves
    mid = (low + high) / 2;
    find_min_max(arr, low, mid, &min1, &max1);
    find_min_max(arr, mid+1, high, &min2, &max2);

    // combine the results from the two halves
    if (min1 < min2) {
        *min = min1;
    } else {
        *min = min2;
    }

    if (max1 > max2) {
        *max = max1;
    } else {
        *max = max2;
    }
}

int main() {
    int n, i;
    int arr[100];
    int min = INT_MAX, max = INT_MIN;

    printf("Enter the number of elements in the array (up to 100): ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    find_min_max(arr, 0, n-1, &min, &max);

    printf("The minimum number in the array is %d\n", min);
    printf("The maximum number in the array is %d\n", max);

    return 0;
}
