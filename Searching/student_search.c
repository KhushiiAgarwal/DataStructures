#include <stdio.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    char name[50];
    int rollNo;
    char division[3];
};

int main() {
    // Take input from the user for the list of students
    int numStudents;
    printf("Enter the number of students in the department: ");
    scanf("%d", &numStudents);
    struct Student students[numStudents];
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Division: ");
        scanf("%s", students[i].division);
    }

    // Take input from the user for the student to be searched
    char targetName[50];
    int targetRollNo;
    printf("Enter the name of the student: ");
    scanf("%s", targetName);
    printf("Enter the roll no. of the student: ");
    scanf("%d", &targetRollNo);

    // Find the required student
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, targetName) == 0 && students[i].rollNo == targetRollNo && strcmp(students[i].division, "SE") == 0) {
            printf("Found student: %s (Roll No: %d)\n", students[i].name, students[i].rollNo);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    return 0;
}
