#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_BUCKET_SIZE 10

// Employee structure
typedef struct {
    char name[50];
    int emp_no;
    float salary;
} Employee;

// Function to swap two employees
void swap(Employee *a, Employee *b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort function
int selection_sort(Employee arr[], int n) {
    int swap_count = 0;
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j].emp_no < arr[min_index].emp_no) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
            swap_count++;
        }
    }
    return swap_count;
}

// Bucket sort function
int bucket_sort(Employee arr[], int n) {
    int swap_count = 0;
    // Create an array of buckets
    Employee buckets[MAX_BUCKET_SIZE][MAX_EMPLOYEES];
    int bucket_sizes[MAX_BUCKET_SIZE] = {0};

    // Insert employees into buckets based on emp_no
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i].emp_no / MAX_BUCKET_SIZE;
        int index = bucket_sizes[bucket_index]++;
        buckets[bucket_index][index] = arr[i];
    }

    // Sort each bucket using selection sort and count swaps
    for (int i = 0; i < MAX_BUCKET_SIZE; i++) {
        swap_count += selection_sort(buckets[i], bucket_sizes[i]);
    }

    // Merge sorted buckets back into original array
    int index = 0;
    for (int i = 0; i < MAX_BUCKET_SIZE; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    return swap_count;
}

int main() {
    // Initialize array of employees
    Employee employees[MAX_EMPLOYEES];
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Get input for each employee
    for (int i = 0; i < n; i++) {
        printf("Enter the name, emp_no, and salary of employee %d: ", i+1);
        scanf("%s %d %f", employees[i].name, &employees[i].emp_no, &employees[i].salary);
    }

    // Print unsorted array of employees
    printf("\nUnsorted array of employees:\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %.2f\n", employees[i].name, employees[i].emp_no, employees[i].salary);
    }
    printf("\n");

    // Sort using selection sort
    int selection_swaps = selection_sort(employees, n);

    // Print sorted array of employees using selection sort
    printf("Sorted array of employees using selection sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %.2f\n", employees[i].name, employees[i].emp_no,employees[i].salary);
    }
    printf("Number of swaps performed using selection sort: %d\n", selection_swaps);

    // Sort using bucket sort
    int bucket_swaps = bucket_sort(employees, n);

    // Print sorted array of employees using bucket sort
    printf("\nSorted array of employees using bucket sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %.2f\n", employees[i].name, employees[i].emp_no,employees[i].salary);
    }
    printf("Number of swaps performed using bucket sort: %d\n", bucket_swaps);

    return 0;
}
