//WAP to perform insertion sort on Student data
#include <stdio.h>
#include <string.h>


#define MAX_STUDENTS 100


typedef struct
{
    char name[50];
    int roll_no;
    int total_marks;
} Student;


int insertion_sort(Student students[], int num_students);
int merge_sort(Student students[], int left, int right);
int merge(Student students[], int left, int mid, int right);
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


    int num_swaps = insertion_sort(students, num_students);


    printf("\n\nAfter Insertion sort:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("%d. %s (Roll No: %d, Total Marks: %d)\n", i + 1, students[i].name, students[i].roll_no, students[i].total_marks);
    }
    printf("Number of swaps performed: %d\n", num_swaps);


    num_swaps = merge_sort(students, 0, num_students - 1);


    printf("\n\nAfter Merge sort:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("%d. %s (Roll No: %d, Total Marks: %d)\n", i + 1, students[i].name, students[i].roll_no, students[i].total_marks);
    }
    printf("Number of swaps performed: %d\n", num_swaps);


    return 0;
}


int insertion_sort(Student students[], int num_students)
{
    int i, j, num_swaps = 0;
    Student key;


    for (i = 1; i < num_students; i++)
    {
        key = students[i];
        j = i - 1;


        while (j >= 0 && students[j].roll_no > key.roll_no)
        {
            students[j + 1] = students[j];
            j = j - 1;
            num_swaps++;
        }


        students[j + 1] = key;
    }


    return num_swaps;
}


int merge_sort(Student students[], int left, int right) {
    int num_swaps = 0;


    if (left < right) {
        int mid = (left + right) / 2;
        num_swaps += merge_sort(students, left, mid);
        num_swaps += merge_sort(students, mid+1, right);
        num_swaps += merge(students, left, mid, right);
    }


    return num_swaps;
}


int merge(Student students[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;


    Student L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = students[left + i];
    for (j = 0; j < n2; j++)
        R[j] = students[mid + 1 + j];


    i = 0;
    j = 0;
    k = left;


    while (i < n1 && j < n2)
    {
        if (L[i].roll_no <= R[j].roll_no)
        {
            students[k] = L[i];
            i++;
        }
        else
        {
            students[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        students[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        students[k] = R[j];
        j++;
        k++;
    }
}


void swap(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}
