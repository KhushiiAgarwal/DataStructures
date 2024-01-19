#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

// Fibonacci search without recursion
int fibSearch(int id, struct Employee *emp, int n) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;
    int offset = -1;
    
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }
    
    while (fib > 1) {
        int i = (offset + fib2 < n) ? offset + fib2 : n - 1;
        
        if (emp[i].id < id) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (emp[i].id > id) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }
    
    if (fib1 == 1 && emp[offset+1].id == id) {
        return offset + 1;
    }
    
    return -1;
}

// Fibonacci search with recursion
int fibSearchRecursive(int id, struct Employee *emp, int n, int fib2, int fib1, int offset) {
    if (fib1 >= 1) {
        int i = (offset + fib2 < n) ? offset + fib2 : n - 1;
        if (emp[i].id < id) {
            return fibSearchRecursive(id, emp, n, fib1, fib2 - fib1, i);
        } else if (emp[i].id > id) {
            return fibSearchRecursive(id, emp, n, fib2, fib1 - fib2, offset);
        } else {
            return i;
        }
    }
    if (fib1 == 0 && emp[offset+1].id == id) {
        return offset + 1;
    }
    return -1;
}

int main() {
    int n, id, pos;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee *emp = (struct Employee *) malloc(n * sizeof(struct Employee));
    printf("Enter employee details:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    pos = fibSearch(id, emp, n);
    if (pos == -1) {
        printf("Employee record with ID %d not found.\n", id);
    } else {
        printf("Employee record with ID %d found at position %d.\n", id, pos+1);
    }
    pos = fibSearchRecursive(id, emp, n, 0, 1, -1);
    if (pos == -1) {
        printf("Employee record with ID %d not found.\n", id);
   
    } else {
        printf("Employee record with ID %d found at position %d.\n", id, pos+1);
    }
    free(emp);
    return 0;
}
