#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    int id;
    char name[20];
    char department[20];
    int salary;
} Employee;

Employee* hashtable[TABLE_SIZE];

int hash(int key) {
    int square = key * key;
    int temp = square / 100;
    int index = temp % TABLE_SIZE;
    return index;
}

void insert(Employee* emp) {
    int index = hash(emp->id);
    int i = index;
    do {
        if (hashtable[i] == NULL) {
            hashtable[i] = emp;
            printf("Employee added to the database.\n");
            return;
        }
        i = (i + 1) % TABLE_SIZE;
    } while (i != index);
    printf("Hash table is full, employee cannot be added.\n");
}

Employee* search(int key) {
    int index = hash(key);
    int i = index;
    do {
        if (hashtable[i] != NULL && hashtable[i]->id == key) {
            return hashtable[i];
        }
        i = (i + 1) % TABLE_SIZE;
    } while (i != index);
    return NULL;
}

void display(Employee* emp) {
    printf("Employee ID: %d\n", emp->id);
    printf("Name: %s\n", emp->name);
    printf("Department: %s\n", emp->department);
    printf("Salary: %d\n", emp->salary);
}

int main() {
    int choice;
    do {
        printf("\n1. Add employee\n2. Search employee\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Employee* emp = (Employee*) malloc(sizeof(Employee));
                printf("Enter employee ID: ");
                scanf("%d", &emp->id);
                printf("Enter employee name: ");
                scanf("%s", emp->name);
                printf("Enter employee department: ");
                scanf("%s", emp->department);
                printf("Enter employee salary: ");
                scanf("%d", &emp->salary);
                insert(emp);
                break;
            }
            case 2: {
                int key;
                printf("Enter employee ID to search: ");
                scanf("%d", &key);
                Employee* emp = search(key);
                if (emp == NULL) {
                    printf("Employee not found in the database.\n");
                } else {
                    display(emp);
                }
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (1);
    return 0;
}
