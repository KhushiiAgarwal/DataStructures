#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct
{
    char name[50];
    int roll_no;
    int total_marks;
} Student;

int bubble_sort(Student students[], int num_students);
int quick_sort(Student students[], int left, int right);
int partition(Student students[], int left, int right);
void swap(Student *a, Student *b);

int main()
{
    Student students[MAX_STUDENTS];
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++)
    {
        printf("\nStudent %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);

        printf("Total Marks: ");
        scanf("%d", &students[i].total_marks);
    }

    printf("\n\nBefore sorting:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("%d. %s (Roll No: %d, Total Marks: %d)\n", i + 1, students[i].name, students[i].roll_no, students[i].total_marks);
    }

    int num_swaps = bubble_sort(students, num_students);

    printf("\n\nAfter Bubble sort:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("%d. %s (Roll No: %d, Total Marks: %d)\n", i + 1, students[i].name, students[i].roll_no, students[i].total_marks);
    }
    printf("Number of swaps performed: %d\n", num_swaps);

    num_swaps = quick_sort(students, 0, num_students - 1);
    printf("\n\nAfter Quick sort:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("%d. %s (Roll No: %d, Total Marks: %d)\n", i + 1, students[i].name, students[i].roll_no, students[i].total_marks);
    }
    printf("Number of swaps performed: %d\n", num_swaps);

    return 0;
}

int bubble_sort(Student students[], int num_students)
{
    int i, j, num_swaps = 0;

    for (i = 0; i < num_students - 1; i++)
    {
        for (j = 0; j < num_students - i - 1; j++)
        {
            if (students[j].roll_no > students[j + 1].roll_no)
            {
                swap(&students[j], &students[j + 1]);
                num_swaps++;
            }
        }
    }

    return num_swaps;
}

int quick_sort(Student students[], int left, int right)
{
    int num_swaps = 0;

    if (left < right)
    {
        int pivot_index = partition(students, left, right);
        num_swaps += quick_sort(students, left, pivot_index - 1);
        num_swaps += quick_sort(students, pivot_index + 1, right);
        num_swaps++;
    }

    return num_swaps;
}

int partition(Student students[], int left, int right)
{
    int pivot_roll_no = students[right].roll_no;
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (students[j].roll_no < pivot_roll_no)
        {
            i++;
            swap(&students[i], &students[j]);
        }
    }

    swap(&students[i + 1], &students[right]);

    return i + 1;
}

void swap(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}
