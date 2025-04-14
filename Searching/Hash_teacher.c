#include<stdio.h>
#include<string.h>
#define SIZE 10 //size of hash table

struct faculty {
    int id;
    char name[50];
    char department[50];
};

struct faculty table[SIZE]; //hash table

//function to insert a faculty member into the hash table
void insert(int id, char name[], char department[]) {
    int key = id % SIZE; //hash function using MOD
    int i = key;
    while(table[i].id != -1) { //linear probing for collision handling
        i = (i+1) % SIZE;
        if(i == key) {
            printf("Hash table is full. Could not insert %s\n", name);
            return;
        }
    }
    table[i].id = id;
    strcpy(table[i].name, name);
    strcpy(table[i].department, department);
    printf("%s inserted successfully into the hash table.\n", name);
}

//function to search for a faculty member by ID
void search(int id) {
    int key = id % SIZE; //hash function using MOD
    int i = key;
    while(table[i].id != -1) { //linear probing for collision handling
        if(table[i].id == id) {
            printf("ID: %d\nName: %s\nDepartment: %s\n", table[i].id, table[i].name, table[i].department);
            return;
        }
        i = (i+1) % SIZE;
        if(i == key) {
            printf("Could not find faculty member with ID %d\n", id);
            return;
        }
    }
    printf("Could not find faculty member with ID %d\n", id);
}

int main() {
    int choice, id;
    char name[50], department[50];
    for(int i=0; i<SIZE; i++) { //initialize hash table with -1
        table[i].id = -1;
    }
    while(1) { //menu-driven program
        printf("\nEnter your choice:\n1. Insert a faculty member\n2. Search for a faculty member by ID\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the faculty member's ID: ");
                scanf("%d", &id);
                printf("Enter the faculty member's name: ");
                scanf("%s", name);
                printf("Enter the faculty member's department: ");
                scanf("%s", department);
                insert(id, name, department);
                break;
            case 2:
                printf("\nEnter the faculty member's ID to search: ");
                scanf("%d", &id);
                search(id);
                break;
            case 3:
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
