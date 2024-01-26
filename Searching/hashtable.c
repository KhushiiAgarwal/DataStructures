// WAP to simulate faculty database as a hash table. Search a particular
// faculty by using 'divide' as a hash function for linear probing with
// chaining without replacement method of collision handling technique.
// Assume suitable data for faculty record.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//search not working
#define SIZE 5

// Structure for faculty record
typedef struct {
    char name[50];
    int id;
    char department[50];
} Faculty;

// Structure for hash table entry
typedef struct {
    Faculty* faculty;
    int filled;
} HashEntry;

// Function prototypes
int hash(int key);
void insert(Faculty* faculty, HashEntry* table);
Faculty* search(char* name, HashEntry* table);

// Main function
int main() {
    HashEntry table[SIZE];
    int i, choice, id;
    char name[50], department[50];
    Faculty* faculty;

    // Initialize hash table
    for(i = 0; i < SIZE; i++) {
        table[i].faculty = NULL;
        table[i].filled = 0;
    }

    // Menu-driven program
    while(1) {
        printf("1. Insert a faculty record\n");
        printf("2. Search for a faculty record\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Get input from user
                faculty = (Faculty*) malloc(sizeof(Faculty));
                printf("Enter faculty name: ");
                scanf("%s", faculty->name);
                printf("Enter faculty ID: ");
                scanf("%d", &faculty->id);
                printf("Enter faculty department: ");
                scanf("%s", faculty->department);

                // Insert faculty record into hash table
                insert(faculty, table);
                break;

            case 2:
                // Get name of faculty to search for
                printf("Enter name of faculty to search for: ");
                scanf("%s", name);

                // Search for faculty record in hash table
                faculty = search(name, table);

                // Print results
                if(faculty != NULL) {
                    printf("Faculty found:\n");
                    printf("Name: %s\n", faculty->name);
                    printf("ID: %d\n", faculty->id);
                    printf("Department: %s\n", faculty->department);
                } else {
                    printf("Faculty not found.\n");
                }
                break;

            case 3:
                // Quit program
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

// Hash function using divide method
int hash(int key) {
    return key % SIZE;
}

// Insert faculty record into hash table
void insert(Faculty* faculty, HashEntry* table) {
    int index = hash(faculty->id);

    // Check if table is already full
    if(table[index].filled == 1) {
        printf("Table is full.\n");
        return;
    }

    // Linear probing with chaining without replacement
    while(table[index].filled == 1) {
        index = (index + 1) % SIZE;
    }

    // Insert faculty record into hash table
    table[index].faculty = faculty;
    table[index].filled = 1;
}

// Search for faculty record in hash table
Faculty* search(char* name, HashEntry* table) {
    int i, index;
    Faculty* faculty;

    // Linear probing with chaining without replacement
    for(i = 0; i < SIZE; i++) {
        index = (hash(i) + i) % SIZE;

        // Check if current entry is empty
        if(table[index].filled == 0) {
            return NULL;
        }

        // Check if current faculty record matches search criteria
        faculty = table[index].faculty;
        if(strcmp(faculty->name, name) == 0) {
            return faculty;
        }
    }

    // Faculty record not found
    return NULL;
}
