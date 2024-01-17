#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for student record
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

// Function to perform binary search without recursion
int binarySearch(struct Student students[], int left, int right, int searchRoll) {
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (students[middle].rollNumber == searchRoll) {
            return middle;
        } else if (students[middle].rollNumber < searchRoll) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1; // Roll number not found
}

// Function to perform binary search using recursion
int binarySearchRecursive(struct Student students[], int left, int right, int searchRoll) {
    if (left > right) {
        return -1; // Roll number not found
    }
    int middle = left + (right - left) / 2;
    if (students[middle].rollNumber == searchRoll) {
        return middle;
    } else if (students[middle].rollNumber < searchRoll) {
        return binarySearchRecursive(students, middle + 1, right, searchRoll);
    } else {
        return binarySearchRecursive(students, left, middle - 1, searchRoll);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for students array dynamically
    struct Student *students = (struct Student*) malloc(n * sizeof(struct Student));

    // Get student data from user input
    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Sort the students array based on roll number using bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].rollNumber > students[j+1].rollNumber) {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }

    // Get the roll number to search from user input
    int searchRoll;
    printf("Enter the roll number to search: ");
    scanf("%d", &searchRoll);

    // Perform binary search without recursion
    int result = binarySearch(students, 0, n-1, searchRoll);
    if (result == -1) {
        printf("Student with roll number %d not found\n", searchRoll);
    } else {
        printf("Student with roll number %d found at index %d\n", searchRoll, result);
        printf("Name: %s, Roll number: %d, Marks: %.2f\n", students[result].name, students[result].rollNumber, students[result].marks);
    }

    // Perform binary search using recursion
    result = binarySearchRecursive(students, 0, n-1, searchRoll);
    if (result == -1) {
        printf("Student with roll number %d not found\n", searchRoll);
    } else {
        printf("Student with roll number %d found at index %d\n", searchRoll, result);
        printf("Name: %s, Roll number: %d, Marks: %.2f\n", students[result].name, students[result].rollNumber, students[result].marks);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
